CFLAGS= -Wshadow -Winit-self -Wredundant-decls -Wcast-align -Wundef -Wfloat-equal -Winline -Wunreachable-code -Wmissing-declarations -Wmissing-include-dirs -Wswitch-enum -Wswitch-default -Weffc++ -Wmain -Wextra -Wall -g -pipe -fexceptions -Wcast-qual -Wconversion -Wctor-dtor-privacy -Wempty-body -Wformat-security -Wformat=2 -Wignored-qualifiers -Wlogical-op -Wno-missing-field-initializers -Wnon-virtual-dtor -Woverloaded-virtual -Wpointer-arith -Wsign-promo -Wstack-usage=8192 -Wstrict-aliasing -Wstrict-null-sentinel -Wtype-limits -Wwrite-strings -Werror=vla -D_DEBUG -D_EJUDGE_CLIENT_SIDE
IFLAGS=-I./headers/ -I./testing/

all: main

main: obj/main.o obj/solve_quadratic.o obj/utils.o obj/tester.o
	g++ obj/main.o obj/solve_quadratic.o obj/utils.o obj/tester.o -o main

obj/main.o: main.cpp
	g++ -c $(IFLAGS) $(CFLAGS) main.cpp -o obj/main.o

obj/solve_quadratic.o: src/solve_quadratic.cpp
	g++ -c $(IFLAGS) $(CFLAGS) src/solve_quadratic.cpp -o obj/solve_quadratic.o

obj/utils.o: src/utils.cpp
	g++ -c $(IFLAGS) $(CFLAGS) src/utils.cpp -o obj/utils.o

obj/tester.o: testing/tester.cpp
	g++ -c $(IFLAGS) $(CFLAGS) testing/tester.cpp -o obj/tester.o
