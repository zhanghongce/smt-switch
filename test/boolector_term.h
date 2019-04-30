#ifndef BOOLECTOR_TERM_H
#define BOOLECTOR_TERM_H

#include "boolector/boolector.h"
#include "term.h"

extern "C"
{
  BoolectorNode* boolector_copy(Btor*, BoolectorNode*);
  void boolector_release(Btor*, BoolectorNode*);
}

namespace smt {

class BoolectorTerm : public TermAbs
{
 public:
  BoolectorTerm(Btor* b, BoolectorNode* n) : btor(b), node(n) {};
  void inc() override { boolector_copy(btor, node); };
  void dec() override { boolector_release(btor, node); };
  bool operator==(TermAbs& other) const
  {
   // TODO: Fix this
   return false;
  }
  // TODO: check if this is okay -- probably not
  std::size_t hash() const { return (std::size_t) boolector_get_node_id(btor, node); };
  bool term_equal(const std::unique_ptr<TermAbs>& absterm) const override
  {
    BoolectorTerm* other = static_cast<BoolectorTerm*>(absterm.get());
    return boolector_get_node_id(this->btor, this->node) == boolector_get_node_id(other->btor, other->node);
  }
  std::unique_ptr<TermAbs> clone() const override
  {
    return std::unique_ptr<TermAbs>(new BoolectorTerm(this->btor, this->node));
  }
 private:
  Btor * btor;
  BoolectorNode * node;
};

}

#endif
