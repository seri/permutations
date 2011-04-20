ALL :
	make Builtin
	make Inject
	make Select

% : Common.hs %.hs 
	ghc -o $@ $^ 
	../../bin/suite ./$@ 11
	rm -f $@ Common.hi Common.o $@.hi $@.o $@.exe

clean : 
	rm -f *.hi *.o *.exe
