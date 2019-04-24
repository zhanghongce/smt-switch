#include <string>
#include <iostream>

#include "term_impl.h"
#include "cvc4/api/cvc4cpp.h"

void cast_test(smt::TermAbs* t)
{
  CVC4::api::Term* ct = static_cast<CVC4::api::Term*>(t);
  CVC4::api::Sort cs = ct->getSort();
  std::cout << cs.toString() << std::endl;
}

int main()
{
  CVC4::api::Solver slv;
  slv.setLogic("QF_BV");
  CVC4::api::Sort bitvector32 = slv.mkBitVectorSort(32);
  CVC4::api::Term x = slv.mkVar(bitvector32, "x");
  // smt::TermImpl t = smt::TermImpl("x");
  std::cout << "here" << std::endl;
  //smt::Term t = smt::Term(&x);
  smt::TermAbs * tp = &x;
  std::cout << "after TermAbs" << std::endl;
  // cast_test(tp);
  return 0;
}
