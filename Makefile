dFuncSource = src/operand_input.c src/operator_input.c
dFuncObject = operand_input.o operator_input.o

bin/calculator : src/calculator.o libs/libfsyscal.so.3
	clang -o bin/calculator src/calculator.o /home/tim/Рабочий\ стол/C/Calculator/libs/libfsyscal.so.3 \
		-Wl,-rpath,/home/tim/Рабочий\ стол/C/Calculator/libs -lm

calculator.o : calculator.c libs/fsyscal.h 
	clang -c src/calculator.c -o src/calculator.o

$(dFuncObject) : $(dFuncSource) libs/fsyscal.h
	@cd src/
	clang -c -fpic $(dFuncSource)
	@cd ../

libs/libfsyscal.so.3 : $(dFuncObject)
	clang -shared -o libs/libfsyscal.so.3 $(dFuncObject)

clean :
	rm $(dFuncObject) src/calculator.o
