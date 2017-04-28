#ifndef __BIGNUM_LCBNL_H
  #line 2 "bignum"
  #include <stdint.h>

  #define __BIGNUM_LCBNL_H

typedef long double ldbl_t;

typedef struct st_bignum_t { 
  int8_t
     * sign_flag, // ease-of-access pointers to data + 1
     * int_dgts,  // = data + 2
     * frc_dgts,  // = data + 3
     * end_sen,   // = data + 4 + *int_dgts + *frc_dgts 

  /* 
    structure:
      SF   sign flag, like above, -1 for negative 1 for positive
      ID   number of integer digits after the next element
      FD   number of fractional digits after this element
      SC.. any number of significands'
      ES   ending sentinel (usually 10, any multi-digit number)
               SF ID FD SC SC SC SC SC SC SC SC SC SC SC SC ES
    example: { -1  3  9  5  1  2  7  6  6  6  6  6  6  6  5 13 } --> -512.766666665
  */
    * data;
  
  size_t uid;
} bignum_t;
  
char*      bignum_see (const bignum_t* const bn);
bignum_t* bignum_ctor (const float fl, const double db, const ldbl_t ldb);
bignum_t* bignum_dtor (bignum_t* const bn);
ldbl_t bignum_to_ldbl (const bignum_t* const bn);

#endif
