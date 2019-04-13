LDFLAGS := -L/usr/lib/x86_64-linux-gnu/ -lboost_math

all: SuperBoostProj clean

SuperBoostProj:
	g++ -c src/main.cpp
	g++ -o SuperBoostProj src/main.cpp
clean:
	rm -rf *.o
