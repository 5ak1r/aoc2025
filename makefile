CXX := g++

SRC := $(wildcard src/*.cpp) \
	$(wildcard src/utils/*.cpp)

TARGET := main.out

$(TARGET):
	$(CXX) $(SRC) -o $(TARGET) -O3

run:
	make && ./main.out

clean:
	rm -f $(TARGET)