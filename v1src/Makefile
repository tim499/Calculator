source = src/typeInput.c src/decimalf.c \
		 src/decInput.c src/binInput.c \
		 src/binaryf.c
objects = typeInput.o decimalf.o decInput.o binInput.o \
				  binaryf.o

CC = clang

flags = -Wall -Wextra -Werror

.PHONY : clean install

CCalculator : main.o $$HOME/.config/CCalculator/lib/libfconv.so
	$(CC) -g3 -o  CCalculator main.o $$HOME/.config/CCalculator/lib/libfconv.so\
		-Wl,-rpath,$$HOME/.config/CCalculator/lib/libfconv.so -lm

main.o : src/main.c lib/fsyscal.h lib/fconv.h
	$(CC) -c -g3 $(flags) src/main.c 

$$HOME/.config/CCalculator/lib/libfconv.so: $(objects) 
	$(CC) -shared -o $$HOME/.config/CCalculator/lib/libfconv.so $(objects)

$(objects) : $(source) lib/fconv.h lib/fsyscal.h
	$(CC) -c -g3 $(flags) -fpic $(source)

install : 
	install ./CCalculator /usr/bin

clean :
	rm *.o
