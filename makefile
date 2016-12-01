# edit this makefile so that running make compiles your enigma program

CC=g++
CFLAGS=-c -pedantic -Wall -Werror
SOURCE=Main.o Rotor.o Plugboard.o Reflector.o Parser.o LetterNumberConverter.o

all: enigma

enigma: $(SOURCE)
	$(CC) -o enigma $(SOURCE)

Main.o: Main.cpp Rotor.hpp Plugboard.hpp Reflector.hpp Parser.hpp LetterNumberConverter.hpp
	$(CC) $(CFLAGS) Main.cpp

Rotor.o: Rotor.hpp Rotor.cpp
	$(CC) $(CFLAGS) Rotor.cpp

Plugboard.o: Plugboard.hpp Plugboard.cpp
	$(CC) $(CFLAGS) Plugboard.cpp

Reflector.o: Reflector.hpp Reflector.cpp
	$(CC) $(CFLAGS) Reflector.cpp

Parser.o: Parser.hpp Parser.cpp
	$(CC) $(CFLAGS) Parser.cpp

LetterNumberConverter.o: LetterNumberConverter.hpp LetterNumberConverter.cpp
	$(CC) $(CFLAGS) LetterNumberConverter.cpp

clean:
	rm -rf enigma *.o enigma.exe

.PHONY: all clean
