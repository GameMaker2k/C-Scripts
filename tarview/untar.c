/*
    This program is free software; you can redistribute it and/or modify
    it under the terms of the Revised BSD License.
 
    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    Revised BSD License for more details.
 
    Copyright 2012 iDB Support - http://idb.berlios.de/
    Copyright 2012 Game Maker 2k - http://gamemaker2k.org/
    C iUnTar ver. 1.2.4 by Kazuki Przyborowski
 
    $FileInfo: untar.c - Last Update: 03/24/2012 Ver 1.2.4 - Author: cooldude2k $
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>

// By TSK
// URL: http://answers.yahoo.com/question/index?qid=20090913180957AAOrsYx
int oct2dec ( int num )
{
	int total = 0,power=1;
	while(num > 0)
	{
	total +=power*(num%10) ;
	num /= 10;
	power *= 8; // 2 for binary to decimal
	}
	return total;
}

// C iUnTAR Version 1.2.4
// license: Revised BSD license
// Kazuki Przyborowski (http://ja.gamemaker2k.org/)
int untar(char *tarfile, char *outdir, int chmod, bool extract)
{
	int TarSize, TarSizeEnd, FileType, FileMode, OwnerID, GroupID, FileSize, LastEdit, Checksum, LinkedFile, CheckSize, SeekSize;
	char FileName[100], PreFileType[1], PreFileMode[8], PreOwnerID[8], PreGroupID[8], PreFileSize[12], PreLastEdit[12], PreChecksum[8], PreLinkedFile[100];
	if(outdir=="") {
	outdir = "./"; }
	if(outdir!="./"&&extract==true) {
	mkdir(outdir, 0755); } 
	FILE *thandle = fopen(tarfile, "rb");
	fseek(thandle, 0L, SEEK_END);
	TarSize = ftell(thandle);
	TarSizeEnd = TarSize - 1024;
	fseek(thandle, 0L, SEEK_SET);
	while (ftell(thandle)<TarSizeEnd) {
	fread(FileName, 100, 1, thandle);
	char FullFileName[strlen(outdir) + strlen(FileName)];
	sprintf(FullFileName, "%s%s", outdir, FileName);
	fseek(thandle, 56L, SEEK_CUR);
	fread(PreFileType, 1, 1, thandle);
	FileType = atoi(PreFileType);
	fseek(thandle, -57L, SEEK_CUR);
	fread(PreFileMode, 8, 1, thandle);
	FileMode = atoi(PreFileMode);
	fread(PreOwnerID, 8, 1, thandle);
	OwnerID = atoi(PreOwnerID);
	fread(PreGroupID, 8, 1, thandle);
	GroupID = atoi(PreGroupID);
	fread(PreFileSize, 12, 1, thandle);
	FileSize = oct2dec(atoi(PreFileSize));
	fread(PreLastEdit, 12, 1, thandle);
	LastEdit = oct2dec(atoi(PreLastEdit));
	fread(PreChecksum, 8, 1, thandle);
	Checksum = oct2dec(atoi(PreChecksum));
	fread(PreFileType, 1, 1, thandle);
	FileType = atoi(PreFileType);
	fread(PreLinkedFile, 100, 1, thandle);
	LinkedFile = atoi(PreLinkedFile);
	fseek(thandle, 255L, SEEK_CUR);
	if(extract==true) {
	if(FileType==0||FileType==7) {
	fprintf(stdout, "inflating file %s\n", FullFileName);
	char FileContent[FileSize];
	if(FileSize==0) {
	char FileContent[1]; }
	if(FileSize==0) {
	strcpy(FileContent, ""); }
	if(FileSize>0) {
	fread(FileContent, FileSize, 1, thandle); }
	FILE *subhandle = fopen(FullFileName, "wb+");
	fwrite(FileContent, FileSize, 1, subhandle);
	fclose(subhandle); }
	if(FileType==5) {
	char FileContent[1];
	strcpy(FileContent, "");
	fprintf(stdout, "inflating dir %s\n", FullFileName);
	mkdir(FullFileName, 0755); } }
	if(extract==false) {
	if(FileType==0||FileType==7) {
	fseek(thandle, FileSize, SEEK_CUR); }
	fprintf(stdout, "%s\n", FullFileName); }
	CheckSize = 512;
	if((FileType==0||FileType==7)&&FileSize>0) {
	while (CheckSize<FileSize) {
	if(CheckSize<FileSize) {
	CheckSize = CheckSize + 512; } }
	SeekSize = CheckSize - FileSize;
	fseek(thandle, SeekSize, SEEK_CUR); } }
	fclose(thandle);
	return 0;
}
int iuntar(char *tarfile, char *outdir, int chmod, bool extract) 
{
	return untar(tarfile, outdir, chmod, extract); 
}

int main(int argc, char *argv[])
{
	char tarfile[256], taroutf[256];
	if(argc==2) {
	untar(argv[1], "./", 0755, true); }
	if(argc==3) {
	untar(argv[1], argv[2], 0755, true); }
	if(argc == 1) {
	fprintf(stdout, "Enter Tar File: ");
	fgets(tarfile, 256, stdin);
	size_t tfln = strlen(tarfile) - 1;
	if(tarfile[tfln] == '\n') {
	tarfile[tfln] = '\0'; }
	fprintf(stdout, "Enter Output Dir: ");
	fgets(taroutf, 256, stdin);
	size_t tofln = strlen(taroutf) - 1;
	if(taroutf[tofln] == '\n') {
	taroutf[tofln] = '\0'; }
	untar(tarfile, taroutf, 0755, true); }
	return 0;
}
