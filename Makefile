CFLAGS = -Wall \
	 -Wcast-qual \
	 -Wconversion \
	 -Werror \
	 -Wshadow \
	 -Wsign-conversion \
	 -Wstrict-overflow=5 \
	 -pedantic \
	 -std=c99
DEFINES = -DBITCOPY_WITH_PTHREAD

all:
	$(CC) $(CFLAGS) $(DEFINES) -o bitcopy bitcopy.c -lpthread

clean:
	rm -f bitcopy

distclean: clean purge

purge:
	rm -f *~
