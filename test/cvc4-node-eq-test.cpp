#include "cvc4/api/cvc4cpp.h"

#include <iostream>

using namespace CVC4::api;

int main()
{
  Solver slv;
  slv.setLogic("QF_BV");
  Sort bv8 = slv.mkBitVectorSort(8);
  Term x = slv.mkVar(bv8, "x");
  Term y = slv.mkVar(bv8, "y");

  std::cout << (x == y) << std::endl;

  return 0;
}
