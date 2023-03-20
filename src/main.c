#include <stdio.h>
#include <stdlib.h>
#include "vector.h"
#include "matrix.h"
#include "polynomial.h"
#include "matrix_vec.h"

//----------------------------
// tests :)
// the following is how I experimented with the code I wrote above to make sure I was doing it right.
//------------------------
int main(void) {
  vector *v1 = calloc(1, sizeof(*v1));
  v1->length = 4;
  v1->data = calloc(v1->length, sizeof(*v1->data));
  for (int i = 0; i < v1->length; i++) {
    v1->data[i] = i;
    }
  vector *result = add_vectors(v1, v1);
    //print_vector(result);
  for (int j = 0; j < v1->length; j++) {
    printf("%d", result->data[j]);
    }
  free(v1->data);
  free(v1);

  free(result->data);
  //free(result);
  
  printf("\n");
  printf("---------polynomials-------\n");

  poly *p1 = calloc(1, sizeof(*p1));
  p1->degree = 3;
  int size = p1->degree + 1;
  p1->coefficients = calloc(size, sizeof(*p1->coefficients));

  for (int k = 0; k < size; k++) {
    p1->coefficients[k] = k;
  }

  poly *result_poly = add_polys(p1, p1);
  int deg = result_poly->degree;
  
  for (int i = 0; i < result_poly->degree + 1; i++) {
    printf("%dx^%d+", result_poly->coefficients[i], deg);
    deg = deg - 1;

}
  free(result_poly->coefficients);
  //free(result_poly);
  printf("\n");
  printf("---eval---\n");
  printf("eval: %d\n", eval_poly(p1, 2));
  free(p1->coefficients);
  free(p1);
  //printf("\n");
  printf("----dot product----");
  vector *v2 = calloc(1, sizeof(*v2));
  v2->length = 4;
  v2->data = calloc(v2->length, sizeof(*v2->data));

  for (int i = 0; i < v2->length; i++) {
    v2->data[i] = i;
  }
  vector *element_wise_prod = element_wise_product(v2, v2);
  /*for (int i = 0; i<element_wise_prod->length; i++) {
    printf("%d", element_wise_prod->data[i]);
    }*/
  free(v2->data);
  free(v2);
  printf("\n");
  printf("dotp: %d\n", dot_product(element_wise_prod));
  printf("\n");

  free(element_wise_prod->data);

  int rows = 2;
  int columns = 3;
  matrix *m1 = make_matrix(rows, columns);
  int data = 1;
  for (int i = 0; i < m1->rows; i++) {
    for (int j = 0; j < m1->columns; j++) {
      m1->data[i][j] = data;
      data += 2;
    }
  }

  matrix *m2 = add_mat(m1, m1);
  for (int i = 0; i < m2->rows; i++) {
    for (int j = 0; j < m2->columns; j++) {
      printf("%d ", m2->data[i][j]);
      printf("\t");
    }
    printf("\n");
  }

  free(m1->data);
  free(m1);
  free(m2->data);
  int rows2 = 2;
  int columns2 = 3;
  matrix *m3 = make_matrix(rows2, columns2);
  int data2 = 1;
  for (int i = 0; i < m3->rows; i++) {
    for (int j = 0; j < m3->columns; j++) {
      m3->data[i][j] = data2;
      data2 += 2;
    }
  }
  int scalar = 3;
  matrix *m4 = mul_scalar(m3, scalar);
  printf("\n");
  printf("---print matrix * scalar-----");
  printf("\n");
  print_matrix(m4);

  free(m3->data);
  free(m3);
  free(m4->data);

  matrix *m5 = make_matrix(4,4);

  initialize_matrix(m5, 2);
  matrix *m6 = mul_sq_matrix(m5, m5);
  printf("\n");
  printf("----squared matrix multiplication.----\n");
  print_matrix(m6);

  free(m5->data);
  free(m5);
  free(m6->data);
  
  printf("\n");
  printf("------matrix-vector product.------------");
  matrix *m7 = make_matrix(2,3);

  // initialize to {{1,2,3} {4,5,6}}
  initialize_matrix(m7, 1);

  // initialize vector to {1,2,3}
  vector *v5 = calloc(1, sizeof(*v5));
  v5->length = 3;
  v5->data = calloc(v5->length, sizeof(*v5->data));
  int integer2 = 1;
  for (int i = 0; i < v5->length; i++) {
    v5->data[i] = integer2;
    integer2+=1;
  }

  /* cause of segmentation fault error.*/
  vector *v6 = mat_vec_prod(m7, v5);

  printf("\n");
  for (int i = 0; i < v6->length; i++) {
    printf("%d\n", v6->data[i]);
  }
  
}
