/**
 *  \brief Needed for computing the 'complex number' elements of a FFT algorithm.
 *  'rou' stands for 'root of unit'
*/

#ifndef _FFT_PREP_CPX_H_
#define _FFT_PREP_CPX_H_

/**
 *  \brief Compute all of the numbers 'x' for which x^N=1 is true
 *  \return An array storing all of this numbers, must be freed by the user
    @param grade [in] - the grade for which it is computed
*/
double* every_rou(int);

/**
 *  \brief Compute the first ROU different from (1, 0)
 *  Save to the given address the first ROU of N-th grade different from (1, 0)
    @param grade [in] - the grade for which it is computed
    @param dst [out] - destination at which to save the computed root
*/
void first_rou(int, double*);


#endif//_FFT_PREP_CPX_H_
