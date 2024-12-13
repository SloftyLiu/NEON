#include <stdio.h>
#include <time.h>

// 矩阵大小
#define SIZE 4
// 循环次数
#define ITERATIONS 10000000

void matrix_multiply(float A[SIZE][SIZE], float B[SIZE][SIZE], float C[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            C[i][j] = 0;
            for (int k = 0; k < SIZE; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    // 初始化矩阵 A 和 B
    float A[SIZE][SIZE] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    float B[SIZE][SIZE] = {
        {17, 18, 19, 20},
        {21, 22, 23, 24},
        {25, 26, 27, 28},
        {29, 30, 31, 32}
    };

    float C[SIZE][SIZE] = {0};

    // 记录开始时间
    clock_t start = clock();

    // 进行多次矩阵乘法
    for (int i = 0; i < ITERATIONS; i++) {
        matrix_multiply(A, B, C);
    }

    // 记录结束时间
    clock_t end = clock();

    // 计算并打印时间
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time taken for %d iterations: %f seconds\n", ITERATIONS, time_spent);

    // 打印结果矩阵 C
    printf("Result matrix C:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%f ", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}