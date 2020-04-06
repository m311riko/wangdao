ELF:=main
OBJS:=main.o func.o
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
