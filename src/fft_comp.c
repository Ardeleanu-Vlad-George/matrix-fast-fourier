#include "fft_comp.h"
#include "fft_prep_bit.h"
#include "fft_prep_cpx.h"
#include "cpx_op.h"
#include "btr_fly.h"

void fft_order_one(int type, int nr, int pwr, double *vct){
  //type: 0 means line, 1 means column
  int iter;
  double buff[2*nr];

  for(iter=0; iter < nr; iter++)
    asn(buff+2*iter, vct+2*iter*(type?nr:1));

  for(iter=0; iter < nr; iter++)
    asn(vct+2*iter*(type?nr:1), buff+2*revidx(iter, pwr));
}

void fft_order(int nr, int pwr, double *vct){
  int iter;

  for(iter=0; iter < nr; iter++)
    fft_order_one(0, nr, pwr, vct+2*iter*nr);

  for(iter=0; iter < nr; iter++)
    fft_order_one(1, nr, pwr, vct+2*iter);
}
/**
 * Consider the next equations making up the butterfly schema:
 * a <- a+b*x
 * b <- a+b*y
 * The 'a' term doesn't have it's own coeficients, it is uniform.
 * The 'b' term does have them so let's call ne-uniform.
 * The two equations have similar names based on the variable to which
 * they are assigned, the coeficients have similar names
 * In order to have notations easy to align, this program uses
 * 'oonn' for 'UNiform' and 'neun' for 'ne-uniform'
*/

void pair_butterfly(double *oonn, double *neun, double *oonn_coef, double *neun_coef){
  //first two belong to the even number, second two to the uneven one
  //last two to the term obtained by multiplying the uneven number 
  double cache[6];
  asn(cache   , oonn);
  asn(cache+2 , neun);
  add(
    oonn, cache, tms(
      cache+4, cache+2, oonn_coef
    )
  );
  add(
    neun, cache, tms(
      cache+4, cache+2, neun_coef
    )
  );
}

void fft_butterfly(int type, int nmbr, double *pair, int lenf, double *ruts, int step){
  double  *oonn_seqn = pair, *neun_seqn = pair+2*lenf, 
          *oonn_ruts = ruts, *neun_ruts = ruts+2*lenf*step;
  
  comp_seqn(lenf, oonn_seqn, type?nmbr:1, neun_seqn, type?nmbr:1, oonn_ruts, step, neun_ruts, step);
}

void fft_apply_one(int type, int nr, int pwr, double *vct, double *rts){
  //0 - means line, 1 - means column
  double *seqn_pair, *vect_stop;
  vect_stop = vct+2*nr;
  int seqn_lenf, layer_cnt, powr_step; 

  for(
    layer_cnt=0, seqn_lenf=1, powr_step=nr/2;
    layer_cnt < pwr;
    layer_cnt++, seqn_lenf*=2, powr_step/=2
  )for(seqn_pair=vct; seqn_pair < vect_stop; seqn_pair+=4*seqn_lenf)
    fft_butterfly(type, nr, seqn_pair, seqn_lenf, rts, powr_step);
}

void fft_apply(int nr, int pwr, double *vct, double *rts){
  int iter;

  for(iter=0; iter < nr; iter++)
    fft_apply_one(0, nr, pwr, vct+2*iter*nr, rts);

  for(iter=0; iter < nr; iter++)
    fft_apply_one(1, nr, pwr, vct+2*iter, rts);
}
