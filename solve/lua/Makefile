ALL :
	make heap
	make exeter
	make bogomolny
	make spread
	make trotter
	make select
	make factoradic 

% : %.lua
	../../bin/suite "luajit ./$<" 11

clean : 
	rm permute.out
