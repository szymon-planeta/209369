#
#  To sa opcje dla kompilacji
#
CPPFLAGS= -c -g -Iinc -Wall -pedantic

__start__: benchmark
	./benchmark

benchmark: obj/main.o obj/program.o obj/benchmark.o obj/tabx2.o
	g++ -Wall -pedantic -o benchmark obj/main.o obj/tabx2.o  \
					obj/program.o obj/benchmark.o	

obj/main.o: src/main.cpp inc/program.hh	inc/benchmark.hh inc/tabx2.hh	
	g++ ${CPPFLAGS} -o obj/main.o src/main.cpp

obj/tabx2.o: src/tabx2.cpp inc/tabx2.hh 
	g++ ${CPPFLAGS} -o obj/tabx2.o src/tabx2.cpp

obj/benchmark.o: src/benchmark.cpp inc/benchmark.hh 
	g++ ${CPPFLAGS} -o obj/benchmark.o src/benchmark.cpp

obj/program.o: src/program.cpp inc/program.hh
	g++ ${CPPFLAGS} -o obj/program.o src/program.cpp

clean:
	rm -f obj/*.o benchmark

doc:
	cd ../dox && make

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
	@echo "  make doc       # generuje dokumentacje w dox/html"
	@echo