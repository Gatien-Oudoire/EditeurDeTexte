.DEFAULT_GOAL := generate

generate:
	g++ -c -Wall main.cpp
	g++ -c -Wall fichiers.cpp
	g++ -c -Wall design.cpp
	g++ main.o fichiers.o design.o -o edt