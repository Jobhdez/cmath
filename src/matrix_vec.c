#include <stdio.h>
#include <stdlib.h>
#include "matrix_vec.h"
#include "matrix.h"
#include "vector.h"

vector *mat_vec_prod(matrix *m1, vector *v1) {
  int rows = m1->rows;
  matrix *m2 = make_matrix(rows, m1->columns);
  vector *v2 = calloc(1, sizeof(*v2));
  v2->length = m1->rows;
  v2->data = calloc(v2->length, sizeof(*v2->data));
  
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < m1->columns; j++) {
      for (int k = 0; k < v1->length; k++) {
	m2->data[i][j] = m1->data[i][j] * v1->data[k];
      }
    }
  }
  
  int sum;
  for (int i = 0; i < m2->rows; i++) {
    sum = 0;
    for (int j = 0; j < m2->columns; j++) {
      sum = sum + m2->data[i][j];
    }
    v2->data[i] = sum;
    }
  return v2;
}
