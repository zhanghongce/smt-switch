#include <string>
#include <iostream>

#include "term_impl.h"
#include "cvc4/api/cvc4cpp.h"


int main()
{
  CVC4::api::Solver slv;
  slv.setLogic("QF_BV");
  CVC4::api::Sort bitvector32 = slv.mkBitVectorSort(32);
  CVC4::api::Term x = slv.mkVar(bitvector32, "x");
  CVC4::api::Term y = slv.mkVar(bitvector32, "y");
  smt::TermAbs * tax = &x;
  smt::TermAbs * tay = &y;
  std::cout << (*tax == *tay) << std::endl;
  return 0;
}
