../bin/sorting: main.o pars_args.o cmpfunc.o getbuf.o rndsort.o
	gcc main.o pars_args.o cmpfunc.o getbuf.o rndsort.o -o ../bin/sorting -std=c99

main.o: main.c
	gcc main.c -c -o main.o -std=c99

pars_args.o: pars_args.c pars_args.h
	gcc pars_args.c -c -o pars_args.o -std=c99

cmpfunc.o: cmpfunc.c cmpfunc.h
	gcc cmpfunc.c -c -o cmpfunc.o -std=c99

getbuf.o: getbuf.c getbuf.h
	gcc getbuf.c -c -o getbuf.o -std=c99

rndsort.o: rndsort.c rndsort.h
	gcc rndsort.c -c -o rndsort.o -std=c99

clean:
	rm *.o ../bin/sorting

install:
	cp ../bin/sorting /usr/local/bin/sorting

uninstall:
	rm -f /usr/local/bin/sorting
