#include "boolector_term.h"

using namespace smt;

int main()
{
  Btor* btor = boolector_new();
  boolector_set_opt(btor, BTOR_OPT_MODEL_GEN, 1);
  BoolectorSort s8 = boolector_bitvec_sort(btor, 8);
  BoolectorNode *x = boolector_var(btor, s8, "x");
  BoolectorTerm b = BoolectorTerm(btor, x);
  return 0;
}
