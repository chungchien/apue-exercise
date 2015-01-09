# lib/Makefile --- for make libapue.a

include ../mak/make.settings

OBJDIR = $(TOPDIR)/obj/apueobjs
INCLUDEDIR = -I../include


OBJECTS := \
  error.o \
  errorlog.o \
  s_pipe.o \
  serv_listen.o \
  serv_accept.o \
  cli_conn.o \
  writen.o \
  readn.o \
  send_fd.o \
  send_err.o \
  recv_fd.o \
  buf_args.o \
  recv_ufd.o \
  daemonize.o \

VPATH = ../include:$(LIBDIR):$(OBJDIR)

LIBAPUE = $(LIBDIR)/libapue$(LIB_SUFFIX)

.PHONY: all clean
all: dirs $(LIBAPUE)

dirs:
	if [ -d $(OBJDIR) ] ; then true; else mkdir -p $(OBJDIR) ; fi; \
	if [ -d $(LIBDIR) ] ; then true; else mkdir -p $(LIBDIR) ; fi;

$(LIBAPUE): $(OBJECTS)
	$(AR) $(LIB_LINK_FLAGS) $@ $(OBJDIR)/*

$(OBJECTS): %.o:%.c
	$(CC) $(LIB_COMPILE_FLAGS) $(INCLUDEDIR) $< -o $(OBJDIR)/$@

$(OBJECTS): apue.h

clean:
	-rm -rf $(OBJDIR)/*
	-rm $(LIBAPUE)
