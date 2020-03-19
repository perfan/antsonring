// 
// walkring_timestep.cc
//
// Time stepping module for 1d random walk on a ring
//

#include "walkring_timestep.h"
#include <random>
#include <iostream>

// Perform a single time step for the random walkers
//
// parameters:
//
//  walkerpositions: the positions of a number of walkers (note that
//                   the number of walker Z can be found from
//                   Z=walkerpositions.size())
//
//  N:               the number of possible positions. All positions
//                   in the walkerpositions array should remain
//                   between 0 and N-1
//
//  prob:            the probability to jump to the left. Also the
//                   probability to just right.  (the probability to
//                   stay on the same spot is thus 1-2p.)
//
// output:
//
//  the content of the walkerpositions arrays should have changed to
//  reflect the random movement of all walker (i.e., they will each
//  have been given a chance to move on position to the left or two
//  the right).
//
void walkring_timestep(rvector<int>& walkerpositions, int N, double prob)
{   
 
    std::random_device rd;              //  Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd());             //  Standard mersenne_twister_engine seeded with rd()
    std::normal_distribution<double> dis(0.5, 0.2);
    double r = dis(gen);

    for (int i=0; i < walkerpositions.size(); i++)
    {   
        r = dis(gen);

        if (r < prob && walkerpositions[i] < N-1 && walkerpositions[i] > 0){
            walkerpositions[i] =  walkerpositions[i] - 1;
        }

        if (r > 1.0 - prob && walkerpositions[i] < N-1 && walkerpositions[i] > 0){
            walkerpositions[i] =  walkerpositions[i] + 1;
        }

        if (walkerpositions[i] == N-1){
            walkerpositions[i] =  1;
        }

        if (walkerpositions[i] == 0){
            walkerpositions[i] =  N-2;
        }

        else {
            walkerpositions[i] =  walkerpositions[i];
        } 
    }

}


