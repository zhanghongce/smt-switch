#include <cassert>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

#include "boolector_term.h"
#include "term.h"

using namespace std;
using namespace smt;

struct TermHash
{
  size_t operator()(const Term& t) const
  {
    return t.hash();
  }
};

using TermMap = std::unordered_map<Term, Term, TermHash>;
using TermVec = std::vector<Term>;

Term get_btor_term(Btor* btor, string name)
{
  BoolectorSort s8 = boolector_bitvec_sort(btor, 8);
  BoolectorNode * btor_term = boolector_var(btor, s8, name.c_str());
  //unique_ptr<BoolectorTerm> bt (new BoolectorTerm(btor, btor_term));
  Term t(std::make_unique<BoolectorTerm>(btor, btor_term));
  return t;
}

int main()
{
  int num_terms = 1500000;
  Btor* btor = boolector_new();
  boolector_set_opt(btor, BTOR_OPT_MODEL_GEN, 1);
  TermMap term_map;
  TermVec term_vec;
  term_vec.reserve(num_terms);
  for(size_t i=0; i < num_terms; i++) {
    Term x = get_btor_term(btor, "x" + std::to_string(i));
    Term y = get_btor_term(btor, "y" + std::to_string(i));
    term_map[x] = y;
    term_vec.push_back(x);
  }
}
