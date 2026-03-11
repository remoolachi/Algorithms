#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double gauss_method(double** matrix, int n){
    double det = 1.0;

    for (int i=0; i<n; i++){
        double main = fabs(matrix[i][i]);
        int max = i;

        for (int k = i+1; k<n; k++){
            if (fabs(matrix[k][i]) > main){
                main = fabs(matrix[k][i]);
                max = k;
            }
        }

        if (main == 0) return 0.0;

        if (max!=i){
            double* row = matrix[i];
            matrix[i] = matrix[max];
            matrix[max] = row;
            det = -det;
        }
        det*= matrix[i][i];

        for (int k = i+1; k<n; k++){
            double new = matrix[k][i]/matrix[i][i];
            for (int j=i; j<n; j++){
                matrix[k][j] -= new * matrix[i][j];
            }
        }

    }
    return det;

}

int main(void){
    int n;

    printf("Dimension: ");
    scanf("%d", &n);

    double** matrix = (double**)malloc(n*sizeof(double*));
    for (int i=0; i<n; i++){
        matrix[i] = (double*)malloc(n *sizeof(double));
    }

    printf("Elements: ");
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++) scanf("%lf", &matrix[i][j]);
    }

    double det = gauss_method(matrix, n);
    printf("Determinant: %f", det);

    for (int i=0; i<n; i++) free(matrix[i]);
    free(matrix);
    
    return 0;




}