CXX = g++
CXXFLAGS = -std=c++17 -Iinclude -Wall -Wextra -pedantic
LDFLAGS = -ltag

SRCS = src/main.cpp src/ID3Reader.cpp
OBJS = $(SRCS:.cpp=.o)
TARGET = app

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean
