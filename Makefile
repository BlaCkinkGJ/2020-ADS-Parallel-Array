CC=C:\Program Files (x86)\CodeBlocks\MinGW\bin\x86_64-w64-mingw32-gcc.exe
CFLAGS=-g -Wall -Werror
# LDFLAGS=
# LDLIBS=
OBJS=main.o parallel-improve.o parallel-trivial.o
TARGET=a.exe

all: $(TARGET)

clean:
	del *.o 
	del $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $@ $(OBJS)
