#include <cassert>
#include <iostream>
#include <memory>
#include <string>

#include "boolector_term.h"
#include "cvc4/api/cvc4cpp.h"
#include "term.h"

using namespace std;
using namespace smt;

struct TermHash
{
  size_t operator()(const shared_ptr<TermAbs>& t) const
  {
    return t->hash();
  }
};

using TermP = shared_ptr<TermAbs>;
using TermMap = std::unordered_map<shared_ptr<TermAbs>, shared_ptr<TermAbs>, TermHash>;

TermP get_btor_term(Btor* btor, string name)
{
  BoolectorSort s8 = boolector_bitvec_sort(btor, 8);
  BoolectorNode * btor_term = boolector_var(btor, s8, name.c_str());
  return shared_ptr<TermAbs>(new BoolectorTerm(btor, btor_term));
  // BoolectorTerm * bt = new BoolectorTerm(btor, btor_term);
  // Term t(bt);
  // return t;
}

int main()
{
  Btor* btor = boolector_new();
  boolector_set_opt(btor, BTOR_OPT_MODEL_GEN, 1);
  TermMap term_map;

  for(size_t i=0; i < 2000; i++) {
    TermP x = get_btor_term(btor, "x" + std::to_string(i));
    TermP y = get_btor_term(btor, "y" + std::to_string(i));
    term_map[x] = y;
  }
}
