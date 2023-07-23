#include <stdio.h>
#include <stdlib.h>
#include "polynomial.h"

poly *add_polys(poly *p1, poly *p2) {
  /*
    @param p1: a Poly struct denoting a polynomial
    @param p2: a Poly struct denoting a polynomial
    @returns: p3, a Poly struct denoting a polynomial

    returns the sum of both polynomials.

   
   */
  poly *p3 = calloc(1, sizeof(*p3));
  int size = p1->degree + 1;
  
  p3->coefficients = malloc(size);
  p3->degree = p1->degree;
  

  for (int i = 0; i < size; i++) {
    p3->coefficients[i] = p1->coefficients[i] + p2->coefficients[i];
    }

  return p3;
}
poly *sub_polys(poly *p1, poly *p2) {

  /*
    @param p1: a Poly struct denoting a polynomial
    @param p2: a Poly struct denoting a polynomial
    @returns: p3, a Poly struct denoting a polynomial

    returns the subtraction of both polynomials.

   
   */
  poly *p3;
  int size = p1->degree + 1;

  p3->coefficients = malloc(size);
  p3->degree = p1->degree;

  for (int i = 0; i < size; i++) {
    p3->coefficients[i] = p1->coefficients[i] + p2->coefficients[i];
  }

  return p3;
}

poly *multiply_polys(poly *p1, poly *p2) {

  /*
    @param p1: a Poly struct denoting a polynomial
    @param p2: a Poly struct denoting a polynomial
    @returns: p3, a Poly struct denoting a polynomial

    returns the product of both polynomials.

   
   */
  poly *p3;
  int p1_size = p1->degree + 1;
  int p2_size = p2->degree + 1;

  p3->coefficients = malloc(p1_size+p2_size-1);
  p3->degree = p1->degree + p2->degree;

  for (int i = 0; i < p1_size; i++) {
    for (int j=0; j<p2_size; j++) {
      p3->coefficients[i+j] += p1->coefficients[i] *  p2->coefficients[j];
    }
  }

  return p3;
}

poly *derivative(poly *p1) {
  /*
    @param p1: poly struct denoting a polynomial
    @returns: poly struct denoting the derivative of p1

    take the derivative of p1.
  */
  poly *p2;
  p2->degree = p1->degree - 1;
  p2->coefficients = malloc(p1->degree);

  int deg = p1->degree;
  for (int i = 0; i < p1->degree + 1; i++) {
    p2->coefficients[i] = p1->coefficients[i] * deg;
    deg = deg - 1;
  }
  return p2;
}
  
int eval_poly(poly *p1, int x) {
  /*
    @param p1: poly struct denoting a polynomial
    @param x: integer
    @returns: int, the evaluation of p1 with respect to x
    
   */
  int sum = 0;
  int inter;
  for (int i = 0; i < p1->degree+1; i++) {
    inter = p1->coefficients[i] * x;
    sum = sum + inter;
  }
  return sum;
}
