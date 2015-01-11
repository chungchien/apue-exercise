include ../mak/make.settings

OBJDIR = $(TOPDIR)/opendobjs
INCLUDEDIR = -I../include
APP = $(BINDIR)/opend

OBJS = \
	main.o \
	request.o \
	cli_args.o \
	clientopts.o \
	loop.o

VPATH = ../include:$(OBJDIR):$(LIBDIR)

.PHONY: dirs all clean

all: dirs $(APP)

dirs:
	if [ -d $(OBJDIR) ] ; then true ; else mkdir -p $(OBJDIR) ; fi ;
	if [ -d $(BINDIR) ] ; then true ; else mkdir -p $(BINDIR) ; fi ;

$(APP): $(OBJS)
	$(CC) $(EXE_LINK_FLAGS) -L$(LIBDIR) -o $@ $(OBJDIR)/* -lapue

$(OBJS): %.o:%.c
	$(CC) $(EXE_COMPILE_FLAGS) $(INCLUDEDIR) -o $(OBJDIR)/$@ $<

clean:
	-rm -rf $(OBJDIR)
	-rm $(APP)
