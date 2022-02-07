exec = sbobos
sources = $(wildcard src/*.c)
objects = $(sources:.c=.o)
flags = -g -Wall  -lm  -ldl -fPIC  -Wl,--export-all-symbols 
$(exec) : $(objects)
	gcc $(objects) $(flags) -o $(exec)

%.o: %.c include/%.h
	gcc -c $(flags) $< -o $@

clean:
	-rm *.out
	-rm *.o
	-rm *.a
	-rm *.s
	-rm *.s.txt
	-rm src/*.o

lint:
	clang-tidy src/*.c src/include/*.h