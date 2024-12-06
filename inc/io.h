/**
    \file io.h
    \brief Module is responsible for program's specific I/O operations
    No checks are performed testing the file's existence or not, it's assumed to be
    true.
    There are 2 functions: one for reading the input vector and one for writing the 
    resulting DFT.
*/

#ifndef _IO_H_
#define _IO_H_

/**
    \brief Read from the input file a square matrix, give back matrix of complex doubles
    In this project a complex double is made from two consecutive doubles in an
    array.
    Since the stored values must be capable of having an imaginary part, 
    the number of columns is double the number of rows, first row is real
    second is imaginary, and so on
    The matrix organizing principle is "all rows saved into one"
    @param file [in] - the name of the input file
    @param length [out] - the address at which the size of the matrix will be saved
    \return array of pointers to double, the pointers represent rows, their members represent elements,
    the user must free the memory of the first row, then of the whole array of pointers
*/
double** read(char*, int*);

/**
    \brief Write vector of complex doubles representing the DFT
    In this project a complex double is made from two consecutive doubles in an
    array.
    Print the matrix indicated by the pointer to pointer to double organized as 
    stated in function's "read" documentation
    @param file [in] - the name of the output file
    @param size [in] - length of the result to be printed
    @param result [in] - result to be printed
*/
void write(char*, int, double**);

#endif//_IO_H_
