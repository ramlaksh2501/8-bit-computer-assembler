#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<assert.h>
#include<sys/stat.h>
int main(int argv,char **argc){
	int fd=open(argc[1],O_RDONLY);
	if(fd==-1){
		printf("Not a valid file\n");
		return 2;
	}
	char a;
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
	if(read(fd,content,bufsize)<=0){
		perror("failed to read file\n");
		return 4;
	}

	printf("%s",content);

	return 0;}

