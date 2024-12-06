#include "fft_comp.h"
#include "fft_prep_bit.h"
#include "fft_prep_cpx.h"
#include "cpx_op.h"

void fft_order(int nr, int pwr, double *vct){
  int it;
  double buff[2*nr];

  for(it=0; it < nr; it++)
    asn(buff+2*it, vct+2*it);

  for(it=0; it < nr; it++)
    asn(vct+2*it, buff+2*revidx(it, pwr));
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
/**
    __OBS__:
    This is the most important function in the whole program, the namesake of the project.
    It's paramount that the explanation is clear and thoughtful.
    
    __Variables__:
    @nr <-> the length of the complex vector
    @pwr <-> the logarithm of 2 of 'nr'
    @vct <-> the complex vector

    __Implement__:
    There are two aspects of it that should be clarified:
    1. the layer structure,
    2. the BFS (ButterFly Schema).
    
    Both are explained in the following subsections.  
    
    __Layers__:
    The FFT could be seen as applying the BFS multiple times, until we reach the desired result. 
    A classic BFS has inputs and outputs, here multiple BFSs will be grouped in a _layer_, it's compounded outputs being fed into the inputs of a similar _layer_.
    This gives the algorithm's layered aspect, the input of the first layer being 'vct' and the output of the final layer being the computed FFT.
    Each layer of schemas (SL - Schema Layer) has a corresponding layer of numbers at input (NL - Number Layer), forming together a WL (Whole Layer).
    Each NL will be  
    


    The following explanation for the layer structure is inspired by the one found in 'docu/link/FAST_FOURIER_TRANSFORM.pdf', especially the schema 
    Layer structure: 
    - the computations can be viewed as a process that feeds information from one layer to the next, each layer having 'nr'
    
    , the butterfly computations
    
    , explained 
*/

//Keeps this definition of the function here, maybe later you will try 
//to measure the efficiency of the two variants
// void fft_apply(int nr, int pwr, double *vct, double *rts){
//     double *rtEvn, *rtOdd;
//         
//     int layer, seqLn, pwStp;
//     int elmId, seqId;
//     double *oddOut, *evnOut,
//            oddInp[2], evnInp[2],
//            temp[2];
//     int oddId, evnId;
//
//     for(layer=0, seqLn=1, pwStp=nr/2;
//         layer < pwr;
//         layer++, seqLn*=2, pwStp/=2)
//             for(seqId=0; seqId < nr/seqLn; seqId+=2)
//                 for(elmId=0; elmId < seqLn; elmId++){
//                     
//                     evnId = seqId*seqLn+elmId;
//                     asn(evnInp, vct+2*evnId);
//                     evnOut = vct+2*evnId;
//                     rtEvn = rts+((evnId*pwStp)%nr)*2;
//
//                     oddId = evnId+seqLn;
//                     asn(oddInp, vct+2*oddId);
//                     oddOut = vct+2*oddId;
//                     rtOdd = rts+((oddId*pwStp)%nr)*2;
//
//                     add( evnOut, evnInp,
//                         tms( temp, oddInp, rtEvn)
//                     );
//
//                     add( oddOut, evnInp,
//                         tms( temp, oddInp, rtOdd)
//                     );
//
//                 }
// }

void seqn_butterfly(double *pair, int lenf, double *ruts, int step){
  double  *oonn_seqn = pair, *neun_seqn = pair+2*lenf, 
          *oonn_ruts = ruts, *neun_ruts = ruts+2*lenf*step;

  int iter;

  for(iter=0; iter<lenf; iter++)
    pair_butterfly(
      oonn_seqn+2*iter,
      neun_seqn+2*iter,
      oonn_ruts+2*iter*step,
      neun_ruts+2*iter*step
    );
}

void fft_apply(int nr, int pwr, double *vct, double *rts){
  double *seqn_pair, *vect_stop;
  vect_stop = vct+2*nr;
  int seqn_lenf, layer_cnt, powr_step; 

  for(
    layer_cnt=0, seqn_lenf=1, powr_step=nr/2;
    layer_cnt < pwr;
    layer_cnt++, seqn_lenf*=2, powr_step/=2
  )for(seqn_pair=vct; seqn_pair < vect_stop; seqn_pair+=4*seqn_lenf)
    seqn_butterfly(seqn_pair, seqn_lenf, rts, powr_step);
}
