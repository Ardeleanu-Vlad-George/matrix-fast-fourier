/**
 *  \brief The 'main' computations of the FFT
 *  Divided into 2 functions: one for the ordering of the input, the other for
 *  the actual computation
*/

#ifndef _FFT_COMP_H_
#define _FFT_COMP_H_

/**
 *  \brief Order the vector
 *  Move each element to where it's reversed index indicates
 *  @param length [in] - the length of the vector
 *  @param expon [in] - log2 of length
 *  @param vector [out] - vector to reorder
*/
void fft_order(int, int, double*);

/**
 *  \brief Compute the FFT on an already ordered vector
 *  @param length [in] - the length of the vector
 *  @param expon [in] - log2 of length
 *  @param vector [out] - vector to which to apply the FFT 
 *  @param roots [in] - roots of unit, needed for computations
*/
void fft_apply(int, int, double*, double*); 

#endif//_FFT_COMP_H_
