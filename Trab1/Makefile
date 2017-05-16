# choose compiler
CC = g++

# um caminho para guardar e acessar cada tipo de arquivo (.h .cpp .o .d)
HEADER_PATH = include
SRC_PATH = src
BIN_PATH = bin
DEP_PATH = dep
SDL_PATH = /usr/include/SDL2


DEP_FLAGS = -MT $@ -MMD -MP -MF $(DEP_PATH)/$*.d

# diretivas usadas na linkagem dos objetos
LIBS = -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf -lm

# diretivas usadas na compilação de objetos
DIRECTIVES = -std=c++11 -Wall -Wextra -I$(SDL_PATH)

# lista de arquivos para cada tipo de arquivo (.cpp .o .d)
CPP_FILES = $(wildcard $(SRC_PATH)/*.cpp)
OBJ_FILES = $(addprefix $(BIN_PATH)/,$(notdir $(CPP_FILES:.cpp=.o)))
DEP_FILES = $(wildcard $(DEP_PATH)/*.d)

# nome da regra principal a ser executada
EXEC = JOGO

all: $(EXEC)

$(EXEC): $(OBJ_FILES)
	$(CC) -o $@ $^ $(LIBS) $(DIRECTIVES)

$(BIN_PATH)/%.o: $(SRC_PATH)/%.cpp
	mkdir -p $(DEP_PATH) $(BIN_PATH)
	$(CC) $(DEP_FLAGS) -c -o $@ $< $(DIRECTIVES)

# g++ -o jogo src/Game.cpp src/Main.cpp -I/usr/include/SDL2 -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf -lm -std=c++11
