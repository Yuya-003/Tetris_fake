CFLAGS = -I/usr/X11R6/include
LDLIBS = -L/usr/X11R6/lib -lglut -lGLU -lGL -lXi -lXext -lX11 -lm -lpthread
CC = gcc
a.out: Main.c declaration.h functions.c keyboad.c key_sp.c drop.c
	$(CC) $(CFLAGS) $< $(LDLIBS)
