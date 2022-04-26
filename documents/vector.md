# Vector

> `std::vector` is a `sequence` container that encapsulates `dynamic size` arrays <sup>[1]
### `std::vector`, 벡터 컨테이너란?

[cppreference](https:://cppreference.com)에서 벡터를 정의한 구문을 그대로 인용하자면
**벡터**란 `캡슐화(encapsulate)`된 `가변 길이(dynamic size)` 배열 형태의 `시퀀스 컨테이너` 입니다.

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

벡터 컨테이너는 아래와 같은 클래스 템플릿으로 정의되어 있씁니다.

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

		OCF
			constructor
			destructor
			operator=

		iterator
		capacity
		element access
		modifiers
		allocator
		non-member function overloads


## 멤버 함수(Member Function)

### OCF(Orthodox Canoical Form)

+ 생성자 (Constructor)

+ 소멸자 (Destructor)

+ 복사 대입 연산자 (Copy Assignment Operator)

### Iterator

+ begin
+ end
+ rbegin
+ rend

### Capacity

+ size
+ max_size
+ resize
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

