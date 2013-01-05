#include"Save_blocks.h"

int incrementOfOne(int *number) {
	return (*number)++;
}

SaveTagArrays allocateNewCell(void) {
	SaveTagArrays newSaveTagArrays = (SaveTagArrays)calloc(1, sizeof(cell));
	if (newSaveTagArrays == NULL) {
		fprintf(stderr, "The allocation of 'newSaveTagArrays' has failed!\n");
	}
	newSaveTagArrays->size = 0;
	return newSaveTagArrays;
}

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

SaveTagArrays addNewCell(SaveTagArrays list, int *index) {
	if (list == NULL) {
		list = allocateNewCell();
		if (list == NULL)
			return NULL;
	}
	if (list->arrayOfTags[*index+1] == NULL) {
		(*index)++;
		list->size = *index;
		list->arrayOfTags[list->size] = allocateNewTagArray(list->arrayOfTags[list->size]);
	}
	return list;
}

int displayTheListOfTheSavingTagArray(SaveTagArrays list) {
	int i=0, j=0;
	FILE* text = NULL;
	SaveTagArrays tmp = NULL;
	text = fopen("display.html", "w");
    if (text == NULL) {
    	return -1;
    }
    tmp = list;
    while(tmp->arrayOfTags[j] != NULL) {
	   	for (i=0 ; i<NB_TAGS+1 ; i++) {
			fprintf (text, "%s\n", list->arrayOfTags[j]->information[i]);	
		}
		j++;
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
