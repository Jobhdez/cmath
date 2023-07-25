CC = gcc
CFLAGS = -c -Wall
LDFLAGS = -lcunit

output: ./src/main.o ./src/vector.o ./src/matrix.o ./src/polynomial.o ./src/matrix_vec.o
	gcc -o output ./src/main.o ./src/vector.o ./src/matrix.o ./src/polynomial.o ./src/matrix_vec.o

main.o: ./src/main.c
	$(CC) $(CFLAGS) ./src/main.c

vector.o: ./src/vector.c ./src/vector.h
	$(CC) $(CFLAGS) ./src/vector.c

matrix.o: ./src/matrix.c ./src/matrix.h
	$(CC) $(CFLAGS) ./src/matrix.c

polynomial.o: ./src/polynomial.c ./src/polynomial.h
	$(CC) $(CFLAGS) ./src/polynomial.c

matrix_vec.o: ./src/matrix_vec.c ./src/matrix_vec.h
	$(CC) $(CFLAGS) ./src/matrix_vec.c

clean:
	rm -f ./src/*.o output matrix_tests matrix_vec_tests polynomial_test vector_tests *.o
