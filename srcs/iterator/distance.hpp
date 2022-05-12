#ifndef _FT_ITERATOR_DISTANCE_HPP
#define _FT_ITERATOR_DISTANCE_HPP

#include "../config.hpp"
#include <memory>

_BEGIN_NAMESPACE_FT

template < class T, class Allocator = std::allocator<T> >
class vector {
public:
	//기본 타입 선언
	typedef T																													value_type;
	typedef Allocator																									allocator_type;
	typedef typename allocator_type::size_type												size_type;
	typedef typename allocator_type::difference_type									difference_type;
	// 참조자 타입 선언
	typedef typename allocator_type::reference												reference;
	typedef typename allocator_type::const_reference									const_reference;
	// 포인터 타입 선언
	typedef typename allocator_type::pointer													pointer;
	typedef typename allocator_type::const_pointer										const_pointer;
	// 반복자 타입 선언
	typedef std::iterator<random_access_iterator_tag, pointer>				iterator;
	typedef std::iterator<random_access_iterator_tag, const_pointer>	const_iterator;
	typedef typename std::reverse_iterator<iterator>									reverse_iterator;
	typedef typename std::reverse_iterator<const_iterator>						const_reverse_iterator;

	// 생성자/소멸자
	explicit vector(const Allocator& alloc = Allocator());
	explicit vector(size_type n, const T& value = T(),
									const Allocator& allocator = Allocator());
	template <class InputIterator>
		vector(InputIterator first, InputIterator last,
					const Allocator& allocator = Allocator());
	explicit vector(const vector<T, Allocator>& x);
	~vector(void);

	// 대입 연산자
	vector<T, Allocator>& operator=(const vector<T, Allocator>& x);

	template <class InputIterator>
		void	assign(size_type n, const T& u);
		allocator_type	get_allocator(void) const;

		//iterator
		iterator								begin(void);
		const_iterator					begin(void) const;
		iterator								end(void);
		const_iterator					end(void) const;
		reverse_iterator				rbegin(void);
		const_reverse_iterator	rbegin(void);
		reverse_iterator				rend(void);
		const_reverse_iterator	rend(void);

		//capacity
		size_type								size(void) const;
		size_type								max_size(void) const;
		void										resize(size_type n, value_type val = value_type());
		size_type								capacity(void) const;
		bool										empty(void) const;
		void										reserve(size_type n);

		// element access
		reference								operator[](size_type n);
		const_reference					operator[](size_type n) const;
		reference								at(size_type n);
		const_reference					at(size_type n) const;
		reference								front(void);
		const_reference					front(void) const;
		reference								back(void);
		const_reference					back(void) const;

		// modifiers
		void										push_back(const T& x);
		void										pop_back(void);
		iterator								insert(iterator position, const T& x);
		void										insert(iterator position, size_type n, const T& x);
		template <class InputIterator>
			void									insert(iterator position, InputIterator first, InputIterator last);
		iterator								erase(iterator position);
		iterator								erase(iterator first, iterator last);
		void										swap(vector<T, Allocator>&);
		void										clear(void);
};
// relation operator
template <class T, class Allocator>
	bool operator==(const vector<T, Allocator>& x, const vector<T, Allocator>& y);
template <class T, class Allocator>
	bool operator!=(const vector<T, Allocator>& x, const vector<T, Allocator>& y);
template <class T, class Allocator>
	bool operator<(const vector<T, Allocator>& x, const vector<T, Allocator>& y);
template <class T, class Allocator>
	bool operator>(const vector<T, Allocator>& x, const vector<T, Allocator>& y);
template <class T, class Allocator>
	bool operator<=(const vector<T, Allocator>& x, const vector<T, Allocator>& y);
template <class T, class Allocator>
	bool operator>=(const vector<T, Allocator>& x, const vector<T, Allocator>& y);

_END_NAMESPACE_FT

#endif