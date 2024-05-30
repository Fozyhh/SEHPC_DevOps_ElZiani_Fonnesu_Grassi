#include "matrix_multiplication.h"
#include <iostream>
#include <vector>
#include <gtest/gtest.h>

// ######################### Source code of multiplyMatrices in src/matrix_mult

//errors: 6, 12, 14, 20
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
TEST(MatrixMultiplicationTest2, TestMultiplyMatrices) { //NOME UNICO 
    std::vector<std::vector<int>> A = {
        {1, 2, 1},
        {},
        {}

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
