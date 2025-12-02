CXX := g++

SRC := src/day2.cpp \
  $(wildcard src/*.cpp) \
	$(wildcard src/helpers/*.cpp)

TARGET := day2.exe

$(TARGET):
	$(CXX) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET)