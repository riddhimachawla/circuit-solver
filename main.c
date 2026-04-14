#include <stdio.h>

float G[10][10];
float V[10];
float I[10];

void gaussianElimination(int n){
    float A[10][11]; // augmented matrix

    // Build augmented matrix [G | I]
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            A[i][j] = G[i][j];
        }
        A[i][n] = I[i];
    }

    // Forward Elimination
    for(int k = 0; k < n - 1; k++){
        for(int i = k + 1; i < n; i++){
            float factor = A[i][k] / A[k][k];

            for(int j = k; j <= n; j++){
                A[i][j] -= factor * A[k][j];
            }
        }
    }

    // Back Substitution
    for(int i = n - 1; i >= 0; i--){
        float sum = 0;

        for(int j = i + 1; j < n; j++){
            sum += A[i][j] * V[j];
        }

        V[i] = (A[i][n] - sum) / A[i][i];
    }
}

int main() {

    int r, n, n1, n2, c, i1, i2;
    float R, conductance, current;

    printf("Nodal Analysis Circuit Solver\n");

    printf("Enter number of nodes (excluding ground): ");
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        for( int j=0; j<n; j++){
            G[i][j] = 0;
        }
    }

    printf("Enter number of resistors: ");
    scanf("%d", &r);

   for(int k = 0; k < r; k++){
        printf("\nResistor %d:\n", k+1);

        printf("Enter node 1: ");
        scanf("%d", &n1);

        printf("Enter node 2: ");
        scanf("%d", &n2);

        printf("Enter resistance value: ");
        scanf("%f", &R);

        conductance = 1.0 / R;

        // Stamping
        if(n1 != 0){
            G[n1-1][n1-1] += conductance;
        }

        if(n2 != 0){
            G[n2-1][n2-1] += conductance;
        }

        if(n1 != 0 && n2 != 0){
            G[n1-1][n2-1] -= conductance;
            G[n2-1][n1-1] -= conductance;
        }
    }

    printf("\nConductance Matrix:\n");

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("%.2f ", G[i][j]);
        }
        printf("\n");
    }

    printf("\nEnter number of current sources: ");
    scanf("%d", &c);

    for(int k = 0; k < c; k++){
    printf("\nCurrent Source %d:\n", k+1);

    printf("Enter node from (source): ");
    scanf("%d", &i1);

    printf("Enter node to (destination): ");
    scanf("%d", &i2);

    printf("Enter current value: ");
    scanf("%f", &current);

        if(i1 != 0){
        I[i1-1] -= current;
    }

    if(i2 != 0){
        I[i2-1] += current;
    }
}

printf("\nCurrent Vector (I):\n");

for(int i = 0; i < n; i++){
    printf("%.2f\n", I[i]);
}

gaussianElimination(n);

    // Print Node Voltages
    printf("\nNode Voltages:\n");
    for(int i = 0; i < n; i++){
        printf("V%d = %.2f V\n", i + 1, V[i]);
    }




    return 0;
}