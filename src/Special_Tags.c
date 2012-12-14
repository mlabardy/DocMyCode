#include"Special_Tags.h"

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
		case 'v' :
			if (information[index+1] == 'e') {
				return 9;
			}
		break;
	}
	return -1;
}

int putInItalic(TagArray arrayOfTags, int index, int position) {
	arrayOfTags->information[index][position] = 60;
	position++;
	arrayOfTags->information[index][position] = 105;
	position++;
	arrayOfTags->information[index][position] = 62;
	position++;
	return position;
}

int endOfItalic(TagArray arrayOfTags, int index, int position) {
	arrayOfTags->information[index][position] = 60;
	position++;
	arrayOfTags->information[index][position] = 47;
	position++;
	arrayOfTags->information[index][position] = 105;
	position++;
	arrayOfTags->information[index][position] = 62;
	position++;
	return position;
}

int putInTypeWriterStyle(TagArray arrayOfTags, int index, int position) {
	arrayOfTags->information[index][position] = 60;
	position++;
	arrayOfTags->information[index][position] = 116;
	position++;
	arrayOfTags->information[index][position] = 116;
	position++;
	arrayOfTags->information[index][position] = 62;
	position++;
	return position;
}

int endOfTypeWriterStyle(TagArray arrayOfTags, int index, int position) {
	arrayOfTags->information[index][position] = 60;
	position++;
	arrayOfTags->information[index][position] = 47;
	position++;
	arrayOfTags->information[index][position] = 116;
	position++;
	arrayOfTags->information[index][position] = 116;
	position++;
	arrayOfTags->information[index][position] = 62;
	position++;
	return position;
}

int putInBoldStyle(TagArray arrayOfTags, int index, int position) {
	arrayOfTags->information[index][position] = 60;
	position++;
	arrayOfTags->information[index][position] = 98;
	position++;
	arrayOfTags->information[index][position] = 62;
	position++;
	return position;
}

int endOfBoldStyle(TagArray arrayOfTags, int index, int position) {
	arrayOfTags->information[index][position] = 60;
	position++;
	arrayOfTags->information[index][position] = 47;
	position++;
	arrayOfTags->information[index][position] = 98;
	position++;
	arrayOfTags->information[index][position] = 62;
	position++;
	return position;
}

int putInParagraphStyle(TagArray arrayOfTags, int index, int position) {
	arrayOfTags->information[index][position] = 60;
	position++;
	arrayOfTags->information[index][position] = 112;
	position++;
	arrayOfTags->information[index][position] = 62;
	position++;
	return position;
}

int endOfParagraphStyle(TagArray arrayOfTags, int index, int position) {
	arrayOfTags->information[index][position] = 60;
	position++;
	arrayOfTags->information[index][position] = 47;
	position++;
	arrayOfTags->information[index][position] = 112;
	position++;
	arrayOfTags->information[index][position] = 62;
	position++;
	return position;
}

int putALineBreak(TagArray arrayOfTags, int index, int position) {
	arrayOfTags->information[index][position] = 60;
	position++;
	arrayOfTags->information[index][position] = 'b';
	position++;
	arrayOfTags->information[index][position] = 'r';
	position++;
	arrayOfTags->information[index][position] = 62;
	position++;
	return position;
}

