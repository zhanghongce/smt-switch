#include "boolector/boolector.h"

int main(void)
{
  Btor *btor = boolector_new();
  boolector_set_opt(btor, BTOR_OPT_MODEL_GEN, 1);
  BoolectorSort s8 = boolector_bitvec_sort(btor, 8);
  BoolectorNode *x = boolector_var(btor, s8, "x");
  // BoolectorNode *y = boolector_var(btor, s8, "y");
  return 0;
}
