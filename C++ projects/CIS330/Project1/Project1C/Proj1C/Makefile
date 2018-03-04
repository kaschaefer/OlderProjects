CC=gcc
CFLAGS=-c -I.

#Directory Variables
INSTALL_DIR=.
MKDIR_P=mkdir -p
SOURCE_DIR1=$(INSTALL_DIR)/trig
SOURCE_DIR2=$(INSTALL_DIR)/exp
BUILD_DIR=$(INSTALL_DIR)/bin
INCLUDE_DIR=$(INSTALL_DIR)/include

#File Variables
CLI_FILE=$(INSTALL_DIR)/cli/cli.c

cli.o: lib/libABC.a $(CLI_FILE)
	$(MKDIR_P) $(BUILD_DIR)
	gcc $(CLI_FILE) -Iinclude -Llib -lABC -lm -o $(BUILD_DIR)/cli

lib/libABC.a: $(SOURCE_DIR1)/cos330.o $(SOURCE_DIR1)/sin330.o $(SOURCE_DIR1)/tan330.o $(SOURCE_DIR1)/arctan330.o $(SOURCE_DIR1)/arcsin330.o $(SOURCE_DIR1)/arccos330.o $(SOURCE_DIR2)/exp330.o $(SOURCE_DIR2)/log330.o
	$(MKDIR_P) $(INCLUDE_DIR)
	cp math330.h $(INCLUDE_DIR)
	$(MKDIR_P) $(INSTALL_DIR)/lib
	ar r libABC.a $(SOURCE_DIR1)/cos330.o $(SOURCE_DIR1)/sin330.o $(SOURCE_DIR1)/tan330.o $(SOURCE_DIR1)/arctan330.o $(SOURCE_DIR1)/arcsin330.o $(SOURCE_DIR1)/arccos330.o $(SOURCE_DIR2)/exp330.o $(SOURCE_DIR2)/log330.o
	mv libABC.a $(INSTALL_DIR)/lib

cos330.o: $(SOURCE_DIR1)/cos330.c
	$(CC) $(CFLAGS) $(SOURCE_DIR1)/cos330.c 

sin330.o: $(SOURCE_DIR1)/sin330.c
	$(CC) $(CFLAGS) $(SOURCE_DIR1)/sin330.c 

tan330.o: $(SOURCE_DIR1)/tan330.c
	$(CC) $(CFLAGS) $(SOURCE_DIR1)/tan330.c 

arctan330.o: $(SOURCE_DIR1)/arctan330.c
	$(CC) $(CFLAGS) $(SOURCE_DIR1)/arctan330.c 

arcsin330.o: $(SOURCE_DIR1)/arcsin330.c
	$(CC) $(CFLAGS) $(SOURCE_DIR1)/arcsin330.c 

arccos330.o: $(SOURCE_DIR1)/arccos330.c
	$(CC) $(CFLAGS) $(SOURCE_DIR1)/arccos330.c 

exp330.o: $(SOURCE_DIR2)/exp330.c
	$(CC) $(CFLAGS) $(SOURCE_DIR2)/exp330.c

log330.o: $(SOURCE_DIR2)/log330.c
	$(CC) $(CFLAGS) $(SOURCE_DIR2)/log330.c



clean:
	rm -r lib include bin ./trig/*.o ./exp/*.o
