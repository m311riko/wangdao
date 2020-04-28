srcs:=$(wildcard *.c)
objs:=$(patsubst %.c,%,$(srcs))

all:$(objs)
	for i in $(objs);do gcc $$i.c -o $$i;done

.PHONY:clean print
clean:
	rm -rf $(out) $(objs)
print:
	@echo $(objs)
