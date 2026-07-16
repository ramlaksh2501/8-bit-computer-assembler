/*
author:LAKSH
project name: 8-bit assembler for a custom hardware
started at :july 12 2026
*/
/*
tool cmd 
must pass atleast one argument (name of the asm file or the entire path of the file 
\\\\\ the assemble file  may be in .s or .asm format\\\\\\\\\\\\\
[name-of-the-binary] [name of the asm file(or the entire path] [name of the binary --optional]
*/

#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<assert.h>
#include<sys/stat.h>
#include<string.h>
#include<errno.h>




int main(int argv,char **argc){
	char *bin;
	if(argv==1){
		errno=ESRCH;
		perror("Need to pass argument : name of the assembly file (.s or .asm file name needed )\n");
		return 1;}
	int ASM=1;
	int HEX=2;
	if(argv==2){
		HEX=-1;
		bin=malloc(sizeof(char)*8);
		char file[]="out.hex";
		memcpy(bin,file,8);
	}
	if(argv>2){
		printf("ERROR:Too many arguments only need a .s/asm(input) and a .hex(output) file as argument\n");
		return 1;
	}
	int fd=open(argc[ASM],O_RDONLY);//opening the asm file 
	if(fd==-1){
		perror("Not a valid file\n");
		return 2;
	}
	printf("%d\n",HEX);
	int fd_hex;
	if(HEX!=-1){
	fd_hex=open(argc[HEX],O_TRUNC|O_CREAT|O_RDONLY,S_IRWXG|S_IRWXU|S_IRWXO);
	}
	else{
	fd_hex=open(bin,O_WRONLY|O_TRUNC|O_CREAT);
	}
	if(fd_hex==-1){
		perror("error while creating the hex file\n");
		return 2;
	}
	int bufsize;
	struct stat file_status;
	if(stat(argc[1],&file_status)==-1){
			perror("error reading file\n");
			}
	bufsize=file_status.st_size+1;
	char *content=(char *)malloc(sizeof(char)*bufsize);
	if(content==NULL){
		perror("memory issue \n");
		return 3;
		}


	return 0;}

