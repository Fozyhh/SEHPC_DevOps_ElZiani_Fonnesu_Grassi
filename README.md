## Overview
This is the repository dedicated to the first step of the DevOps Project done in the Software Engineering for HPC course. In particular, these are the two main objectives:

- **Identify Errors:** develop test cases that can identify potential errors in a buggy matrix multiplication implementation;
- **Automate Testing:** use Google Test to automate the execution of the developed test cases

  The function to be tested has the following signature:

```
void multiplyMatrices(const std::vector<std::vector<int>>& A,
                      const std::vector<std::vector<int>>& B,
                      std::vector<std::vector<int>>& C,
                      int rowsA, int colsA, int colsB);
```
Specifically:
- A is the matrix on the left side;
- B is the matrix on the right side;
- C is the rowsA X colsB matrix containing the result of the multiplication.


## Project Structure
The repository is divided in the following directories:
- **include:** contains the header file matrix_multiplication.h, which defines the matrix multiplication signature;
- **lib:** directory containing the buggy matrix multiplication object code libmatrix_multiplication.a;
- **src:** here there is the file mutrix_mult.cpp, which is a correct implementation of a multiplication between matrices that can be used as a reference;
- **test:** contains the test_matrix_multiplication.cpp file where are written a total of 10 test cases for the function, each of which is preceded by a description that summerizes what it does, what is expected and what errors it returns;
- **Makefile:** build configuration file for CMake containing instructions to include the necessary directories, add Google Test, define the test executable, link the required libraries, and set up the test discovery and execution.

## How to run tests

### Test example

Here’s an example test case included in test_matrix_multiplication.cpp:

```
/**
 * @brief Construct a new TEST object which multiplicates two matrices A (2X3) and B (3X2)
 * @note expected a 2X2 matrix being the product between the two matrices
 * 
 * @bug error 6: Result matrix contains a number bigger than 100!
 * @bug error 12: The number of rows in A is equal to the number of columns in B!
 * @bug error 14: The number matrix C has an even number of rows! 
 * @bug error 20: Number of columns in matrix A is odd!
 */
TEST(MatrixMultiplicationTest, TestMultiplyMatrices) {
    std::vector<std::vector<int>> A = {
        {1, 2, 3},
        {4, 5, 6}
    };
    std::vector<std::vector<int>> B = {
        {7, 8},
        {9, 10},
        {11, 12}
    };
    std::vector<std::vector<int>> C(2, std::vector<int>(2, 0));

    multiplyMatrices(A, B, C, 2, 3, 2);

    std::vector<std::vector<int>> expected = {
        {58, 64},
        {139, 154}
    };

    ASSERT_EQ(C, expected) << "Matrix multiplication test failed! :(((()";
}
```

## Errors found

|Error|Description|Found|
|-----|-----------|-----|
|Error #1| Element-wise multiplication of ones detected! | <p align="center">🟢</p> |
|Error #2| Matrix A contains a number bigger than 100! | <p align="center">🟢</p> |
|Error #3| Matrix A contains a negative number! | <p align="center">🟢</p> |
|Error #4| Matrix B contains the number 3! | <p align="center">🟢</p> |
|Error #5| Matrix B contains a negative number! | <p align="center">🟢</p> |
|Error #6| Result matrix contains a number bigger than 100! | <p align="center">🟢</p> |
|Error #7| Result matrix contains a number between 11 and 20! | <p align="center">🟢</p> |
|Error #8| Result matrix contains zero! | <p align="center">🟢</p> |
|Error #9| Result matrix contains the number 99! | <p align="center">🟢</p> |
|Error #10| A row in matrix A contains more than one '1'! | <p align="center">🟢</p> |
|Error #11| Every row in matrix B contains at least one '0'! | <p align="center">🟢</p> |
|Error #12| The number of rows in A is equal to the number of columns in B! | <p align="center">🟢</p> |
|Error #13| The first element of matrix A is equal to the first element of matrix B! | <p align="center">🟢</p> |
|Error #14| The number matrix C has an even number of rows!  | <p align="center">🟢</p> |
|Error #15| A row in matrix A is filled entirely with 5s! | <p align="center">🟢</p> |
|Error #16| Matrix B contains the number 6! | <p align="center">🟢</p> |
|Error #17| Result matrix C contains the number 17! | <p align="center">🟢</p> |
|Error #18| Matrix A is a square matrix! | <p align="center">🟢</p> |
|Error #19| Every row in matrix A contains the number 8! | <p align="center">🟢</p> |
|Error #20| Number of columns in matrix A is odd! | <p align="center">🟢</p> |

## Credits
- Nizare Elziani
- Lorenzo Fonnesu
- Andrea Grassi
