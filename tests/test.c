#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define DELTA 0.1

void createGrid(double *x, double *y, int N)
{
    x[0] = -1.0;
    y[0] = -1.0;
    for(int i=1; i<N; ++i)
    {
            x[i] = x[i-1] + DELTA;
            y[i] = y[i-1] + DELTA;
    }
}

void analytical(double **phiExact,double *x, double *y,double **q,  int N)
{
    for(int i=0; i<N; ++i)
    {
        for(int j=0; j<N; ++j)
        {
            phiExact[i][j] = ((pow(x[i],2.0) - 1.0)) * ((pow(y[j],2.0)) - 1.0);
            q[i][j] = 2 * (2 - (pow(x[i],2)) - (pow(y[j],2)));
                
        }
    }
}

void numericalMethod(double *x, double *y, double **phiNum, double **phiExact,double **residual, double **q, int N)
{
    int count =0;
    for(int i=0; i<N; ++i)
    {
        phiNum[0][i] = 0.0;
        phiNum[N-1][i] = 0.0;
    }

    for(int i=0; i<N; ++i)
    {
        phiNum[i][0] = 0.0;
        phiNum[i][N-1] = 0.0;
    }

    while(count < 20)
    {
        for(int i=1; i<N-1; ++i)
        {
            for(int j=1; j<N-1; ++j)
            {
                phiNum[i][j] = 0.25 * (phiNum[i+1][j] + phiNum[i-1][j] + phiNum[i][j+1] + phiNum[i][j-1]) + (q[i][j] * 0.25 * DELTA * DELTA);
            }
        }

        ++count; 
    }

    // Calculating Residual
    for(int i=0; i<N; ++i)
        for(int j=0; j<N; ++j)
            residual[i][j] = phiExact[i][j] - phiNum[i][j];
}

int main()
{

    int N = (2/DELTA) + 1;

    // Allocating array for analytical method. 
    double **phiExact = (double **)malloc(sizeof(double) * N);
    for(int i=0; i<N; ++i)
        phiExact[i] = (double *)malloc(sizeof(double) * N);

    // Allocating Array for numerical method. 
    double **phiNum = (double **)malloc(sizeof(double) * N);
    for(int i=0; i<N; ++i)
        phiNum[i] = (double *)malloc(sizeof(double) * N);

    // Allocating Array for numerical method. 
    double **q = (double **)malloc(sizeof(double) * N);
    for(int i=0; i<N; ++i)
        q[i] = (double *)malloc(sizeof(double) * N);
    
    // Allocating Array for numerical method. 
    double **residual = (double **)malloc(sizeof(double) * N);
    for(int i=0; i<N; ++i)
        residual[i] = (double *)malloc(sizeof(double) * N);





    
    double x[N], y[N];
    createGrid(x,y,N);
    analytical(phiExact,x,y,q,N);

    numericalMethod(x,y,phiNum,phiExact,residual,q,N);

    for (int i = 0; i < N; i++)
            //printf("%f ",phiNum[i][(3*(N-1)) / 4]); // y = 0.5
            for(int j=0; j<N; ++j)
                printf("%f ",residual[i][j]); // y = 0.5
    
    return 0;
} 

/*

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define DELTA 0.1

void createGrid(double *x, double *y, int N) {
    x[0] = -1.0;
    y[0] = -1.0;
    for(int i = 1; i < N; ++i) {
        x[i] = x[i-1] + DELTA;
        y[i] = y[i-1] + DELTA;
    }
}

void analytical(double **phiExact, double *x, double *y, int N) {
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j)
            phiExact[i][j] = ((pow(x[i], 2.0) - 1.0)) * ((pow(y[j], 2.0)) - 1.0);
    }
}

int main() {
    int N = 10; // Adjust N according to your requirements
    double *x = (double *)malloc(N * sizeof(double));
    double *y = (double *)malloc(N * sizeof(double));
    double **phiExact = (double **)malloc(N * sizeof(double *));
    for (int i = 0; i < N; ++i) {
        phiExact[i] = (double *)malloc(N * sizeof(double));
    }

    createGrid(x, y, N);
    analytical(phiExact, x, y, N);

    for (int i = 0; i < N; i++)
    {
        for(int j=0; j<N; ++j)
            printf("%f ",phiExact[i][j]);
    }

    // Free allocated memory
    free(x);
    free(y);
    for (int i = 0; i < N; ++i) {
        free(phiExact[i]);
    }
    free(phiExact);

    return 0;
}
*/