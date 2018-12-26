####################
### MACROS		 ###
####################

CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g
LDFLAGS_LINUX = -lncurses -ltinfo
LDFLAGS= $(LDFLAGS_LINUX)
INC= -I./include

####################
### USER SECTION ###
####################
 
SRCS = ./src/*.cpp 
HEADERS = ./include/*.h
OBJS = ./build/*.o
PROG = adventureGame

# This is the name of your compressed file. 
# Edit name as needed. Keep the format.
TAR = adventureGame.tar.bz2

#####################
### BUILD SECTION ###
#####################

adventureGame: ${SRCS} ${HEADERS} 
	${CXX} ${INC} ${CXXFLAGS} ${SRCS} -o ${PROG} ${LDFLAGS}

# Typing 'make all' in terminal calls this build.
all:
	${CXX} ${INC} ${CXXFLAGS} ${SRCS} ${HEADERS} -o ${PROG} ${LDFLAGS}

# Typing 'make tar' in terminal calls this build.
# This creates a compressed file for submission.
tar:
	tar cvjf ${TAR} ${INC} ${SRCS} ${HEADERS} ${DOC} makefile

# Typing 'make clean' calls this build.
# It's designed to clean up the folder.
# Be careful with this, edit as needed.
clean: 
	rm -f ${PROG} ${OBJS}