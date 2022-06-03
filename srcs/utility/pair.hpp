#ifndef _FT_PAIR_HPP
#define _FT_PAIR_HPP

#include "../config.hpp"
// namespace_start
_BEGIN_NAMESPACE_FT

template <class T1, class T2>
struct pair {
 protected:
 private:
 public:
  // default_constructor
  explicit pair(void);
  // initializeㅎㄴㅅ
  explicit pair(const T1& x, const T2& y);
  // copy_constructor
  template <class U1, class U2>
  pair(const pair<U1, U2>& p){};
  // destructor
  ~pair(void);
  // operator=
  pair operator=(const pair& x);
};
// namespace_end
_END_NAMESPACE_FT

#endif