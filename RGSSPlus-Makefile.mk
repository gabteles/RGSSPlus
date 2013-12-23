# Environment
CC=g++.exe
RM=rm
MKDIR=mkdir
CFLAGS=-c -Wall -Wextra -IInclude -DBUILDING_DLL -Wno-unused
CCFLAGS=-shared -Wl,--subsystem,windows
LIBNAME=RGSSPlus.dll
LIBDIR=Library
OUTDIR=build
OBJDIR=obj

# Auto
SOURCES=$(wildcard *.cpp)
LIB1=$(wildcard $(LIBDIR)/*.a)
LIB2=$(notdir $(LIB1))
LIB3=$(subst lib,,$(LIB2))
LIBS=$(patsubst %.a,%,$(LIB3))
LIBSINC=$(addprefix -l,$(LIBS))
OBJECTS=$(SOURCES:.cpp=.o)
LINKOBJ=$(patsubst %.o,${OBJDIR}/%.o,$(OBJECTS))
	
#===============================================================================
	
all: directories compile

clean:
	$(RM) -rf $(OBJDIR)/*o

#===============================================================================

compile: $(OBJECTS)
	$(CC) $(LINKOBJ) $(LIBSINC) -L$(LIBDIR) $(CCFLAGS) -o $(OUTDIR)/$(LIBNAME)

directories: ${OUTDIR} ${OBJDIR}

${OUTDIR}:
	${MKDIR} ${OUTDIR}
	
${OBJDIR}:
	${MKDIR} ${OBJDIR}

%.o: %.cpp
	$(CC) $(CFLAGS) $< -o ${OBJDIR}/$@