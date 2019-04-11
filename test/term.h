#ifndef TERM_H
#define TERM_H

//#include "sort.h"
#include <iostream>

namespace smt
{

  // abstract class
  class TermAbs
  {
  public:
    TermAbs()
      {std::cout << "Constructing base" << std::endl; };
    virtual ~TermAbs()
      {std::cout << "base destructor" << std::endl;};
    void inc() {};
    void dec() {};
    virtual std::size_t hash() const = 0;
    //virtual bool operator==(const TermAbs& t) const = 0;
    // virtual std::size_t hash() const = 0;
    // virtual vector< std::unique_ptr<TermAbs> > getChildren();
    // not sure if these are necessary
    // virtual void delete() = 0;
    // virtual std::size_t getRefCount() const = 0;
  };

/* // wrapper */
/* class Term */
/* { */
/*  public: */
/*   // TODO fill out */
/*   // constructor */
/*   // copy constructor */
/*   // assignment */
/*   // swap? could use for copy-and-swap idiom */
/*   // destructor */

/*   // children() */
/*   // sort() */
/*   // hash() */

/*   // TermAbs provides: */
/*   //   inc() */
/*   //   dec() */
/*   //   delete() ?? */
/*   //   getRefCount() ?? */
/*   // which can be used for reference counting or might do nothing */
/*   // TermAbs reference count should start at 1 */
/*   Term(TermAbs* t) : term(t) {}; */
/*   Term(const Term& t) { term = t.term; t.term->inc(); }; */
/*   // not sure if we need a move constructor */
/*   // Term(Term&& t) { swap(*this, other); }; */
/*   virtual ~Term() { term->dec(); }; */
/*   Term& operator=(Term t) { swap(*this, t); term->inc(); return *this; }; */
/*   //bool operator==(const Term& t) const { return (*term) == *(t.term); }; */
/*   friend void swap(Term& t1, Term& t2) { std::swap(t1.term, t2.term); }; */
/*   /\* std::vector<Term> children() const *\/ */
/*   /\* { *\/ */
/*   /\*   std::vector<Term> c; *\/ */
/*   /\*   for (std::unique_ptr<TermAbs> t : term->getChildren()) *\/ */
/*   /\*   { *\/ */
/*   /\*     c.push_back(Term(t->get())); *\/ */
/*   /\*   } *\/ */
/*   /\*   return c; *\/ */
/*   /\* }; *\/ */
/*   /\* Sort sort() const = 0; *\/ */
/*  private: */
/*   TermAbs* term; */
/* }; */
}

#endif
