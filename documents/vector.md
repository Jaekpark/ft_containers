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

	속성|내용
	--|--
	sequence | 벡터의 원소들은 선형적인 순서로 정렬됩니다. 각 원소들은 이 순서상 자신의 위치에 따라 접근 될 수 있습니다.
	dynamic | 원소가 추가 혹은 삭제됨에 따라 동적으로 메모리가 관리되고, 포인터, 반복자를 통해 각 원소에 접근할 수 있습니다. 또한 컨테이너의 마지막 위치에서 원소를 빠르게 추가, 제거 할 수 있습니다.
	Allocator | 벡터는 `std::allocator` 객체를 사용해 필요한 메모리를 동적으로 관리합니다.
### 정의

```c++
template < class T, class Allocator = std::allocator<T> >
class Vector;
```

+ `T`

	벡터 컨테이너 원소의 타입으로 사용되는 `템플릿 파라미터`입니다.
	벡터 클래스 내부에서 `value_type`으로 `재정의(typedef)` 됩니다.

+ `Allocator`

	메모리 할당을 수행하는 객체입니다. 기본적으로 `std::allocator<T>` 객체가 정의되어 있고, 벡터 클래스 내부에서 `allocator_type`으로 `재정의(typedef)` 됩니다.

	
	개념

	컨테이너 속성

	템플릿 파라미터

	멤버 타입

	멤버 함수
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



## Reference

<a name="vector">[1]</a>: ["std::vector", cppreference, last modified 21 Mar, 2022, accessed Apr 26, 2022, "https://en.cppreference.com/w/cpp/container/vector"](https://en.cppreference.com/w/cpp/container/vector)