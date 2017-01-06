# Recursive Wildcard Gather
rwildcard=$(wildcard $1$2) $(foreach d,$(wildcard $1*),$(call rwildcard,$d/,$2))
# ============= #
CC= g++
CFLAGS= -g -c -Wall -std=c++14 -stdlib=libc++
LDFLAGS= -L.
# SOURCES= hosting/hosting.cpp hosting/create_command.cpp hosting/actions.cpp
SOURCES = $(call rwildcard,./,*.cpp)
OBJECTS = $(SOURCES:.cpp=.o)
INCLUDES= -I.
OBJECTS= $(SOURCES:.cpp=.o)
TARGET= bin/host
all: $(SOURCES) $(TARGET)
$(TARGET): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@
.cpp.o:
	$(CC) $(CFLAGS) $(INCLUDES) $< -o $@
clean:
	rm -rf $(OBJECTS) $(TARGET)
