/usr/bin/CCalculator : main.o
	clang -o /usr/bin/CCalculator main.o

main.o : src/main.c lib/fsyscal.h
	clang -c -g3 -Wall -Wextra -Werror src/main.c 

clean :
	rm *.o
