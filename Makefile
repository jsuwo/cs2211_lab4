################################################################################
#
# Makefile
# Author: Jeff Shantz
#
# Targets of interest:
#
# Compile all binaries                       make or make all
# Build strarr                               make strarr
# Build strlst                               make strlst
# Remove intermediate files                  make clean
# Remove intermediate files and binaries     make realclean
#
################################################################################

all: strarr

strarr: main.o string_helper.o
	gcc -o strarr main.o string_helper.o

main.o: main.c boolean.h string_helper.h
	gcc -c main.c

string_helper.o: string_helper.c string_helper.h
	gcc -c string_helper.c

clean:
	rm -f *.o

realclean: clean
	rm -f strarr

