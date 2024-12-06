#include "cpx_op.h"

double* tms(double* trgt, double* src1, double* src2){
  trgt[0]=src1[0]*src2[0]-src1[1]*src2[1];
  trgt[1]=src1[1]*src2[0]+src1[0]*src2[1];
  return trgt;
}

double* add(double* trgt, double* src1, double* src2){
  trgt[0]=src1[0]+src2[0];
  trgt[1]=src1[1]+src2[1];
  return trgt;
}

double* asn(double* trgt, double* src){
  trgt[0]=src[0]; trgt[1]=src[1];
  return trgt;
}
