#ifndef MATRIX_H_
#define MATRIX_H_

typedef struct matrix {
  int rows;
  int columns;
  int **data;
} matrix;


matrix *make_matrix(int rows, int columns);

matrix *add_mat(matrix *m1, matrix *m2);

matrix *sub_mat(matrix *m1, matrix *m2);

matrix *mul_scalar(matrix *m1, int scalar);

matrix *mul_sq_matrix(matrix *m1, matrix *m2);

matrix *mul_sq_matrix_c(matrix *m1, matrix *m2);

void print_matrix(matrix *m1);

matrix *initialize_matrix(matrix *m1, int **data);

matrix *transpose_matrix(matrix *m1);

#endif
