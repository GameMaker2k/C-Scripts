/*
    This program is free software; you can redistribute it and/or modify
    it under the terms of the Revised BSD License.
 
    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    Revised BSD License for more details.
 
    Copyright 2012 iDB Support - http://idb.berlios.de/
    Copyright 2012 Game Maker 2k - http://gamemaker2k.org/
 
    $FileInfo: count.c - Last Update: 03/24/2012 Ver 1 - Author: cooldude2k $
*/

#include <ctype.h>
#include <errno.h>
#include <float.h>
#include <limits.h>
#include <math.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[])
{
//int y = 0,x,tstart,tend,tcheck;
  long int y = 0,x,z = 0,tstart,tend,tcheck;
  char prey[256],prex[256],prez[256];
  FILE *fp;
  if(argc >= 2) {
  x = strtol(argv[1],NULL,0); }
  if(argc >= 3) {
  y = strtol(argv[2],NULL,0); }
  if(argc >= 4) {
  z = strtol(argv[3],NULL,0); }
  if(argc >= 5) {
  fp = fopen(argv[4], "w+"); }
  if(argc <= 1) {
  printf("Executing %s\n", argv[0]); }
  if(argc == 2) {
  printf("Executing %s with argument %s\n", argv[0], argv[1]); }
  if(argc == 3) {
  printf("Executing %s with arguments %s,%s\n", argv[0], argv[1], argv[2]); }
  if(argc == 4) {
  printf("Executing %s with arguments %s,%s,%s\n", argv[0], argv[1], argv[2], argv[3]); }
  if(argc >= 5) {
  printf("Executing %s with arguments %s,%s,%s,%s\n", argv[0], argv[1], argv[2], argv[3], argv[4]); 
  fprintf(fp, "Executing %s with arguments %s,%s,%s,%s\n", argv[0], argv[1], argv[2], argv[3], argv[4]);
  printf("Writing output to file %s\n", argv[4]);
  fprintf(fp, "Writing output to file %s\n", argv[4]); }
  if(argc <= 1) {
  printf("Please enter a number to count to: ");
//scanf("%ld", &x);
  fgets(prex, 256, stdin);
  x = strtol(prex,NULL,0); }
  if(argc <= 2) {
  printf("Please enter a number to start at: ");
//scanf("%ld", &y);
  fgets(prey, 256, stdin);
  y = strtol(prey,NULL,0); }
  if(argc <= 3) {
  printf("Please enter a number to cont by: ");
//scanf("%ld", &z);
  fgets(prez, 256, stdin);
  z = strtol(prez,NULL,0); }
  printf("You entered numbers %ld,%ld,%ld\n", x, y, z);
  if(argc >= 5) {
  fprintf(fp, "You entered numbers %ld,%ld,%ld\n", x, y, z); }
  tstart = time(NULL);
  if(z == 0) {
  z = 1; }
  if(x <= y) {
  while (y >= x) { 
      printf("%ld\n", y);
      if(argc >= 5) {
      fprintf(fp, "%ld\n", y); }
      if(z > 1 || z < 0) {
      y -= z; }
      if(z == 1) {
      y--; }
  } }
  else if(x > y) {
  while (y <= x) { 
      printf("%ld\n", y);
      if(argc >= 5) {
      fprintf(fp, "%ld\n", y); }
      if(z > 1 || z < 0) {
      y += z; }
      if(z == 1) {
      y++; }
  } }
  tend = time(NULL);
  tcheck = difftime(tend,tstart);
  printf("%s executed in %ld seconds\n", argv[0], tcheck);
  if(argc >= 5) {
  fprintf(fp, "%s executed in %ld seconds\n", argv[0], tcheck); }
  if(argc >= 5) {
  fclose(fp); }
//if(argc <= 1) {
//getchar(); }
  return 0;
}

