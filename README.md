# cmath
a tiny toy math library consisting of basic math: vectors, matrices, polynomials, matrix-vec arithmetic

## running the program

1. clone the repo
2. navigate to the repo's directory and type `make` to make sure everything compiles correctly.

## running the tests

To run the tests:

1. `chmod +x run_tests.sh`

2. `./run_tests.sh`

## dependencies
1. You need to install cunit, the test framework.

   * Arch Linux: `sudo pacman -S cunit`
   
## thoughts

I actually like C. I think it has forced me to think deeper about programming; for example, I was able to associate pointers, and memory allocation with my studies of operating systems; for instance, every time you use `malloc` or `calloc` in C you are allocating memory in the heap. In an operating system textbook you learn that a process' memory consists of text, data, heap and stack regions. I don't know - for me, making this connection was a good experience; moreover, with respect to pointers, studying this made see how memory is contiguous and that a pointer points to an memory address. This is all related to virtual memory, another concept in operating systems; virtual memory consists of a virtual address space. When working with pointers you are interacting with virtual memory. In assembly --e.g., x86-- you interact with the virtual memort more explicitly. Furthermore, I also like C because is the programming language for Unix/Linux and I love Linux and it culture. But I believe to truly understand the C programming language I need to implement it and as a result I am thinking of building a C compiler :)

Thanks!

-- Job Hdez

