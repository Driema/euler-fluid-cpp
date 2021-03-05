build: ./src/*.cpp
	g++ -std=c++17 -c ./src/*.cpp
	mv ./*.o ./obj
	g++ ./obj/*.o -o main -lsfml-graphics -lsfml-window -lsfml-system 
	chmod 755 ./main
	./main
