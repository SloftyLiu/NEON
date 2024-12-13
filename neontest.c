#include <arm_neon.h>
#include <stdio.h>
#include <time.h>

// 矩阵大小
#define SIZE 4
// 循环次数
#define ITERATIONS 10000000

void matrix_multiply(float32_t A[SIZE][SIZE], float32_t B[SIZE][SIZE], float32_t C[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
          // 加载矩阵 A 的一行
          float32x4_t a = vld1q_f32(&A[i][0]);

          // 加载矩阵 B 的一列
          float32x4_t b = {B[0][j], B[1][j], B[2][j], B[3][j]};
          
          // 将结果存储到矩阵 C 中
          C[i][j] = vaddvq_f32(vmulq_f32(a, b));
        }
    }
}

int main() {
    // 初始化矩阵 A 和 B
    float32_t A[SIZE][SIZE] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    float32_t B[SIZE][SIZE] = {
        {17, 18, 19, 20},
        {21, 22, 23, 24},
        {25, 26, 27, 28},
        {29, 30, 31, 32}
    };

    float32_t C[SIZE][SIZE] = {0};

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