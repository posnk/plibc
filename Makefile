#
# 'make depend' uses makedepend to automatically generate dependencies 
#               (dependencies are added to end of Makefile)
# 'make'        build executable file 'mycc'
# 'make clean'  removes all .o and executable files
#
TARGET=i386-pc-posnk

# define the C compiler to use
CC = @echo " [  CC  ]	" $< ; $(TARGET)-gcc
LD = @echo " [  LD  ]	" $@ ; $(TARGET)-gcc
AR = @echo " [  AR  ]   " $@ ; $(TARGET)-ar
RL = @echo " [RANLIB]   " $@ ; $(TARGET)-ranlib

# define the program name and path
PROGNAME=libc.a
PROGPATH=/usr/lib/libc.a

# define any compile-time flags
CFLAGS = -Wall -g

# define any directories containing header files other than /usr/include
#
INCLUDES = -Iinclude

# define library paths in addition to /usr/lib
#   if I wanted to include libraries not in /usr/lib I'd specify
#   their path using -Lpath, something like:
LFLAGS = 

ARFLAGS = rcs

# define any libraries to link into executable:
#   if I want to link in libraries (libx.so or libx.a) I use the -llibname 
#   option, something like (this will link in libmylib.so and libm.so:
LIBS = -lgcc

# define the C source files
OBJS = $(BUILDDIR)stdlib/base64.o \
	$(BUILDDIR)stdlib/math.o \
	$(BUILDDIR)stdlib/strtoint.o \
	$(BUILDDIR)string/memcpy.o \
	$(BUILDDIR)string/memcmp.o \
	$(BUILDDIR)string/memmove.o \
	$(BUILDDIR)string/memset.o \
	$(BUILDDIR)string/memchr.o \
	$(BUILDDIR)string/strcpy.o \
	$(BUILDDIR)string/strcmp.o \
	$(BUILDDIR)string/strlen.o \
	$(BUILDDIR)string/strchr.o \
	$(BUILDDIR)string/strcat.o \
	$(BUILDDIR)string/strspn.o \
	$(BUILDDIR)string/strdup.o \
	$(BUILDDIR)string/strncat.o \
	$(BUILDDIR)string/strncmp.o \
	$(BUILDDIR)string/strncpy.o \
#	$(BUILDDIR)nonstd/numfmt.o \
#	$(BUILDDIR)stdio/printf.o \
#$(BUILDDIR)file.o \
	
# define the C object files 
#
# This uses Suffix Replacement within a macro:
#   $(name:string1=string2)
#         For each word in 'name' replace 'string1' with 'string2'
# Below we are replacing the suffix .c of all words in the macro SRCS
# with the .o suffix
#
all:	$(BUILDDIR)$(PROGNAME)

$(BUILDDIR)$(PROGNAME): $(OBJS)
	$(AR) $(ARFLAGS) $(BUILDDIR)$(PROGNAME) $(OBJS)
	$(RL) $(BUILDDIR)$(PROGNAME)

install: $(BUILDDIR)$(PROGNAME)
	cp $(BUILDDIR)$(PROGNAME) $(DESTDIR)$(PROGPATH)
	cp -r include/* $(DESTDIR)/usr/include/	

.PHONY: depend clean

# this is a suffix replacement rule for building .o's from .c's
# it uses automatic variables $<: the name of the prerequisite of
# the rule(a .c file) and $@: the name of the target of the rule (a .o file) 
# (see the gnu make manual section about automatic variables)
$(BUILDDIR)%.o: src/%.c
	@cd src/;find -type d -links 2 -exec mkdir -p "$(BUILDDIR){}" \; 2> /dev/null
	$(CC) $(CFLAGS) $(INCLUDES) -c $<  -o $@

clean:
	$(RM) $(BUILDDIR)*.o $(BUILDDIR)*~ $(BUILDDIR)$(PROGNAME)

depend: $(SRCS)
	makedepend $(INCLUDES) $^

# DO NOT DELETE THIS LINE -- make depend needs it

