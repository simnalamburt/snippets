# vars
CPP = clang++
CPPFLAGS = -Wall -std=c++1y -O3


# make somethine
%: %.cpp
	$(CPP) $(CPPFLAGS) $< -o $@


# clean
BINARIES = $(patsubst %.cpp, %, $(wildcard *.cpp))

clean:
	rm -f $(BINARIES)

.PHONY: clean
.PRECIOUS: $(BINARIES)
