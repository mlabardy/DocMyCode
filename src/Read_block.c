#include"Read_block.h"

/**
* \version			 \p \a 1.5	**
  \date 			 \p december 2012
* \author			 \p Martine
* \details 			 \p This file contains every functions managing the arrays
*/

int returnPosition(TagArray arrayOfTags, int index);

/**
 * \fn 				\c int returnPosition( \c TagArray \a arrayOfTags, \c int \a index )
 * \brief			Determine the last position in an array
 * \param			\c TagArrays \a arrayOfTags  a block from the list of blocks of a file \B
 * \param			\c int \a index  the index of a tag
 * \version			\p 1.0
 * \date 			\p December
 * 					2012
 * \author			\p Chaymae & Martine
 * \details 		\p This function allows to determine the index of the end of the string
 *					in a block of information for a tag \a index
 */
 
int returnPosition(TagArray arrayOfTags, int index) {
	int position = 0;
	while (arrayOfTags->information[index][position] != '\0') {
		position++;
	}
	return position;
}

/**
 * \fn 				\c char* createAnArrayOfChar( \c char* \a information , \c int \a size )
 * \brief			Create an array for strings
 * \date 			\p November 2012
 * \return			\p \a information  an array of char newly allocate \B
 * \return 			   \a NULL  the allocation failed				
 * \author			\p Chaymae
 * \details 		\p This function allows to create an array of String, 
 *					   and return the new array \a information
 */

char* createAnArrayOfChar(char* information, int size) {
	information = (char*)calloc(size, sizeof(char));
	if (information == NULL) {
		fprintf(stderr, "The allocation of the array of tags has failed!\n");
	}
	return information;
}

/**
 * \fn 				\c void freeArrayOfChar( \c char* \c * \a array )
 * \brief			Free the memory allocated
 * \param			\c char* \a array  an array of char
 * \date 			\p November
 * 					2012
 * \author			\p Me and you
 * \details 		\p Free the memory allocated by a simple array of char
 */

void freeArrayOfChar(char* array) {
	free(array);
	array = NULL;
}


/**
 * \fn 				\c char* \c * allocateDoubleArrayOfChar( \c char* \c * \a array , \c int \a size )
 * \brief			Allocate memory for a bouble array of char
 * \param			\c char* \c * \a array  an array of char
 * \param			\c int \a size  the size of the array
 * \date 			\p December
 * 					2012
 * \author			\p Chaymae & Martine
 * \details 		\p This function allows to create a double \a array of char depending on the \a size
 */

char* * allocateDoubleArrayOfChar(char* * array, int size) {
	array = (char**)calloc(size, sizeof(char*));
	if (array == NULL) {
		fprintf(stderr, "The array cannot be allocate\n");
		return NULL;
	}
	return array;
}

/**
 * \fn 				\c void freeDoubleArrayOfChar( \c char* \c * \a array , \c int \a size )
 * \brief			Free the memory allocated by a double array
 * \param			\c char* \c * \a array  the array to free
 * \param			\c int \a size  the size of the double array
 * \author			\p Chaymae
 * \details 		\p This function allows to free all the memory allocated 
 *					for a double \a array of char
 */

void freeDoubleArrayOfChar(char* * array, int size) {
	int i = 0;
	for (i=0 ; i<size ; i++) {
		free(array[i]);
		array[i] = NULL;
	}
	free(array);
	array = NULL;
}

/**
 * \fn 				\c TagArray allocateNewTagArray( \c TagArray \a arrayOfTags )
 * \brief			Allocate memory for one block
 * \param			\c TagArrays \a arrayOfTags  a block from the list of blocks of a file
 * \version			\p 1.0
 * \author			\p Chaymae & Martine
 * \details 		\p This function allows to allocate memory for one 
 block
 */

TagArray allocateNewTagArray(TagArray arrayOfTags) {
	int size = NB_TAGS+1;
	arrayOfTags = (TagArray)calloc(1, sizeof(tagArray));
	if (arrayOfTags == NULL) {
		fprintf(stderr, "The allocation of the structure tagArray has failed!\n");
	}
	arrayOfTags->information = (char**)calloc(size, sizeof(char*));
	if (arrayOfTags->information == NULL) {
		fprintf(stderr, "The allocation of 'arrayOfTags->information' has failed!\n");
		free(arrayOfTags);
		arrayOfTags = NULL;
	}
	return arrayOfTags;
}

/**
 * \fn 				\c void freeTagArray( \c TagArray \a arrayOfTags )
 * \brief			Free one block
 * \param			\c TagArrays \a arrayOfTags  a block from the list of blocks of a file
 * \version			\p 1.0
 * \date 			\p December
 * 					2012
 * \author			\p Chaymae & Martine
 * \details 		\p Free all the memory allocated for a block
 */

void freeTagArray(TagArray arrayOfTags) {
	int i;
	for (i=0 ; i<NB_TAGS+1 ; i++) {
		free(arrayOfTags->information[i]);
		arrayOfTags->information[i] = NULL;
	}
	free(arrayOfTags->information);
	arrayOfTags->information = NULL;
	free(arrayOfTags);
	arrayOfTags = NULL;
}
