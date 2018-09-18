CC=gcc
SYMBOLS?=
CFLAGS=$(addprefix -D ,${SYMBOLS}) -Wall -Wextra -pedantic -std=c18
VPATH=src/
OBJPATH=objs/
BINPATH=bin/

SRCS=extenint.c
OBJS=$(SRCS:%.c=${OBJPATH}%.o)
HDRS=$(wildcard ${VPATH}*.h)
TARGET?=${BINPATH}extint

ifeq (${DEBUG}, 1)
SYMBOLS+=_DEBUG
endif

.PHONY: all clean debug

all: $(TARGET)

$(TARGET): $(OBJS) $(HDRS)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $^ -o $@ $(LDLIBS)

$(OBJS): $(OBJPATH)%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $<   -o $@

debug:
	DEBUG=1 $(MAKE)

clean:
	$(RM) -r $(OBJPATH) $(BINPATH)


