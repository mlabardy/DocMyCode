#include"Write_One_Doc.h"


/**
* \version			 \p \a 2	**
  \date 			 \p January 2012
* \author			 \p Martine
* \details 			 \p This file contains every functions to write in html file
*/
char* renameAFileToHeader(char* source, char* destination);
/**
 * \fn 			\c char* renameAFileToHeader( \c char* \a source , \c char* \a destination )
 * \file 		Write_One_Doc.c
 * \param		\c char* \a source  the name of the file to convert \B \c char* \a destination	the name of the new header
 * \author		\p Chaymae & Martine
 * \version		\p 1.5
 * \date		\p December 2012
 * \brief 		\p Rename a C file into a Header file
 */

char* renameAFileToHeader(char* source, char* destination) {
	int sizeS = strlen(source) + 1;
	int i = 0;
	destination = createAnArrayOfChar(destination, sizeS);
	if (destination != NULL) {
		while (source[i] != '.') {
			destination[i] = source[i];
			i++;
		}
	}
	destination[i] = '.';
	destination[i+1] = 'h';
	return destination;
}

/**
 * \fn 			\c char* renameAFileToHtml(\c char* \a source , \c char* \a destination)
 * \file 		Write_One_Doc.c
 * \param		\c char* \a source  the name of the file to convert \B \c char* \a destination	the name of the new html
 * \author		\p Chaymae & Martine
 * \version		\p 1.5
 * \date		\p December 2012
 * \brief 		\p Rename a C file into a HTML file
 * \return 		\p The name of the new html file
 */

char* renameAFileToHtml(char* source, char* destination) {
	int sizeS = strlen(source);
	int sizeD = sizeS + 4;
	int i = 0;
	destination = createAnArrayOfChar(destination, sizeD);
	if (destination != NULL) {
		while (source[i] != '.') {
			destination[i] = source[i];
			i++;
		}
	}
	destination[i] = '.';
	destination[i+1] = 'h';
	destination[i+2] = 't';
	destination[i+3] = 'm';
	destination[i+4] = 'l';
	return destination;
}

/**
 * \fn 			\c void startToWriteMenu( \c FILE* \a file)
 * \author		\p Chaymae & Martine
 * \param		\c FILE* \a file  the file where will be write the tags for the html
 * \version		\p 1.1
 * \brief 		\p Write a part of the menu for the html
 * \details		\p This function write the first tag to write a menu
 */

void startToWriteMenu(FILE* file) {
	fputs("\t\t<nav>\n", file);
	fputs("\t\t\t<ul id=\"menuDeroulant\">\n", file);   	
	fputs("\t\t\t\t<li>\n\t\t\t\t\t<a href=\"#\" class=\"type3\">Home</a>\n\t\t\t\t</li>\n", file);
}

/**
 * \fn 			\c void stopToWriteMenu( \c FILE* \a file )
 * \author		\p Chaymae & Martine
 * \param		\c FILE* \a file  the file where will be write the tags for the html
 * \version		\p 1.1
 * \brief 		\p Write a part of the menu for the html
 * \details		\p This function write the last tags of the menu
 */

void stopToWriteMenu(FILE* file) {
	fputs("\t\t\t\t</li>\n\t\t\t</ul>\n", file);
	fputs("\t\t\t<hr/>\n", file);
	fputs("\t\t\t<p>This documentation was realized for the project \"Doc My Code\" in C and HTML language</p>\n", file);
   	fputs("\t\t\t<hr/>\n", file);
   	fputs("\t\t\t\t<a href=\"http://www.univ-mlv.fr/\"><img width=\"102%\" height=\"50%\"  src=\"../WWW/Picture/logo-umlv.jpg\" alt=\"Universit&eacute; Paris-Est Marne-la-Vall&eacute;e\"></a>\n", file);
   	
   	fputs("\t\t</nav>\n", file);
}

/**
 * \fn 			\c int startListOfFunctionsPart( \c SaveTagArrays \a list , \c FILE* \a file, \c char* \a sourceName)
 * \author		\p Chaymae & Martine
 * \param		\c FILE* \a file  the file where will be write the tags for the html
 * \param		\c char* \a souceName  the name of the file
 * \param		\c SaveTagArrays \a list  the \a list of tags of the file \a sourceName 
 * \version		\p 1.1
 * \brief 		\p Write the first tags to write the list of functions
 * \details		\p This function write the first tags of the list of tags per file
 * \return 		\p the \a index
 */

int startListOfFunctionsPart(SaveTagArrays list, FILE* file, char* sourceName) {
	int index = 0;
	SaveTagArrays tmp = NULL;
	tmp = list;
	while (tmp->arrayOfTags[index] != NULL) {
		if (list->arrayOfTags[index]->information[File] != NULL && list->arrayOfTags[index]->information[Fn] != NULL) {
		   	if (compareStrings(list->arrayOfTags[index]->information[File], sourceName) == 1) {
				fputs("\t\t\t\t<h1>List of functions</h1>\n", file);
				return index;
			}
		}
		else if (list->arrayOfTags[index]->information[File] == NULL && list->arrayOfTags[index]->information[Fn] != NULL) {
			fputs("\t\t\t\t<h1>List of functions</h1>\n", file);
			return index;
		}
		index++;
	}
	return 0;
}

/**
 * \fn 			\c void endListOfFunctionsPart( \c FILE* \a file )
 * \author		\p Chaymae & Martine
 * \param		\c FILE* \a file  the file where will be write the tags for the html
 * \brief 		\p Write the last tag of the list of function
 * \details		\p This function write the first tags of the list of tags per file
 */

void endListOfFunctionsPart(FILE* file) {
	fputs("\t\t\t\t<hr/>\n", file);
}

/**
 * \fn 			\c void writeListOfFunctions( \c SaveTagArrays \a list , \c FILE* \a file, \c int \a index , \c char* \a sourceName , char* * saveFunctions, \c int* \a i )
 * \author		\p Chaymae & Martine
 * \param		\c FILE* \a file  the file where will be write the tags for the html
 * \param		\c char* \a souceName  the name of the file
 * \param		\c SaveTagArrays \a list  the \a list of tags of the file \a sourceName 
 * \param		\c int \a index  the index of the block where 
 * \param		\c int* \a i  the index int the array \a saveFunctions
 * \param		\c char* \c * \a saveFunctions  array where are stock all functions in the current file
 * \version		\p 2.0
 * \brief 		\p Write the list of functions per file
 * \details		\p This function write the list of functions, brief of the blocks and store its in an array (\a saveFunctions )
 */

void writeListOfFunctions(SaveTagArrays list, FILE* file, int index, char* sourceName, char* * saveFunctions, int* i) {
	char j = 97;
	while (list->arrayOfTags[index] != NULL) {
	   	if (list->arrayOfTags[index]->information[File] != NULL) {
		   	if (compareStrings(list->arrayOfTags[index]->information[File], sourceName) == 1) {
		   		if (list->arrayOfTags[index]->information[Fn] != NULL) {
				   	fputs("\t\t\t\t\t<table>\n", file);
				   	fputs("\t\t\t\t\t\t<tr>\n", file);
				   	fprintf(file, "\t\t\t\t\t\t\t<td><strong><a href=\"#%c\">%s</a></strong></td>\n", j, list->arrayOfTags[index]->information[Fn]);
				   	j++;
				   	
				   	if (list->arrayOfTags[index]->information[Brief] != NULL) {
				   		fprintf(file, "\t\t\t\t\t\t\t<td>%s</td>\n", list->arrayOfTags[index]->information[Brief]);
				   	}
				   	fputs("\t\t\t\t\t\t</tr>\n", file);
				   	fputs("\t\t\t\t\t</table>\n", file);
			   	}
			}
		}
		else if (list->arrayOfTags[index]->information[File] == NULL) {
			fputs("\t\t\t\t\t<table>\n", file);
		   	fputs("\t\t\t\t\t\t<tr>\n", file);
		   	fprintf(file, "\t\t\t\t\t\t\t<td><strong><a href=\"#%c\">%s</a></strong></td>\n", j, list->arrayOfTags[index]->information[Fn]);
		   	
		   	j++;
		   		
		   	if (list->arrayOfTags[index]->information[Brief] != NULL) {
		   		fprintf(file, "\t\t\t\t\t\t\t<td>%s</td>\n", list->arrayOfTags[index]->information[Brief]);
		   	}
		   	fputs("\t\t\t\t\t\t</tr>\n", file);
		   	fputs("\t\t\t\t\t</table>\n", file);
		}
		index++;
	}
}

/**
 * \fn 			\c void startDescriptionOfFunctionsPart( \c SaveTagArrays \a list , \c FILE* \a file, \c char* \a sourceName)
 * \author		\p Chaymae & Martine
 * \param		\c FILE* \a file  the file where will be write the tags for the html
 * \param		\c char* \a souceName  the name of the file
 * \param		\c SaveTagArrays \a list  the \a list of tags of the file \a sourceName 
 * \version		\p 1.0
 * \brief 		\p Write the first tags to write the detailed description of functions
 */

void startDescriptionOfFunctionsPart(SaveTagArrays list, FILE* file, char* sourceName) {
	fputs("\t\t\t\t<hr/>\n", file);
	fputs("\t\t\t\t<h1>Functions</h1>\n", file);
}

/**
 * \fn 			\c void startDescriptionOfFunctionsPart( \c SaveTagArrays \a list , \c FILE* \a file, \c char* \a sourceName)
 * \author		\p Chaymae & Martine
 * \param		\c FILE* \a file  the file where will be write the tags for the html
 * \param		\c char* \a souceName  the name of the file
 * \param		\c SaveTagArrays \a list  the \a list of tags of the file \a sourceName 
 * \version		\p 1.0
 * \brief 		\p Write informations about functions
 * \details		\p This function write every informations about functions per file
 */

void writeDescriptionOfFunctions(SaveTagArrays list, FILE* file, char* sourceName) {
	int index = 0;
	char j = 97;
	while(list->arrayOfTags[index] != NULL) {
		if (list->arrayOfTags[index]->information[File] != NULL) {
			if (compareStrings(list->arrayOfTags[index]->information[File], sourceName) == 1) {
			   	if (list->arrayOfTags[index]->information[Fn] != NULL && list->arrayOfTags[index]->information[Struct] == NULL) {
			   		fputs("\t\t\t\t<table class=\"tableau\">\n", file);
			   		fputs("\t\t\t\t\t<tr>\n\t\t\t\t\t\t<th>\n", file);
			   		fprintf(file, "\t\t\t\t\t\t<strong><a name=\"%c\">%s</a></strong>\n", j, list->arrayOfTags[index]->information[Fn]);
			   		j++;
					
				   	fputs("\t\t\t\t\t\t</th>\n\t\t\t\t\t</tr>\n", file);
				   	fputs("\t\t\t\t\t<tr>\n\t\t\t\t\t\t<td>\n", file);
				   	if (list->arrayOfTags[index]->information[Details] != NULL) {
					   	fprintf(file, "\t\t\t\t\t\t\t%s\n", list->arrayOfTags[index]->information[Details]);
					}
				   	if (list->arrayOfTags[index]->information[Param] != NULL) {
				   		fputs("\t\t\t\t\t\t\t<h2>Parameters</h2>\n", file);
				   		fprintf(file, "\t\t\t\t\t\t\t<p>%s<br>\n", list->arrayOfTags[index]->information[Param]);
				   	}
				   	if (list->arrayOfTags[index]->information[Return] != NULL) {
				   		fputs("\t\t\t\t\t\t\t<h2>Return</h2>\n", file);
				   		fprintf(file, "\t\t\t\t\t\t\t<p>%s<br>\n", list->arrayOfTags[index]->information[Return]);
				   	}
				   	if (list->arrayOfTags[index]->information[Author] != NULL) {
					   	fputs("\t\t\t\t\t\t\t<h2>Authors</h2>\n", file);
					   	fprintf(file, "\t\t\t\t\t\t\t<p>%s<br>\n", list->arrayOfTags[index]->information[Author]);
				   	}
				   	if (list->arrayOfTags[index]->information[Date] != NULL) {
					   	fputs("\t\t\t\t\t\t\t<h2>Date</h2>\n", file);
					   	fprintf(file, "\t\t\t\t\t\t\t<p>%s<br>\n", list->arrayOfTags[index]->information[Date]);
				   	}
				   	if (list->arrayOfTags[index]->information[Version] != NULL) {
					   	fputs("\t\t\t\t\t\t\t<h2>Version</h2>\n", file);
					   	fprintf(file, "\t\t\t\t\t\t\t<p>%s<br>\n", list->arrayOfTags[index]->information[Version]);
				   	}
				   	fputs("\t\t\t\t\t\t</td>\n\t\t\t\t\t</tr>\n", file);
				   	fputs("\t\t\t\t</table>\n", file);
				   	fputs("\t\t\t\t<br>\n", file);
				}
			}
		}
		else if (list->arrayOfTags[index]->information[File] == NULL) {
		   	if (list->arrayOfTags[index]->information[Fn] != NULL && list->arrayOfTags[index]->information[Struct] == NULL) {
		   		fputs("\t\t\t\t<table class=\"tableau\">\n", file);
		   		fputs("\t\t\t\t\t<tr>\n\t\t\t\t\t\t<th>\n", file);
		   		fprintf(file, "\t\t\t\t\t\t<strong><a name=\"%c\">%s</a></strong>\n", j, list->arrayOfTags[index]->information[Fn]);
		   		j++;
			   	fputs("\t\t\t\t\t\t</th>\n\t\t\t\t\t</tr>\n", file);
			   	fputs("\t\t\t\t\t<tr>\n\t\t\t\t\t\t<td>\n", file);
			   	
			   	if (list->arrayOfTags[index]->information[Details] != NULL) {
				   	fprintf(file, "\t\t\t\t\t\t\t%s\n", list->arrayOfTags[index]->information[Details]);
				}
			   	if (list->arrayOfTags[index]->information[Param] != NULL) {
			   		fputs("\t\t\t\t\t\t\t<h2>Parameters</h2>\n", file);
			   		fprintf(file, "\t\t\t\t\t\t\t<p>%s<br>\n", list->arrayOfTags[index]->information[Param]);
			   	}
			   	if (list->arrayOfTags[index]->information[Return] != NULL) {
			   		fputs("\t\t\t\t\t\t\t<h2>Return</h2>\n", file);
			   		fprintf(file, "\t\t\t\t\t\t\t<p>%s<br>\n", list->arrayOfTags[index]->information[Return]);
			   	}
			   	if (list->arrayOfTags[index]->information[Author] != NULL) {
				   	fputs("\t\t\t\t\t\t\t<h2>Authors</h2>\n", file);
				   	fprintf(file, "\t\t\t\t\t\t\t<p>%s<br>\n", list->arrayOfTags[index]->information[Author]);
			   	}
			   	if (list->arrayOfTags[index]->information[Date] != NULL) {
				   	fputs("\t\t\t\t\t\t\t<h2>Date</h2>\n", file);
				   	fprintf(file, "\t\t\t\t\t\t\t<p>%s<br>\n", list->arrayOfTags[index]->information[Date]);
			   	}
			   	if (list->arrayOfTags[index]->information[Version] != NULL) {
				   	fputs("\t\t\t\t\t\t\t<h2>Version</h2>\n", file);
				   	fprintf(file, "\t\t\t\t\t\t\t<p>%s<br>\n", list->arrayOfTags[index]->information[Version]);
			   	}
			   	fputs("\t\t\t\t\t\t</td>\n\t\t\t\t\t</tr>\n", file);
			   	fputs("\t\t\t\t</table>\n", file);
			   	fputs("\t\t\t\t<br>\n", file);
			}
		}
		index++;
	}	
}

/**
 * \fn 			\c int startListOfFunctionsPart( \c SaveTagArrays \a list , \c FILE* \a file, \c char* \a sourceName)
 * \author		\p Chaymae & Martine
 * \param		\c FILE* \a file  the file where will be write the tags for the html
 * \param		\c char* \a souceName  the name of the file
 * \param		\c SaveTagArrays \a list  the \a list of tags of the file \a sourceName 
 * \version		\p 1.1
 * \brief 		\p Write the first tags to write informations about file
 * \details		\p This function write the first tags for the informations about the file
 */

int startFilePart(SaveTagArrays list, FILE* file, int index, char* fileName) {
	index = 0;
	while (list->arrayOfTags[index] != NULL) {
		if (list->arrayOfTags[index]->information[File] == NULL) {
			if (list->arrayOfTags[index]->information[Struct] == NULL && list->arrayOfTags[index]->information[Fn] == NULL) {
				
				fprintf(file, "\t\t\t\t<h1>Detailed description of the file %s</h1>\n", fileName);
				return index;
			}
		}
		else if (list->arrayOfTags[index]->information[File] != NULL) {
			if (compareStrings(list->arrayOfTags[index]->information[File], fileName) == 1) {
				if (list->arrayOfTags[index]->information[Struct] == NULL && list->arrayOfTags[index]->information[Fn] == NULL) {
					
					fprintf(file, "\t\t\t\t<h1>Detailed description of the file %s</h1>\n", fileName);
					return index;
				}
			}
		}
		index++;
	}
	return -1;
}

/**
 * \fn 			\c void writeDescriptionOfFile( \c SaveTagArrays \a list , \c FILE* \a file , \c int \a index , \c char* \a fileName)
 * \author		\p Chaymae & Martine
 * \param		\c FILE* \a file  the file where will be write the tags for the html
 * \param		\c char* \a fileName	the name of the current file
 * \param		\c SaveTagArrays \a list  the \a list of tags of the file \a sourceName 
 * \version		\p 1.1
 * \brief 		\p Write the first tags to write the list of functions
 * \details		\p This function write the first tags of the list of tags per file
 */

void writeDescriptionOfFile(SaveTagArrays list, FILE* file, int index, char* fileName) {
	if (list->arrayOfTags[index]->information[Details] != NULL) {
	}
   	fprintf(file, "\t\t\t\t\t%s\n", list->arrayOfTags[index]->information[Details]);
   	if (list->arrayOfTags[index]->information[Author] != NULL) {
	   	fputs("\t\t\t\t<h2>Authors</h2>\n", file);
	   	fprintf(file, "\t\t\t\t\t%s\n", list->arrayOfTags[index]->information[Author]);
   	}
   	if (list->arrayOfTags[index]->information[Date] != NULL) {
	   	fputs("\t\t\t\t<h2>Date</h2>\n", file);
	   	fprintf(file, "\t\t\t\t\t%s\n", list->arrayOfTags[index]->information[Date]);
   	}
   	if (list->arrayOfTags[index]->information[Version] != NULL) {
	   	fputs("\t\t\t\t<h2>Version</h2>\n", file);
	   	fprintf(file, "\t\t\t\t\t%s\n", list->arrayOfTags[index]->information[Version]);
   	}
}

/**
 * \fn 			\c FILE* openHtmlFile( \c char* sourceName , \c char* \a fileToWrite , \c FILE* \a file )
 * \author		\p Chaymae & Martine
 * \param		\c FILE* \a file  the file where will be write the tags for the html
 * \param		\c char* \a souceName  the name of the file
 * \param		\c char* \a fileToWrite  the name of the html file to write
 * \version		\p 1.1
 * \brief 		\p Write the first tags to write an html file
 */

FILE* openHtmlFile(char* sourceName, char* fileToWrite, FILE* file) {
	file = fopen(fileToWrite, "w");
	if (file == NULL) {
		fprintf(stderr, "The file cannot be open or created\n");
		return NULL;	
	}
	fputs("<!DOCTYPE html>\n", file);
	fputs("<html>\n\t<head>\n", file);
   	fputs("\t\t<meta charset=\"utf-8\" />\n", file);
   	fputs("\t\t<link rel=\"stylesheet\" href=\"../WWW/Css.css\"/>\n", file);
   	fputs("\t\t<title>DocMyCode</title>\n", file);
   	fputs("\t</head>\n\t<body>\n", file);
   	fputs("\t\t<header>\n\t\t\t<a href=\"Accueil.html\" class=\"type1\"><h1>Doc My Code</h1></a>\n\t\t</header>\n", file);
	return file;
}

/**
 * \fn 			\c void closeHtmlFile( \c FILE* \a file )
 * \author		\p Chaymae & Martine
 * \param		\c FILE* \a file  the file where will be write the tags for the html
 * \version		\p 1.1
 * \brief 		\p Write the last tags to write the end of the file
 */

void closeHtmlFile(FILE* file) {
   	fputs("\t\t\t<br>\n", file);
   	fputs("\t\t\t<footer>\n\t\t\t\t<div id=\"pied_de_page\">Cr&eacute;ation : <cite>KADDOURI Chaymae & LABARDY Martine &copy; January</cite> 2013\n\t\t\t\t</div>\n\t\t\t</footer>\n", file);
   	fputs("\t</body>\n", file);
   	fputs("</html>\n", file);
	fclose(file);
}
