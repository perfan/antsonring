// 
// diffring_timestep.cc
//
// Time step module for 1d diffusion on a ring
//

#include "diffring_timestep.h"
#include <cblas.h>
#include <cmath>
#include <iostream>
#include <iomanip>


// perform a single time step for the random walkers
void diffring_timestep(const rmatrix<double>& F, rvector<double>& P)
{
    int n = F.extent(0);
    double a = 1.0, b = 0.0;  
    double *rhs = new double[n];
    
    for(int i = 0; i < n; i++) { 
        rhs[i] = P[i]; 
    }

    cblas_dgemv(CblasRowMajor, CblasNoTrans, n, n, a, F[0], n, rhs, 1, b, P, 1);
    delete [] rhs;

}

// fill the matrix needed in perform_time_step
void diffring_fill_timestep_matrix(rmatrix<double>& F, double D, double dt, double dx)
{
   int n = F.extent(0); 
   double alpha = dt * D / (dx*dx);

    for(int i = 0; i < n; i++) { 
        for(int j = 0; j < n; j++)
            F[i][j] = 0.0;
    } 

    for (int i = 0; i < n; i++)
    {

        if (i==0) {
            F[i][0] = 1.0 - 2.0 * alpha;
            F[i][1] = alpha;
            F[i][n-1] = alpha;
        }

        if (i==n-1) {
            F[i][0] = alpha;
            F[i][n-2] = alpha;
            F[i][n-1] = 1.0 - 2.0 * alpha;
        }

        if ((i > 0) && (i < (n - 1))) {
            F[i][i-1] = alpha;  
            F[i][i] = 1.0 - 2.0 * alpha; 
            F[i][i+1] = alpha;
        } 
    }

}
