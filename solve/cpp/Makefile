ALL :
	make heap
	make exeter
	make bogomolny
	make spread
	make trotter
	make select
	make factoradic

% : %.cc common.hh common.cc
	g++ -Wall $< common.cc -o $@
	../../bin/suite ./$@ 11
	rm -f $@ $@.exe
