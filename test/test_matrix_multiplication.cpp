#include "matrix_multiplication.h"
#include <iostream>
#include <vector>
#include <gtest/gtest.h>

// ######################### Source code of multiplyMatrices in src/matrix_mult

/**
 * @brief Construct a new TEST object which multiplicates two matrices A (2X3) and B (3X2)
 * @note expected the product between the two matrices
 * 
 * @bug error 6: 
 * @bug error 12:
 * @bug error 14:
 * @bug error 20:
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

//errors: 1, 3, 7, 10, 12, 13, 20
// This test has been done to see the behaviour of the program with a row-column multiplication which gives as result 0, expecting so errors
// due mainly to the structure of the matrices.
/**
 * @brief Construct a new TEST object that does a row-column multiplication which gives as result 0, with the row containing a negative number
 * @note the expected result is a scalar, precisely 0
 * 
 * @bug error 1: 
 * @bug error 6:
 * @bug error 7:
 * @bug error 10:
 * @bug error 12:
 * @bug error 13:
 * @bug error 20:
 */
TEST(MatrixMultiplicationTest1, TestMultiplyMatrices) {
    std::vector<std::vector<int>> A = {
        {1, -2, 1}
    };
    std::vector<std::vector<int>> B = {
        {1},
        {1},
        {1}
    };
    std::vector<std::vector<int>> C(1, std::vector<int>(1, 0));

    multiplyMatrices(A, B, C, 1, 3, 1);

    std::vector<std::vector<int>> expected = {
        {0}
    };

    ASSERT_EQ(C, expected) << "Matrix multiplication test failed! :(((()";
}

//errors: 1, 5, 10, 13, 15, 18, 20
// This test has the objective to do the same of the previous one, with little changes to the matrices sone to see how the program behaves 
// with the presence of negative numbers in B.
/**
 * @brief Construct a new TEST object does a row-column multiplication which gives as result 0, with the column containing a negative number
 * @note the expected result is a scalar, precisely 0
 * 
 * @bug error 1: 
 * @bug error 5: 
 * @bug error 10: 
 * @bug error 13: 
 * @bug error 15: 
 * @bug error 18: 
 * @bug error 20: 
 */
TEST(MatrixMultiplicationTest2, TestMultiplyMatrices) {
    std::vector<std::vector<int>> A = {
        {1, 2, 1}

    };
    std::vector<std::vector<int>> B = {
        {1},
        {-1},
        {1}
    };
    std::vector<std::vector<int>> C(1, std::vector<int>(1, 0));

    multiplyMatrices(A, B, C, 1, 3, 1); //MAT1(a*b), MAT2(b*c), RESULTING MATRIX(a*c), a,b,c

    std::vector<std::vector<int>> expected = {
        {0}
    };

    ASSERT_EQ(C, expected) << "Matrix multiplication test failed! :(((()";
}

//error: 4, 8, 9, 11, 12, 14, 16, 17, 18 
// This test aims to observe how the program behaves with two big matrix, one which is the identity and one with all the possible numbers 
// from 1 to 100 in the diagonal.
// With this text we expect to see errors due to the presence of determined numbers in B and C as well as problems caused by using matrices
// with a lot of zeros.
/**
 * @brief Construct a new TEST object which confront one 100X100 identity matrix with a diagonal matrix with values that go from 1 to 100
 * @note we expect the resulting matrix to be equal to B
 * 
 * @bug error 4: 
 * @bug error 8: 
 * @bug error 9: 
 * @bug error 11: 
 * @bug error 12: 
 * @bug error 14: 
 * @bug error 16: 
 * @bug error 17: 
 * @bug error 18: 
 */
TEST(MatrixMultiplicationTest4, TestMultiplyMatrices) { //NOME UNICO 
    size_t rowsA = 100;
    size_t colsA = 100;
    size_t colsB = rowsA;
    size_t rowsB = 100;

    std::vector<std::vector<int>> A(rowsA, std::vector<int>(colsA, 0));
    for(size_t i = 0; i < rowsA; ++i) {
        A[i][i] = 1;
    }
    std::vector<std::vector<int>> B(rowsB, std::vector<int>(colsB, 0));
    for(size_t i = 0; i < rowsB; ++i) {
        B[i][i] = i+1;
    }
    std::vector<std::vector<int>> C(rowsA, std::vector<int>(colsB, 0));

    multiplyMatrices(A, B, C, rowsA, colsB, rowsA); //MAT1(a*b), MAT2(b*c), RESULTING MATRIX(a*c), a,b,c

    std::vector<std::vector<int>> expected(rowsA, std::vector<int>(colsB, 0));
    for(size_t i = 0; i < rowsB; ++i) {
        expected[i][i] = i+1;
    }

    ASSERT_EQ(C, expected) << "Matrix multiplication test failed! :(((()";
}

//error: 1, 2, 7, 11, 12, 14, 17, 18, 19  
// With this text we want to see specially the behaviour of A containing all the numbers from 0 to 9 and all the rows equals to each other.
// We expect to observe errors due to the presence of numbers in A or some patterns contained in it.
/**
 * @brief Construct a new TEST object that multiplies two matrices 10X10 that are respectively the former a matrix with all rows equals
 * between each other, containg all numbers from 0 to 9, and the latter which is an identity matrix
 * @note we expect the resulting matrix to be equal to C
 * 
 * @bug error 1:
 * @bug error 2:
 * @bug error 7:
 * @bug error 11:
 * @bug error 12:
 * @bug error 14:
 * @bug error 17:
 * @bug error 18:
 * @bug error 19:
 */
TEST(MatrixMultiplicationTest5, TestMultiplyMatrices) { //NOME UNICO 
    size_t rowsA = 10;
    size_t colsA = 10;
    size_t colsB = rowsA;
    size_t rowsB = 10;

    std::vector<std::vector<int>> A(rowsA, std::vector<int>(colsA, 0));
    for(size_t i = 0; i < rowsA; ++i) {
        for (size_t j = 0; j < colsA; j++){
            A[i][j] = j;
        }
        
    }
    std::vector<std::vector<int>> B(rowsB, std::vector<int>(colsB, 0));
    for(int i = 0; i < rowsB; ++i) {
        B[i][i] = 1;
    }
    std::vector<std::vector<int>> C(rowsA, std::vector<int>(colsB, 0));

    multiplyMatrices(A, B, C, rowsA, colsB, rowsA); //MAT1(a*b), MAT2(b*c), RESULTING MATRIX(a*c), a,b,c

    std::vector<std::vector<int>> expected(rowsA, std::vector<int>(colsB, 0));
    for(int i = 0; i < rowsA; ++i) {
        expected[i][i] = i;
    }

    ASSERT_EQ(C, expected) << "Matrix multiplication test failed! :(((()";
}

//error: 1, 2, 6, 8, 10, 12, 14, 15, 18
// This test is similar to the previous one, but in this case column are equals to each other, not rows.
/**
 * @brief Construct a new TEST object that multiplies two matrices 10X10 that are respectively the former a matrix with all columns equals
 * between each other, containg all numbers from 0 to 9, and the latter which is an identity matrix
 * @note we expect the resulting matrix to be equal to C
 * 
 * @bug error 1:
 * @bug error 2:
 * @bug error 6:
 * @bug error 8:
 * @bug error 10:
 * @bug error 12:
 * @bug error 14:
 * @bug error 15:
 * @bug error 18:
 */
TEST(MatrixMultiplicationTest6, TestMultiplyMatrices) { //NOME UNICO 
    size_t rowsA = 10;
    size_t colsA = 10;
    size_t colsB = rowsA;
    size_t rowsB = 10;

    std::vector<std::vector<int>> A(rowsA, std::vector<int>(colsA, 0));
    for(size_t i = 0; i < rowsA; ++i) {
        for (size_t j = 0; j < colsA; j++){
            A[i][j] = i;
        }
        
    }
    std::vector<std::vector<int>> B(rowsB, std::vector<int>(colsB, 2));
    for(int i = 0; i < rowsB; ++i) {
        B[i][i] = 1;
    }
    std::vector<std::vector<int>> C(rowsA, std::vector<int>(colsB, 0));

    multiplyMatrices(A, B, C, rowsA, colsB, rowsA); //MAT1(a*b), MAT2(b*c), RESULTING MATRIX(a*c), a,b,c

    std::vector<std::vector<int>> expected(rowsA, std::vector<int>(colsB, 0));
    for(int i = 0; i < rowsA; ++i) {
        expected[i][i] = i;
    }

    ASSERT_EQ(C, expected) << "Matrix multiplication test failed! :(((()";
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
