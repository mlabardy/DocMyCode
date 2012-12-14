#include"Save_blocks.h"

SaveTagArrays allocateNewCell(void) {
	SaveTagArrays newSaveTagArrays = (SaveTagArrays)calloc(1, sizeof(cell));
	if (newSaveTagArrays == NULL) {
		fprintf(stderr, "The allocation of 'newSaveTagArrays' has failed!\n");
	}
	newSaveTagArrays->size = 0;
	return newSaveTagArrays;
}

SaveTagArrays addNewCell(SaveTagArrays list) {
	if (list == NULL) {
		list = allocateNewCell();
		if (list == NULL) 	
			return NULL;
	}
	list->size = 1 + list->size;
	list->arrayOfTags[list->size-1] = allocateNewTagArray(list->arrayOfTags[list->size-1]);
	return list;
}

int displayTheListOfTheSavingTagArray(SaveTagArrays list) {
	int i=0, j=0;
	FILE* text = NULL;
	text = fopen("display.html", "w");
    if (text == NULL) {
    	return -1;
    }
	   	for (i=0 ; i<NB_TAGS+1 ; i++) {
			fprintf (text, "%s\n", list->arrayOfTags[0]->information[i]);	
		}


	fclose(text);
	return 0;
}

void freeSaveTagArray(SaveTagArrays list) {
	int i = 0;
	while (list->arrayOfTags[i] != NULL) {
		freeTagArray(list->arrayOfTags[i]);
		i++;
	}
	free(list);
	list = NULL;
}
