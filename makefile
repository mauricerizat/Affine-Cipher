#AFFINE CIPHER

affineCiph.out: main.o header.h encrypt.o decrypt.o checkKey.o math.o
	g++ -o affineCiph.out main.o header.h encrypt.o decrypt.o checkKey.o math.o

main.o: main.o header.h encrypt.o decrypt.o checkKey.o
	g++ -c main.cpp

encrypt.o: encrypt.cpp header.h 
	g++ -c encrypt.cpp

decrypt.o: decrypt.cpp header.h 
	g++ -c decrypt.cpp

checkKey.o: checkKey.cpp header.h 
	g++ -c checkKey.cpp

math.o: math.cpp header.h
	g++ -c math.cpp

clean:
	rm *.o affineCiph.out
