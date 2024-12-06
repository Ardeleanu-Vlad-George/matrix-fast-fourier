/**
  * \file
  * \brief Treat two consecutive values in an array of doubles as a complex number.
    All functions implement just one operation between complex numbers.
    All functions receive as first argument the pointer in which to save the result.
    All functions return this address at the end of execution.
    Additional addresses are given as inputs, their number based on the operation itself.
    All functions represent operations simple enough that their implementation is self-evident.
    Thus, no further comments are required for explaining the code.
*/

#ifndef _CPX_OP_H_
#define _CPX_OP_H_

double* add(double*, double*, double*);
/**
* \brief 'tms' is shorthand for 'times'
*/
double* tms(double*, double*, double*);
/**
* \brief 'asn' is shorthand for 'assign'
*/
double* asn(double*, double*);

#endif//_CPX_OP_H_
