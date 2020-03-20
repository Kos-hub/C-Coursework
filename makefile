all: clean find

find:
	cl find.c substring.c

clean:
	del *.obj
	del *.exe