#include <stdio.h>
#include <stdlib.h>
#include "io.h"
#include "fft_comp.h"
#include "fft_prep_bit.h"
#include "fft_prep_cpx.h"


int main(){
  double **mtrx;
  double *ruts;
  int size, powr;
  mtrx = read("data/in", &size);
  ruts = every_rou(size);
  powr = getexp(size);
  fft_order(size, powr, *mtrx);
  fft_apply(size, powr, *mtrx, ruts);
  write("./data/out", size, mtrx);

  free(ruts);
  free(*mtrx);
  free(mtrx);
  return 0;
}
