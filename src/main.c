#include <stdio.h>
#include <stdlib.h>
#include "io.h"

int main(){
  double **mtr;
  int size;
  mtr = read("data/in", &size);
  write("./data/out", size, mtr);
  free(*mtr);
  free(mtr);
  return 0;
}
