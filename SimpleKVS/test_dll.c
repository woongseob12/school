#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dlfcn.h>
#include "kvs.h"

extern FILE *putP, *getP;

pNode *pHead; 

int main(int argc, char* argv[])
{
	if (argc != 4){
		printf("Usage : ./%s put.txt get.txt result_dll.txt\n",argv[0]);
		return 0;
	}

	void *handle;
	int (*open)();
	int (*put)(char* key, char* value, int nbytes);
	char* (*get)(char* key, int* nbytes);
	void (*close)();
	char *error;
	
	handle = dlopen("./libfile.so", RTLD_NOW);
	if(!handle){
		fprintf(stderr,"%s\n", dlerror());
		exit(1);
	}

	int openErr;
	int sucPut;
	char key[16];
	char value[99];
	char getValue[99];

	open = (int(*)()) dlsym(handle, "open");
	if((error = dlerror()) != NULL){
		fprintf(stderr, "%s\n", error);
		exit(1);
	}
	
	openErr=open();
	if(openErr !=  0){
		if(openErr == -1){
			printf("put.txt Open Error!");
		}
		else{
			printf("get.txt Open Error!");
		}
		return 0;
	}

	put = (int(*)(char*, char*, int)) dlsym(handle, "put");
	if((error = dlerror()) != NULL){
		fprintf(stderr, "%s\n", error);
		exit(1);
	}

	pHead = (pNode*)malloc(sizeof(pNode));
	pHead->next = NULL;
	
	while(feof(putP) == 0){
		fscanf(putP,"%s %s\n",key,value);
		sucPut = put(key, value, 1);
		if(sucPut == -1){
			printf("Fail to store\n");
			exit(1);
		}
	}

	get = (char*(*)(char*,int*))dlsym(handle, "get");
	if((error = dlerror()) != NULL){
		fprintf(stderr, "%s\n", error);
		exit(1);
	}
	
	FILE *resP = fopen("result_dll.txt","w");

	while(feof(getP) == 0){
		fscanf(getP,"%s\n",key);
		strcpy(getValue,get(key,NULL));
		if(getValue[0] != '\0'){
			fputs(getValue,resP);
			fputc('\n',resP);
		}
	}

	fclose(resP);

	close = (void(*)()) dlsym(handle, "close");
	if((error = dlerror()) != NULL){
		fprintf(stderr, "%s\n", error);
		exit(1);
	}
	close();

	if(dlclose(handle) < 0){
		fprintf(stderr, "%s\n", dlerror());
		exit(1);
	}
	return 0;
}
