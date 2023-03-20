#ifndef VECTOR_H_
#define VECTOR_H_

typedef struct vector {
  int length;
  int *data;
} vector;


vector *add_vectors(vector *v1, vector *v2);

vector *sub_vectors(vector *v1, vector *v2);

vector *vec_mul_by_scalar(vector *v1, int scalar);

vector *element_wise_product(vector *v1, vector *v2);

int dot_product(vector *inter_element_wise);

#endif
