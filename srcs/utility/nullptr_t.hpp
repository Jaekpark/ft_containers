#ifndef _FT_NULLPTR_T_HPP
#define _FT_NULLPTR_T_HPP

// namespace_start
template <>
struct nullptr_t {
 public:
  // default_constructor
  explicit nullptr_t(void);
  // copy_constructor
  explicit nullptr_t(const nullptr_t& x);
  // destructor
  ~nullptr_t(void);
  // operator=
  nullptr_t operator=(const nullptr_t& x);
};
// namespace_end
#endif