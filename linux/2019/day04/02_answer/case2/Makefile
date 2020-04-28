out:=main
srcs:=$(wildcard *.c)
objs:=$(patsubst %.c,%.o,$(srcs))

$(out):$(objs)
	gcc $^ -o $@

# 注意加-c选项
%.o:%.c
	gcc -c $< -o $@

# 注意rebuild的依赖要在一行
.PHONY:clean rebuild print
rebuild:clean $(out)
clean:
	rm -rf $(out) $(objs)
print:
	@echo $(objs)
