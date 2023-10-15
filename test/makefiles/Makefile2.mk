../testbin/binaryf : binaryf.o binaryf_test.o
	clang -o ../testbin/binaryf binaryf.o binaryf_test.o -lm

binaryf.o : ../../src/binaryf.c 
	clang -c ../../src/binaryf.c

binaryf_test.o : ../binaryf_test.c 
	clang -c ../binaryf_test.c

clean :
	rm binaryf_test.o binaryf.o
