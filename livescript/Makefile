all: $(patsubst %.ls, %.js, $(wildcard *.ls))
%.js: %.ls
	lsc -c $<

clean:
	rm -f *.js
