CXX := g++

SRC := $(wildcard src/*.cpp) \
	$(wildcard src/helpers/*.cpp)

TARGET := main.out

$(TARGET):
	$(CXX) $(SRC) -o $(TARGET)

run:
	make && ./main.out

clean:
	rm -f $(TARGET)