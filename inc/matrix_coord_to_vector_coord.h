#ifndef _MATRIX_COORD_TO_VECTOR_COORD_H_
#define _MATRIX_COORD_TO_VECTOR_COORD_H_

//Macros designed to translate the coordinates of a matrix
//represented as a vector to the coordinate/index needed
//to access the underlying vector
//The macros take as argument the address of the matrix
//and return the address to the specified element

#define elem(MATRIX, IDX_LN, IDX_CM) MATRIX

#endif//_MATRIX_COORD_TO_VECTOR_COORD_H_
