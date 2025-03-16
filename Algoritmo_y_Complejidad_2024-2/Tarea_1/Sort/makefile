sbubble:
		g++ -g -o bubble bubblesort.cpp -Wall
		./bubble < data/desordenados.txt
		./bubble < data/desordenados1.txt
		./bubble < data/parcialemente_ordenados.txt
		./bubble < data/ordenados_inversamente.txt

squick:
		g++ -g -o quick quicksort.cpp -Wall
		./quick < data/desordenados.txt
		./quick < data/desordenados1.txt
		./quick < data/parcialemente_ordenados.txt
		./quick < data/ordenados_inversamente.txt

smerge:
		g++ -g -o merge mergesort.cpp -Wall
		./merge < data/desordenados.txt
		./merge < data/desordenados1.txt
		./merge < data/parcialemente_ordenados.txt
		./merge < data/ordenados_inversamente.txt

sstl:
		g++ -g -o stl stlsort.cpp -Wall
		./stl < data/desordenados.txt
		./stl < data/desordenados1.txt
		./stl < data/parcialemente_ordenados.txt
		./stl < data/ordenados_inversamente.txt

datasets:
		g++ -g -o datas data/datasets.cpp -Wall
		./datas

clear:
		rm -f bubble datas quick merge stl *.txt