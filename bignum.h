#line 1 "bignum"
#include <stdint.h>

#ifndef __BIGNUM_LCBNL_H
  #define __BIGNUM_LCBNL_H

typedef long double ldbl_t;

typedef struct st_bignum_t { 
  // UNUSED: int8_t sign_flag; // redundant? -1 = negative, 1 = positive, other vals invalid
  
  /* 
    structure:
      SF   sign flag, like above, -1 for negative 1 for positive
      ID   number of integer digits after the next element
      FD   number of fractional digits after this element
      SC.. any number of significands'
      ES   ending sentinel (usually 10, any multi-digit number)
               SF ID FD SC SC SC SC SC SC SC SC SC SC SC SC ES
    example: { -1  3  2  5  1  2  7  6  6  6  6  6  6  6  5 13 } --> -512.766666665
  */
  int8_t* data;
  
  size_t uid;
} bignum_t;
  
char*     bignum_see (const bignum_t* const bn);
bignum_t* bignum_new (const float fl, const double db, const ldbl_t ldb);
#endif
