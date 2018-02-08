CFLAGS = -std=c99 -g -Wall -Wshadow --pedantic -Wvla -Werror
GCC = gcc $(CFLAGS)
SRCS = pe05.c main.c
OBJS = $(SRCS:%.c=%.o) pe04.o
VALGRIND = valgrind --tool=memcheck --leak-check=full

pe05:$(OBJS)
	$(GCC) $(OBJS) -o pe05


.c.o:
	$(GCC) $(FLAGS) -c $*.c

clean:
	/bin/rm -f pe05.o pe05
	/bin/rm -f input* output*
