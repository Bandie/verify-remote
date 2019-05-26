/*
FILENAME :     verify-remote.c
DESCRIPTION :  Functions which touches a file to R_VRFFILE if an object exists under URL
AUTHOR :       Bandie
DATE :         2019-05-26T20:48:48+02:00
LICENSE :      GNU-GPLv3
*/


#include "verify-remote.h"


size_t write_data(void *buffer, size_t size, size_t nmemb, void *userp){
   return size * nmemb;
}

void touch(){
  FILE *f = fopen(R_VRFFILE, "w");
  if(f == NULL){
    fprintf(stderr, "ERROR opening file.");
    exit(1);
  }
  fclose(f);
}

void rm(){
  if(access(R_VRFFILE, F_OK) != -1)
    unlink(R_VRFFILE);
}

int vrf(){

  CURL *curl;
  CURLcode ret;
  long http = 0;

  curl = curl_easy_init();
  ret = curl_easy_perform(curl);

  if(curl){
    curl_easy_setopt(curl, CURLOPT_URL, URL);
    curl_easy_setopt(curl, CURLOPT_TIMEOUT, TMOUT);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
    ret = curl_easy_perform(curl);
  
    if(ret != CURLE_OK){
      fprintf(stderr, "Failed: %s\n", curl_easy_strerror(ret));
      rm();
      curl_easy_cleanup(curl);
      return 1;
    }
    else{
      curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &http);
      if(http == 200){
        touch();
        curl_easy_cleanup(curl);
        return 2;
      }
      else{
        rm();
        curl_easy_cleanup(curl);
        return 4;
      }
  
    }

    curl_easy_cleanup(curl);
  }


  return 0;
}
