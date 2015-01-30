all:
	$(CC) $(CFLAGS) -o bitcopy bitcopy.c

clean:
	rm -f *~
	rm -f bitcopy

distclean: clean purge

purge:
	rm -f *~
