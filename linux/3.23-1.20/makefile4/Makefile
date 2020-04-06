SOURCES:=$(wildcard *.c)
ELF:=main
OBJS:=$(patsubst %.c,%.o,$(SOURCES))
CFLAGS:=-g
CC:=gcc
$(ELF):$(OBJS)
	$(CC) -o $@ $^
main.o:main.c
	$(CC) -o $@ -c $(CFLAGS) $<
func.o:func.c
	$(CC) -o $@ -c $(CFLAGS) $<
.PHONY:clean

clean:
	rm -f $(OBJS)
