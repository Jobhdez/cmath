#!/bin/bash

function compile_and_run() {
    # Compile the C file
    gcc -o "$1" "$2" -lcunit

    # Check if the compilation was successful before running
    if [ $? -eq 0 ]; then
        echo "Compilation of $2 successful. Running..."
        # Run the compiled program
        ./"$1"
    else
        echo "Error: Compilation of $2 failed."
    fi
}

# Compile and run each C file one by one
compile_and_run "matrix_tests" "tests/matrix_tests.c"
compile_and_run "matrix_vec_tests" "tests/matrix_vec_tests.c"
compile_and_run "polynomial_test" "tests/polynomial_test.c"
compile_and_run "vector_tests" "tests/vector_tests.c"
