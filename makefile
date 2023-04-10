src = src/*.cpp
bin = bin
out = $(bin)/out
obj = ../obj/quaternion.o



make: library build run

build:
	g++ $(src) -o $(out) -L$(bin) -leternion

run:
	./$(out)

library:
	cd obj;\
	gcc -c ../src/eternion/*.c -O2;\
	cd ../bin;\
	ar rcs libeternion.a $(obj);\
	cd ../;