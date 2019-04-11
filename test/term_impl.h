#ifndef TERM_IMPL_H
#define TERM_IMPL_H

#include "term.h"
#include <string>

namespace smt
{
  // a dumb term implementation for testing
  class TermImpl : public TermAbs
  {
  public:
    TermImpl(std::string s) : d_str(s)
      {std::cout << "Constructing derived" << std::endl; } ;
    //TermImpl() { d_str = ""; };
    ~TermImpl()
      {std::cout << "Destructing derived" << std::endl; };
    std::size_t hash() const;
    //bool operator==(const TermImpl& t) const;
  private:
    std::string d_str;
  };
}

#endif
