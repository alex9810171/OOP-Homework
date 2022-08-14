#
#  Sample Makefile for C++ programs 
#  Designed for the OOP class
#  by Tsai-Yen Li (li@cs.nccu.edu.tw) 08/08/96
#

# the name of this package. 
# The library and tar file, if any, will be named after it.
PACKAGE  = Cards
# The executable program
TARGET   = CardTest
# The C++ source programs (.cc) [multiple files]
SOURCES  = AnsiPrint Cards 
# The C++ source program for testing your implementation
TEST     = CardTest

O_DIR    = O_$(HOSTTYPE)
SYSDIR   = /usr/local
CLASSDIR = $(SYSDIR)/class/oop
BASEDIR  = .
INCDIR   = $(BASEDIR)/include #-I$(SYSDIR)/lib/g++-include 
LIBDIR   = -L$(BASEDIR)/lib -L/usr/openwin/lib -L/usr/ucblib
LIBS     = $(LIBDIR) -lm -lc #-lucb  -liostream

# You may not need to modify anything below

CXX      = g++
CXXFLAGS = -g -Wall -I$(INCDIR) #-D__STDC__ 
TARG     = $(TARGET)_$(HOSTTYPE)
LIB      = lib$(PACKAGE)_$(HOSTTYPE).a

SRCS     = ${SOURCES:%=%.cc}
OBJS     = ${SRCS:%.cc=$(O_DIR)/%.o}
HEADERS  = ${SRCS:%.cc=%.h} Cards.h
TESTSRC  = ${TEST:%=%.cc}
TESTOBJ  = ${TESTSRC:%.cc=$(O_DIR)/%.o}
#MAKEDEP  = $(CLASSDIR)/bin/makedepend
MAKEDEP  = makedepend

$(TARG) : $(O_DIR) $(OBJS) $(TESTOBJ)
	$(CXX) -o $@ $(CXXFLAGS) $(OBJS) $(TESTOBJ) $(LIBS) 

$(O_DIR) :
	mkdir $@

lib : $(O_DIR) $(LIB)
	@echo $@ Built

$(LIB) : $(OBJS)
	rm -f $(LIB)
	ar cr $@ $(OBJS)
	ranlib $@

$(O_DIR)/%.o: %.cc
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean: 
	rm -f $(OBJS) $(TESTOBJ) $(TARG) core* *~ Makefile.bak 
	rmdir $(O_DIR)

tags: 
	etags $(SRCS) $(HEADERS)

ztar:
	tar zcvf $(PACKAGE).tgz Makefile $(SRCS) $(HEADERS) $(TESTSRC) 

ci:
	ci -l Makefile $(SRCS) $(HEADERS) $(TESTSRC) 

depend : 
	$(MAKEDEP) -p$(O_DIR)/ -I$(INCDIR) $(SRCS) $(TESTSRC)

# DO NOT DELETE THIS LINE -- make depend depends on it.

O_sun4/AnsiPrint.o: /usr/include/stdlib.h /usr/include/sys/feature_tests.h
O_sun4/AnsiPrint.o: AnsiPrint.h
O_sun4/Cards.o: /usr/include/stdio.h /usr/include/sys/feature_tests.h
O_sun4/Cards.o: /usr/include/stdlib.h /usr/include/assert.h Cards.h
O_sun4/Cards.o: AnsiPrint.h
O_sun4/CardTest.o: /usr/include/stdio.h /usr/include/sys/feature_tests.h
O_sun4/CardTest.o: /usr/include/stdlib.h /usr/include/assert.h AnsiPrint.h
O_sun4/CardTest.o: Cards.h
