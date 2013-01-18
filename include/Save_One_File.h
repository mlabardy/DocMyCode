#ifndef SAVE_ONE_FILE_H
#define SAVE_ONE_FILE_H

#include"Save_blocks.h"
#include"Read_block.h"
#include"Special_Tags.h"

/**
* \file				Read_block.c
* \brief			\a cette fonction ne devrait pas être là, ceci est une description courte
* \details 			\a cette fonction ne devrait pas être là, ceci est une description longue
* \param   			char information
* 					int \a size
* \return 			\b an array of char
*					this function create an array of char
*/
int stockInformation(TagArray arrayOfTags, char* string, int *i, int index, int position, int previousStar);
int verifyTheNextType(char* string, int *i);
int verifyTheFile(SaveTagArrays source, char* fileName);

/**
* \file 			Read_block.c
* \param   			char information
* 					int \a size
* \return 			\b an array of char
*					this function create an array of char
*/

int compareStrings(char* string_1, char* string_2);


SaveTagArrays readFile(char* fileName);
void readHeaderSource(SaveTagArrays sourceTagArray, SaveTagArrays headerTagArray, char* headerName, char* sourceName);
void headerSourceSavingArray(SaveTagArrays sourceTagArray, SaveTagArrays headerTagArray);

#endif
