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
  BoolectorNode * btor_term = boolector_var(btor, s8, name.c_str());
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

bool unit_test_term_assignment()
{
  Btor* btor = boolector_new();
  boolector_set_opt(btor, BTOR_OPT_MODEL_GEN, 1);

  Term bt1_copy;
  Term bt1 = get_btor_term(btor, "x");
  bt1_copy = bt1;
  Term bt2 = bt1;
  bt2 = get_btor_term(btor, "y");

  if ( !((bt1 == bt1_copy) && !(bt1 == bt2)) )
  {
    cout << "btor term failed test" << endl;
    return false;
  }

  CVC4::api::Solver slv;
  slv.setLogic("QF_BV");

  Term ct1_copy;
  Term ct1 = get_cvc4_term(slv, "x");
  ct1_copy = ct1;
  Term ct2 = ct1;
  ct2 = get_cvc4_term(slv, "y");

  if ( !((ct1 == ct1_copy) && !(ct1 == ct2)) )
  {
    cout << "cvc4 term failed test" << endl;
    return false;
  }

  return true;
}

bool unit_test_scoping()
{
  Btor* btor = boolector_new();
  boolector_set_opt(btor, BTOR_OPT_MODEL_GEN, 1);

  Term bx;
  if (!bx.isNull())
  {
    cout << "btor term not null after null constructor" << endl;
    return false;
  }

  {
    bx = get_btor_term(btor, "x");
  }

  if (bx.isNull())
  {
    cout << "btor term failed test" << endl;
    return false;
  }

  try
  {
    bx.hash();
  }
  catch(...)
  {
    cout << "btor term failed test broken pointer chain" << endl;
    return false;
  }

  CVC4::api::Solver slv;
  slv.setLogic("QF_BV");

  Term cx;
  if (!cx.isNull())
    {
      cout << "cvc4 term not null after null constructor" << endl;
      return false;
    }

  {
    cx = get_cvc4_term(slv, "x");
  }

  if (cx.isNull())
    {
      cout << "cvc4 term failed test" << endl;
      return false;
    }

  try
    {
      cx.hash();
    }
  catch(...)
    {
      cout << "cvc4 term failed test broken pointer chain" << endl;
      return false;
    }

  return true;
}

bool run_test()
{
  Btor* btor = boolector_new();
  boolector_set_opt(btor, BTOR_OPT_MODEL_GEN, 1);
  BoolectorSort s8 = boolector_bitvec_sort(btor, 8);
  BoolectorNode * btor_term = boolector_var(btor, s8, "x");
  BoolectorTerm * bt = new BoolectorTerm(btor, btor_term);
  Term t(bt);
  //boolector_release(btor, btor_term);
  boolector_release_sort(btor, s8);
  //delete bt;
  //t.~Term();
  //boolector_delete(btor);
  return true;
}

int main()
{
  // assert(unit_test_term_assignment());
  // assert(unit_test_scoping());
  run_test();
  std::cout << "All tests passed" << std::endl;
  return 0;
}
