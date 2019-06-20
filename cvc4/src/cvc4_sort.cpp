#include "exceptions.h"

#include "cvc4_sort.h"

namespace smt {

std::string CVC4Sort::to_string() const
{
  return sort.toString();
}

unsigned int CVC4Sort::get_width() const
{
  return sort.getBVSize();
}

Sort CVC4Sort::get_indexsort() const
{
  Sort idxsort(new CVC4Sort(sort.getArrayIndexSort()));
  return idxsort;
}

Sort CVC4Sort::get_elemsort() const
{
  Sort elemsort(new CVC4Sort(sort.getArrayElementSort()));
  return elemsort;
}

std::vector<Sort> CVC4Sort::get_domain_sorts() const
{
  std::vector<::CVC4::api::Sort> cvc4_sorts = sort.getFunctionDomainSorts();
  std::vector<Sort> domain_sorts;
  domain_sorts.reserve(cvc4_sorts.size());
  Sort s;
  for (auto cs : cvc4_sorts)
  {
    s.reset(new CVC4Sort(cs));
    domain_sorts.push_back(s);
  }
  return domain_sorts;
}

Sort CVC4Sort::get_codomain_sort() const
{
  Sort s(new CVC4Sort(sort.getFunctionCodomainSort()));
  return s;
}

bool CVC4Sort::compare(const Sort s) const
{
  std::shared_ptr<CVC4Sort> cs = std::static_pointer_cast<CVC4Sort> (s);
  return sort == cs->sort;
}

SortCon CVC4Sort::get_sort_con() const
{
  if (sort.isBoolean())
  {
    return BOOL;
  }
  else if (sort.isBitVector())
  {
    return BV;
  }
  else if (sort.isInteger())
  {
    return INT;
  }
  else if (sort.isReal())
  {
    return REAL;
  }
  else if (sort.isArray())
  {
    return ARRAY;
  }
  else if (sort.isFunction())
  {
    return UNINTERPRETED;
  }
  else
  {
    throw NotImplementedException("Unknown kind in CVC4 translation.");
  }
}

}
