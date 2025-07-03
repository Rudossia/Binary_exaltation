CXX = g++
CXXFLAGS = -std=c++20 -O2

all: main_mod main_full

main_mod: main.cpp pow.h pow_mod.cpp
	$(CXX) $(CXXFLAGS) -o $@ main.cpp pow_mod.cpp

main_full: main.cpp pow.h pow_full.cpp
	$(CXX) $(CXXFLAGS) -DUSE_BIGINT -o $@ main.cpp pow_full.cpp -lboost_system
