#include"Save_One_File.h"



/**
 * \fn				\c SaveTagArrays readFile( \c char* \a fileName )
 * \brief			Read a file 
 * \param   		\c char* \a fileName
 * \return 			\p The new list 
 * \details			\p Read a file, save all blocks in a list and return it
 */
 
SaveTagArrays readFile(char* fileName) {
	FILE* file = NULL;
 	char string[SIZE];
 	int i = 0, position = 0, c = 0;
 	int block = -1, index = -1, previousStar = 0, previousIndex = OFF, switcher_1 = OFF;
 	int switcher_2 = OFF, over = ON;
 	SaveTagArrays list = NULL;
    file = fopen(fileName, "r");
 	if (file == NULL) {
    	return NULL;
    }
 	while (fgets(string, SIZE, file) != NULL) {
 		i = 0;
 		while (string[i] != '\0') {
 			switch (string[i]) {
 				case '/' :
 					switch (string[i+1]) {
 						case '*' :
 						 	if (string[i+2] == '*') {
 						 		list = addNewCell1(list, c);
 						 		block = START_TYPE_1;
 						 		over = OFF;
 						 		i += 2;
 						 	}
 						break;
 						case '/' :
 							if (string[i+2] == '/') {
 								list = addNewCell1(list, c);
								block = START_TYPE_2;
								previousStar = ON;
								switcher_1 = ON;
								if (verifyTheNextType(string, &i) == 2) {
									index = previousIndex;
								}
							}
 						break;
 						case '\0' :
 						break;
 					}
 				break;
 				case 39 :
 					i += 3;
 				break;
 				case ';' :
	 				if (block == END && switcher_2 == OFF) {
						index = Fn;
						switcher_2 = ON;i++;
						c++;
					}
 				break;
 				case '*' :
 				if (over != ON) {
 					if (string[i+1] == '/') {
 						switcher_2 = OFF;
 						block = END;
 						over = ON;
 						index = -1;
 					}
 					if (verifyTheNextType(string, &i) == 2) {
						index = previousIndex;
						block = START_TYPE_2;
					}
					switcher_1 = ON;
					previousStar = ON;
				}
 				break;
 				case '#' :
 				break;
 				case 92 :switcher_2 = OFF;
 					if (string[i+1] == 'n') {
 						while (string[i] != ';') {
 							i++;
 						}switcher_2 = ON;
 						break;
 					}
 					switch (previousStar == ON && switcher_1 == ON) {
	 					case ON :
	 						i++;
							index = recognizeATag(string, i);
							if (index == -1) {
								i--;
								if (verifyTheNextType(string, &i) == 1) {
									index = previousIndex;
									if (index == Details) {
										i-=2;
									}
									else {
										i++;
									}
								}
								if (index == -1) {
									index = Details;
									stockInformation(list->arrayOfTags[c], string, &i, index, position, previousStar);
								}
							}
							if (index != -1) {
								while (string[i] != ' ' && string[i] != '\t' && string[i] != '\0') {
									i++;
								}
								while (string[i] == ' ' || string[i]  == '\t') {
									i++;
								}
							}
							if (string[i]  == 92) {
								stockInformation(list->arrayOfTags[c], string, &i, index, position, previousStar);
							}
							else 
								i--;
 						break;
 					}
 				break;
 				default :
 					if (index > -1) {
 						previousStar = OFF;
	 					switcher_1 = stockInformation(list->arrayOfTags[c], string, &i, index, position, previousStar);
 					}
 					else if (index == -1 && block == START_TYPE_2) {
 						switcher_2 = OFF;
 						previousStar = OFF;
	 					switcher_1 = stockInformation(list->arrayOfTags[c], string, &i, Details, position, previousStar);
 					}
 				break;
 			}
 			i++;
 		}
 		if (block == START_TYPE_2) {
 			block = END;
 			switcher_1 = OFF;
 			previousStar = OFF;
 		}
 		previousIndex = index;
 		index = -1;
 		previousStar = 1;
 	}
    fclose(file);
 	return list;
}

/**
 * \fn				\c int verifyTheNextType( \c char* \a string, \c int* \a i )
 * \brief			Locate the beginning of the block 
 * \param   		\c char* \a fileName
 * \return 			\p The list 
 * \details			\p Read a file, save all blocks in a list and return it
 */

int verifyTheNextType(char* string, int* i) {
	while (string[* i] != '\0') {
		switch (string[* i]) {
			case 92 :
				(* i)--;
			return 1;
			case ' ' :
				(*i)++;
			break;
			case '/' :
				(* i)++;
			break;
			case '\t' :
				(* i)++;
			break;
			case '\n' :
				return 0;
			case '*' :
				(* i)++;
			break;
			default :
				(* i)--;
			return 2;
		}
	}
	(* i)--;
	return 0;
}

/**
 * \fn				\c int compareStrings( \c char* \a string_1 , \c char* \a string_2 )
 * \brief			Compare two strings 
 * \param   		\c char* \a string_1  string 1\B
 * \param   		\c char* \a string_2  string 2
 * \return 			\p 1  if the strings are similiar \B 
 * \return 			0  if the strings are differents 
 * \details			\p Compare two strings and return 1  if they are similiar \B
 *					and 0  if they are not 
 */

int compareStrings(char* string_1, char* string_2) {
	int i = 0, count = 1;
	int size_1 = strlen(string_1) + 1;
	int size_2 = strlen(string_2) + 1;
	if (size_1 <= size_2) {
		while (string_1[i] != '\0') {
			if (string_1[i] == string_2[i]) {
				count++;
			}
			i++;
		}
		if (count == size_1) {
			return 1;
		}
	}
	else {
		while (string_2[i] != '\0') {
			if (string_1[i] == string_2[i]) {
				count++;
			}
			i++;
		}
		if (count == size_2) {
			return 1;
		}
	}
	return 0;
}

/**
 * \fn				\c int stockInformation(TagArray arrayOfTags , char* string , int* i, int index, int position ,  int previousStar)
 * \brief			Stock informations in one block
 * \param   		TagArray arrayOfTags \B
 * \param   		char* string  a string \B
 * \param			int* i \B
 * \param			int position  the last character in the string \B
 * \param			int previousStar 
 * \return 			\p -1  in case of failure \B
 * \return 			ON -> 1  if the end of \a string is achieved \B
 * \return 			OFF ->0  to stop the lecture of the \a string
 * \details			\p Stock informations in a block according the string 
 */

int stockInformation(TagArray arrayOfTags, char* string, int* i, int index, int position, int previousStar) {
	int j = 0, tmp = -1, nbSpace = 0;
	position = 0;
	if (arrayOfTags->information[index] != NULL) {
		if (index == 6) {
			return OFF;
		}
		position = returnPosition(arrayOfTags, index);
	}  
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
			return -1;
		}
	}
	while (string[* i] != '\0') {
		if ((string[* i] == '*') && (string[(*i)+1] != ' ')) {
			(* i)--;
			return ON;
		}
		if (string[* i] == ';') {
			return OFF;
		}
		if ((index == 7 || index == 8) && nbSpace == 0) {
			if ((string[* i] == ' ' && string[(*i)+1] == ' ') || string[* i] == '\t')
				nbSpace = 2;
		}
		if (string[* i] == 92) {
			(* i)++;
			tmp = recognizeSecondaryTag(arrayOfTags, string, index, &position, &i);
		}
		else {
			if (tmp != -1 && (string[* i] == ' ' || string[* i] == '\t'))	tmp = putEndToTag(arrayOfTags, tmp, index, &position);
			if (nbSpace == 2) {
				arrayOfTags->information[index][position] = ' '; position++;
				arrayOfTags->information[index][position] = ':'; position++;
				nbSpace = -1;
			}
			arrayOfTags->information[index][position] = string[* i];
			position++;
		}
		(*i)++;
	}
	if (tmp != -1) {
		tmp = putEndToTag(arrayOfTags, tmp, index, &position);
	}
	(*i)--;
	return OFF;
}
