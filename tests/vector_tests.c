#include "CUnit/Basic.h"
#include "../src/vector.c"

void vector_add_tests() {
  vector *v1 = calloc(1, sizeof(*v1));
  v1->length = 4;
  v1->data = calloc(v1->length, sizeof(*v1->data));
  int vec1[] = {2,3,4,5};
  for (int i = 0; i < v1->length; i++) {
    v1->data[i] = vec1[i];
  }

  vector *expected_vector = calloc(1, sizeof(*expected_vector));
  expected_vector->length = 4;
  expected_vector->data = calloc(expected_vector->length, sizeof(*expected_vector->data));

  int vec2[] = {4,6,8,10};
  for (int i = 0; i < expected_vector->length; i++) {
    expected_vector->data[i] = vec2[i];
  }

  vector *given_vector = add_vectors(v1, v1);

  CU_ASSERT_EQUAL(given_vector->length, expected_vector->length);
  for (int i = 0; i < expected_vector->length; i++) {
    CU_ASSERT_EQUAL(given_vector->data[i], expected_vector->data[i]);
  }
}


void vector_sub_tests() {
  vector *v1 = calloc(1, sizeof(*v1));
  v1->length = 4;
  v1->data = calloc(v1->length, sizeof(*v1->data));
  int vec1[] = {2,3,4,5};
  for (int i = 0; i < v1->length; i++) {
    v1->data[i] = vec1[i];
  }

  vector *expected_vector = calloc(1, sizeof(*expected_vector));
  expected_vector->length = 4;
  expected_vector->data = calloc(expected_vector->length, sizeof(*expected_vector->data));

  int vec2[] = {0,0,0,0};
  for (int i = 0; i < expected_vector->length; i++) {
    expected_vector->data[i] = vec2[i];
  }

  vector *given_vector = sub_vectors(v1, v1);

  CU_ASSERT_EQUAL(given_vector->length, expected_vector->length);
  for (int i = 0; i < expected_vector->length; i++) {
    CU_ASSERT_EQUAL(given_vector->data[i], expected_vector->data[i]);
  }
}

void vector_mul_scalar_tests() {
  vector *v1 = calloc(1, sizeof(*v1));
  v1->length = 4;
  v1->data = calloc(v1->length, sizeof(*v1->data));
  int vec1[] = {2,3,4,5};
  for (int i = 0; i < v1->length; i++) {
    v1->data[i] = vec1[i];
  }

  int scalar = 3;
  
  vector *expected_vector = calloc(1, sizeof(*expected_vector));
  expected_vector->length = 4;
  expected_vector->data = calloc(expected_vector->length, sizeof(*expected_vector->data));

  int vec2[] = {6,9,12,15};
  for (int i = 0; i < expected_vector->length; i++) {
    expected_vector->data[i] = vec2[i];
  }

  vector *given_vector = vec_mul_by_scalar(v1, scalar);

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
  if ((NULL == CU_add_test(pSuite1, "\n\nVector Sum Test\n\n", vector_add_tests)))
    {
      CU_cleanup_registry();
      return CU_get_error();
    }
   if ((NULL == CU_add_test(pSuite1, "\n\nSubtraction Subtraction Testing\n\n", vector_sub_tests)))
    {
      CU_cleanup_registry();
      return CU_get_error();
    }
    if ((NULL == CU_add_test(pSuite1, "\n\nVector times scalar Testing\n\n", vector_mul_scalar_tests)))
    {
      CU_cleanup_registry();
      return CU_get_error();
    }
    
  CU_basic_run_tests();
  CU_cleanup_registry();
  return CU_get_error();
}
