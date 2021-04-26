all: MWP
#****************<Make_Link_Compile>****************
MWP: main.o  MyFileStream.o Main.o
	g++ main.o MyFileStream.o Main.o -o MWP

main.o: main.cpp MainHeader.hpp
	g++ -c main.cpp -o main.o

MyFileStream.o: MyFileStream.cpp MainHeader.hpp
	g++ -c MyFileStream.cpp -o MyFileStream.o

Main.o: Main.cpp MainHeader.hpp
	g++ -c Main.cpp -o Main.o

#****************<Clear>****************
clean:
	rm *.o MWP