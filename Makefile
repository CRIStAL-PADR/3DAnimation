#
# CONFIGURATION GENERALE
#

EXEC = 3danimation 
OBJETS =  Vect3D.o Matrice.o 
NOM_PROJET = 3DAnimation

#
# SUFFIXES
#

.SUFFIXES: .cpp .o

#
# OBJETS
#

EXEC_O = $(EXEC:=.o)
OBJETS_O = $(OBJETS) $(EXEC_O)

#
# ARGUMENTS ET COMPILATEUR
#

CC = g++
CCFLAGS = -Wall -O3 -Werror -ansi -pedantic
CCFLAGS_DEBUG = -D _DEBUG_


#
# REGLES
#

all: msg $(OBJETS) $(EXEC_O)
	@echo "Creation des executables..."
	@for i in $(EXEC); do \
	$(CC) -o $$i $$i.o $(OBJETS) ; \
	done
	@echo "Termine."

msg:
	@echo "Projet : 3DAnimation"
	@echo "Creation des objets..."
	

debug: CCFLAGS = $(CCFLAGS) $(CCFLAGS_DEBUG)
debug: all

#
# REGLES GENERALES
#

clean:
	@echo "Suppresion des objets, des fichiers temporaires..."
	@rm -f $(OBJETS) $(EXEC_O)
	@rm -f *~ *#
	@rm -f *.tar.gz
	@rm -f $(EXEC)
	@rm -f dependances
	@echo "Termine."

depend:
	@echo "Creation des dependances..."
	@sed -e "/^# DEPENDANCES/,$$ d" makefile > dependances
	@echo "# DEPENDANCES" >> dependances
	@for i in $(OBJETS_O); do \
	$(CC) -MM -MT $$i $(CCFLAGS) `echo $$i | sed "s/\(.*\)\\.o$$/\1.cpp/"` >> dependances; \
	done
	@cat dependances > makefile
	@rm dependances
	@echo "Termine."

#
# CREATION ARCHIVE
#

ARCHIVE_FILES = *

dist: clean
	@echo "Creation de l'archive $(NOM_PROJET)$(shell date '+%y%m%d.tar.gz')..."
	@REP=`basename "$$PWD"`; tar -zcf $(NOM_PROJET)$(shell date '+%y%m%d.tar.gz') $(addprefix ,$(ARCHIVE_FILES)) 
	@echo "Termine."

# DEPENDANCES
Vect3D.o: Vect3D.cpp Vect3D.hpp
Matrice.o: Matrice.cpp Matrice.hpp Vect3D.hpp
3danimation.o: 3danimation.cpp Matrice.hpp Vect3D.hpp
