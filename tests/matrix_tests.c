#include "CUnit/Basic.h"
#include "../src/matrix.c"

void matrix_add_tests() {
  int rows = 2;
  int columns = 3;
  matrix *m1 = make_matrix(rows, columns);
  int matrix1[2][3] = {{3,4,5}, {4,5,6}};
  
   for (int i = 0; i < m1->rows; i++) {
    for (int j = 0; j < m1->columns; j++) {
      m1->data[i][j] = matrix1[i][j];
    }
  }

  int rows2 = 2;
  int columns2 = 3;
  matrix *expected_matrix = make_matrix(rows2, columns2);
  int m2[2][3] = {{6,8,10}, {8,10,12}};
   for (int i = 0; i < m1->rows; i++) {
    for (int j = 0; j < m1->columns; j++) {
      expected_matrix->data[i][j] = m2[i][j];
    }
  }
  
  matrix *m3 = add_mat(m1, m1);

  CU_ASSERT_EQUAL(m3->rows, expected_matrix->rows);
  CU_ASSERT_EQUAL(m3->columns, expected_matrix->columns);
  for (int i = 0; i < m3->rows; i++) {
    for (int j = 0; j < m3->columns; j++) {
      CU_ASSERT_EQUAL(m3->data[i][j], expected_matrix->data[i][j]);
  }
  
}
}

void matrix_sub_tests() {
  int rows = 2;
  int columns = 3;
  matrix *m1 = make_matrix(rows, columns);
  int matrix1[2][3] = {{3,4,5}, {4,5,6}};
  
  for (int i = 0; i < m1->rows; i++) {
    for (int j = 0; j < m1->columns; j++) {
      m1->data[i][j] = matrix1[i][j];
    }
  }

  int rows2 = 2;
  int columns2 = 3;
  matrix *expected_matrix = make_matrix(rows2, columns2);
  int m2[2][3] = {{0,0,0}, {0,0,0}};
  
   for (int i = 0; i < m1->rows; i++) {
    for (int j = 0; j < m1->columns; j++) {
      expected_matrix->data[i][j] = m2[i][j];
    }
  }
  
  matrix *given_matrix = sub_mat(m1, m1);

  CU_ASSERT_EQUAL(given_matrix->rows, expected_matrix->rows);
  CU_ASSERT_EQUAL(given_matrix->columns, expected_matrix->columns);
  for (int i = 0; i < given_matrix->rows; i++) {
    for (int j = 0; j < given_matrix->columns; j++) {
      CU_ASSERT_EQUAL(given_matrix->data[i][j], expected_matrix->data[i][j]);
    }
  }
}

void matrix_mul_scalar_tests() {
  int rows = 2;
  int columns = 3;
  matrix *m1 = make_matrix(rows, columns);
  int elements[2][3] = {{3,4,5}, {4,5,6}};
  for (int i = 0; i < m1->rows; i++) {
    for (int j = 0; j < m1->columns; j++) {
      m1->data[i][j] = elements[i][j];
    }
  }
  int scalar = 3;

  int rows2 = 2;
  int columns2 = 3;
  matrix *expected_matrix = make_matrix(rows2, columns2);
  int m2[2][3] = {{9,12,15}, {12,15,18}};

 for (int i = 0; i < m1->rows; i++) {
    for (int j = 0; j < m1->columns; j++) {
      expected_matrix->data[i][j] = m2[i][j];
    }
  }
 
  matrix *m3 = mul_scalar(m1, scalar);

  CU_ASSERT_EQUAL(m3->rows, expected_matrix->rows);
  CU_ASSERT_EQUAL(m3->columns, expected_matrix->columns);
  for (int i = 0; i < m1->rows; i++) {
    for (int j = 0; j < m1->columns; j++) {
      CU_ASSERT_EQUAL(m3->data[i][j], expected_matrix->data[i][j]);
    }
  }
}

void matrix_mul_sq_mat_tests() {
  int rows = 2;
  int columns = 2;
  matrix *m1 = make_matrix(rows, columns);
  int matrix1[2][2] = {{3,4}, {4,5}};
  
 for (int i = 0; i < m1->rows; i++) {
    for (int j = 0; j < m1->columns; j++) {
      m1->data[i][j] = matrix1[i][j];
    }
  }

  int rows2 = 2;
  int columns2 = 2;
  matrix *expected_matrix = make_matrix(rows2, columns2);
  int m2[2][2] = {{25,32}, {32, 41}};
  
  for (int i = 0; i < m1->rows; i++) {
    for (int j = 0; j < m1->columns; j++) {
      expected_matrix->data[i][j] = m2[i][j];
    }
  }
 
  
  matrix *m3 = mul_sq_matrix(m1, m1);

  CU_ASSERT_EQUAL(m3->rows, expected_matrix->rows);
  CU_ASSERT_EQUAL(m3->columns, expected_matrix->columns);
  for (int i = 0; i < m1->rows; i++) {
    for (int j = 0; j < m1->columns; j++) {
      CU_ASSERT_EQUAL(m3->data[i][j], expected_matrix->data[i][j]);
    }
  }
}


void transpose_matrix_tests() {
  int rows = 2;
  int columns = 3;
  matrix *m1 = make_matrix(rows, columns);
  int matrix1[2][3] = {{2,3,4}, {5,6,7}};

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      m1->data[i][j] = matrix1[i][j];
    }
  }

  matrix *expected_matrix = make_matrix(columns, rows);
  
  int matrix2[3][2] = {{2,5}, {3,6}, {4,7}};

  for (int i = 0; i < columns; i++) {
    for (int j = 0; j < rows; j++) {
      expected_matrix->data[i][j] = matrix2[i][j];
    }
  }

  matrix *given_matrix = transpose_matrix(m1);

  CU_ASSERT_EQUAL(given_matrix->rows, expected_matrix->rows);
  CU_ASSERT_EQUAL(given_matrix->columns, expected_matrix->columns);
  for (int i = 0; i < expected_matrix->rows; i++) {
    for (int j = 0; j < expected_matrix->columns; j++) {
      CU_ASSERT_EQUAL(given_matrix->data[i][j], expected_matrix->data[i][j]);
    }
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
  if ((NULL == CU_add_test(pSuite1, "\n\nMatrix Sum Test\n\n", matrix_add_tests)))
    {
      CU_cleanup_registry();
      return CU_get_error();
    }
   if ((NULL == CU_add_test(pSuite1, "\n\nSubtraction Matrix Testing\n\n", matrix_sub_tests)))
    {
      CU_cleanup_registry();
      return CU_get_error();
    }
    if ((NULL == CU_add_test(pSuite1, "\n\nMatrix times scalar Testing\n\n", matrix_mul_scalar_tests)))
    {
      CU_cleanup_registry();
      return CU_get_error();
    }
     if ((NULL == CU_add_test(pSuite1, "\n\nSq Matrix time Sq Matrix multiplication Testing\n\n", matrix_mul_sq_mat_tests)))
    {
      CU_cleanup_registry();
      return CU_get_error();
    }

     if ((NULL == CU_add_test(pSuite1, "\n\nMatrix transpose Testing\n\n", transpose_matrix_tests)))
    {
      CU_cleanup_registry();
      return CU_get_error();
    }
  CU_basic_run_tests();
  CU_cleanup_registry();
  return CU_get_error();
}
