CXX = g++
CXXFLAGS = -std=c++17 -Iinclude -Wall -Wextra -pedantic
LDFLAGS = -ltag

SRC_DIR = src
BUILD_DIR = build

SRCS = $(SRC_DIR)/main.cpp $(SRC_DIR)/ID3Reader.cpp
OBJS = $(BUILD_DIR)/main.o $(BUILD_DIR)/ID3Reader.o
TARGET = app

all: $(TARGET)

$(TARGET) : $(OBJS)
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDFLAGS)

$(BUILD_DIR)/main.o: $(SRC_DIR)/main.cpp
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIR)/ID3Reader.o: $(SRC_DIR)/ID3Reader.cpp
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET)
	rm -rf $(BUILD_DIR)

.PHONY: all clean
