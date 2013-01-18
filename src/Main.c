#include"Main.h"

int main(int argc, char *argv[]) {
	int option;
	int i = 0, j = 0;
	int index = 0;
	int nbOptions = 1;
	char* fileToWrite = NULL;
	SaveTagArrays list = NULL;
	FILE* file = NULL;
	char* * saveFunctions = NULL;
	
	while (nbOptions < argc) {
		i = 0;	index = 0;
		saveFunctions = allocateDoubleArrayOfChar(saveFunctions, NB_TAGS);
		fileToWrite = renameAFileToHtml(argv[nbOptions], fileToWrite);
		file = openHtmlFile(argv[nbOptions], fileToWrite, file);
		free(fileToWrite);
		fileToWrite = NULL;
		startToWriteMenu(file);
		for (j=1 ; j<argc ; j++) {
			fileToWrite = renameAFileToHtml(argv[j], fileToWrite);
			list = readFile(argv[j]);
			fputs("\t\t\t\t<hr/>\n", file);
			fprintf(file, "\t\t\t\t<li>\t\t\t\t\t<a href=\"%s\" class=\"type3\">%s</a>\n", fileToWrite, argv[j]);
			freeSaveTagArray(list);
			free(fileToWrite);
			fileToWrite = NULL;		
		}
		stopToWriteMenu(file);
		
		fputs("\t\t\t<section>\n", file);
		fputs("\t\t\t<div id=\"corps\">\n", file);
		j = 0;
		/*while (j != 2) {
			if (j == 0)*/
				list = readFile(argv[nbOptions]);
			/*else {
				fileToWrite = renameAFileToHeader(argv[nbOptions], fileToWrite);
				list = readFile(fileToWrite);
				free(fileToWrite);
				fileToWrite = NULL;
			}*/
			
			index = startListOfFunctionsPart(list, file, argv[nbOptions]);
		
			if (index != -1) {
				writeListOfFunctions(list, file, index, argv[nbOptions], saveFunctions, &i);
				endListOfFunctionsPart(file);
			}
		
			index = startFilePart(list, file, index, argv[nbOptions]);
			if (index != -1)
				writeDescriptionOfFile(list, file, index, argv[nbOptions]);


			startDescriptionOfFunctionsPart(list, file, argv[nbOptions]);
			writeDescriptionOfFunctions(list, file, argv[nbOptions]/*, saveFunctions, &i*/);
			freeSaveTagArray(list);
			j++;
		/*}*/
	
		fputs("\t\t\t</div>\n", file);
		fputs("\t\t\t</section>\n", file);
		
		closeHtmlFile(file);
		freeDoubleArrayOfChar(saveFunctions, NB_TAGS);
		nbOptions++;
	}
	
	
	
	/*do {
		i = 0;
		saveFunctions = allocateDoubleArrayOfChar(saveFunctions, NB_TAGS);
		list = readFile(argv[count]);
		printf("TEST\n");
		
		if (list != NULL) {
			
			if (file != NULL) {
				index = startToWriteMenu(list, file, argv[count], fileToWrite);
				if (index != -1) {
					writeMenu(list, file, index, saveFunctions, &i);
					stopToWriteMenu(file);
	
					fputs("\t\t\t<section>\n", file);
				   	fputs("\t\t\t<div id=\"corps\">\n", file);
				   	
				  	index = startListOfFunctionsPart(list, file, argv[count]);
					writeListOfFunctions(list, file, index, argv[count], saveFunctions, &i);

					index = startFilePart(list, file, index, argv[count]);
					writeDescriptionOfFile(list, file, index, argv[count]);
	
					startDescriptionOfFunctionsPart(list, file, argv[count]);
					writeDescriptionOfFunctions(list, file, argv[count], saveFunctions, &i);

				   	fputs("\t\t\t</div>\n", file);
				   	fputs("\t\t\t</section>\n", file);
	
					endListOfFunctionsPart(file);					
					freeDoubleArrayOfChar(saveFunctions, NB_TAGS);
					closeHtmlFile(file);
					freeSaveTagArray(list);
					free(fileToWrite);
					fileToWrite = NULL;
					count++;
				}
				else if (index == -1) {
					freeDoubleArrayOfChar(saveFunctions, NB_TAGS);
					closeHtmlFile(file);
					free(fileToWrite);
					fileToWrite = NULL;
					return -1;
				}
			}
			else if (file == NULL) {
				freeDoubleArrayOfChar(saveFunctions, NB_TAGS);
				closeHtmlFile(file);
				free(fileToWrite);
				fileToWrite = NULL;
				return -2;
			}
		}
		else if (list == NULL) {
			freeDoubleArrayOfChar(saveFunctions, NB_TAGS);
			return -3;
		}
		
	}while (count <= argc);*/
	
	
	/*printf("optarg -> %s\n", argv[1]);
	if (strcmp(argv[0], "./docmycode") == 0) {
		const char* const short_options = "1234h";
		const struct option long_options[] = {
		    { "Read_block.c",      	0,  NULL,  '1' },
		    { "Save_blocks.c",     	0,  NULL,  '2' },
		    { "Special_Tags.c", 	0,  NULL,  '3' },
		    { "Save_One_File.c", 	0,  NULL,  '4' },
		    { "Help",         	    0,  NULL,  'h' },
		    { NULL,         	    0,  NULL,   0  }    
		};
		do {
		    option = getopt_long (argc, argv, short_options, long_options, NULL);
		    switch (option) {
		        case '1':
		        	list = readFile("Read_block.c");
		        	file = openHtmlFile(list, "Read_block.c", fileToWrite);
		        	
		        	index = startToWriteMenu(list, file, "Read_block.c");
		        	writeMenu(list, file, index);
		        
		        	stopToWriteMenu(file);
		        	
		        	closeHtmlFile(file);
		        	
		        	freeSaveTagArray(list);free(fileToWrite);fileToWrite = NULL;
		        	
		        break;
		        case '2': 
		        	sourceTagArray = readFile("Save_blocks.c");
		        	freeSaveTagArray(sourceTagArray);
		        break;
		        case '3': 
		           	sourceTagArray = readFile("Special_Tags.c");
		        	freeSaveTagArray(sourceTagArray);
		        break;
		        case '4': 
		           	sourceTagArray = readFile("Save_One_File.c");
		        	freeSaveTagArray(sourceTagArray);
		        break;
		        case 'h':
		         	fprintf(stdout, "-1 --> Read_block.c\n");
		         	fprintf(stdout, "-2 --> Save_blocks.c\n");
		         	fprintf(stdout, "-3 --> Special_Tags.c\n");
		         	fprintf(stdout, "-3 --> Save_One_File.c\n");
		        break;
		    }
    }
    while (option != -1);
	}
	else {
		fprintf(stderr, "You didn't specify the right executable\nPlease try this : ./docmycode\n");
	}*/
	return 0;
}
