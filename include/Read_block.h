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


int returnPosition(TagArray arrayOfTags, int index);
char* createAnArrayOfChar(char* information, int size);
void freeArrayOfChar(char* array);
TagArray allocateNewTagArray(TagArray arrayOfTags);
void freeTagArray(TagArray arrayOfTags);
char* * allocateDoubleArrayOfChar(char* * array, int size);
void freeDoubleArrayOfChar(char* * array, int size);

#endif
