include ../mak/make.settings

OBJDIR = $(TOPDIR)/obj/openobjs
INCLUDEDIR = -I../include

OBJS = main.o \
       csopen.o \

APP = $(BINDIR)/open

VPATH = ../include:$(LIBDIR):$(OBJDIR)

.PHONY: all dirs clean

all: dirs $(APP)

dirs:
	if [ -d $(OBJDIR) ] ; then true; else mkdir -p $(OBJDIR) ; fi; \
	if [ -d $(BINDIR) ] ; then true; else mkdir -p $(BINDIR) ; fi;

$(APP): $(OBJS)
	$(CC) $(EXE_LINK_FLAGS) -L$(LIBDIR) -o $@ $(OBJDIR)/* -lapue 

$(OBJS): %.o:%.c
	$(CC) $(EXE_COMPILE_FLAGS) $(INCLUDEDIR) $< -o $(OBJDIR)/$@

clean:
	-rm -rf $(OBJDIR)/*
	-rm $(APP)