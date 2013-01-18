#ifndef SAVE_BLOCKS_H
#define SAVE_BLOCKS_H

#define NB_FN 10

#include"Read_block.h"

typedef struct {
	TagArray arrayOfTags[NB_FN];
	int size;
}cell, *SaveTagArrays;

SaveTagArrays allocateNewCell(void);
SaveTagArrays addNewCell1(SaveTagArrays listOfTagArray, int index);
void freeSaveTagArray(SaveTagArrays listOfTagArray);

#endif
