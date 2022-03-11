OUT := matrix
OBJS := main.o

CXX := g++
CXXFLAGS := -std=c++17

TMP := ._$(OUT)

$(OUT): $(OBJS)
	touch $(TMP).cc
	make $(TMP)
	mv $(TMP) $(OUT)
	rm -f $(TMP)*

$(TMP): $(TMP).cc $(OBJS)

main.o: matrix.hh

%.cc: %.hh
	touch $@
%.hh: %.tt
	touch $@

.PHONY: clean
clean:
	rm -f *.o
	rm -f $(OUT)
	rm -f $(TMP)*
