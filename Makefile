COMPILE_FLAGS = -Wall -c
INCLUDED_FILES = ./build/main.o \
	./build/src/Engine/list.o \
	./build/src/Engine/process.o \
	./build/src/Engine/objects.o \
	./build/src/Engine/rooms.o \
	./build/src/Engine/math.o \
	./build/src/Input/input.o \
	./build/src/Mouse/mouse.o \
	./build/src/Engine/base.o
	
dev:
	make compile && make run
compile: ./main.cpp compile_process compile_objects compile_rooms compile_list compile_math compile_input compile_mouse compile_base
	g++ ${COMPILE_FLAGS} main.cpp -Ilibs/sfml/include -o ./build/main.o \
	&& g++ -Wall -Llibs/sfml/lib ${INCLUDED_FILES} -o game -lsfml-system -lsfml-window \
	-lsfml-audio -lsfml-graphics
compile_process: ./src/Engine/process.cpp ./include/Engine/process.hpp
	g++ ${COMPILE_FLAGS} src/Engine/process.cpp -Ilibs/sfml/include -o ./build/src/Engine/process.o
compile_objects: ./src/Engine/objects.cpp ./include/Engine/rooms.hpp
	g++ ${COMPILE_FLAGS} src/Engine/objects.cpp -Ilibs/sfml/include -o ./build/src/Engine/objects.o
compile_rooms: ./src/Engine/rooms.cpp ./include/Engine/rooms.hpp
	g++ ${COMPILE_FLAGS} src/Engine/rooms.cpp -Ilibs/sfml/include -o ./build/src/Engine/rooms.o
compile_list: ./src/Engine/list.cpp ./include/Engine/list.hpp
	g++ ${COMPILE_FLAGS} src/Engine/list.cpp -Ilibs/sfml/include -o ./build/src/Engine/list.o
compile_math: ./src/Engine/math.cpp ./include/Engine/math.hpp
	g++ ${COMPILE_FLAGS} src/Engine/math.cpp -Ilibs/sfml/include -o ./build/src/Engine/math.o
compile_input: ./src/Input/input.cpp ./include/Input/input.hpp
	g++ ${COMPILE_FLAGS} src/Input/input.cpp -Ilibs/sfml/include -o ./build/src/Input/input.o
compile_mouse: ./src/Mouse/mouse.cpp ./include/Mouse/mouse.hpp
	g++ ${COMPILE_FLAGS} src/Mouse/mouse.cpp -Ilibs/sfml/include -o ./build/src/Mouse/mouse.o
compile_base: ./src/Engine/base.cpp ./include/Engine/base.hpp
	g++ ${COMPILE_FLAGS} src/Engine/base.cpp -Ilibs/sfml/include -o ./build/src/Engine/base.o
run: ./game.exe
	"./game.exe"
	