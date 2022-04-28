# Vector

> `std::vector` is a `sequence` container that encapsulates `dynamic size` arrays <sup>[1]
### `std::vector`, 벡터 컨테이너란?

[cppreference](https:://cppreference.com)에서 벡터를 정의한 구문을 그대로 인용하자면
**벡터**란 [`캡슐화(encapsulate)`](https://ko.wikipedia.org/wiki/%EC%BA%A1%EC%8A%90%ED%99%94)된 `가변 길이(dynamic size)` 배열 형태의 `시퀀스 컨테이너` 입니다.

벡터는 일반 배열처럼 원소를 순차적으로 보관한다는 점에서 `시퀀스 컨테이너`로 분류됩니다. 다만 일반 배열과 다른 것은 `가변 길이 배열(dynamic size array)`이라는 점입니다. 

```c++
#define SIZE 5

int array[SIZE];

int *array_ptr = malloc(sizeof(int) * SIZE);
int *array_ptr = new int[SIZE];
```

위와 같이 선언된 일반 배열은 처음 할당된 `SIZE` 만큼의 원소들만 가질 수 있습니다. 하지만 `벡터 컨테이너`는 원소가 추가 혹은 삭제됨에 따라 자동으로 메모리를 `재할당`해 크기를 `동적(dynamic)`으로 변경 해줍니다.

+ 벡터 컨테이너의 속성

 | 속성      | 내용                                                                                                                                                                                    |
 | --------- | --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
 | sequence  | 벡터의 원소들은 선형적인 순서로 정렬됩니다. 각 원소들은 이 순서상 자신의 위치에 따라 접근 될 수 있습니다.                                                                               |
 | dynamic   | 원소가 추가 혹은 삭제됨에 따라 동적으로 메모리가 관리되고, 포인터, 반복자를 통해 각 원소에 접근할 수 있습니다. 또한 컨테이너의 마지막 위치에서 원소를 빠르게 추가, 제거 할 수 있습니다. |
 | Allocator | 벡터는 `std::allocator` 객체를 사용해 필요한 메모리를 동적으로 관리합니다.                                                                                                              |
## `std::vector` 컨테이너 정의

벡터 컨테이너는 아래와 같은 클래스 템플릿으로 정의되어 있습니다.

```c++
template < class T, class Allocator = allocator<T> >
class Vector;
```

+ `T`

	벡터 컨테이너 원소의 타입으로 사용되는 `템플릿 파라미터`입니다.
	벡터 클래스 내부에서 `value_type`으로 `재정의(typedef)` 됩니다.

+ `Allocator`

	메모리 할당을 수행하는 객체입니다. 기본적으로 `std::allocator<T>` 객체가 정의되어 있고, 벡터 클래스 내부에서 `allocator_type`으로 `재정의(typedef)` 됩니다.

## 멤버 타입(Member types) <sup>[1][2]

```c++
// Vector Synopsis

namespace std
{

template <class T, class Allocator = allocator<T> >
class vector
{
public:
    typedef T                                        value_type;
    typedef Allocator                                allocator_type;
    typedef typename allocator_type::reference       reference;
    typedef typename allocator_type::const_reference const_reference;
    typedef implementation-defined                   iterator;
    typedef implementation-defined                   const_iterator;
    typedef typename allocator_type::size_type       size_type;
    typedef typename allocator_type::difference_type difference_type;
    typedef typename allocator_type::pointer         pointer;
    typedef typename allocator_type::const_pointer   const_pointer;
    typedef std::reverse_iterator<iterator>          reverse_iterator;
    typedef std::reverse_iterator<const_iterator>    const_reverse_iterator;
	//....
}
```

| member type            | definition                                                                                        | note                                                                   |
| ---------------------- | ------------------------------------------------------------------------------------------------- | ---------------------------------------------------------------------- |
| value_type             | `템플릿 파라미터 T`, 벡터에 저장된 데이터 형식을 나타내는 멤버 변수 입니다.                       | -                                                                      |
| allocator_type         | `템플릿 파라미터 Allocator`, 벡터 클래스에 메모리를 관리하는 클래스를 나타내는 멤버 변수입니다.   | 기본은 표준 라이브러리의 `std::allocator` 클래스로 설정 되어 있습니다. |
| reference              | 벡터에 저장된 원소의 `참조`를 제공하기 위한 멤버 변수입니다.                                      | `std::allocator::value_type&`                                          |
| const_reference        | 벡터에 저장된 원소의 `참조자`를 `const`로 제공하기 위한 멤버 변수 입니다.                         | `std::allocator::const value_type&`                                    |
| pointer                | 벡터의 원소에 대한 `포인터`를 제공하기 위한 멤버 변수 입니다.                                     | `std::allocator::value_type*`                                          |
| const_pointer          | 벡터의 원소에 대한 `const 포인터`를 제공하기 위한 멤버 변수 입니다.                               | `std::allocator::const value_type*`                                    |
| iterator               | `value_type`의 원소에 접근하기 위한 `임의 접근 반복자(Ramdom Access Iterator)` 입니다             | -                                                                      |
| const_iterator         | `const value_type`의 원소에 접근하기 위한 `임의 접근 반복자(Ramdom Access Iterator)`입니다.       | -                                                                      |
| reverse_iterator       | 역방향 벡터 원소에 접근할 수 있는 `임의 접근 반복자(Random Access Iterator)` 입니다.              | -                                                                      |
| const_reverse_iterator | 역방향 벡터 `const` 타입 원소에 접근할 수 있는 `임의 접근 반복자(Random Access Iterator)` 입니다. | -                                                                      |
| difference_type        | 벡터 내의 두 원소간 `주소 차이`를 제공하기 위한 멤버 변수입니다.                                  | 보통 `ptrdiff_t`와 같습니다.                                           |
| size_type              | 벡터 `원소의 수`를 표현하는 형식입니다.                                                           | 보통 `size_t`와 같습니다.                                              |

## 멤버 함수(Member Function)

### OCF(Orthodox Canoical Form)

+ 생성자 (Constructor)

	```c++
    // 기본 생성자 (default constructor)

    explicit vector(const allocator type& alloc = allocator_type());

    // 오버로딩
    // size n 만큼 val로 초기화 생성
    explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type());

    // first ~ last 까지 복사 생성
    template <class InputIterator>
  	explicit vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type());

	// 복사 생성자
	explicit vector(const vector& x);
	```

+ 소멸자 (Destructor)
  
	```c++
	~vector(void)
	```

+ 복사 대입 연산자 (Copy Assignment Operator)

	```c++
	vector& operator=(const vector& x);
	```

### Iterator

#### begin & end
![cppreference](https://upload.cppreference.com/mwiki/images/1/1b/range-begin-end.svg)

+ `begin` : 컨테이너의 첫 번째 원소를 가리키는 `반복자(iterator)` 반환

	 **Prototype**
	```c++
	iterator	begin();
	const_iterator	begin() const;
	```

	컨테이너의 첫 원소를 가리키는 `임의 접근 반복자(Random Access Iterator)` 반환합니다. `const`로 선언된 컨테이너의 경우에는 `const iterator`를 반환합니다. `Element access`의 `front`와 첫 원소의 위치를 얻을 수 있다는 점에서 같지만, `front`는 첫 원소의 `참조자(reference)`를 반환하고, `begin` 함수는 `반복자(iterator)`를 반환 한다는 점에서 다릅니다.

	`비어있는(Empty)` 컨테이너의 경우에 `begin`으로 부터 반환 된 `반복자`를 `역참조(dereference)`할 경우 에러가 발생하므로 주의해야합니다.

	```c++
	#include <iostream>
	#include <vector>

	int main(void) {
		std::vector<int> a(0);
		std::vector<int>::iterator iter_a = a.begin();
		std::cout << *iter_a << std::endl;
		// undefine behavior, segmentation fault

		std::vector<int> b(1);
		std::vector<int>::iterator iter_b = b.begin();
		std::cout << *iter_b << std::endl;
		// 0

		return 0;
	}
	```
+ `end` : 마지막 원소 바로 다음(past-the-end)을 가리키는 `반복자`를 반환

	 **Prototype**
	```c++
	iterator	end();
	const_iterator	end() const;
	```

	컨테이너의 마지막 원소의 다음의 위치를 기리키는 `반복자`를 반환합니다. `end` 함수에서 반환되는 반복자는 실제 값을 가진 컨테이너 `원소`의 위치가 아닌 컨테이너의 메모리 상 위치를 지정하는 `placeholder`입니다. 비어있는 컨테이너의 경우는 `begin`과 동일합니다.

	일반적으로 `begin`과 함께 벡터 컨테이너의 모든 원소를 포함하는 범위를 지정하기 위해 같이 사용됩니다.

	빈 컨테이너로 부터 반환 받은 반복자는 역참조 할 수 없습니다.

	```c++
    #include <iostream>
    #include <vector>

    int main(void) {
    	std::vector<int> a;

    	a.push_back(11);
    	a.push_back(12);
    	a.push_back(13);

		// a -> [11, 12, 13]
    	std::vector<int>::iterator begin = a.begin();
    	std::vector<int>::iterator end = a.end();
    	
		std::cout << *end << std::endl;
		// 0
		std::cout << *(--end) << std::endl;
		// 13

    	while (begin != end) {
    		std::cout << *begin << std::endl;
    		begin++;
    	}
		// 11, 12, 13
    	return 0;
    }
	```

#### rbegin & rend

![rbegin-rend](https://upload.cppreference.com/mwiki/images/3/39/range-rbegin-rend.svg)

+ rbegin : 마지막 원소를 가리키는 `역방향 반복자(reverse iterator)`를 반환

	**Prototype**
	```c++
	reverse_iterator	rbegin();
	const_reverse_iterator	rbegin() const;
	```
	
	컨테이너의 마지막 원소를 가리키는 `역방향 반복자`를 반환합니다. 역방향 반복자는 컨테이너를 마지막 원소부터 첫 원소까지 역방향으로 탐색하기 위한 경우 사용합니다.
	4개의 원소를 가진 컨테이너가 있고 각 원소의 위치를 `[first, second, third, last]`로 표현한다면 기존 `begin` 함수에서 반환된 `반복자`같은 경우 `first`를 가리키고 `++`연산자를 사용할 경우  `second`로 이동합니다. 하지만 `rbegin`은 `last`를 반환하고 `rbegin - 2` 연산을 통해 `second`로 이동 할 수 있습니다.

	```c++
	#include <iostream>
    #include <vector>

    int main(void) {
      	std::vector<int> a;

    	a.push_back(1);
    	a.push_back(2);
    	a.push_back(3);
    	a.push_back(4);

    	std::vector<int>::reverse_iterator rbegin = a.rbegin();

    	std::cout << *rbegin << std::endl;
		// 4
		return 0;
    }
	```

+ rend : 첫 원소의 직전 위치를 가리키는 `역방향 반복자`를 반환

	**Prototype**
	```c++
	reverse_iterator	rend();
	const_reverse_iterator	rend() const;
	```

	컨테이너 첫 원소의 직전 위치를 가리키는 `역방향 반복자`를 반환합니다. `rbegin`과 함께 컨테이너를 역순으로 순회하기 위해 사용 할 수 있습니다. `end` 함수가 마지막 원소의 다음 위치를 반환해 `placeholder` 역할을 수행한다면, `rbegin`은 반대로 첫 원소 직전 위치를 가리키는 `역방향 반복자` 반환을 통해 해당 역할을 수행합니다. `--`연산을 통해 마지막 원소에 가까운 위치로 접근할 수 있습니다.

	```c++
    #include <iostream>
    #include <vector>

    int main(void) {
    	std::vector<int> a;

    	a.push_back(1);
    	a.push_back(2);
    	a.push_back(3);
    	a.push_back(4);

    	std::vector<int>::reverse_iterator rbegin = a.rbegin();
    	std::vector<int>::reverse_iterator rend = a.rend();

    	std::cout << *rbegin << std::endl; // 4
    	std::cout << *rend << std::endl; // 0 (past-end-last)

    	std::cout << *(++rbegin) << std::endl; // 3
    	std::cout << *(--rend) << std::endl; // 1

		--rbegin; 
		++rend;

    	while (rbegin != rend) {
    		std::cout << *rbegin << std::endl;
    		rbegin++;
    	} // 4 3 2 1

    	return 0;
	}
	```
### Capacity

+ size : 컨테이너 `원소 개수` 반환 함수

	**Prototype**
	```c++
	size_type	size() const;
	```	
	컨테이너에 존재 하는 원소의 개수를 반환하는 함수 입니다. 
	`std::distance(container.begin(), container.end())` 즉, 컨테이너의 `begin iterator`와 `end iterator` 사이 거리와 같습니다.

	```c++
	#include <iostream>
    #include <vector>

    int main(void) {
    	std::vector<int> a;

    	a.push_back(1);
    	a.push_back(2);

    	std::cout << a.size() << std::endl;
		std::cout << std::distance(a.begin(), a.end()) << std::endl;
    	// 2, 2
    	return 0;
    }
	```

+ max_size : 최대 원소 개수 반환

	**Prototype**
	```c++
	size_type	max_size() const;
	```

	컨테이너가 가질 수 있는 원소의 `최대 개수`를 반환 합니다. 사용하고 있는 시스템이나 운영체제의 환경에 따라 컨테이너가 가질 수 있는 원소의 최대 개수는 달라질 수 있습니다. 주의 할 점은 메모리는 한정적인 자원이기 때문에 컨테이너가 반드시 `max_size` 함수에서 반환 받은 크기만큼 원소를 갖는다는 보장은 없습니다.

	```c++
    #include <iostream>
    #include <vector>

    int main(void) {
    	std::vector<int> a;

    	std::cout << a.max_size() << std::endl;
    	// 4611686018427387903 (2020 Intel Macbook pro, Monterey)
    	return 0;
    }
	```

+ resize : 컨테이너 사이즈를 재정의

	**Prototype**
	```c++
	void	resize(size_type n, value_type val = value_type());
	```

	컨테이너 사이즈를 매개변수 `n`으로 리사이징 하는 함수 입니다. 몇 가지 사용방법에 따라 다른 동작을 수행합니다.

	1. `size > n`
		
		변경하려는 사이즈 `n`보다 기존 컨테이너의 `size`가 `큰` 경우, 첫 원소부터 `n`번째 원소까지만 남겨지고 남은 원소는 제거됩니다.
	
	2. `size < n`

		변경하려는 사이즈가 기존 사이즈보다 큰 경우, 늘어난 공간에 `val`을 채웁니다. 사용자가 `val` 값을 입력하지 않을 경우 클래스 내부에 정의된 기본 `value_type()` 형태의 기본 생성자 실행 결과 값으로 초기화 됩니다.
	
	```c++
	#include <iostream>
    #include <vector>
    
	int main(void) {
      	std::vector<int> a;

      	a.push_back(1);
      	a.push_back(2);
      	a.push_back(3);
      	a.push_back(4);

      	std::vector<int>::iterator b = a.begin();
      	std::vector<int>::iterator e = a.end();

      	std::cout << "before" << std::endl;
      	while(b != e) {
      		std::cout << *b << " ";
      		b++;
      	}
		// Before resize 1 2 3 4
      	std::cout << std::endl << "after" << std::endl;

      	a.resize(7, 1); // size 4 -> 7 | 5, 6, 7번째 원소 1로 초기화
      	b = a.begin();
      	e = a.end();
      	while(b != e) {
      		std::cout << *b << " ";
      		b++;
      	}
		// After resize 1 2 3 4 1 1 1
      	std::cout << std::endl;
		return 0;
	}
	```

+ capacity
+ empty
+ reserve

### Element access
+ operator[]
+ at
+ front
+ back

### Modifiers
+ assign
+ push_back
+ pop_back
+ insert
+ erase
+ swap
+ clear

### Allocator
+ get_allocator
## 비-멤버 함수 (Non-menber Function)

+ 관계 연산자
+ swap
## Reference

<a name="cpp-vector">[1]</a>: ["std::vector", cppreference, last modified 21 Mar, 2022, accessed Apr 26, 2022, "https://en.cppreference.com/w/cpp/container/vector"](https://en.cppreference.com/w/cpp/container/vector)

<a name="vector-class">[2]</a>: ["Vector class", Microsoft Docs, last modified 08 Apr, 2021, accessed Apr 26, 2022, "https://docs.microsoft.com/en-us/cpp/standard-library/vector-class?view=msvc-170"](https://docs.microsoft.com/en-us/cpp/standard-library/vector-class?view=msvc-170)

<a name="cplus-vector">[3]</a>: ["std::vector", cplusplus, last modified unknown, accessed Apr 26, 2022, "https://www.cplusplus.com/reference/vector/vector/"](https://www.cplusplus.com/reference/vector/vector/)

