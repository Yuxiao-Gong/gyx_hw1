#include "algebra.h"
#include <stdio.h>
#include <math.h>

Matrix create_matrix(int row, int col)
{
    Matrix m;
    m.rows = row;
    m.cols = col;
    return m;
}

Matrix add_matrix(Matrix a, Matrix b)
{
    if (a.rows != b.rows || a.cols != b.cols) {
        printf("Error: Matrix a and b must have the same rows and cols.\n");
        return create_matrix(0, 0);
    }else{
        Matrix result = create_matrix(a.rows, a.cols);
    int i,j;
    for (i = 0; i < a.rows; i++) {
        for (j = 0; j < a.cols; j++) {
            result.data[i][j] = a.data[i][j] + b.data[i][j];
        }
    }
    return result;
    }
}
Matrix sub_matrix(Matrix a, Matrix b)
{
    if (a.rows != b.rows || a.cols != b.cols) {
        printf("Error: Matrix a and b must have the same rows and cols.\n");
        return create_matrix(0, 0);
    }else{
        Matrix result = create_matrix(a.rows, a.cols);
    int i,j;
    for (i = 0; i < a.rows; i++) {
        for (j = 0; j < a.cols; j++) {
            result.data[i][j] = a.data[i][j] - b.data[i][j];
        }
    }
    return result;
    }
}

Matrix mul_matrix(Matrix a, Matrix b)
{
    if (a.rows != b.cols) {
        printf("Error: a.cols must equal to b.rows\n");
        return create_matrix(0, 0);
    }else{
        Matrix result = create_matrix(a.rows, b.cols);
    int i,j,k;
    for (i = 0; i < a.rows; i++) {
        for (j = 0; j < b.cols; j++) {
            result.data[i][j] = 0;
            for (k = 0; k < a.cols; k++) {
                result.data[i][j] += a.data[i][k] * b.data[k][j];
            }
        }
    }
    return result;
    }
}

Matrix scale_matrix(Matrix a, double k)
{
    Matrix scaled = create_matrix(a.rows, a.cols);
    int i,j;
    for (i = 0; i < a.rows; ++i) {
        for (j = 0; j < a.cols; ++j) {
            scaled.data[i][j] = k * a.data[i][j];
        }
    }
    return scaled;
}

Matrix transpose_matrix(Matrix a)
{
    Matrix transposed = create_matrix(a.cols, a.rows);
    int i,j;
    for (i = 0; i < a.rows; ++i) {
        for (j = 0; j < a.cols; ++j) {
            transposed.data[j][i] = a.data[i][j];
        }
    }
    return transposed;
}

double det_matrix(Matrix a)
{
    // ToDo
    return 0;
}

Matrix inv_matrix(Matrix a)
{
    // ToDo
    return create_matrix(0, 0);
}

int rank_matrix(Matrix a)
{
    // ToDo
    return 0;
}

double trace_matrix(Matrix a)
{
    if (a.rows != a.cols) {
        printf("Error: Trace is only defined for square matrices.\n");
        return 0;
    }
    
    double trace = 0.0;
    int i;
    for (i = 0; i < a.rows; ++i) {
        trace += a.data[i][i];
    }
    
    return trace;
}

void print_matrix(Matrix a)
{
    int i;
    for (i = 0; i < a.rows; i++)
    {
        int j;
        for (j = 0; j < a.cols; j++)
        {
            // 按行打印，每个元素占8个字符的宽度，小数点后保留2位，左对齐
            printf("%-8.2f", a.data[i][j]);
        }
        printf("\n");
    }
}