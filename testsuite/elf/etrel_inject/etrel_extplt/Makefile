##
## Makefile for elfsh
##
## Started on  Sun Mar 10 01:19:24 2002 jfv
##
##

include ../../../../config.h

SRC	= etrel_inject.c
CC	= gcc
RM	= rm -f 
VULN	= host.c
RELSRC	= rel.c

RELOBJ32  = $(RELSRC:.c=.32.o)
RELOBJ64  = $(RELSRC:.c=.64.o)
OBJ32	  = $(SRC:.c=.32.o)
OBJ64	  = $(SRC:.c=.64.o)
CFLAGS32  =$(shell eresi-config32 libelfsh --cflags)
LDFLAGS32 =$(shell eresi-config32 libelfsh --libs)
CFLAGS64  =$(shell eresi-config64 libelfsh --cflags)
LDFLAGS64 =$(shell eresi-config64 libelfsh --libs)
NAME32	  = relinject32
NAME64	  = relinject64

all: all32 all64

all32: $(OBJ32) $(RELOBJ32)
	$(CC) $(LDFLAGS32) $(OBJ32) -o $(NAME32)
	$(CC) $(VULN) -o hijackme32

all64: $(OBJ64) $(RELOBJ64)
	$(CC) $(LDFLAGS64) $(OBJ64) -o $(NAME64)
	$(CC) -m64 $(VULN) -o hijackme64

fclean: clean
	$(RM) $(NAME32) $(NAME64) hijackme* fake_aout*

clean:
	$(RM) $(OBJ32) $(OBJ64) $(RELOBJ32) $(RELOBJ64) *~

%.32.o:	%.c
	$(CC) -c $< -o $@ $(CFLAGS32) -g

%.64.o:	%.c
	$(CC) -c $< -o $@ $(CFLAGS64) -g
