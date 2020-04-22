cc=g++
target = main
CFLAGS = -W -Wall
object = main.o

all : $(target)

$(target): $(object)
	$(cc) -o $@ $(object)

.PHONY : clean

clean:
	rm -f *.o
	rm -f $(target)
