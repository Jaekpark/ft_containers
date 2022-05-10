#ifndef FT_VECTOR_HPP
#define FT_VECTOR_HPP

#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <iterator>
// #include <iterator/iterator_traits.h>
#include <stdexcept>

namespace ft {
std::iterator<int>::InputIterator	iter;
	template < class T, class Allocator = std::allocator<T> >
	class vector {
	public:
		typedef T											value_type;
		typedef Allocator									allocator_type;
		typedef typename allocator_type::size_type			size_type;
		// typedef typename std::allocator_traits<allocator_type>::size_type			size_type;
	// protected:
		typedef typename allocator_type::reference			reference;
		typedef typename allocator_type::const_reference	const_reference;
        // typedef std::allocator_traits<allocator_type>::reference    reference;
        // typedef std::allocator_traits<allocator_type>::const_reference    const_reference;
		typedef typename allocator_type::difference_type	difference_type;
		typedef typename allocator_type::pointer			pointer;
		typedef typename allocator_type::const_pointer		const_pointer;
		typedef std::iterator<pointer>						iterator;
		typedef std::iterator<const_pointer>				const_iterator;
		// typedef typename std::allocator_traits<allocator_type>::difference_type	difference_type;
		// typedef typename std::allocator_traits<allocator_type>::pointer			pointer;
		// typedef typename std::allocator_traits<allocator_type>::const_pointer		const_pointer;
		typedef typename std::reverse_iterator<iterator>				reverse_iterator;
		typedef typename std::reverse_iterator<const_iterator>		const_reverse_iterator;

		Vector(void);
		explicit Vector(const allocator_type& alloc = allocator_type());
		// explicit vector(size_type n, const allocator_type& alloc = allocator_type()) {
			
		// }
		// explicit vector(size_type n, const value_type& value = value_type(), const allocator_type& alloc = allocator_type()) {
		// 	for (int i = 0; i < n; i++)
		// 		pointer++ = value;
		// }
		// template <class InputIterator>
		// 	explicit vector(InputIterator first, Inputiterator last, const allocator_type& alloc = allocator_type()) {
		// 		for (iterator iter = first; iter != last; first++)
		// 			iterator 
		// 	}
		// explicit Vector(const vector& x);
		~Vector(void);

	private:

	};
}

#endif