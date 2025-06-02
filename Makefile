all:
	$(MAKE) -C src/
	$(MAKE) -C vm/

clean:
	rm -rf *.o *.out *.exe 
	$(MAKE) -C src/ clean
	$(MAKE) -C vm/ clean