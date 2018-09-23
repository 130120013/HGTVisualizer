 
all:
	g++ Client.cpp BMPGenerator.cpp HGTVisualizer.cpp -o HRTVisualizer -std=c++14 -pthread
	
clean:
	rm -f HRTVisualizer
