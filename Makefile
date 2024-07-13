## ============= AVISO ============= ##
## Isso aqui foi gerado usando IA, ok?
## ================================= ##

FLAGS = -g -Wall -pedantic -Iinclude
SRC_DIR = src
BUILD_DIR = _build
RELEASE_DIR = _release
TEST_DIR = tests

SRC_FILES = $(wildcard $(SRC_DIR)/**/*.cpp)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SRC_FILES))
OBJ_FILES += $(BUILD_DIR)/main.o
OBJ_FILES_WITHOUT_MAIN = $(filter-out $(BUILD_DIR)/main.o, $(OBJ_FILES))
TEST_SRC_FILES = $(wildcard $(TEST_DIR)/*.cpp)
TEST_OBJ_FILES = $(patsubst $(TEST_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(TEST_SRC_FILES))

ifeq ($(OS),Windows_NT)
EXEC = $(RELEASE_DIR)/main.exe
TEST_EXEC = $(RELEASE_DIR)/test_main.exe
ENV = set LD_LIBRARY_PATH=$(RELEASE_DIR)/lib
MKDIR = if not exist $(subst /,\,$(dir $@)) mkdir $(subst /,\,$(dir $@))
else
EXEC = $(RELEASE_DIR)/main
TEST_EXEC = $(RELEASE_DIR)/test_main
ENV = export LD_LIBRARY_PATH=$(RELEASE_DIR)/lib
MKDIR = mkdir -p $(dir $@)
endif

all: $(EXEC) $(TEST_EXEC)

valgrind: $(EXEC)
	$(ENV) && valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --log-file=valgrind.log $(EXEC)

run: $(EXEC)
	$(ENV) && $(EXEC)

dev: $(EXEC)
	$(ENV) && $(EXEC)

compile: $(OBJ_FILES)
	g++ -o $(EXEC) $^ -L$(RELEASE_DIR)/lib -lsfml-graphics -lsfml-window -lsfml-system

test: $(TEST_EXEC)
	$(ENV) && $(TEST_EXEC)

$(EXEC): $(OBJ_FILES)
	g++ -o $@ $^ -L$(RELEASE_DIR)/lib -lsfml-graphics -lsfml-window -lsfml-system

$(TEST_EXEC): $(TEST_OBJ_FILES) $(OBJ_FILES_WITHOUT_MAIN)
	g++ -o $@ $^ -L$(TEST_DIR)/googletest/build/lib -lgtest -lgtest_main -lgmock -pthread -L$(RELEASE_DIR)/lib -lsfml-graphics -lsfml-window -lsfml-system

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(MKDIR)
	g++ $(FLAGS) -c $< -o $@

$(BUILD_DIR)/%.o: $(TEST_DIR)/%.cpp
	$(MKDIR)
	g++ $(FLAGS) -c $< -o $@

$(BUILD_DIR)/main.o: main.cpp
	$(MKDIR)
	g++ $(FLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR) $(EXEC) $(TEST_EXEC)

.PHONY: all valgrind run dev compile test clean