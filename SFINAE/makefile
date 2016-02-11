CXXFLAGS += -I. -Igmock/include -std=c++14 -Wpedantic -Wall -Wextra

HEADER_FILES = $(wildcard *.h)
COMPILED_HEADER_FILES = $(patsubst %.h,%.compiled_h,$(HEADER_FILES))
CPP_FILES = $(wildcard *.cpp)
GMOCK_FILES = gmock/gmock-gtest-all.cc gmock/gmock_main.cc

.PHONY: test.output
test.output: test makefile
	@./$< --gtest_shuffle

test: makefile $(CPP_FILES) $(COMPILED_HEADER_FILES)
	@$(CXX) $(CXXFLAGS) -O $(GMOCK_FILES) $(CPP_FILES) -pthread -o $@


%.compiled_h: %.h
	@$(CXX) -x c++ $(CXXFLAGS) -c -o $@ $<
