TARGET=game
MODULES=game.o Board.o Piece.o ioutil.o Pawn.o Rook.o Bishop.o Knight.o Queen.o King.o
MODULESHEADER=game.h Board.h Piece.h ioutil.h Pawn.h Rook.h Bishop.h Knight.h Queen.h King.h
MODULETEST1=test_Board.o Board.o Piece.o Pawn.o	Rook.o Bishop.o Knight.o Queen.o King.o
MODULETEST2=test_Piece.o Piece.o Board.o Pawn.o Rook.o Bishop.o Knight.o Queen.o King.o
CPPFLAGS=-ansi -pedantic-errors -Wall -Wconversion
GCOVFLAGS=-fprofile-arcs -ftest-coverage
GTFLAGS=-lgtest -lgtest_main
TESTS1=test_Board
TESTS2=test_Piece

$(TARGET): $(MODULES)
	g++ $(CPPFLAGS) $(GCOVFLAGS) $(GTFLAGS) $(MODULES) -o $(TARGET)

$(TESTS1): $(MODULETEST1)
	g++ $(GTFLAGS) $(GCOVFLAGS) $(MODULETEST1) -o $(TESTS1)
	$(TESTS1)
	gcov $(TESTS1).cpp 2> /dev/null | grep -A 1 $(TESTS1).cpp

$(TESTS2): $(MODULETEST2)
	g++ $(GTFLAGS) $(GCOVFLAGS) $(MODULETEST2) -o $(TESTS2)
	$(TESTS2)
	gcov $(TESTS2).cpp 2> /dev/null | grep -A 1 $(TESTS2).cpp

clean:
	/bin/rm -f *~ *# *.o $(TARGET) $(TESTS1) $(TESTS2) *.gcda *.gcov *.gcno

all: clean $(TARGET) $(TESTS1) $(TESTS2) 

$(TARGET).o: $(TARGET).cpp $(MODULESHEADER)
	g++ $(CPPFLAGS) -c $(TARGET).cpp

Piece.o : Piece.cpp Piece.h
	g++ $(CPPFLAGS) -c Piece.cpp

Board.o: Board.cpp Board.h Piece.h
	g++ $(CPPFLAGS) -c Board.cpp

ioutil.o: ioutil.cpp ioutil.h
	g++ $(CPPFLAGS) -c ioutil.cpp

Pawn.o:	Pawn.cpp Pawn.h Piece.h
	g++ $(CPPFLAGS) -c Pawn.cpp

Rook.o: Rook.cpp Rook.h Piece.h
	g++ $(CPPFLAGS) -c Rook.cpp

Knight.o: Knight.cpp Knight.h Piece.h
	g++ $(CPPFLAGS) -c Knight.cpp

Bishop.o: Bishop.cpp Bishop.h Piece.h
	g++ $(CPPFLAGS) -c Bishop.cpp

Queen.o: Queen.cpp Queen.h Piece.h
	g++ $(CPPFLAGS) -c Queen.cpp

King.o: King.cpp King.h Piece.h
	g++ $(CPPFLAGS) -c King.cpp

$(TESTS1).o: $(TESTS1).cpp Board.h Piece.h Pawn.h
	g++ $(CPPFLAGS) $(GCOVFLAGS) -c $(TESTS1).cpp

$(TESTS2).o: $(TESTS2).cpp Piece.h Board.h 
	g++ $(CPPFLAGS) $(GCOVFLAGS) -c $(TESTS2).cpp
