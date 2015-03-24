all: result.32 result.64

result.%: main.%.o
	objdump -rd $< > $@
main.32.o: main.c
	gcc -m32 -c $< -o $@
main.64.o: main.c
	gcc -c $< -o $@

clean:
	rm -f result.* *.o
