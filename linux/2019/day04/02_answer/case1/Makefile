main:main.o add.o
	gcc main.o add.o -o main

# 注意加-c选项
main.o:main.c
	gcc -c main.c -o main.o

add.o:add.c
	gcc -c add.c -o add.o

# 注意rebuild的依赖要在一行
.PHONY:clean rebuild
rebuild:clean main
clean:
	rm -rf main.o add.o main
