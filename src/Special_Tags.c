#include"Special_Tags.h"



int recognizeATag(char* information, int index);

/**
 * \fn				\c int recognizeATag( \c char* \a information , \c int \a index )
 * \brief			Recognize a tag
 * \param   		\c char* \a information  an information about a tag
 * \return 			\p the 0-10  if a tag has been identified \B
 * \return			\p 0  if the tag has not been identified
 * \details			This fonction compare a character with the tags in the switch and return its value
 *					if the result is -1, the character is not a tag
 */
 
int recognizeATag(char* information, int index) {
	switch (information[index]) {
		case 'a' :
			if (information[index+1] == 'u') {
				return 0;
			}
		break;
		case 'b' :
			switch (information[index+1]) {
				case 'r' :
				return 1;
				case 'u' :
				return 2;
			}
		break;
		case 'd' :
			switch (information[index+1]) {
				case 'a' :
				return 3;
				case 'e' :
				return 4;
			}
		break;
		case 'f' :
			switch (information[index+1]) {
				case 'i' :
				return 5;
				case 'n' :
				return 6;
			}
		break;
		case 'p' :
			if (information[index+1] == 'a') {
				return 7;
			}
		break;
		case 'r' :
			if (information[index+1] == 'e') {
				return 8;
			}
		break;
		case 's' :
			if (information[index+1] == 't') {
				return 10;
			}
		break;
		case 'v' :
			if (information[index+1] == 'e') {
				return 9;
			}
		break;
	}
	return -1;
}

/**
 * \fn				\c int recognizeSecondaryTag(TagArray arrayOfTags , char* string , int index , int* position , int* * i )
 * \brief			Recognize a secondary tag
 * \param   		\c TagArray \a arrayOfTags \B
 * \param   		char* \a string \B
 * \param   		int \a index \B
 * \param   		int \a position \B
 * \param   		int* * \a i \B
 * \return 			\p the 0-3  if a tag has been identified \B
 * \return			\p -1  if the tag has not been identified
 * \details			This fonction compare a character with the tags in the switch and return its value
 *					if the result is -1, the character is not a tag
 */

int recognizeSecondaryTag(TagArray arrayOfTags, char* string, int index, int *position, int**i) {
	switch (string[**i]) {
		case 'a' :
			putInItalic(arrayOfTags, index, &position);
			(**i)++;
		return 0;
		case 'b' :
			putInBoldStyle(arrayOfTags, index, &position);
			(**i)++;
		return 1;
		case 'c' :
			putInTypeWriterStyle(arrayOfTags, index, &position);
			(**i)++;
		return 2;
		case 'p' :
			putInParagraphStyle(arrayOfTags, index, &position);
			(**i)++;
		return 3;
		case 'B' :
			putALineBreak(arrayOfTags, index, &position);
			(**i)++;
		return -1;
	}
	return -1;
}

/**
 * \fn				\c int putEndToTag( \c TagArray arrayOfTags , int \a tmp , int \a index , int* \a position )
 * \brief			Close a tag
 * \param   		\c TagArray \a arrayOfTags \B
 * \param   		\c int \a tmp \B
 * \param   		\c int \a index \B
 * \param   		\c int* \a position 
 * \return 			\p the 0-2  if a tag has been identified \B
 * \return			\p -1  if there is not a previous tag
 * \details			Close a tag 
 */

int putEndToTag(TagArray arrayOfTags, int tmp, int index, int *position) {
	switch (tmp) {
		case 0 :
			endOfItalic(arrayOfTags, index, &position);
		break;
		case 1 :
			endOfBoldStyle(arrayOfTags, index, &position);
		break;
		case 2 :
			endOfTypeWriterStyle(arrayOfTags, index, &position);
		break;
	}
	return -1;
}

/**
 * \fn				\c void putInItalic( \c TagArray \a arrayOfTags , \c int \a index, \c int* \c * \a position )
 * \brief			Put a word une italic
 * \param   		\c TagArray \a arrayOfTags  a block \B
 * \param   		\c int \a index \B
 * \param   		\c int* \c * \a position 
 * \details			\p Put a word une italic
 */

void putInItalic(TagArray arrayOfTags, int index, int**position) {
	arrayOfTags->information[index][**position] = 60;
	(**position)++;
	arrayOfTags->information[index][**position] = 105;
	(**position)++;
	arrayOfTags->information[index][**position] = 62;
	(**position)++;
}

 /**
 * \fn				\c void endOfItalic( \c TagArray \a arrayOfTags , \c int \a index, \c int* \c * \a position )
 * \brief			Close the tag italic to put a word une italic
 * \param   		\c TagArray \a arrayOfTags  a block \B
 * \param   		\c int \a index \B
 * \param   		\c int* \c * \a position 
 * \details			\p Put a word une italic
 */

void endOfItalic(TagArray arrayOfTags, int index, int**position) {
	arrayOfTags->information[index][**position] = 60;
	(**position)++;
	arrayOfTags->information[index][**position] = 47;
	(**position)++;
	arrayOfTags->information[index][**position] = 105;
	(**position)++;
	arrayOfTags->information[index][**position] = 62;
	(**position)++;
}


 /**
 * \fn				\c void putInTypeWriterStyle( \c TagArray \a arrayOfTags , \c int \a index, \c int* \c * \a position )
 * \brief			Put a word in type writer style
 * \param   		\c TagArray \a arrayOfTags  a block \B
 * \param   		\c int \a index \B
 * \param   		\c int* \c * \a position 
 * \details			\p Put a word in type writer style
 */


void putInTypeWriterStyle(TagArray arrayOfTags, int index, int**position) {
	arrayOfTags->information[index][**position] = 60;
	(**position)++;
	arrayOfTags->information[index][**position] = 116;
	(**position)++;
	arrayOfTags->information[index][**position] = 116;
	(**position)++;
	arrayOfTags->information[index][**position] = 62;
	(**position)++;
}

/**
 * \fn				\c void endOfTypeWriterStyle( \c TagArray \a arrayOfTags , \c int \a index, \c int* \c * \a position )
 * \brief			Close the tag type writer style to put a word in type writer style
 * \param   		\c TagArray \a arrayOfTags  a block \B
 * \param   		\c int \a index \B
 * \param   		\c int* \c * \a position 
 * \details			\p Put a word in type writer style
 */

void endOfTypeWriterStyle(TagArray arrayOfTags, int index, int**position) {
	arrayOfTags->information[index][**position] = 60;
	(**position)++;
	arrayOfTags->information[index][**position] = 47;
	(**position)++;
	arrayOfTags->information[index][**position] = 116;
	(**position)++;
	arrayOfTags->information[index][**position] = 116;
	(**position)++;
	arrayOfTags->information[index][**position] = 62;
	(**position)++;
}

/**
 * \fn				\c void putInBoldStyle( \c TagArray \a arrayOfTags , \c int \a index, \c int* \c * \a position )
 * \brief			Put a word in bold style
 * \param   		\c TagArray \a arrayOfTags  a block \B
 * \param   		\c int \a index \B
 * \param   		\c int* \c * \a position 
 * \details			\p Put a word in bold style
 */

void putInBoldStyle(TagArray arrayOfTags, int index, int**position) {
	arrayOfTags->information[index][**position] = 60;
	(**position)++;
	arrayOfTags->information[index][**position] = 98;
	(**position)++;
	arrayOfTags->information[index][**position] = 62;
	(**position)++;
}

/**
 * \fn				\c void endOfBoldStyle( \c TagArray \a arrayOfTags , \c int \a index, \c int* \c * \a position )
 * \brief			Close the tag bold to put a word in bold
 * \param   		\c TagArray \a arrayOfTags  a block \B
 * \param   		\c int \a index \B
 * \param   		\c int* \c * \a position 
 * \details			\p Put a word in bold
 */

void endOfBoldStyle(TagArray arrayOfTags, int index, int**position) {
	arrayOfTags->information[index][**position] = 60;
	(**position)++;
	arrayOfTags->information[index][**position] = 47;
	(**position)++;
	arrayOfTags->information[index][**position] = 98;
	(**position)++;
	arrayOfTags->information[index][**position] = 62;
	(**position)++;
}




void putInParagraphStyle(TagArray arrayOfTags, int index, int**position) {
	arrayOfTags->information[index][**position] = 60;
	(**position)++;
	arrayOfTags->information[index][**position] = 112;
	(**position)++;
	arrayOfTags->information[index][**position] = 62;
	(**position)++;
}




void endOfParagraphStyle(TagArray arrayOfTags, int index, int**position) {
	arrayOfTags->information[index][**position] = 60;
	(**position)++;
	arrayOfTags->information[index][**position] = 47;
	(**position)++;
	arrayOfTags->information[index][**position] = 112;
	(**position)++;
	arrayOfTags->information[index][**position] = 62;
	(**position)++;
}


void putALineBreak(TagArray arrayOfTags, int index, int**position) {
	arrayOfTags->information[index][**position] = 60;
	(**position)++;
	arrayOfTags->information[index][**position] = 'b';
	(**position)++;
	arrayOfTags->information[index][**position] = 'r';
	(**position)++;
	arrayOfTags->information[index][**position] = 62;
	(**position)++;
}
