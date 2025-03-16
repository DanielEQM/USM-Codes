datasets:
		g++ -g -o datas data/datasetsM.cpp -Wall
		./datas

Mult_Matriz: 
		g++ Mul_Matriz.cpp auxMatrix.hpp -o MuMa -Wall
		./MuMa < data/MatricesR.txt
		./MuMa < data/Matrices.txt

Mult_Matriz_T:
		g++ Mul_MatrizT.cpp auxMatrix.hpp -o MuMaT -Wall
		./MuMaT < data/MatricesR.txt
		./MuMaT < data/Matrices.txt

Strassen:
		g++ Strassen.cpp auxMatrix.hpp -o MStrassen -Wall
		./MStrassen < data/Matrices.txt

clear:
		rm -f MuMa MuMaT datas MStrassen *.txt