#ifndef _BTR_FLY_H_
#define _BTR_FLY_H_

//Apply the butterfly schema to a pair or a sequence, 
//the numbers are expected to be complex, 
//that is achieved in the current project by using 
//two consecutive elements in an array of doubles
void comp_pair(double*, double*, double*, double*);

void comp_seqn(int, double*, int, double*, int, double*, int, double*, int);

#endif//_BTR_FLY_H_
