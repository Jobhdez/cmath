#include "CUnit/Basic.h"
#include "../src/polynomial.c"

void polynomial_sum_test() {
  // Check the sum of two polynomials
  poly *p1 = calloc(1, sizeof(*p1));
  p1->degree = 3;
  int size = p1->degree + 1;
  p1->coefficients = calloc(size, sizeof(*p1->coefficients));
  int poly1[] = {3, 2, 1, 7};
  for (int i = 0; i < 4; i++) {
    p1->coefficients[i] = poly1[i];
  }

  // result Polynomial struct
  poly *p3 = calloc(1, sizeof(*p3));
  
  p3->coefficients = malloc(size);
  p3->degree = p1->degree;
  int poly2[] = {6,4,2,14};
  for (int i = 0; i < 4; i++) {
    p3->coefficients[i] = poly2[i];
  }

 
 poly *result = add_polys(p1, p1);
 poly *sub_poly_result = sub_polys(p3, p1);
 
 CU_ASSERT_EQUAL(result->degree, p3->degree);
 CU_ASSERT_EQUAL(sub_poly_result->degree, p1->degree);
 for (int i = 0; i < size; i++) {
   CU_ASSERT_EQUAL(result->coefficients[i], p3->coefficients[i]);
   CU_ASSERT_EQUAL(sub_poly_result->coefficients[i], p1->coefficients[i]);
  }
 free(p1->coefficients);
 free(p1);
 free(p3->coefficients);
 free(p3);
}
int main() {
  CU_pSuite pSuite1 = NULL;
  if (CUE_SUCCESS != CU_initialize_registry()) {
    return CU_get_error();
  }

  pSuite1 = CU_add_suite("Test Suite1", 0, 0);
  if (NULL == pSuite1) {
    CU_cleanup_registry();
    return CU_get_error();
  }
  if ((NULL == CU_add_test(pSuite1, "\n\nPolynomial Sum function Testing\n\n", polynomial_sum_test)))
    {
      CU_cleanup_registry();
      return CU_get_error();
    }
  CU_basic_run_tests();
  CU_cleanup_registry();
  return CU_get_error();
}
