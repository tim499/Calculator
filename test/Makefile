testbin/decimalf : decimalf.o decimalf_test.o
	clang -o testbin/decimalf decimalf.o decimalf_test.o

decimalf.o : ../src/decimalf.c 
	clang -c ../src/decimalf.c 

decimalf_test.o :decimalf_test.c 
	clang -c decimalf_test.c

clean :
	rm decimalf_test.o decimalf.o
