ConvSource = src/conv_input.c
ConvObject = conv_input.o

SysSource = src/helper.c src/stackf.c
SysObject = helper.o stackf.o

CC = clang

flags = -Wall -Wextra -Werror

.PHONY : clean install

CCalculator : main.o /lib64/CCalculator/libfconv.so /lib64/CCalculator/libfsys.so
	$(CC) -g3 -o  CCalculator main.o /lib64/CCalculator/libfconv.so /lib64/CCalculator/libfsys.so\
		-Wl,-rpath,/lib64/CCalculator/ -lm

main.o : src/main.c lib/fsyscal.h lib/fconv.h
	$(CC) -c -g3 $(flags) src/main.c 

/lib64/CCalculator/libfsys.so : $(SysObject) 
	$(CC) -shared -o /lib64/CCalculator/libfsys.so $(SysObject)

/lib64/CCalculator/libfconv.so: $(ConvObject) 
	$(CC) -shared -o /lib64/CCalculator/libfconv.so $(ConvObject)

$(ConvObject) : $(ConvSource) lib/fconv.h lib/fsyscal.h
	$(CC) -c -g3 $(flags) -fpic $(ConvSource)

$(SysObject) : $(SysSource) lib/fsyscal.h
	$(CC) -c -g3 $(flags) -fpic $(SysSource)

install : 
	install ./CCalculator /usr/bin

clean :
	rm *.o
