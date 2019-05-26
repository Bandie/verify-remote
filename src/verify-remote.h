/*
FILENAME :     verify-remote.h
DESCRIPTION :  Header file for verify-remote.c. Configure me!
AUTHOR :       Bandie
DATE :         2019-05-26T20:48:48+02:00
LICENSE :      GNU-GPLv3
*/

#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>
#include <unistd.h>

#define R_VRFFILE "/r_verified"
#define URL "http://10.1.0.1/verified"
#define TMOUT 5L

