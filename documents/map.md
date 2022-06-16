# 맵(map)

## 목차(Contents)

### [1. `std::map`, 맵 컨테이너란?]
### [2. `std::map` 클래스]
+ [개요(Synopsis)](#개요synopsis)
+ [멤버 타입 (Member types)]
+ [멤버 함수 (Member functions)]
    + [OCF (Orthodox Canonical Form)]
    + [Iterator]
    + [capacity]
    + [Modifiers]
    + [Element access]
    + [Observers]
    + [Operations]
    + [Allocator]
+ [비-멤버 함수 (Non-menber Function)]
### [3. 참고 자료 (Reference)](#reference)
---
# `std::map`, 맵 컨테이너란?

> Maps are associative containers that store elements formed by a combination of a key value and a mapped value, following a specific order.<sup>[1]

**맵(map)** 이란 `키(key)`와 `값(value)`의 조합으로 이루어진 한 쌍의 데이터 묶음을 특정 순서로 저장하는 `연관 컨테이너(associate container)` 입니다. 

> key, value로 이루어진 한 쌍의 데이터 묶음을 `Node(노드)`라고 표현합니다.

<p align="center">
<img src="https://github.com/Jaekpark/ft_containers/blob/master/images/map_node.png?raw=true">
</p>

이 때 `키`는 각 원소를 비교하거나 정렬하는데 사용됩니다. 이 때 키는 중복이 허용되지 않기 때문에 하나의 키에 매핑된 하나의 값만 존재합니다. 맵에 삽입되는 원소들은 컨테이너 내부의 원소 비교 객체에 의해 순서대로 정렬됩니다.

> C++에서 하나의 `키`에 여러 `값`이 존재할 수 있는 컨테이너는 `멀티맵(multi-map)`이 있습니다.

맵은 일반적으로 `이진 탐색 트리(binary search tree)`로 구현됩니다.

> `트리(tree)`구조나 `이진 탐색 트리(binary search tree)`에 대해 잘 모르시는 경우 [이 문서](tree.md)를 참고하시기 바랍니다.


# `std::map` 클래스

 `맵(map)` 클래스는 다음과 같은 클래스 템플릿으로 정의되어 있습니다.

 ```c++
 template <class Key, class T, class Compare = std::less<T>, class Allocator = std::allocator<std::pair<const Key, T> > >
 class map
 ```
+ `Key`

	`key`의 자료형을 나타내는 템플릿 매개변수 입니다.

+ `T`

	`value`의 자료형을 나타내는 템플릿 매개변수 입니다.

+ `Compare`
	
	노드간 비교를 하기 위한 객체입니다. 별도의 처리가 없을 경우 기본적으로 `std::less`가 사용됩니다.

+ `Allocator`

	메모리 할당 객체입니다. 기본적으로 `std::allocator`가 사용됩니다. 맵 컨테이너는 `std::pair<const Key, T>` 타입의 객체를 원소로 사용하므로 해당 타입이 메모리 할당 객체의 템플릿 매개변수로 전달됩니다.
---
## 개요(Synopsis)

```c++
//Map synopsis
template <class Key, class T,class Compare = std::less<T>,
	class Allocator = std::allocator<std::pair<const Key, T> > >
class map {
public:
	// type alias
	typedef Key 						key_type;
	typedef T 						mapped_type;
	typedef std::pair<key_type, mapped_type>		value_type;
	typedef Compare 					key_compare;
	typedef Allocator					allocator_type;
	typedef typename allocator_type::reference		reference;
	typedef typename allocator_type::const_reference	const_reference;
	typedef typename allocator_type::pointer		pointer;
	typedef typename allocator_type::const_pointer		const_pointer;
	typedef typename allocator_type::size_type		size_type;
	typedef typename allocator_type::difference_type	difference_type;
	typedef implementation					iterator;
	typedef implementation					const_iterator;
	typedef std::reverse_iterator<iterator>			reverse_iterator;
	typedef std::reverse_iterator<const_iterator>		const_reverse_iterator;

	// value_compare
	class value_compare {
			friend class map;
	protected:
		key_compare		comp;

		value_compare(key_compare c);
	public:
		typedef bool		result_type;
		typedef value_type	first_argument_type;
		typedef value_type	second_argument_type;
		bool operator()(const value_type& x, const value_type& y) const;
	};

	// constructor
	map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type());
	template <class InputIterator>
	map(InputIterator first, InputIterator last,
		const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type());
	map(const map& x);
	// destructor
	~map();
	// operator=
	map& operator=(const map& x);
	
	// member functions

	// iterators
	iterator		begin();
	const_iterator		begin() const;
	iterator		end();
	const_iterator		end() const;
	reverse_iterator	rbegin();
	const_reverse_iterator	rbegin() const;
	reverse_iterator	rend();
	reverse_const_iterator	rend() const;

	// capacity
	bool		empty() const;
	size_type	size() const;
	size_type	max_size() const;

	// element access
	mapped_type& operator[](const key_type& key);

	// modifiers
	pair<iterator, bool>	insert(const key_type& key);
	iterator		insert(iterator position, const key_type& key);
	template <class InputIterator>
	void			insert(InputIterator first, InputIterator last);
	void			erase(iterator position);
	size_type		erase(const key_type& key);
	void		erase(iterator first, iterator last);
	void		swap(map& x);
	void		clear();

	// observers
	key_compare	key_comp() const;
	value_compare	value_comp() const;

	// operations
	iterator		find(const key_type& key);
	const_iterator	find(const key_type& key) const;
	size_type		count(const key_type& key) const;
	iterator		lower_bound(const key_type& key);
	const_iterator	lower_bound(const key_type& key) const;
	iterator		upper_bound(const key_type& key);
	const_iterator	upper_bound(const key_type& key) const;
	pair<iterator, iterator>	equal_range(const key_type& key);
	pair<const_iterator, const_iterator>	equal_range(const key_type& key) const;
	// allocator
	allocator_type& get_allocator();
};
// non-member functions

// relation operators overloading
template <class Key, class T, class Compare, class Allocator>
bool operator==(const map<Key, T, Compare, Allocator>& lhs, const map<Key, T, Compare, Allocator>& rhs);
template <class Key, class T, class Compare, class Allocator>
bool operator!=(const map<Key, T, Compare, Allocator>& lhs, const map<Key, T, Compare, Allocator>& rhs);
template <class Key, class T, class Compare, class Allocator>
bool operator<(const map<Key, T, Compare, Allocator>& lhs, const map<Key, T, Compare, Allocator>& rhs);
template <class Key, class T, class Compare, class Allocator>
bool operator>(const map<Key, T, Compare, Allocator>& lhs, const map<Key, T, Compare, Allocator>& rhs);
template <class Key, class T, class Compare, class Allocator>
bool operator<=(const map<Key, T, Compare, Allocator>& lhs, const map<Key, T, Compare, Allocator>& rhs);
template <class Key, class T, class Compare, class Allocator>
bool operator>=(const map<Key, T, Compare, Allocator>& lhs, const map<Key, T, Compare, Allocator>& rhs);
// specializes the std::swap
template <class Key, class T, class Compare, class Allocator>
void swap(map<Key, T, Compare, Allocator>& lhs, map<Key, T, Compare, Allocator>& rhs);
```
---
## 멤버 타입(Member types)

```c++
// map Synopsis


```


---
## 멤버 함수(Member Function)

### OCF(Orthodox Canoical Form)

#### 생성자 (Constructor)

#### 소멸자 (Destructor)
  
```c++
~map(void)
```

#### 복사 대입 연산자 (Copy Assignment Operator)

```c++
map& operator=(const map& x);
```
---
### Iterator
---
### Capacity
---
### Element access
---
### Modifiers
---
### Observers
---
### Operations
---
### Allocator
---
## 비-멤버 함수 (Non-menber Function)
---
### relation operators
---
### std::swap
## Reference

