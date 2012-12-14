#ifndef SPECIAL_TAGS_H
#define SPECIAL_TAGS_H

#include"Read_block.h"

enum {Brief=6, DETAILS=4, Author=2, PARAM=7, RETURN=27, Date=25, FN=6, Bug=24, File=15, Version=28};

int recognizeATag(char* information, int index);
int putInItalic(TagArray arrayOfTags, int index, int position);
int endOfItalic(TagArray arrayOfTags, int index, int position);
int putInTypeWriterStyle(TagArray arrayOfTags, int index, int position);
int endOfTypeWriterStyle(TagArray arrayOfTags, int index, int position);
int putInBoldStyle(TagArray arrayOfTags, int index, int position);
int endOfBoldStyle(TagArray arrayOfTags, int index, int position);
int putInParagraphStyle(TagArray arrayOfTags, int index, int position);
int endOfParagraphStyle(TagArray arrayOfTags, int index, int position);
int putALineBreak(TagArray arrayOfTags, int index, int position);

#endif
