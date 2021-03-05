Face Detector: main.o
	g++ main.o -o "Face Detector" `pkg-config --cflags --libs opencv4`

main.o: main.cpp
	g++ -c main.cpp `pkg-config --cflags --libs opencv4`

clean:
	rm *.o 'Face Detector'