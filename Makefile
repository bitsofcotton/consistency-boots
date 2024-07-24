CXX=	clang++
LD=	${CXX}

# compiler flags.
#CXXFLAGS+=	-std=c++11 -Ofast -gfull -mtune=native
#LDFLAGS+=	-lc++ -static
LDFLAGS+=	-lc++

CLEANFILES= *.o *.dSYM incre

all:		incre
clean:
	@rm -rf ${CLEANFILES}

