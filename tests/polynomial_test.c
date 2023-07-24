#include "CUnit/Basic.h"
#include "../src/polynomial.c"

void polynomial_tests() {
  //------------------------------------
  // Check the sum of two polynomials
  //------------------------------------
  poly *p1 = calloc(1, sizeof(*p1));
  p1->degree = 3;
  int size = p1->degree + 1;
  p1->coefficients = calloc(size, sizeof(*p1->coefficients));
  int poly1[] = {3, 2, 1, 7};
  for (int i = 0; i < 4; i++) {
    p1->coefficients[i] = poly1[i];
  }

  // polynomial `p3` is the expected polynomial from the addition p1+p1
  poly *p3 = calloc(1, sizeof(*p3));
  
  p3->coefficients = malloc(size);
  p3->degree = p1->degree;
  int poly2[] = {6,4,2,14};
  for (int i = 0; i < 4; i++) {
    p3->coefficients[i] = poly2[i];
  }

 
 poly *result = add_polys(p1, p1);
 //-------------------------------------------------
 // Polynomial Subtraction
 //--------------------------------------------------
 poly *sub_poly_result = sub_polys(p3, p1);
 //--------------------------------------------
 // polynomial multiplication
 //--------------------------------------------

 // Polynomial `p4` for polynomial multiplication test
  poly *p4 = calloc(1, sizeof(*p3));
  
  p4->coefficients = malloc(size);
  p4->degree = 2;
  int poly3[] = {3,4,5};
  for (int i = 0; i < 3; i++) {
    p4->coefficients[i] = poly3[i];
  }

  // expected polynomial from multiplying polynomial `p4` to itself -- i.e., p4*p4
  poly *p5 = calloc(1, sizeof(*p3));
  
  p5->coefficients = malloc(size);
  p5->degree = p4->degree + p4->degree;
  int poly4[] = {9,24,46,40,25};
  for (int i = 0; i < p5->degree+1; i++) {
    p5->coefficients[i] = poly4[i];
  }
  // result_mul: result of my `multiply_polys` function
 poly *result_mul = multiply_polys(p4, p4);

 // Assertions
 CU_ASSERT_EQUAL(result->degree, p3->degree);
 CU_ASSERT_EQUAL(sub_poly_result->degree, p1->degree);
 CU_ASSERT_EQUAL(result_mul->degree, 4);
 for (int i = 0; i < size; i++) {
   CU_ASSERT_EQUAL(result->coefficients[i], p3->coefficients[i]);
   CU_ASSERT_EQUAL(sub_poly_result->coefficients[i], p1->coefficients[i]);
   CU_ASSERT_EQUAL(result_mul->coefficients[i], p5->coefficients[i]);
  }
 free(p1->coefficients);
 free(p1);
 free(p3->coefficients);
 free(p3);
 free(p4->coefficients);
 free(p4);
 free(p5->coefficients);
 free(p5);
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
  if ((NULL == CU_add_test(pSuite1, "\n\nPolynomial Sum function Testing\n\n", polynomial_tests)))
    {
      CU_cleanup_registry();
      return CU_get_error();
    }
  CU_basic_run_tests();
  CU_cleanup_registry();
  return CU_get_error();
}
