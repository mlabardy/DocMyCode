#ifndef WRITE_ONE_DOC_H
#define WRITE_ONE_DOC_H

#include"Read_block.h"
#include"Save_blocks.h"
#include"Save_One_File.h"
#include"Special_Tags.h"

char* renameAFileToHtml(char* source, char* destination);
char* renameAFileToHeader(char* source, char* destination);
void startToWriteMenu(FILE* file);
void stopToWriteMenu(FILE* file);
int startListOfFunctionsPart(SaveTagArrays list, FILE* file, char* sourceName);
void endListOfFunctionsPart(FILE* file);
void writeListOfFunctions(SaveTagArrays list, FILE* file, int index, char* sourceName, char* * saveFunctions, int* i);
void startDescriptionOfFunctionsPart(SaveTagArrays list, FILE* file, char* sourceName);
void writeDescriptionOfFunctions(SaveTagArrays list, FILE* file, char* sourceName);
int startFilePart(SaveTagArrays list, FILE* file, int index, char* fileName);
void writeDescriptionOfFile(SaveTagArrays list, FILE* file, int index, char* fileName);
FILE* openHtmlFile(char* sourceName, char* fileToWrite, FILE* file);
void closeHtmlFile(FILE* file);

#endif
