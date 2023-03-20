#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

/* basic matrix algebra. */
matrix *make_matrix(int rows, int columns) {
  /*
    make a matrix given two ints: rows, and columns
  */
  matrix *m = calloc(1, sizeof(*m));
  m->rows = rows;
  m->columns = columns;
  m->data = calloc(m->rows, sizeof(*m->data)); // allocate memory for column array
  for (int i = 0; i < m->rows; i++) {
    m->data[i] = calloc(m->columns, sizeof(**m->data));
  }

  return m;
}

matrix *add_mat(matrix *m1, matrix *m2) {

  /*
    add matrixes m1 and m2.
    
   */
  int rows = m1->rows;
  int columns = m1->columns;

  matrix *m3 = make_matrix(rows, columns);

  for (int i = 0; i < m3->rows; i++) {
    for (int j = 0; j < m3->columns; j++) {
      m3->data[i][j] = m1->data[i][j] + m2->data[i][j];
    }
  }
  return m3;
}

matrix *sub_mat(matrix *m1, matrix *m2) {
  /* subtract matrixes m1 and m2*/
  int rows = m1->rows;
  int columns = m1->columns;

  matrix *m3 = make_matrix(rows, columns);

  for (int i = 0; i < m3->rows; i++) {
    for (int j = 0; j < m3->columns; j++) {
      m3->data[i][j] = m1->data[i][j] + m2->data[i][j];
    }
  }
  return m3;
}

matrix *mul_scalar(matrix *m1, int scalar) {

  /* multiply `scalar` by the matrix m1*/
  
  int rows = m1->rows;
  int columns = m1->columns;

  matrix *m2 = make_matrix(rows, columns);

  int i, j;
  for (i = 0; i < rows; i++) {
    for (j = 0; j < columns; j++) {
      m2->data[i][j] = m1->data[i][j] * scalar;
    }
  }
  return m2;
}

// note: expects two square matrices
matrix *mul_sq_matrix(matrix *m1, matrix *m2) {
  /* given two *square* matrixes m1 and m2 multiply them*/
  int n = m1->rows;
  matrix *m3 = make_matrix(m1->rows, m1->columns);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      m3->data[i][j] = 0;
      for (int k = 0; k < n; k++) {
	m3->data[i][j] = m3->data[i][j] + m1->data[i][k] * m2->data[k][j];
	}
      }
    }
  return m3;
}

void print_matrix(matrix *m1) {
  for (int i = 0; i < m1->rows; i++) {
    for (int j = 0; j < m1->columns; j++) {
      printf("%d ", m1->data[i][j]);
      printf("\t");
    }
    printf("\n");
  }
}

void initialize_matrix(matrix *m1, int data) {
  for (int i = 0; i < m1->rows; i++) {
    for (int j = 0; j < m1->columns; j++) {
      m1->data[i][j] = data;
      data += 1;
    }
  }
}
