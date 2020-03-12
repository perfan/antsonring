/// 
/// @file diffring_timestep.h
///
/// @brief Time step module for 1d diffusion on a ring
///

#ifndef DIFFRINGTIMESTEPH
#define DIFFRINGTIMESTEPH

#include <rarray>

/// @brief Perform a single time step for the density field.
///
/// @param F  matrix that describes the time evolution
/// @param P  the density
void diffring_timestep(const rmatrix<double>& F, rvector<double>& P);

/// @brief Fill the matrix needed in perform_time_step.
///
/// @param F   matrix that describes the time evolution
/// @param D   the diffusion constant
/// @param dt  the time step to be used
/// @param dx  the spatial resolution
void diffring_fill_timestep_matrix(rmatrix<double>& F, double D, double dt, double dx);

#endif
