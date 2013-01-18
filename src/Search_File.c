#include"Search_File.h"
 
int isDir(char* s) {
    if ((strchr(s, '.')) == NULL)
        return 1;
    else
        return 0;
}

char* copy(char* dest) {
	char* tmp = (char* )calloc(strlen(dest)+5, sizeof(char));
	int j = 0, i= 0;
	tmp[0] = '.';
	tmp[1] = '/';
	for (i=2; j<strlen(dest) ;i++) {
		tmp[i] = dest[j];
		j++;
	}
	return tmp;
}

int serchingFile(char* actualRepertory, char* file) {
	DIR* rep = NULL; 
	char* tmp = NULL; 
	struct dirent* fichierLu = NULL;
    tmp = copy(actualRepertory);
    rep = opendir(tmp); 
    if (rep == NULL) {
       puts("Le dossier n'a pu etre ouvert");
        exit(1); 
    }
 	while ((fichierLu = readdir(rep))!= NULL) {
 	if (strcmp(fichierLu->d_name, ".") != 0 && strcmp(fichierLu->d_name, "..") != 0) {
 		printf("fichier lu %s\n", fichierLu->d_name);
 	}
 		
 		if (strcmp(fichierLu->d_name, file) == 0) {
 			if (closedir(rep) == -1) 
       			 exit(-1);
 			return 1;
 		}
 	}
 	free(tmp);
 	return 0;
}

char* * browseRepertory(char* actualRepertory, char* file) {
	char* * t = NULL;
	DIR* rep = NULL; 
	int i=0, j;
    struct dirent* fichierLu = NULL;
    rep = opendir(actualRepertory); 
 	t = (char* * )calloc(14, sizeof(char* ));
 	if (t == NULL) return NULL;
    if (rep == NULL) {
        exit(1); 
    }
 	while ((fichierLu = readdir(rep))!= NULL) {
 		if ((strcmp(fichierLu->d_name, "Makefile") != 0) && (strcmp(fichierLu->d_name, "docmycode") != 0)) {
 			if (isDir(fichierLu->d_name)) {
 				t[i] = (char* )calloc((strlen(fichierLu->d_name) +1), sizeof(char));
 				if (t[i] == NULL) {
 					for (j=0 ; j<i ; j++) {
 						free(t[j]);
 						t[j] = NULL;
 					}
 					free(t);
 					t = NULL;
 					return NULL;
 				}
 				strcpy(t[i], fichierLu->d_name); 
 				printf("fichier lu %s\n", t[i]);
 				i++;
 			}
 		}
 		if (strcmp(fichierLu->d_name, file) == 0) {
 			if (closedir(rep) == -1) 
       			 exit(-1);
 			return NULL;
 		}
 	}
 	i=0;
 	while(t[i] != NULL) {
 		if(serchingFile(t[i], file)) 
 			return t;
 		i++;
 	}
 	if (closedir(rep) == -1) 
        exit(-1);
 	return NULL;
}
