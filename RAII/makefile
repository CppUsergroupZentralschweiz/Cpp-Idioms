CXXFLAGS += -I. -std=c++14 -Wpedantic -Wall -Wextra

HEADER_FILES = $(wildcard *.h)
COMPILED_HEADER_FILES = $(patsubst %.h,%.compiled_h,$(HEADER_FILES))
CPP_FILES = $(wildcard *.cpp)

.PHONY: main.output
main.output: main makefile
	@./$<

main: makefile $(CPP_FILES) $(COMPILED_HEADER_FILES)
	@$(CXX) $(CXXFLAGS) -O $(CPP_FILES) -o $@


%.compiled_h: %.h
	@$(CXX) -x c++ $(CXXFLAGS) -c -o $@ $<
