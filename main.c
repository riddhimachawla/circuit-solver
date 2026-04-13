#include <stdio.h>

float G[10][10];
float V[10];
float I[10];

void initialization(int n){
    for(int i=0; i<n; i++){
        for( int j=0; j<n; j++){
            G[i][j] = 0;
        }
    }
}

int main() {

    int r, n, n1, n2;
    float R, conductance;

    printf("Nodal Analysis Circuit Solver\n");

    printf("Enter number of nodes (excluding ground): ");
    scanf("%d", &n);
    initialization(n);

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


    return 0;
}