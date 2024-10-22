## ============= AVISO ============= ##
## Isso aqui foi gerado usando IA, ok?
## ================================= ##

FLAGS = -g -Wall -Wextra -pedantic -Iinclude
SFML_FLAGS = -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-system
LINUX_FLAGS = -lFLAC -lfreetype -logg -lopenal -lvorbis -lvorbisenc -lvorbisfile
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
EXEC = $(RELEASE_DIR)\bin\main.exe
TEST_EXEC = $(RELEASE_DIR)\bin\tests.exe
ENV = set LD_LIBRARY_PATH=$(RELEASE_DIR)/lib
MKDIR = if not exist $(subst /,\,$(dir $@)) mkdir $(subst /,\,$(dir $@))
RM = del /q /f
RMDIR = rmdir /q /s
else
EXEC = $(RELEASE_DIR)/bin/main
TEST_EXEC = $(RELEASE_DIR)/bin/tests
ENV = export LD_LIBRARY_PATH=$(RELEASE_DIR)/lib
MKDIR = mkdir -p $(dir $@)
RM = rm -f
RMDIR = rm -rf
SFML_FLAGS += $(LINUX_FLAGS)
endif

all: $(EXEC) $(TEST_EXEC)

valgrind: $(EXEC)
	$(ENV) && valgrind --suppressions=./suppressions.supp --leak-check=full --show-leak-kinds=definite,possible --track-origins=yes --log-file=valgrind.log $(EXEC)

run: $(EXEC)
	$(ENV) && $(EXEC)

dev: $(EXEC)
	$(ENV) && $(EXEC)

compile: $(OBJ_FILES)
	g++ -o $(EXEC) $^ -L$(RELEASE_DIR)/lib $(SFML_FLAGS)

test: $(TEST_EXEC)
	$(ENV) && $(TEST_EXEC)

$(EXEC): $(OBJ_FILES)
	g++ -o $@ $^ -L$(RELEASE_DIR)/lib $(SFML_FLAGS)

$(TEST_EXEC): $(TEST_OBJ_FILES) $(OBJ_FILES_WITHOUT_MAIN)
	g++ -o $@ $^ -L$(RELEASE_DIR)/lib -lgtest -lgtest_main -lgmock -lgmock_main -pthread $(SFML_FLAGS)

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
	@$(RMDIR) $(BUILD_DIR)
	@$(RM) $(EXEC)
	@$(RM) $(TEST_EXEC)

.PHONY: all valgrind run dev compile test clean
