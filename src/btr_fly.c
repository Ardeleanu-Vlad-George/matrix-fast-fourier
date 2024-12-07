#include "btr_fly.h"
#include "cpx_op.h"

void comp_pair(double *oonn_elem, double *neun_elem, double *oonn_coef, double *neun_coef){
  //Variable's name is shortened from 'store'
  double stor[6];
  //first two elements are for storing the old value 
  //of the uniform element, next two are for the 
  //ne-uniform values, last two serve as temporary
  //value in computing the equations
  asn(stor  , oonn_elem);
  asn(stor+2, neun_elem);
  add(
    oonn_elem, stor, 
    tms(stor+4, stor+2, oonn_coef)
  );
  add(
    neun_elem, stor, 
    tms(stor+4, stor+2, neun_coef)
  );
}

void comp_seqn(
  int lenf,
  double *oonn_elem, int un_lm_step,
  double *neun_elem, int ne_lm_step,
  double *oonn_coef, int un_cf_step,
  double *neun_coef, int ne_cf_step
){
  int iter;
  for(iter=0; iter<lenf; iter++)
    comp_pair(
      oonn_elem+iter*un_lm_step*2,
      neun_elem+iter*ne_lm_step*2,
      oonn_coef+iter*un_cf_step*2,
      neun_coef+iter*ne_cf_step*2
    );
}
