#include"Save_blocks.h"

/**
* \version			 \p \a 1.5	**
  \date 			 \p November 2012
* \author			 \p Martine
* \details 			 \p This file contains every functions allowing the manipulation 
*					 of the structure managing the informations in the blocks
*/

SaveTagArrays allocateNewCell(void);

/**
 * \fn				\c SaveTagArrays allocateNewCell(void)
 * \return 			\p the new cell allowing to save information about a block					
 * \brief		    Allocate the memory for a new block of information 
 * \param			void;
 */
 
SaveTagArrays allocateNewCell(void) {
	SaveTagArrays newSaveTagArrays = (SaveTagArrays)calloc(1, sizeof(cell));
	if (newSaveTagArrays == NULL) {
		fprintf(stderr, "The allocation of 'newSaveTagArrays' has failed!\n");
	}
	newSaveTagArrays->size = 0;
	return newSaveTagArrays;
}

/**
 * \fn				\c SaveTagArrays addNewCell1( \c SaveTagArrays \a list , \c int \a index )
 * \return 			\p the new cell allowing to save information about a block \B
 * \return      	NULL  if failure
 * \param 			SaveTagArrays \a list  the list of informations for a file
 * \param			int \a index  the index of the list where will be add the new block					
 * \brief		    add the new cell into the list of blocks 
 */
 
SaveTagArrays addNewCell1(SaveTagArrays list, int index) {
	if (list == NULL) {
		list = allocateNewCell();
		if (list == NULL)
			return NULL;
	}
	if (list->arrayOfTags[index] == NULL) {
		list->size = index;
		list->arrayOfTags[list->size] = allocateNewTagArray(list->arrayOfTags[list->size]);
	}
	return list;
}

/**
 * \fn				\c void freeSaveTagArray( \c SaveTagArrays \a list )
 * \param   		SaveTagArrays \a list  the list of information for a file
 * \brief 			Free the memory allocated for the \a list
 */

void freeSaveTagArray(SaveTagArrays list) {
	int i = 0;
	while (list->arrayOfTags[i] != NULL) {
		freeTagArray(list->arrayOfTags[i]);
		i++;
	}
	free(list);
	list = NULL;
}
