#ifndef READ_BLOCK_H
#define READ_BLOCK_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<dirent.h>
#include<sys/types.h>


#define NB_TAGS 10
#define SIZE 200
#define ON 1
#define OFF 0
#define START_TYPE_1 1
#define START_TYPE_2 2
#define START 1
#define END 0
#define OVER -1

typedef struct {
	char**information;
	int size;
}tagArray, *TagArray; 


int searchInformations(char* string);
char* createAnArrayOfChar(char* information, int size);
int* initArrayOfInt(int* isEmpty, int size);
TagArray allocateNewTagArray(TagArray arrayOfTags);
TagArray stockInformation(TagArray arrayOfTags, char c, int index, int position);
void freeTagArray(TagArray arrayOfTags);
int displayTagArray(TagArray arrayOfTags);
int readFile(char* fileName);

#endif
