build:
	g++ -std=c++17 -o trackwatch main.cpp

test:
	g++ -std=c++17 -pthread main_test.cpp -o trackwatch_test && ./trackwatch_test

all: build test

install:
	cp trackwatch /usr/local/bin

clean:
	rm -f trackwatch

.PHONY: build all install test clean uninstall

uninstall:
	rm -f /usr/local/bin/trackwatch