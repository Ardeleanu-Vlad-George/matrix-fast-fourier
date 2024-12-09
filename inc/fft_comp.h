/**
 *  \brief The 'main' computations of the FFT
 *  Divided into 2 functions: one for the ordering of the input, the other for
 *  the actual computation
*/

#ifndef _FFT_COMP_H_
#define _FFT_COMP_H_

/**
 *  \brief Order the line or column of the matrix, indicated by the valid index
 *  Move each element to where it's reversed index indicates
 *  To indicate if the function works on lines or columns
 *  give what you want to work on as a valid index
 *  If indices are valid, the function can't work, the matrix remains the same
 *  Same story if both are invalid
 *  @param size [in] - the size of the vector
 *  @param expon [in] - log2 of size
 *  @param line [in] - the line of the matrix
 *  @param column [in] - the column of the matrix
 *  @param matrix [out] - matrix to reorder
*/
void fft_order_one(int, int, int, int, double**);

/**
 *  \brief Order the matrix
 *  Apply the 'fft_order_one' function for all of the lines
 *  and columns
 *  @param size [in] - the size of the vector
 *  @param expon [in] - log2 of size
 *  @param matrix [out] - matrix to reorder
*/
void fft_order_all(int, int, double**);

/**
 *  \brief Compute the FFT on an already ordered matrix line, column
 *  Same protocol for selecting lines/columns
 *  @param size [in] - the size of the vector
 *  @param expon [in] - log2 of size
 *  @param line [in] - the line of the matrix
 *  @param column [in] - the column of the matrix
 *  @param matrix [out] - matrix to reorder
 *  @param roots [in] - roots of unit, needed for computations
*/
void fft_apply_one(int, int, int, int, double**, double*); 

/**
 *  \brief Compute the FFT on an already ordered vector
 *  @param size [in] - the size of the vector
 *  @param expon [in] - log2 of size
 *  @param matrix [out] - matrix to reorder
 *  @param roots [in] - roots of unit, needed for computations
*/
void fft_apply_all(int, int, double**, double*); 

#endif//_FFT_COMP_H_
