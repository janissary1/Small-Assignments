#include <stdio.h>

void  mat_mult(int ** arr1, int rows1, int cols1, int ** arr2, int rows2, int cols2, int** arr3)
{
    int sum,counter = 0;
    for (int i = 0; i < rows1; i++)
    {
        for (int k = 0; k < cols2; k++)
        {
            sum = 0;
            for (int j = 0; j < cols1; j++)
            {
            sum += arr1[i][j] * arr2[j][k];
            }
            arr3[i][k] = sum;
        }
    }
}
void mat_out(int ** arr, int rows1, int cols2)
{
 for(int x = 0; x < rows1 ; x++)
    {
        for(int y = 0; y < cols2 ; y++)
        {
          printf(" %d ", arr[x][y]);
        }
        printf("\n");
    }
}
int main()
{
    int row1,col1,row2,col2;
    
    FILE *fp = fopen("matrix.txt", "r");
    
    fscanf(fp,"%d",&row1);
    fscanf(fp, "%d", &col1);
    
    int **matrix1 = calloc(row1, sizeof(int*));
    for(int jj = 0; jj < row1; jj++){matrix1[jj] = calloc(col1, sizeof(int));}

    for(int i = 0; i < row1; i++)
    {
        for(int j = 0; j < col1; j++)
        {
            int input;
            fscanf(fp,"%d",&input);
            matrix1[i][j] = input;
        }
    }
    
    fscanf(fp,"%d",&row2);
    fscanf(fp, "%d", &col2);
    int **matrix2 = calloc(row2, sizeof(int*));
    for(int kk = 0; kk < row2; kk++){matrix2[kk] = calloc(col2, sizeof(int));}

    for(int k = 0; k < row2; k++)
    {
        for(int l = 0; l < col2; l++)
        {
            int input;
            fscanf(fp,"%d",&input);
            matrix2[k][l] = input;
        }
    }
    int **matrix3 = calloc(row1, sizeof(int*));
    for(int xx = 0; xx < row1; xx++){matrix3[xx] = calloc(col2, sizeof(int));}
    mat_mult(matrix1,row1,col1,matrix2,row2,col2,matrix3);
    mat_out(matrix3,row1,col2);

    return 0;
}