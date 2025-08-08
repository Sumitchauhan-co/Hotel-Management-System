CXX = g++
CXXFLAGS = -std=c++17 -Wall -I./files.h
vpath %.cpp files.cpp

SRC = \
    files.cpp/main.cpp \
    files.cpp/application.cpp \
    files.cpp/customer.cpp \
    files.cpp/errorHandling.cpp \
    files.cpp/room.cpp \
    files.cpp/booking.cpp \
    files.cpp/billManager.cpp \
    files.cpp/order.cpp \
    files.cpp/storable.cpp 

OBJ = $(SRC:.cpp=.o)
TARGET = hotel_app

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)
