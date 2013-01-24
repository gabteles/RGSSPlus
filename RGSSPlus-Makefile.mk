# Environment
CC=g++.exe
RM=rm
MKDIR=mkdir
CFLAGS=-c -Wall
CCFLAGS=
LIBNAME=RGSSPlus.dll
OUTDIR=build
OBJDIR=obj

# Auto
SOURCES=$(wildcard *.cpp)
OBJECTS=$(SOURCES:.cpp=.o)
LINKOBJ=$(patsubst %.o,${OBJDIR}/%.o,$(OBJECTS))
	
#===============================================================================
	
all: directories compile clean

clean:
	$(RM) -rf $(OBJDIR)/*o

#===============================================================================

compile: $(OBJECTS)
	$(CC) $(LINKOBJ) $(CCFLAGS) -o $(OUTDIR)/$(LIBNAME)

directories: ${OUTDIR} ${OBJDIR}

${OUTDIR}:
	${MKDIR} ${OUTDIR}
	
${OBJDIR}:
	${MKDIR} ${OBJDIR}

%.o: %.cpp
	$(CC) $(CFLAGS) $< -o ${OBJDIR}/$@