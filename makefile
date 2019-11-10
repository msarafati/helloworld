gcc := g++ -c -std=c++11 
all: changelogch
changelogch:main.o check.o exec.o file.o diff.o
	g++ -std=c++11 main.o check.o exec.o file.o diff.o -o changelogch
exec.o:exec.cpp header.h
	$(gcc) exec.cpp
diff.o:diff.cpp diff.h error.h diff.h
	$(gcc) diff.cpp
main.o: main.cpp header.h error.h check.h file.h diff.h
	$(gcc) main.cpp
check.o:check.cpp header.h error.h check.h
	$(gcc) check.cpp
file.o:file.cpp header.h error.h file.h
	$(gcc) file.cpp
install:
	mkdir -p $(DESTDIR)/usr/bin
	cp changelogch $(DESTDIR)/usr/bin/changelogch

clean:
	rm -f changelogch