bin_PROGRAMS = parser
parser_SOURCES = parser.c

if WESTMERE
westmere/parser.$(OBJEXT) : CFLAGS += -march=westmere
parser_SOURCES += westmere/parser.c
endif

if HASWELL
haswell/parser.$(OBJEXT) : CFLAGS += -march=haswell
parser_SOURCES += haswell/parser.c
endif
