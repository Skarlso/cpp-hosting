CC= g++
CFLAGS= -g -c -Wall -std=c++14 -stdlib=libc++
LDFLAGS= -L. 
SOURCES= hosting/hosting.cpp
INCLUDES= -I.
OBJECTS= $(SOURCES:.cpp=.o)
TARGET= host
all: $(SOURCES) $(TARGET)
$(TARGET): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@
.cpp.o:
	$(CC) $(CFLAGS) $(INCLUDES) $< -o $@
clean:
	rm -rf $(OBJECTS) $(TARGET)
