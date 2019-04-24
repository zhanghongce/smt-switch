#include <cassert>
#include <iostream>
#include <string>

#include "boolector_term.h"
#include "cvc4/api/cvc4cpp.h"
#include "term.h"

using namespace std;
using namespace smt;

Term get_btor_term(Btor* btor, string name)
{
  BoolectorSort s8 = boolector_bitvec_sort(btor, 8);
  BoolectorNode *btor_term = boolector_var(btor, s8, name.c_str());
  BoolectorTerm * bt = new BoolectorTerm(btor, btor_term);
  Term t(bt);
  return t;
}

Term get_cvc4_term(CVC4::api::Solver& slv, string name)
{
  CVC4::api::Sort bitvector8 = slv.mkBitVectorSort(8);
  CVC4::api::Term ct = slv.mkVar(bitvector8, name);
  CVC4::api::Term * ctp = new CVC4::api::Term(ct);
  Term t(ctp);
  return t;
}

int main()
{
  Btor* btor = boolector_new();
  // callWhatAmI(t);

  Term bt = get_btor_term(btor, "x");

  // CVC4::api::Solver slv;
  // slv.setLogic("QF_BV");

   // std::cout << "now with get_btor_term" << std::endl;
   // Term b_y = get_btor_term(btor, "y");  // CVC4::api::Sort bitvector8 = slv.mkBitVectorSort(8);
  // CVC4::api::Term t = slv.mkVar(bitvector8, "x");
  // std::cout << t.toString() << std::endl;
  // CVC4::api::Term * tp = new CVC4::api::Term(t);
  // std::cout << tp << " " << &t << std::endl;
  //std::cout << tp->toString() << std::endl;
  // CVC4::api::Term * tp = new CVC4::api::Term(t);
  // std::cout << "here" << std::endl;  return 0;
}
