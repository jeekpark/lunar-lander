TARGET				=	lunar-lander


CXX         = c++
CXXFLAGS    = -I./lib/sfml/2.6.1/include -I./src -std=c++11 #-Wall -Wextra -Werror

LDFLAGS     = -L./lib/sfml/2.6.1/lib -lsfml-window -lsfml-graphics -lsfml-audio -lsfml-system  -Wl,-rpath,./lib/sfml/2.6.1/lib

SRC_DIR     = ./src
LLAN_DIR		=	$(SRC_DIR)/llan
CORE_DIR		=	$(LLAN_DIR)/Core
UI_DIR			=	$(LLAN_DIR)/UI
SOUND_DIR		=	$(LLAN_DIR)/Sound


OBJ_DIR			=	./obj

CLANGD_GEN  = ./clangd_gen.sh

SRC_FILES		=	$(SRC_DIR)/main.cpp           				\
							$(CORE_DIR)/Core.cpp									\
							$(CORE_DIR)/EventManager.cpp					\
							$(CORE_DIR)/Starship.cpp							\
							$(CORE_DIR)/Terrain.cpp								\
							$(CORE_DIR)/Render.cpp								\
							$(UI_DIR)/UI.cpp											\
							$(SOUND_DIR)/Sound.cpp


OBJ_FILES   = $(SRC_FILES:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)


HEADER      = 

PCH					=	$(LLAN_DIR)/common.hpp.gch
PCH_SRC			=	$(LLAN_DIR)/common.hpp


all : $(TARGET)


$(TARGET) : $(OBJ_FILES)
	$(CXX) $(LDFLAGS) $^ -o $@

$(PCH) : $(PCH_SRC)
	$(CXX) $(CXXFLAGS) -x c++-header -o $@ $<

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cpp $(HEADER)
	mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -include $(PCH_SRC) -c $< -o $@

clean :
	rm -rf $(OBJ_DIR) $(TARGET) $(PCH)

clangd :
	/bin/bash $(CLANGD_GEN)

re : clean
	make all

.PHONY: all clean