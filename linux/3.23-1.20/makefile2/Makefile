ELF:=main
OBJS:=main.o func.o
$(ELF):$(OBJS)
	gcc -o $(ELF) $(OBJS)
main.o:main.c
	gcc -o main.o -c main.c
func.o:func.c
	gcc -o func.o -c func.c

.PHONY:clean
	
clean:
	rm -f $(OBJS)
