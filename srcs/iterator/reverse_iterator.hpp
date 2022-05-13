#ifndef _FT_REVERSE_ITERATOR_HPP
#define	_FT_REVERSE_ITERATOR_HPP

#include "../config.hpp"
#include "../iterator/iterator.hpp"
#include "../iterator/iterator_traits.hpp"

_BEGIN_NAMESPACE_FT

template <class Iterator>
struct reverse_iterator
	: public iterator <typename iterator_traits<Iterator>::iterator_category,
										typename iterator_traits<Iterator>::value_type,
										typename iterator_traits<Iterator>::difference_type,
										typename iterator_traits<Iterator>::pointer,
										typename iterator_traits<Iterator>::reference> {
protected:
	Iterator current;

public:
	typedef Iterator	iterator_type;
	typedef typename iterator_traits<Iterator>::difference_type	difference_type;
	typedef typename iterator_traits<Iterator>::pointer					pointer;
	typedef typename iterator_traits<Iterator>::reference				reference;

	reverse_iterator(void) : current() {};
	explicit reverse_iterator(Iterator x) : current(x) {};
	template <class U>
		reverse_iterator(const reverse_iterator<U>& u) : current(u.base()) {};
	reverse_iterator operator=(const reverse_iterator& x) { current = x.base(); return *this; }

	Iterator	base(void) const { return current; };
	reference	operator*(void) const { iterator_type tmp = current; return *--tmp; };
	pointer		operator->(void) const { return &(operator*()); };

	reverse_iterator&	operator++(void) { --current; return *this; };
	reverse_iterator	operator++(int)	{ reverse_iterator tmp = *this; --current; return tmp; };
	reverse_iterator& operator--(void) { ++current; return *this; }
	reverse_iterator	operator--(int) { reverse_iterator tmp = *this; ++current; return tmp; };
	reverse_iterator	operator+	(difference_type n) const { return reverse_iterator(current - n); };
	reverse_iterator	operator-	(difference_type n) const { return reverse_iterator(current + n); };
	reverse_iterator	operator+=(difference_type n) { current -= n; return *this; };
	reverse_iterator	operator-=(difference_type n) { current += n; return *this; };
};

template <class Iterator>
	bool operator==(const reverse_iterator<Iterator>& x,
									const	reverse_iterator<Iterator>& y) { return x.current == y.current; };
template <class Iterator>
	bool operator<(const reverse_iterator<Iterator>& x,
									const	reverse_iterator<Iterator>& y) { return x.current > y.current; };
template <class Iterator>
	bool operator!=(const reverse_iterator<Iterator>& x,
									const	reverse_iterator<Iterator>& y) { return x.current != y.current; };
template <class Iterator>
	bool operator>(const reverse_iterator<Iterator>& x,
									const	reverse_iterator<Iterator>& y) { return x.current < y.current; };
template <class Iterator>
	bool operator<=(const reverse_iterator<Iterator>& x,
									const	reverse_iterator<Iterator>& y) { return x.current >= y.current; };
template <class Iterator>
	bool operator>=(const reverse_iterator<Iterator>& x,
									const	reverse_iterator<Iterator>& y) { return x.current <= y.current; };
template <class Iterator>
	typename reverse_iterator<Iterator>::difference_type operator-(
		const reverse_iterator<Iterator>& x,
		const reverse_iterator<Iterator>& y) { return y.current - x.current; };

template <class Iterator>
	reverse_iterator<Iterator> operator+(
		typename reverse_iterator<Iterator>::difference_type n,
		const reverse_iterator<Iterator>& x) { return x.current - n; };

_END_NAMESPACE_FT

#endif