
CXX = g++
CXXFLAGS = -std=c++0x
#CXXFLAGS += -Wall
#CXXFLAGS += -pedantic-errors
#CXXFLAGS += -g
#CXXFLAGS += -O3
#LDFLAGS = -lboost_date_time

OBJS = main.o menu.o inputValidation.o fantasyGame.o

SRCS = main.cpp menu.cpp inputValidation.cpp fantasyGame.cpp

HEADERS = menu.hpp inputValidation.hpp fantasyGame.hpp 

#target: dependencies
#	rule to build
#

fantasyGame: ${SRCS} ${HEADERS}	
	${CXX} ${CXXFLAGS} ${SRCS} -o fantasyGame

#${OBJS}: ${SRCS}
#	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)
