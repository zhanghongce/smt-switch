CXX=g++

main: unit-tests.cpp
	$(CXX) -std=c++17 -o unit-tests.out -I/usr/include/c++/8/ unit-tests.cpp /home/makaim/repos/boolector/deps/btor2tools/build/btor2parser.o /usr/local/lib/libboolector.a /home/makaim/repos/boolector/deps/lingeling/liblgl.a -lm -lpthread -lcvc4

main-debug: unit-tests.cpp
	$(CXX) -g -std=c++17 -o unit-tests.out -I/usr/include/c++/8/ unit-tests.cpp /home/makaim/repos/boolector/deps/btor2tools/build/btor2parser.o /usr/local/lib/libboolector.a /home/makaim/repos/boolector/deps/lingeling/liblgl.a -lm -lpthread -lcvc4

two_base_destructors: term_impl.cpp two_base_destructors.cpp
	$(CXX) -std=c++17 term_impl.cpp two_base_destructors.cpp -o test.out -lcvc4

testmake: term_impl.cpp comparison.cpp
	$(CXX) -std=c++17 term_impl.cpp comparison.cpp -o comparison.out -lcvc4

btor: btor-main.cpp
	$(CXX) -std=c++17 -o btor-main.out btor-main.cpp /home/makaim/repos/boolector/deps/btor2tools/build/btor2parser.o /usr/local/lib/libboolector.a /home/makaim/repos/boolector/deps/lingeling/liblgl.a -lm -lpthread

clean:
	rm -rf *.out *.o
