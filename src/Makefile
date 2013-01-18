INCL = ../include/

lib = 
inc = -I../include

PROJET = Read_block.o Main.o Special_Tags.o Save_blocks.o Save_One_File.o Write_One_Doc.o Search_File.o

EXEC = docmycode

FLAGS = -Wall -ansi -g -pedantic

DEBUG = -Wall -ansi -g -O3 -fpic -pedantic
CC = gcc

$(EXEC) : $(PROJET)
	@echo "Création de l'exécutable -> $@"
	@$(CC) $(DEBUG) $(PROJET) $(lib) -o $@


%.o : %.c $(INCL)%.h
	@echo "Création de l'objet $@"
	@$(CC) $(DEBUG) $(inc) -c $< -o $@

clean :
	@rm -f $(EXEC) *.o
