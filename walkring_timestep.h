///
/// @file walkring_timestep.h
///
/// @brief Module to perform a single time step for the random walkers.
///
#ifndef WALKRINGTIMESTEPH
#define WALKRINGTIMESTEPH

#include <rarray>

/// @brief Perform a single time step for the random walkers
///
/// @param walkerpositions  the positions of a number of walkers, which 
///              will get updated to reflect the random movement of all
///              walker (i.e., they will each have been given a chance
///              to move on position to the left or two the right).
///
/// @param N:    the number of possible positions. All positions
///              in the walkerpositions array should remain
///              between 0 and N-1
///
/// @param prob  the probability to jump to the left. Also the
///              probability to just right.  (the probability to
///              stay on the same spot is thus 1-2p.)
void walkring_timestep(rvector<int>& walkerpositions, int N, double prob);

#endif
