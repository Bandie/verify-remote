/*
FILENAME :     verify-remote_serv.c
DESCRIPTION :  Service handler for verify-remote.c
AUTHOR :       Bandie
DATE :         2019-05-26T20:48:48+02:00
LICENSE :      GNU-GPLv3
*/

#include "verify-remote.c"
#include <signal.h>
#include <sys/wait.h>

#define SLP 5

void sig_handler(int signo){
  if(signo == SIGTERM || signo == SIGINT){
    rm();
    exit(0);
  }
}

int main(){

  int statval;

  while(1){
    
    if(fork() == 0){
      return vrf();
    }
    else{
      wait(&statval);
    }

    sleep(5);
  }

  return 0;
}
