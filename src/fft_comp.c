#include "fft_comp.h"
#include "fft_prep_bit.h"
#include "fft_prep_cpx.h"
#include "cpx_op.h"
#include "btr_fly.h"


void fft_order_one(int nmbr, int powr, int line, int clmn, double **mtrx){
  int iter;
  double buff[2*nmbr];

  //VLD - means 'validate', DIM - means the 'dimension to be validated'
  #define VLD(DIM) (DIM<0 || DIM>nmbr-1 ? DIM:iter)

  for(iter=0; iter < nmbr; iter++)
    asn(buff+2*iter, mtrx[VLD(line)]+2*VLD(clmn));

  for(iter=0; iter < nmbr; iter++)
    asn(mtrx[VLD(line)]+2*VLD(clmn), buff+2*revidx(iter, powr));
}

void fft_apply_one(int nmbr, int powr, int line, int clmn, double **mtrx, double *rts){
  double *seqn_pair, *vect_stop;
  vect_stop = *mtrx+2*nmbr*nmbr;
  int seqn_lenf, layer_cnt, powr_step; 

  for(
    layer_cnt=0, seqn_lenf=1, powr_step=nmbr/2;
    layer_cnt < powr;
    layer_cnt++, seqn_lenf*=2, powr_step/=2
  )for(seqn_pair=*mtrx; seqn_pair < vect_stop; seqn_pair+=4*seqn_lenf);

  #undef VLD
}

void fft_order_all(int nmbr, int pwr, double **mtrx){
  int iter;

  for(iter=0; iter < nmbr; iter++)
    fft_order_one(nmbr, pwr, -1, iter, mtrx);

  for(iter=0; iter < nmbr; iter++)
    fft_order_one(nmbr, pwr, iter, -1, mtrx);
}

void fft_apply_all(int nmbr, int pwr, double **mtrx, double *rts){
  int iter;

  for(iter=0; iter < nmbr; iter++)
    fft_apply_one(nmbr, pwr, iter, -1, mtrx, rts);

  for(iter=0; iter < nmbr; iter++)
    fft_apply_one(nmbr, pwr, -1, iter, mtrx, rts);
}
