#ifndef SPECIAL_TAGS_H
#define SPECIAL_TAGS_H

#include"Read_block.h"

enum {Brief=1, Details=4, Author=0, Param=7, Return=8, Date=3, Fn=6, Bug=2, File=5, Version=9, Struct=10};

int recognizeATag(char* information, int index);
int recognizeSecondaryTag(TagArray arrayOfTags, char* string, int index, int *position, int**i);
int putEndToTag(TagArray arrayOfTags, int tmp, int index, int *position);
void putInItalic(TagArray arrayOfTags, int index, int**position);
void endOfItalic(TagArray arrayOfTags, int index, int**position);
void putInTypeWriterStyle(TagArray arrayOfTags, int index, int**position);
void endOfTypeWriterStyle(TagArray arrayOfTags, int index, int**position);
void putInBoldStyle(TagArray arrayOfTags, int index, int**position);
void endOfBoldStyle(TagArray arrayOfTags, int index, int**position);
void putInParagraphStyle(TagArray arrayOfTags, int index, int**position);
void endOfParagraphStyle(TagArray arrayOfTags, int index, int**position);
void putALineBreak(TagArray arrayOfTags, int index, int**position);

#endif
