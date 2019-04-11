#include "term_impl.h"
#include <string>

using namespace std;

namespace smt
{
size_t TermImpl::hash() const
{
  return std::hash<string>()(d_str);
}

// bool TermImpl::operator==(const TermAbsl& t) const
// {
//   return d_str == t.d_str;
// }

} // namespace smt
