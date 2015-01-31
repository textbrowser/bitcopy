CFLAGS = -Wall -Wcast-qual -Wconversion -Werror -Wstrict-overflow=5 \
	 -pedantic -std=c99

all:
	$(CC) $(CFLAGS) -o bitcopy bitcopy.c

clean:
	rm -f *~
	rm -f bitcopy

distclean: clean purge

purge:
	rm -f *~
