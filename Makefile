COMPILE_FLAGS = -Wall -c
INCLUDED_FILES = ./build/main.o \
	./build/src/list.o \
	./build/src/process.o \
	./build/src/objects.o \
	./build/src/rooms.o
	
dev:
	make compile && make run
compile: ./main.cpp compile_process compile_objects compile_rooms compile_list
	g++ ${COMPILE_FLAGS} main.cpp -Ilibs/sfml/include -o ./build/main.o \
	&& g++ -Wall -Llibs/sfml/lib ${INCLUDED_FILES} -o game -lsfml-system -lsfml-window \
	-lsfml-audio -lsfml-graphics
compile_process: ./src/process.cpp ./include/process.h
	g++ ${COMPILE_FLAGS} src/process.cpp -Ilibs/sfml/include -o ./build/src/process.o
compile_objects: ./src/objects.cpp ./include/rooms.h
	g++ ${COMPILE_FLAGS} src/objects.cpp -Ilibs/sfml/include -o ./build/src/objects.o
compile_rooms: ./src/rooms.cpp ./include/rooms.h
	g++ ${COMPILE_FLAGS} src/rooms.cpp -Ilibs/sfml/include -o ./build/src/rooms.o
compile_list: ./src/list.cpp ./include/list.h
	g++ ${COMPILE_FLAGS} src/list.cpp -Ilibs/sfml/include -o ./build/src/list.o
run: ./game.exe
	"./game.exe"
	