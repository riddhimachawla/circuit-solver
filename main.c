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

    printf("Nodal Analysis Circuit Solver\n");
    int n;

    printf("Enter number of nodes (excluding ground): ");
    scanf("%d", &n);

initialization(n);
    printf("\nInitialized Conductance Matrix:\n");
    for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
        printf("%.2f ", G[i][j]);
    }
    printf("\n");
}


    return 0;
}