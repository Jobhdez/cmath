output: ./src/main.o ./src/vector.o ./src/matrix.o ./src/polynomial.o ./src/matrix_vec.o
	gcc -o output ./src/main.o ./src/vector.o ./src/matrix.o ./src/polynomial.o ./src/matrix_vec.o

main.o: ./src/main.c
	gcc -c ./src/main.c

vector.o: ./src/vector.c ./src/vector.h
	gcc -c  ./src/vector.c

matrix.o: ./src/matrix.c ./src/matrix.h
	gcc -c ./src/matrix.c

polynomial.o: ./src/polynomial.c ./src/polynomial.h
	gcc -c ./src/polynomial.c

matrix_vec.o: ./src/matrix_vec.c ./src/matrix_vec.h
	gcc -c ./src/matrix_vec.c

clean:
	rm -f ./src/*.o output matrix_tests matrix_vec_tests polynomial_test vector_tests *.o
