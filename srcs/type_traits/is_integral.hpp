#ifndef _FT_IS_INTEGRAL_HPP
#define _FT_IS_INTEGRAL_HPP

#include <type_traits>

#include "../config.hpp"
// namespace_start
_BEGIN_NAMESPACE_FT

// template <class _Tp, _Tp __v>
// struct _LIBCPP_TEMPLATE_VIS integral_constant
// {
//   static _LIBCPP_CONSTEXPR const _Tp      value = __v;
//   typedef _Tp               value_type;
//   typedef integral_constant type;
//   _LIBCPP_INLINE_VISIBILITY
//   _LIBCPP_CONSTEXPR operator value_type() const _NOEXCEPT {return value;}
// #if _LIBCPP_STD_VER > 11
//   _LIBCPP_INLINE_VISIBILITY
//   constexpr value_type operator ()() const _NOEXCEPT {return value;}
// #endif
// };

template <class T, T v>
struct integral_constant {
  static const T value = v;
  typedef T value_type;
  typedef integral_constant<T, v> type;

  const operator value_type() const { return value; };
  const value_type operator()() const { return value; }
};
typedef integral_constant<bool, true> true_type;
typedef integral_constant<bool, false> false_type;

template <class T>
struct is_integral {
 protected:
 private:
 public:
  // default_constructor
  explicit is_integral(void);
  // copy_constructor
  explicit is_integral(const is_integral& x);
  // destructor
  ~is_integral(void);
  // operator=
  is_integral operator=(const is_integral& x);
};

_END_NAMESPACE_FT
// namespace_end
#endif