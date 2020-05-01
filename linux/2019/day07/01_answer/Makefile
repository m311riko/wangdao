CC:=gcc
srcs:=$(wildcard *.c)
objs:=$(patsubst %.c,%,$(srcs))

all:$(objs)
%:%.c
	$(CC) -o $@ $<

.PHONY:clean rebuild print
rebuild:clean all
clean:
	rm -rf $(out) $(objs)
print:
	@echo $(objs)
