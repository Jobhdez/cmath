#ifndef POLYNOMIAL_H_
#define POLYNOMIAL_H_

typedef struct poly {
  int degree;
  int *coefficients;
} poly;


poly *add_polys(poly *p1, poly *p2);

poly *sub_polys(poly *p1, poly *p2);

poly *multiply_polys(poly *p1, poly *p2);

poly *derivative(poly *p1);

int eval_poly(poly *p1, int x);

#endif
