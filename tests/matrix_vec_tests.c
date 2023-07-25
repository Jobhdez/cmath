#include "CUnit/Basic.h"
#include "../src/matrix_vec.c"
#include "../src/matrix.c"

void matrix_vec_product_tests() {
  int rows = 2;
  int columns = 3;
  matrix *m1 = make_matrix(rows, columns);
  int matrix1[2][3] = {{1,2,3}, {4,5,6}};
  
   for (int i = 0; i < m1->rows; i++) {
    for (int j = 0; j < m1->columns; j++) {
      m1->data[i][j] = matrix1[i][j];
    }
  }

  vector *v5 = calloc(1, sizeof(*v5));
  v5->length = 3;
  v5->data = calloc(v5->length, sizeof(*v5->data));
  int integer2 = 1;
  for (int i = 0; i < v5->length; i++) {
    v5->data[i] = integer2;
    integer2+=1;
  }

  vector *expected_vector = calloc(1, sizeof(*expected_vector));
  expected_vector->length = 2;
  expected_vector->data = calloc(expected_vector->length, sizeof(*expected_vector->data));
  int v1[] = {18,45};
   for (int i = 0; i < expected_vector->length; i++) {
      expected_vector->data[i] = v1[i];
    }
  
  vector *given_vector = mat_vec_prod(m1, v5);

  CU_ASSERT_EQUAL(given_vector->length, expected_vector->length);
  for (int i = 0; i < expected_vector->length; i++) {
    CU_ASSERT_EQUAL(given_vector->data[i], expected_vector->data[i]);
  }
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
  if ((NULL == CU_add_test(pSuite1, "\n\nVector-Matrix Product Test\n\n", matrix_vec_product_tests)))
    {
      CU_cleanup_registry();
      return CU_get_error();
    }

  CU_basic_run_tests();
  CU_cleanup_registry();
  return CU_get_error();
}
