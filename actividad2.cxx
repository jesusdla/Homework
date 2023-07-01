#include <stdio.h>
#include <stdlib.h>

int LeerMatriz(int n, int m, int **D) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("Introduzca el valor de la celda %d, %d: ", i, j);
            scanf("%d", &D[i][j]);
        }
    }
    return 0;
}

int TranspMatriz(int n, int m, int **D, int **E) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            E[j][i] = D[i][j];
        }
    }
    return 0;
}

int SumarMatriz(int n, int m, int **D, int **E, int **F) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            F[i][j] = D[i][j] + E[i][j];
        }
    }
    return 0;
}

int EscribirMatriz(int n, int m, int **D) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("%d ", D[i][j]);
        }
        printf("\n");
    }
    return 0;
}

int main() {
    int n, m;
    printf("Ingrese las dimensiones de las matrices (n m): ");
    scanf("%d %d", &n, &m);

    // Allocate memory for matrix A
    int **A = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        A[i] = (int *)malloc(m * sizeof(int));
    }

    // Allocate memory for matrix B
    int **B = (int **)malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++) {
        B[i] = (int *)malloc(n * sizeof(int));
    }

    // Allocate memory for matrix C
    int **C = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        C[i] = (int *)malloc(m * sizeof(int));
    }

    printf("Ingrese los elementos de la matriz A:\n");
    LeerMatriz(n, m, A);

    printf("Ingrese los elementos de la matriz B:\n");
    LeerMatriz(m, n, B);

    printf("La matriz A es:\n");
    EscribirMatriz(n, m, A);

    printf("La matriz B es:\n");
    EscribirMatriz(m, n, B);

    printf("La transpuesta de la matriz A es:\n");
    TranspMatriz(n, m, A, C);
    EscribirMatriz(m, n, C);

    printf("La transpuesta de la matriz B es:\n");
    TranspMatriz(m, n, B, C);
    EscribirMatriz(n, m, C);

    printf("La suma de las transpuestas de A y B es:\n");
    SumarMatriz(n, m, A, C, C);
    EscribirMatriz(n, m, C);

    // Free memory
    for (int i = 0; i < n; i++) {
        free(A[i]);
        free(C[i]);
    }
    free(A);
    free(C);

    for (int i = 0; i < m; i++) {
        free(B[i]);
    }
    free(B);

    return 0;
}

