sort: main.o pars_args.o cmpfunc.o
	gcc main.o pars_args.o cmpfunc.o -o sort -std=c99

main.o: main.c
	gcc main.c -c -o main.o -std=c99

pars_args.o: pars_args.c pars_args.h
	gcc pars_args.c -c -o pars_args.o -std=c99

cmpfunc.o: cmpfunc.c cmpfunc.h
	gcc cmpfunc.c -c -o cmpfunc.o -std=c99
