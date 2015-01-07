INCLUDE_DIRS += -I../include

CC ?= clang
CFLAGS += -Wall $(INCLUDE_DIRS)
RM ?= $(-rm -rf)

ifeq ($(BUILD_TYPE), Release)
CFLAGS += -O
else
CFLAGS += -g
endif

OBJECTS := error.o s_pipe.o serv_listen.o serv_accept.o cli_conn.o \
           writen.o readn.o send_fd.o send_err.o recv_fd.o

SOURCES := $(OBJECTS:%.o,%.c)

VPATH = ../include

.PHONY: all clean
all: libapue.a

libapue.a: $(OBJECTS)
	$(AR) -cr $@ $(OBJECTS)

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	$(RM) *.o libapue.a

$(OBJECTS): apue.h