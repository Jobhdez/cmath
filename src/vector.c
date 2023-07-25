#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

vector *add_vectors(vector *v1, vector *v2) {
  /*
    @param p1: a vector struct denoting a vector
    @param p2: a vector struct denoting a vector
    @returns: p3, a vector struct denoting a vector

    returns the sum of both vector.

   
   */
  vector *result = calloc(1, sizeof(*result));
  result->data = calloc(v1->length, sizeof(*result->data));
  result->length = v1->length;

  if (!result->data) {
    return NULL;
  }

  for (int i = 0; i < v1->length; i++) {
    result->data[i] = v1->data[i] + v2->data[i];
  }

  return result;
}

vector *sub_vectors(vector *v1, vector *v2) {

  /*

    @param p1: a vector struct denoting a vector
    @param p2: a vector struct denoting a vector
    @returns: p3, a vector struct denoting a vector

    returns the subtraction of both vector.



   */
  vector *result = calloc(1, sizeof(*result));
  result->data = calloc(v1->length, sizeof(*result->data));
  result->length = v1->length;

  if (!result->data) {
    return NULL;
  }

  for (int i = 0; i < v1->length; i++) {
    result->data[i] = v1->data[i] - v2->data[i];
  }
  return result;
}

vector *vec_mul_by_scalar(vector *v1, int scalar) {
  /*
    @param p1: a vector struct denoting a vector
    @param p2: a scalar
    @returns: p3, a vector struct denoting a vector * scalar
  */
  vector *result = calloc(1, sizeof(*result));
  result->data = calloc(v1->length, sizeof(*result->data));
  result->length = v1->length;

  for (int i = 0; i < v1->length; i++) {
    
    result->data[i] = v1->data[i] * scalar;
  }
  return result;
}
vector *element_wise_product(vector *v1, vector *v2) {
  /*

    @param v1: vector
    @param v2: vector
    @returns: vector

    eg. {1,2,3,4} * {3,4,6,7} = {3,8,18,28}


   */
  vector *element_wise =  calloc(1, sizeof(*element_wise));
  element_wise->data = calloc(v1->length, sizeof(*element_wise->data));
  element_wise->length = v1->length;
  
  for (int i = 0; i < v1->length; i++) {
    element_wise->data[i] = v1->data[i] * v2->data[i];
  }

  return element_wise;
}
int dot_product(vector *inter_element_wise) {
  /*
    assumes an element wise product of the two vectors that get multiplied.

   */
  int sum = 0;
  int inter;
  for (int j = 0; j < inter_element_wise->length; j++) {
    inter = inter_element_wise->data[j];
    sum = sum + inter;
  }

  return sum;
}

void free_vector(vector *v) {
  free(v->data);
  free(v);
}
int print_vector(vector *v1) {

  if (v1->data) {
    for (int i = 0; i < v1->length; i++) {
      printf("%d", v1->data[i]);
    }
  }
  free(v1->data);
}
