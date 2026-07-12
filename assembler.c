#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<assert.h>
int main(int argv,char **argc){
	int fd=open(argc[1],O_RDONLY);
	if(fd==-1){
		printf("Not a valid file\n");
		return 3;
	}
	char a;
	if(read(fd,&a,1)){
		printf("failed to read(may be the file is empty) \n"); 
		return 2;
	}

	while(1){
		assert(read(fd,&a,1));
		printf("%c",a);
	}
	printf("\n");






	return 0;}

