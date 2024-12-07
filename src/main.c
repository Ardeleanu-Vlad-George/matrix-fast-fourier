#include <stdio.h>
#include <stdlib.h>
#include "io.h"
#include "fft_comp.h"
#include "fft_prep_bit.h"


int main(){
  double **mtr;
  int size, powr;
  mtr = read("data/in", &size);
  powr = getexp(size);
  fft_order(size, powr, *mtr);
  write("./data/out", size, mtr);

  free(*mtr);
  free(mtr);
  return 0;
}
