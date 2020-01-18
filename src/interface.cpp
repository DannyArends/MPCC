#include "interface.h"

extern "C" {

  // Wrap the matrix version into a C call
  void R_pcc_matrix(double* aM, double* bM, int* nptr, int* mptr, int* pptr, double* res, bool* debugptr) {
    #ifndef NOMKL
    if(*debugptr)
      info("[INFO] Library compiled with Intel MKL support: %d\n", 0);
    pcc_matrix((int)(*mptr), (int)(*nptr), (int)(*pptr), aM, bM, res);
    #else
    if(*debugptr)
      info("[INFO] Library compiled with openBLAS support: %d\n", 0);
    pcc_matrix((int)(*mptr), (int)(*nptr), (int)(*pptr), aM, bM, res);
    #endif
  }

  // Wrap the naive version into a C call
  void R_pcc_naive(double* aM, double* bM, int* nptr, int* mptr, int* pptr, double* res, bool* debugptr) {
    pcc_naive((int)(*mptr), (int)(*nptr), (int)(*pptr), aM, bM, res);
  }
}

