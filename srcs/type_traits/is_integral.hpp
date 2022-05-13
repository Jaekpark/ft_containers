#ifndef _FT_IS_INTEGRAL_HPP
#define _FT_IS_INTEGRAL_HPP

#include "../config.hpp"
//namespace_start
_BEGIN_NAMESPACE_FT

template <class T>
struct is_integral {
protected:

private:

public:
	//default_constructor
	explicit is_integral(void);
	//copy_constructor
	explicit is_integral(const is_integral& x);
	//destructor
	~is_integral(void);
	//operator=
	is_integral operator=(const is_integral& x);
};

_END_NAMESPACE_FT
//namespace_end
#endif