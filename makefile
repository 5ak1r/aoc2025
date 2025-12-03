CXX := g++

SRC := src/day03.cpp \
	$(wildcard src/helpers/*.cpp)

TARGET := day03.exe

$(TARGET):
	$(CXX) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET)