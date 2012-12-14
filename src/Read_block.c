#include"Read_block.h"
#include"Special_Tags.h"
#include"Save_blocks.h"

char* createAnArrayOfChar(char* information, int size) {
	information = (char*)calloc(size, sizeof(char));
	if (information == NULL) {
		fprintf(stderr, "The allocation of the array of tags has failed!\n");
	}
	return information;
}

int* initArrayOfInt(int* isEmpty, int size) {
	int i;	size = NB_TAGS+1;
	for(i=0 ; i<size ; i++) {
		isEmpty[i] = 0;
	}
	return isEmpty;
}

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

TagArray stockInformation(TagArray arrayOfTags, char c, int index, int position) {
	int j = 0;
	if (arrayOfTags->information[index] == NULL) {
		arrayOfTags->information[index] = createAnArrayOfChar(arrayOfTags->information[index], 150);
		if (arrayOfTags->information[index] == NULL) {
			while (j < index) {
				free(arrayOfTags->information[j]);
				arrayOfTags->information[j] = NULL;
			}
			free(arrayOfTags->information);
			arrayOfTags->information = NULL;
			free(arrayOfTags);
			arrayOfTags = NULL;
		}
	}
	arrayOfTags->information[index][position] = c;
	return arrayOfTags;
}

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

int displayTagArray(TagArray arrayOfTags) {
	int i;
	FILE* text = NULL;
	text = fopen("display.html", "w");
    if (text == NULL) {
    	return -1;
    }
   	for (i=0 ; i<NB_TAGS+1 ; i++) {
    	fprintf (text, "%s\n", arrayOfTags->information[i]);	
	}
	fclose(text);
	return 0;
}

int readFile(char* fileName) {
	FILE* file = NULL;
 	char string[SIZE];
 	int j, i = 0, position = 0, stringNull = OFF;
 	int isEmpty[NB_TAGS+1];
 	int block = END, index = NB_TAGS, previousStar = 0, textStart = 0, italic = OFF, typeWriterStyle = OFF, getInfo = 0;
 	int boldStyle = OFF, paragraphStyle = OFF, previousIndex = OFF, previousPosition = 0, previousTag = OFF, over = OFF;
 	int c = 0;
 	SaveTagArrays list = NULL;
 	initArrayOfInt(isEmpty, NB_TAGS+1);
 	
    file = fopen(fileName, "r");
 	if (file == NULL) {
    	return -1;
    }
 	while (fgets(string, SIZE, file) != NULL) {
 		i = 0;
 		while (string[i] != '\0') {
 			switch (string[i]) {
 				case '/' :
 					over = OFF;
 					switch (string[i+1]) {
 						case '*' :
 						 	if (string[i+2] == '*') {
 						 		list = addNewCell(list);
 						 		initArrayOfInt(isEmpty, NB_TAGS+1);
 						 		block = START_TYPE_1;
 						 		stringNull = OFF;
 						 	}
 						break;
 						case '/' :
 							if (string[i+2] == '/') {
								block = START_TYPE_2;
 						 		list = addNewCell(list);
								if (string[i+3] == '\n') {
									getInfo = 1;
								}
							}
 						break;
 					}
 				break;
 				case '*' :
 					if (string[i+1] == '\n') {
 						stringNull = ON;
						getInfo = 1;
					}
 					previousStar = 1;
 					previousTag = OFF;
 					if (string[i+1] == '/') {
 						stringNull = OFF;
						block = END;
 					}
 				break;
 				case 92 :
 					stringNull = OFF;
 					if (block == START_TYPE_2) {
 						previousStar = 1;
 					}
 					switch (previousStar) {
 						case OFF :
	 						string[i+1] = '\0';
	 					break;
	 					case ON :
							switch (string[i+1]) {
								case 'a' :
									if (string[i+2] == ' ' || string[i+2] == '\t') {
										if (previousTag == OFF) {
											index = previousIndex;
											position = previousPosition;
											position = putALineBreak(list->arrayOfTags[c], index, position);
										}
										list->arrayOfTags[c] = stockInformation(list->arrayOfTags[c], string[i], index, position);
										position = putInItalic(list->arrayOfTags[c], index, position);
										i += 2;
										italic = ON;
									}
									else {
										previousTag = ON;
										index = recognizeATag(string, i+1);
										while (string[i] != ' ' && string[i] != '\0' && string[i] != '\t') {
											fprintf(stdout, "%c", string[i]);
											i++;
										} 
										if (isEmpty[index] != 0) {
											fprintf(stdout, "%d   %d\n", previousIndex, previousPosition);
											previousTag = OFF;
										}
										fprintf(stdout, "------------> %d\n", index);
									}
								break;
								case 'b' :
									if (string[i+2] == ' ' || string[i+2] == '\t') {
										if (previousTag == OFF) {
											index = previousIndex;
											position = previousPosition;
											position = putALineBreak(list->arrayOfTags[c], index, position);
										}
										list->arrayOfTags[c] = stockInformation(list->arrayOfTags[c], string[i], index, position);
										position = putInBoldStyle(list->arrayOfTags[c], index, position);
										i += 2;
										boldStyle = ON;
									}
									else {
										previousTag = ON;
										index = recognizeATag(string, i+1);
										while (string[i] != ' ' && string[i] != '\0' && string[i] != '\t') {
											fprintf(stdout, "%c", string[i]);
											i++;
										} 
										if (isEmpty[index] != 0) {
											fprintf(stdout, "%d   %d\n", previousIndex, previousPosition);
											previousTag = OFF;
										}
										fprintf(stdout, "------------> %d\n", index);
									}
								break;
								case 'c' :
									if (string[i+2] == ' ' || string[i+2] == '\t') {
										if (previousTag == OFF) {
											index = previousIndex;
											position = previousPosition;
											position = putALineBreak(list->arrayOfTags[c], index, position);
										}
										list->arrayOfTags[c] = stockInformation(list->arrayOfTags[c], string[i], index, position);
										position = putInTypeWriterStyle(list->arrayOfTags[c], index, position);
										i += 2;
										typeWriterStyle = ON;
									}
									else {
										previousTag = ON;
										index = recognizeATag(string, i+1);
										while (string[i] != ' ' && string[i] != '\0' && string[i] != '\t') {
											fprintf(stdout, "%c", string[i]);
											i++;
										}
										if (isEmpty[index] != 0) {
											fprintf(stdout, "%d   %d\n", previousIndex, previousPosition);
											previousTag = OFF;
										} 
										fprintf(stdout, "------------> %d\n", index);
									}
								break;
								case 'e' :
									if (string[i+2] == ' ' || string[i+2] == '\t') {
										if (previousTag == OFF) {
											index = previousIndex;
											position = previousPosition;
											position = putALineBreak(list->arrayOfTags[c], index, position);
										}
										list->arrayOfTags[c] = stockInformation(list->arrayOfTags[c], string[i], index, position);
										position = putInItalic(list->arrayOfTags[c], index, position);
										i += 2;
										italic = ON;
									}
									else {
										previousTag = ON;
										index = recognizeATag(string, i+1);
										while (string[i] != ' ' && string[i] != '\0' && string[i] != '\t') {
											fprintf(stdout, "%c", string[i]);
											i++;
										} 
										if (isEmpty[index] != 0) {
											fprintf(stdout, "%d   %d\n", previousIndex, previousPosition);
											previousTag = OFF;
										}
										fprintf(stdout, "------------> %d\n", index);
									}
								break;
								case 'p' :
									if (string[i+2] == ' ' || string[i+2] == '\t') {
										if (previousTag == OFF) {
											index = previousIndex;
											position = previousPosition;
											position = putALineBreak(list->arrayOfTags[c], index, position);
										}
										list->arrayOfTags[c] = stockInformation(list->arrayOfTags[c], string[i], index, position);
										position = putInParagraphStyle(list->arrayOfTags[c], index, position);
										i += 2;
										paragraphStyle = ON;
									}
									else {
										previousTag = ON;
										index = recognizeATag(string, i+1);
										while (string[i] != ' ' && string[i] != '\0' && string[i] != '\t') {
											fprintf(stdout, "%c", string[i]);
											i++;
										} 
										if (isEmpty[index] != 0) {
											fprintf(stdout, "%d   %d\n", previousIndex, previousPosition);
											previousTag = OFF;
										}
										fprintf(stdout, "------------> %d\n", index);
									}
								break;
								default :
									getInfo = 0;
									previousTag = ON;
									index = recognizeATag(string, i+1);
									if (index == -1)	index = NB_TAGS;
									while (string[i] != ' ' && string[i] != '\0' && string[i] != '\t') {
										fprintf(stdout, "%c", string[i]);
										i++;
									} 
									if (isEmpty[index] != 0) {
										fprintf(stdout, "%d   %d\n", previousIndex, previousPosition);
										previousTag = OFF;
									}
									fprintf(stdout, "(------------>) %d\n", index);
								break;
							}
 						break;
 					}
 				break;
 				case 59 :
 					if (list->arrayOfTags[c]->information[FN] == NULL) {
	 					if (block == END && over == OFF) {
	 						for(j=0 ; j<i ;j++) {
	 							fprintf(stdout, "%c", string[j]);
	 							list->arrayOfTags[c] = stockInformation(list->arrayOfTags[c], string[j], FN, position);
	 							position++;
	 						}
	 						over = ON;
	 						
	 					}
 					}
 				break;
 				case '{' :
 					if (list->arrayOfTags[c]->information[FN] == NULL) {
	 					if (block == END && over == OFF) {
	 						for(j=0 ; j<i ;j++) {
	 							fprintf(stdout, "%c", string[j]);
	 							list->arrayOfTags[c] = stockInformation(list->arrayOfTags[c], string[j], FN, position);
	 							position++;
	 						}
	 						over = ON;
	 					}
 					}
 				break;
 				case '\n' :
 				break;
 				default :
 					if(getInfo == 1)	stringNull = 2;
 					if (block != END && over == OFF) {
 						if (string[i] != ' ' && string[i] != '\t') {
 							textStart = ON;
 						}
 						if (textStart == ON) {
 							switch (string[i]) {
 								case ' ' :
 									if (string[i+1] == ' ' && string[i+2] != '\t' && string[i+2] != ' ') {
 										list->arrayOfTags[c] = stockInformation(list->arrayOfTags[c], ':', index, position);
			 							position++;
 									}
 								break;
 								case '\t' :
 									if (string[i+2] != '\t' && string[i+2] != ' ') {
 										list->arrayOfTags[c] = stockInformation(list->arrayOfTags[c], ':', index, position);
			 							position++;
 									}
 								break;
 							}
 							if (previousTag == OFF) {
 								if (stringNull != 2) {
	 								index = previousIndex;
	 								position = previousPosition;
	 								position = putALineBreak(list->arrayOfTags[c], index, position);
 								}
 								if (stringNull == 2) {
 									index = 4;
 									position = isEmpty[index]; 
 									list->arrayOfTags[c] = stockInformation(list->arrayOfTags[c], ' ', index, position);
 									position++;
 								}
 								if (italic == ON) {
 									position = putInItalic(list->arrayOfTags[c], index, position);
 								}
 								if (boldStyle == ON) {
 									position = putInBoldStyle(list->arrayOfTags[c], index, position);
 								}
 								if (typeWriterStyle == ON) {
 									position = putInTypeWriterStyle(list->arrayOfTags[c], index, position);
 								}
 								if (paragraphStyle == ON) {
 									position = putInParagraphStyle(list->arrayOfTags[c], index, position);
 								}
 								previousTag = ON;
 							}
 							if (italic == ON && string[i] == ' ') {
 								position = endOfItalic(list->arrayOfTags[c], index, position);
					 			italic = OFF;
 							}
 							if (typeWriterStyle == ON && string[i] == ' ') {
 								position = endOfTypeWriterStyle(list->arrayOfTags[c], index, position);
					 			typeWriterStyle = OFF;
 							}
 							if (boldStyle == ON && string[i] == ' ') {
 								position = endOfBoldStyle(list->arrayOfTags[c], index, position);
					 			boldStyle = OFF;
 							}
			 				list->arrayOfTags[c] = stockInformation(list->arrayOfTags[c], string[i], index, position);
 							position++;
 						}
 					}	
 				break;
 			}
			i++;
 		}
 		isEmpty[index] = position;
 		if (block == START_TYPE_2) {
 			previousStar = OFF;
 			block = END;
 			previousTag = OFF;
 		}
 		if (italic == ON) {
 			endOfItalic(list->arrayOfTags[c], index, position);
			italic = OFF;
 		}
 		if (typeWriterStyle == ON) {
 			endOfTypeWriterStyle(list->arrayOfTags[c], index, position);
			typeWriterStyle = OFF;
 		}
 		if (boldStyle == ON) {
 			endOfBoldStyle(list->arrayOfTags[c], index, position);
			boldStyle = OFF;
 		}
 		if (paragraphStyle == ON) {
 			endOfParagraphStyle(list->arrayOfTags[c], index, position);
			paragraphStyle = OFF;
 		}
 		previousIndex = index;
		previousPosition = position;
		position = 0;
 		textStart = OFF;
 		index = NB_TAGS;
 		stringNull = OFF;
 	}
 	displayTheListOfTheSavingTagArray(list);
 	freeSaveTagArray(list);
 	/*freeTagArray(list->arrayOfTags[c]);
 	free(list);
 	list = NULL;*/
 	fclose(file);
 	return 0;
}
