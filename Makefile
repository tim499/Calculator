dFuncSource = src/operand_input.c src/operator_input.c
dFuncObject = operand_input.o operator_input.o
dFuncSourceConv = src/typeInput.c src/decimalf.c src/decInput.c src/binInput.c \
				  src/binaryf.c
dFuncObjectConv = typeInput.o decimalf.o decInput.o binInput.o \
				  binaryf.o

bin/calculator : src/calculator.o libs/libfsyscal.so.3 libs/libfconv.so.1
	clang -g3 -o bin/calculator src/calculator.o /home/tim/Рабочий\ стол/C/Calculator/libs/libfsyscal.so.3 \
		/home/tim/Рабочий\ стол/C/Calculator/libs/libfconv.so.1 -Wl,-rpath,/home/tim/Рабочий\ стол/C/Calculator/libs -lm

src/calculator.o : src/calculator.c libs/fsyscal.h libs/fsqmath.h libs/fconv.h
	clang -g3 -c src/calculator.c -o src/calculator.o

$(dFuncObject) : $(dFuncSource) libs/fsyscal.h
	@cd src/
	clang -g3 -c -fpic $(dFuncSource)
	@cd ../

$(dFuncObjectConv) : $(dFuncSourceConv) libs/fconv.h libs/fsyscal.h
	@cd src/
	clang -g3 -c -fpic $(dFuncSourceConv)
	@cd ../

libs/libfsyscal.so.3 : $(dFuncObject)
	clang -shared -o libs/libfsyscal.so.3 $(dFuncObject)

libs/libfconv.so.1 : $(dFuncObjectConv)
	clang -shared -o libs/libfconv.so.1 $(dFuncObjectConv)

clean :
	rm $(dFuncObject) $(dFuncObjectConv) src/calculator.o
