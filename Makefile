FLAGS = -g -Wall -pedantic -Iinclude
BUILD = ./build/main.o \
	./build/src/Engine/list.o \
	./build/src/Engine/process.o \
	./build/src/Engine/objects.o \
	./build/src/Engine/math.o \
	./build/src/Input/input.o \
	./build/src/Mouse/mouse.o \
	./build/src/Engine/base.o

ifeq ($(OS),Windows_NT)
	EXEC=./release/main.exe
	ENV=set LD_LIBRARY_PATH=./release/lib
else
	EXEC=./release/main
	ENV=export LD_LIBRARY_PATH=./release/lib
endif

valgrind: compile
	$(ENV) && valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --log-file=valgrind.log $(EXEC)
run:
	$(ENV) && $(EXEC)
dev: compile
	$(ENV) && $(EXEC)
compile: $(BUILD)
	g++ -o $(EXEC) $(BUILD) -L./release/lib -lsfml-graphics -lsfml-window -lsfml-system
build/main.o: main.cpp #src/includes/list.hpp
	g++ $(FLAGS) -c main.cpp -Iinclude -o build/main.o
build/src/Engine/list.o: src/Engine/list.cpp include/Engine/list.hpp
	g++ $(FLAGS) -c src/Engine/list.cpp -Iinclude -o build/src/Engine/list.o
build/src/Engine/process.o: src/Engine/process.cpp include/Engine/process.hpp
	g++ $(FLAGS) -c src/Engine/process.cpp -Iinclude -o build/src/Engine/process.o
build/src/Engine/objects.o: src/Engine/objects.cpp include/Engine/objects.hpp
	g++ $(FLAGS) -c src/Engine/objects.cpp -Iinclude -o build/src/Engine/objects.o
build/src/Engine/math.o: src/Engine/math.cpp include/Engine/math.hpp
	g++ $(FLAGS) -c src/Engine/math.cpp -Iinclude -o build/src/Engine/math.o
build/src/Input/input.o: src/Input/input.cpp include/Input/input.hpp
	g++ $(FLAGS) -c src/Input/input.cpp -Iinclude -o build/src/Input/input.o
build/src/Mouse/mouse.o: src/Mouse/mouse.cpp include/Mouse/mouse.hpp
	g++ $(FLAGS) -c src/Mouse/mouse.cpp -Iinclude -o build/src/Mouse/mouse.o
build/src/Engine/base.o: src/Engine/base.cpp include/Engine/base.hpp
	g++ $(FLAGS) -c src/Engine/base.cpp -Iinclude -o build/src/Engine/base.o