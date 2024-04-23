#include "../inc/algebra.h"
#include <stdio.h>

Matrix create_matrix(int row, int col)
{
    Matrix m;
    m.rows = row;
    m.cols = col;
    return m;
}

Matrix add_matrix(Matrix a, Matrix b)
{
    if(a.cols!=b.cols || a.rows!=b.rows){
        printf("Error: Matrix a and b must have the same rows and cols.\n");
        return create_matrix(0,0);
    }
    Matrix result = create_matrix(a.rows, a.cols);
    for (int i = 0; i < a.rows; i++) {
        for (int j = 0; j < a.cols; j++) {
            result.data[i][j] = a.data[i][j] + b.data[i][j];
        }
    }
    return result;
}

Matrix sub_matrix(Matrix a, Matrix b)
{
    if(a.cols!=b.cols || a.rows!=b.rows){
        printf("Error: Matrix a and b must have the same rows and cols.\n");
        return create_matrix(0,0);
    }
    Matrix result = create_matrix(a.rows, a.cols);
    for (int i = 0; i < a.rows; i++) {
        for (int j = 0; j < a.cols; j++) {
            result.data[i][j] = a.data[i][j] - b.data[i][j];
        }
    }
    return result;
}

Matrix mul_matrix(Matrix a, Matrix b)
{
    // 检查行列
    if (a.cols != b.rows) {
        printf("Error: The number of cols of matrix a must be equal to the number of rows of matrix b.\n");
        return create_matrix(0, 0); // 返回一个空矩阵
    }

    Matrix result = create_matrix(a.rows, b.cols);
    for (int i = 0; i < a.rows; i++) {
        for (int j = 0; j < b.cols; j++) {
            result.data[i][j] = 0; // 初始化结果矩阵的当前元素
            for (int k = 0; k < a.cols; k++) {
                result.data[i][j] += a.data[i][k] * b.data[k][j];
            }
        }
    }
    return result;
}

Matrix scale_matrix(Matrix a, double k)
{   
    Matrix result = create_matrix(a.rows, a.cols);   
    for (int i = 0; i < a.rows; i++) {
        for (int j = 0; j < a.cols; j++) {
            result.data[i][j] = 0; // 初始化结果矩阵的当前元素
            for (int k = 0; k < a.cols; k++) {
                result.data[i][j] = a.data[i][j] * k;
            }
        }
    }
    return result;
}

Matrix transpose_matrix(Matrix a)
{
    //规模转置
    Matrix result = create_matrix(a.cols, a.rows);

    for (int i = 0; i < a.rows; i++) {
        for (int j = 0; j < a.cols; j++) {
            result.data[j][i] = a.data[i][j]; // 交换行列索引进行转置
        }
    }
    return result;
}

double det_matrix(Matrix a)
{   
    // 非方阵报错
    if (a.rows != a.cols) {
        printf("Error: The matrix must be a square matrix.\n");
        return 0;
    }
    // 一维行列式
    if (a.rows == 1) {
        return a.data[0][0];
    }
    // 二维行列式
    if (a.rows == 2) {
        return (a.data[0][0]*a.data[1][1]-a.data[0][1]*a.data[1][0]);
    }
    double Det = 0;
    int sign = 1;
    for(int i = 0; i <a.rows; i++){
        //代数余子式矩阵
        Matrix remain_det = create_matrix(a.rows - 1, a.cols - 1);

        for (int subRow = 0; subRow < a.rows - 1; subRow++) {
            for (int subCol = 0; subCol < a.cols - 1; subCol++) {
                int row = subRow < i ? subRow : subRow + 1;
                int col = subCol < 0 ? subCol : subCol + 1;
                remain_det.data[subRow][subCol] = a.data[row][col];
            }
        }

        Det += sign * a.data[i][0] * det_matrix(remain_det);
        sign = -sign; //-1的幂
    } 
    return 0;
}


Matrix inv_matrix(Matrix a) {
    // 检查是否为方阵
    if (a.rows != a.cols) {
        printf("Error: The matrix must be a square matrix.\n");
        return create_matrix(0, 0); // 返回一个空矩阵
    }

    // 计算行列式
    double det = det_matrix(a);
    if (det == 0) {
        printf("Error: The matrix is singular.\n");
        return create_matrix(0, 0); // 返回一个空矩阵
    }

    // 计算伴随矩阵
    Matrix adj = adjugate_matrix(a);

    // 计算逆矩阵：伴随矩阵的每个元素除以行列式
    Matrix inv = create_matrix(a.rows, a.cols);
    for (int i = 0; i < a.rows; i++) {
        for (int j = 0; j < a.cols; j++) {
            inv.data[i][j] = adj.data[i][j] / det;
        }
    }

    return inv;
}

// 实现计算伴随矩阵的函数
Matrix adjugate_matrix(Matrix a) {
    Matrix adj = create_matrix(a.rows, a.cols);

    for (int i = 0; i < a.rows; i++) {
        for (int j = 0; j < a.cols; j++) {
            // 创建余子矩阵
            Matrix subMatrix = create_matrix(a.rows - 1, a.cols - 1);
            for (int subRow = 0; subRow < a.rows - 1; subRow++) {
                for (int subCol = 0; subCol < a.cols - 1; subCol++) {
                    int row = subRow < i ? subRow : subRow + 1;
                    int col = subCol < j ? subCol : subCol + 1;
                    subMatrix.data[subRow][subCol] = a.data[row][col];
                }
            }
            // 计算余子矩阵的行列式
            double minor = det_matrix(subMatrix);
            // 根据位置决定正负号
            adj.data[j][i] = ((i + j) % 2 == 0 ? 1 : -1) * minor;
        }
    }

    return adj;
}


int rank_matrix(Matrix a) {
    int rank = ((a.rows<a.cols) ? a.rows : a.cols); // r<=min(rows,cols)
    int i, j, k;

    for (i = 0, j = 0; j < a.cols && i < a.rows; j++) {
        // Step a: 检查aii是否为0
        if (a.data[i][j] < 1e-8 && a.data[i][j] > -1e-8) {
            // Step c: 寻找零元素
            int non_zero_found = 0;
            for (k = i + 1; k < a.rows; k++) {
                if (a.data[k][j] > 1e-8 || a.data[k][j] < -1e-8) {
                    // 交换非零行
                    for (int l = 0; l < a.cols; l++) {
                        double temp = a.data[i][l];
                        a.data[i][l] = a.data[k][l];
                        a.data[k][l] = temp;
                    }
                    non_zero_found = 1;
                    break;
                }
            }

            // 无非零元素，下面全0
            if (!non_zero_found) {
                rank--; // 减少r
                continue; // 下一列
            }
        }

        // Step b: 对角线下方全0
        for (k = i + 1; k < a.rows; k++) {
            double factor = a.data[k][j] / a.data[i][j];
            for (int l = j; l < a.cols; l++) {
                a.data[k][l] -= a.data[i][l] * factor;
            }
        }
        i++; // 下一行对角线元素
    }

    return rank;
}
double trace_matrix(Matrix a)
{  
    int trace=0;
    if(a.cols != a.rows){
        printf("Error: The matrix must be a square matrix.\n");
        return 0;
    }
    for(int i = 0; i < a.cols; i++){
        trace += a.data[i][i];
    }
    return trace;
}

void print_matrix(Matrix a)
{
    for (int i = 0; i < a.rows; i++)
    {
        for (int j = 0; j < a.cols; j++)
        {
            // 按行打印，每个元素占8个字符的宽度，小数点后保留2位，左对齐xx
            printf("%-8.2f", a.data[i][j]);
        }
        printf("\n");
    }
}