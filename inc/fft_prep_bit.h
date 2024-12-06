/**
 *  \file
 *  \brief Functions that help with the binary operations of the FFT
*/

#ifndef _FFT_PREP_BIT_H_
#define _FFT_PREP_BIT_H_

/**
 *  \brief Compute the 'left-to-right' inverse of a number's binary form on a given bit length
    The given bit length is computed with the other function based applied to the data's length
    @param index [in] - index to be reversed
    @param length [in] - the 'length' on which the inversion takes place
    \return The binary reversed number
*/
int revidx(int, int);

/**
 *  \brief Compute to which exponent must '2' be raised in order to obtain 'number'
    'number' is for certain a power of two, no checks required
    @param number [in] - number for which to compute
    \return The exponent
*/
int getexp(int);

#endif//_FFT_PREP_BIT_H_
