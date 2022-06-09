#ifndef _FT_MAP_HPP
#define _FT_MAP_HPP

#include "../config.hpp"
_BEGIN_NAMESPACE_FT
// namespace_start
template <class T>
class map {
 protected:
 private:
 public:
  // default_constructor
  explicit map(void);
  // copy_constructor
  explicit map(const map& x);
  // destructor
  ~map(void);
  // operator=
  map operator=(const map& x);
};

_END_NAMESPACE_FT
// namespace_end
#endif