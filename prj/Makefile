#
#  To sa opcje dla kompilacji
#
CPPFLAGS= -c -g -Iinc -Wall -pedantic

__start__: benchmark
	./benchmark

benchmark: obj/main.o obj/timer.o obj/benchmark.o
	g++ -Wall -pedantic -o benchmark obj/main.o obj/timer.o obj/benchmark.o

obj/main.o: src/main.cpp inc/ABData/list.hh inc/ABData/abdata.hh inc/ABData/iterable.hh inc/ABData/list.hh inc/ABData/stack.hh inc/ABData/queue.hh inc/Benchmark/timer.hh inc/Benchmark/observer.hh inc/Benchmark/benchmark.hh inc/ABData/sorts.hh inc/ABData/abdatatools.hh inc/ABData/listarray.hh inc/assoctab.hh inc/Trees/trees.hh
	g++ ${CPPFLAGS} -o obj/main.o src/main.cpp

obj/benchmark.o: src/benchmark.cpp inc/Benchmark/benchmark.hh inc/Benchmark/timer.hh
	g++ ${CPPFLAGS} -o obj/benchmark.o src/benchmark.cpp

obj/timer.o: src/timer.cpp inc/Benchmark/timer.hh 
	g++ ${CPPFLAGS} -o obj/timer.o src/timer.cpp

clean:
	rm -f obj/*.o benchmark

doc:
	cd ../dox && make
	cd latex && make

all:
	make clean
	clear
	make

help:
	@echo
	@echo "  Lista podcelow dla polecenia make"
	@echo 
	@echo "        - (wywolanie bez specyfikacji celu) wymusza"
	@echo "          kompilacje i uruchomienie programu."
	@echo "  clean - usuwa produkty kompilacji oraz program"
	@echo "  doc   - powoduje generowanie dokumentacji"
	@echo "  help  - wyswietla niniejszy komunikat"
	@echo
	@echo " Przykladowe wywolania dla poszczegolnych wariantow. "
	@echo "  make           # kompilacja i uruchomienie programu."
	@echo "  make clean     # usuwa produkty kompilacji."
	@echo "  make doc       # generuje dokumentacje w dox/latex"
	@echo