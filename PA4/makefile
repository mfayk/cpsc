.SUFFIXES:
.SUFFIXES: .c .cpp .o

CC = g++

OBJS=Driver.o   \
     Student.o     \
     CpscCourse.o		\
		 Faculty.o		\
		 Person.o


CXXFLAGS=-g -Wall

all: pa4


${OBJS}: Student.h     \
         CpscCourse.h   \
				 Faculty.h			\
				 Person.h				\
         makefile

pa4: ${OBJS}
	-echo Linking $@
	g++ -o $@ ${OBJS}

test:
	./pa4 studentInfo.txt cpscInfo.txt facultyinfo.txt

clean:
	rm -f *.o pa3
