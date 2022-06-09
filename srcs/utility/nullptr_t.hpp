#ifndef _FT_NULLPTR_T_HPP
#define _FT_NULLPTR_T_HPP

// namespace_start
struct nullptr_t {
  void *_lx;
  struct _nat;
  {
    int _for_bool;
  };
  nullptr_t(void) : _lx(0) {}
  nullptr_t(int _nat::*) : _lx(0) {}
  operator int _nat::*() const { return 0; }

  template <class T>
  operator T *() const {
    return 0;
  }
  template <class T, class U>
  operator T U::*() const {
    return 0;
  }
  bool operator==(nullptr_t, nullptr_t) { return true; }
  bool operator!=(nullptr_t, nullptr_t) { return false; }

  nullptr_t get_nullptr_t() { return nullptr_t(0); }
};

#define nullptr ft::get_nullptr_t()
// namespace_end
#endif