#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kvs.h"

extern FILE *putP, *getP;

pNode *pHead;

int main(int argc, char* argv[])
{
	if (argc != 4){
		printf("Usage : ./%s put.txt get.txt result_static.txt\n",argv[0]);
		return 0;
	}
	
	int openErr;
	int sucPut;
	char key[16];
	char value[99];
	char getValue[99];

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

	pHead = (pNode*)malloc(sizeof(pNode));
	pHead->next = NULL;
	while(feof(putP) == 0){
		fscanf(putP,"%s %s\n",key,value);
		sucPut = put(key, value, 1);
		if(sucPut == -1){
			printf("Fail to store\n");
			return 0;
		}
	}
	
	FILE *resP = fopen("result_static.txt","w");
	
	while(feof(getP) == 0){
		fscanf(getP,"%s\n",key);
		strcpy(getValue,get(key,NULL));
		if(getValue[0] != '\0'){
			fputs(getValue,resP);
			fputc('\n',resP);
		}
	}
	fclose(resP);

	close();
}
