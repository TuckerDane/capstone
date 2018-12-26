CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g
LDFLAGS_LINUX = -lncurses -ltinfo
LDFLAGS= $(LDFLAGS_LINUX)

####################
### USER SECTION ###
####################

# SRCS is a standard name for the source files. 
SRCS = Main.cpp Aarow.cpp Door.cpp Dungeon.cpp GreatRoom.cpp hHallWay.cpp Object.cpp Player.cpp Room.cpp Space.cpp Stone.cpp Switch.cpp vHallWay.cpp
# HEADERS is a standard name for the header files. 
HEADERS = Aarow.h Door.h Dungeon.h GreatRoom.h hHallWay.h Object.h Player.h Room.h Space.h Stone.h Switch.h vHallWay.h

# executable name 
PROG = FinalProject

OBJS = Main.o Aarow.o Door.o Dungeon.o GreatRoom.o hHallWay.o Object.o Player.o Room.o Space.co Stone.o Switch.o vHallWay.o

# This is the name of your compressed file. 
# Edit name as needed. Keep the format.
TAR = cs162_finalproject_tucker_walker.tar.bz2

#####################
### BUILD SECTION ###
#####################

# Typing 'make' in terminal calls the first build availible.
# In this case, default.
lab1: ${SRCS} ${HEADERS} 
	${CXX} ${CXXFLAGS} ${SRCS} -o ${PROG}

# Typing 'make all' in terminal calls this build.
all:
	${CXX} ${CXXFLAGS} ${SRCS} ${HEADERS} -o ${PROG} ${LDFLAGS}

# Typing 'make tar' in terminal calls this build.
# This creates a compressed file for submission.
tar:
	tar cvjf ${TAR} ${SRCS} ${HEADERS} ${DOC} makefile

# Typing 'make clean' calls this build.
# It's designed to clean up the folder.
# Be careful with this, edit as needed.
clean: 
	rm -f ${PROG} *.o *~

