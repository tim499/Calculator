dFuncSource = operand_input.c operator_input.c
dFuncObject = operand_input.o operator_input.o

bin/calculator : calculator.o libs/libfsyscal.so.3
	clang -o bin/calculator calculator.o /home/tim/Рабочий\ стол/C/Calculator/libs/libfsyscal.so.3 -Wl,-rpath,/home/tim/Рабочий\ стол/C/Calculator/libs -lm

calculator.o : calculator.c libs/fsyscal.h 
	clang -c calculator.c

$(dFuncObject) : $(dFuncSource) libs/fsyscal.h
	clang -c -fpic $(dFuncSource)

libs/libfsyscal.so.3 : $(dFuncObject)
	clang -shared -o libs/libfsyscal.so.3 $(dFuncObject)

clean :
	rm $(dFuncObject) calculator.o
