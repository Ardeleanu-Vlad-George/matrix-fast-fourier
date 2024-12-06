#include "fft_prep_bit.h"

int getexp(int L){
  int itr=1, exp=0;
  for(itr=1, exp=0; itr<L; itr*=2,exp++);
  return exp;
}

int revidx(int nr, int bitLen){
    int it, revNr=0;
    for(it=0; it < bitLen; it++){
        revNr <<= 1;
        revNr |= (nr & 1);
        nr >>= 1;
    }
    return revNr;
}
