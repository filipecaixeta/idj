CC = g++
RMDIR = rm -rf
RM = rm -f
DEP_FLAGS = -MT $@ -MMD -MP -MF $(DEP_PATH)/$*.d
DIRECTIVES = -std=c++11 -Wall -Wextra -c -I $(HEADER_PATH)
LIBS = -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf -lm

HEADER_PATH = include
SRC_PATH = src
BIN_PATH = .bin
DEP_PATH = .dep

CPP_FILES = $(wildcard $(SRC_PATH)/*.cpp)
OBJ_FILES = $(addprefix $(BIN_PATH)/,$(notdir $(CPP_FILES:.cpp=.o)))
DEP_FILES = $(wildcard $(DEP_PATH)/*.d)

EXEC = Filipe_CAIXETA_100129706

all: $(EXEC)

$(EXEC): $(OBJ_FILES)
	$(CC) -o $@ $^ $(LIBS)

$(BIN_PATH)/%.o: $(SRC_PATH)/%.cpp


	@mkdir -p $(DEP_PATH) $(BIN_PATH)


	$(CC) $(DEP_FLAGS) -c -o $@ $< $(DIRECTIVES)

clean:
	$(RMDIR) $(BIN_PATH) $(DEP_PATH)
	$(RM) $(EXEC)

-include $(DEP_FILES)

.PRECIOUS: $(DEP_PATH)/%.d

.PHONY: debug clean release

print-% : ; @echo $* = $($*)

debug: DIRECTIVES += -ggdb -O0
debug: all

release: DIRECTIVES += -Ofast -mtune=native
release: all