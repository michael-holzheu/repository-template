include ../common.mak

ALL_CPPFLAGS += -g

TARGETS = example

all: $(TARGETS)

libs =	\
	$(rootdir)/libexample/libexample.a \
	$(rootdir)/libutil/libutil.a

example: example.o opts.o $(libs)

install: all

clean:
	rm -f *.o *~ $(TARGETS)

.PHONY: all install clean
