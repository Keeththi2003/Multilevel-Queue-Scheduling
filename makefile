CXX = g++
CXXFLAGS = -std=c++11 -Wall -g

TARGET = mlq

all: $(TARGET)

$(TARGET): mlq.o main.o
	$(CXX) $(CXXFLAGS) -o $(TARGET) main.o mlq.o

main.o: main.cpp mlq.h process.h
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o

mlq.o: mlq.cpp mlq.h process.h
	$(CXX) $(CXXFLAGS) -c mlq.cpp -o mlq.o

clean:
	rm -f mlq.o main.o $(TARGET)

run: $(TARGET)
	./$(TARGET)

