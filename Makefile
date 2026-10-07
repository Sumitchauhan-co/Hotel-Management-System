CXX = g++
CXXFLAGS = -std=c++17 -Wall -I./files.h

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
TARGET = hotel_app.exe

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) -o $@ $^

files.cpp/%.o: files.cpp/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	del /f /q files.cpp\*.o $(TARGET) 2>nul || rm -f $(OBJ) $(TARGET)
