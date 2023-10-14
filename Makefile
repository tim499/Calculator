dFuncSource = operand_input.c operator_input.c
dFuncObject = operand_input.o operator_input.o
dFuncSourceConv = typeInput.c decimalf.c decInput.c binInput.c \
				  binaryf.c
dFuncObjectConv = typeInput.o decimalf.o decInput.o binInput.o \
				  binaryf.o

bin/calculator : calculator.o libs/libfsyscal.so.3 libs/libfconv.so.1
	clang -g3 -o bin/calculator calculator.o /home/tim/Рабочий\ стол/C/Calculator/libs/libfsyscal.so.3 \
		/home/tim/Рабочий\ стол/C/Calculator/libs/libfconv.so.1 -Wl,-rpath,/home/tim/Рабочий\ стол/C/Calculator/libs -lm

calculator.o : calculator.c libs/fsyscal.h libs/fsqmath.h libs/fconv.h
	clang -g3 -c calculator.c

$(dFuncObject) : $(dFuncSource) libs/fsyscal.h
	clang -g3 -c -fpic $(dFuncSource)

$(dFuncObjectConv) : $(dFuncSourceConv) libs/fconv.h libs/fsyscal.h
	clang -g3 -c -fpic $(dFuncSourceConv)

libs/libfsyscal.so.3 : $(dFuncObject)
	clang -shared -o libs/libfsyscal.so.3 $(dFuncObject)

libs/libfconv.so.1 : $(dFuncObjectConv)
	clang -shared -o libs/libfconv.so.1 $(dFuncObjectConv)

clean :
	rm $(dFuncObject) $(dFuncObjectConv) calculator.o
