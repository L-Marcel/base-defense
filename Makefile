FLAGS = -g -Wall -pedantic -Iinclude
BUILD = ./_build/main.o \
	./_build/src/Engine/list.o \
	./_build/src/Engine/process.o \
	./_build/src/Engine/objects.o \
	./_build/src/Engine/math.o \
	./_build/src/Input/input.o \
	./_build/src/Mouse/mouse.o \
	./_build/src/Engine/base.o

ifeq ($(OS),Windows_NT)
	EXEC=./_release/main.exe
	ENV=set LD_LIBRARY_PATH=./_release/lib
else
	EXEC=./_release/main
	ENV=export LD_LIBRARY_PATH=./_release/lib
endif

valgrind: compile
	$(ENV) && valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --log-file=valgrind.log $(EXEC)
run:
	$(ENV) && $(EXEC)
dev: compile
	$(ENV) && $(EXEC)
compile: $(BUILD)
	g++ -o $(EXEC) $(BUILD) -L./_release/lib -lsfml-graphics -lsfml-window -lsfml-system
_build/main.o: main.cpp #src/includes/list.hpp
	g++ $(FLAGS) -c main.cpp -Iinclude -o _build/main.o
_build/src/Engine/list.o: src/Engine/list.cpp include/Engine/list.hpp
	g++ $(FLAGS) -c src/Engine/list.cpp -Iinclude -o _build/src/Engine/list.o
_build/src/Engine/process.o: src/Engine/process.cpp include/Engine/process.hpp
	g++ $(FLAGS) -c src/Engine/process.cpp -Iinclude -o _build/src/Engine/process.o
_build/src/Engine/objects.o: src/Engine/objects.cpp include/Engine/objects.hpp
	g++ $(FLAGS) -c src/Engine/objects.cpp -Iinclude -o _build/src/Engine/objects.o
_build/src/Engine/math.o: src/Engine/math.cpp include/Engine/math.hpp
	g++ $(FLAGS) -c src/Engine/math.cpp -Iinclude -o _build/src/Engine/math.o
_build/src/Input/input.o: src/Input/input.cpp include/Input/input.hpp
	g++ $(FLAGS) -c src/Input/input.cpp -Iinclude -o _build/src/Input/input.o
_build/src/Mouse/mouse.o: src/Mouse/mouse.cpp include/Mouse/mouse.hpp
	g++ $(FLAGS) -c src/Mouse/mouse.cpp -Iinclude -o _build/src/Mouse/mouse.o
_build/src/Engine/base.o: src/Engine/base.cpp include/Engine/base.hpp
	g++ $(FLAGS) -c src/Engine/base.cpp -Iinclude -o _build/src/Engine/base.o