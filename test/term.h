#ifndef TERM_H
#define TERM_H

//#include "sort.h"
#include <iostream>
#include <memory>

namespace smt
{

  // abstract class
  class TermAbs
  {
  public:
    TermAbs() {};
    virtual ~TermAbs() {};
    virtual void inc() {};
    virtual void dec() {};
    virtual std::size_t hash() const = 0;
    // it would be nice to make this private, but then can't be called by Term
    // unless we make it a friend (which would be strange for CVC4)
    /* Should return true iff the terms are identical */
    virtual bool term_equal(TermAbs* absterm) const = 0;
    virtual std::unique_ptr<TermAbs> clone() const = 0;
    // virtual vector< std::unique_ptr<TermAbs> > getChildren();
    // not sure if these are necessary
    // virtual void delete() = 0;
    // virtual std::size_t getRefCount() const = 0;
  };

// wrapper
class Term
{
 public:
  // TODO fill out
  // constructor
  // copy constructor
  // assignment
  // swap? could use for copy-and-swap idiom
  // destructor

  // children()
  // sort()
  // hash()

  // TermAbs provides:
  //   inc()
  //   dec()
  //   delete() ??
  //   getRefCount() ??
  // which can be used for reference counting or might do nothing
  // TermAbs reference count should start at 1
  // TODO: remove null constructor
  // null constructor -- don't keep this! unsafe
  Term() : term(nullptr) {};
  Term(TermAbs* t) : term(t) {};
  Term(const Term& t) { term = t.term; t.term->inc(); };
  // not sure if we need a move constructor
  Term(Term&& t) { swap(*this, t); };
  ~Term()
  {
    if (term) term->dec();
  };
  Term& operator=(Term t)
    {
     swap(*this, t);
     // TODO: Verify that we don't need inc here, already happened in copy constructor
     //term->inc();
     return *this;
  };
  //Term& operator=(Term&& t) {std::cout << "move assignment" << std::endl; swap(*this, t); term->inc(); return *this; };
  bool operator==(const Term& t) const
  {
    if (typeid(*term) != typeid(*t.term)) return false;
    return term->term_equal(t.term);
  };
  friend void swap(Term& t1, Term& t2)
  {
    std::swap(t1.term, t2.term);
  };
  // TODO: remove this
  bool isNull() { return (term == nullptr); };
  virtual std::size_t hash() const { return term->hash(); } ;
  /* std::vector<Term> children() const */
  /* { */
  /*   std::vector<Term> c; */
  /*   for (std::unique_ptr<TermAbs> t : term->getChildren()) */
  /*   { */
  /*     c.push_back(Term(t->get())); */
  /*   } */
  /*   return c; */
  /* }; */
  /* Sort sort() const = 0; */
  // debugging
 private:
  // TODO: Make this a unique_ptr
  TermAbs* term;
};
}

#endif
