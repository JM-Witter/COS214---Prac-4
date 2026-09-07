all:
	g++ -std=c++11 -Werror -Wall *.cpp -o taskforge

run: all
	./taskforge

memory:
	g++ -std=c++11 -Werror -Wall *.cpp -o taskforge
	valgrind --leak-check=full --show-leak-kinds=all ./taskforge
