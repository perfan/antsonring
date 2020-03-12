/// 
/// @file walkring_output.h
///
/// @brief Module for output for 1d random walk on a ring.
///
#ifndef WALKRINGOUTPUTH
#define WALKRINGOUTPUTH

#include <fstream>
#include <rarray>

/// @brief Setup output into a file of file name datafilename.
///        A header will be written to screen as well.
///
/// @param file          the file object to use to open a file
/// @param datafilename  name of the file to open
void walkring_output_init(std::ofstream& file, std::string datafilename);

/// @brief Output into a file of file name datafilename. There will be
///        other output to screen as well, such as a little histogram
///        of where the walkers are.
///
/// @param file        the file object to use
/// @param step        number of the current time step
/// @param time        current value of the time
/// @param N           number of grid points
/// @param w           position of the walkers
/// @param outputcols  width of the output graph.
void walkring_output(std::ofstream& file, int step, double time, int N, const rvector<int> &w, int outputcols);

/// @brief Finalize output.
///
/// @param file the file object that was used.
void walkring_output_finish(std::ofstream& file);

#endif

