iterator)

## 목차(Contents)

### [1. `iterator`, 반복자란?]
### [2. `iterator` 클래스]
+ [멤버 타입 (Member types)]
### [3. 참고 자료 (Reference)](#reference)
---
# `iterator`, 반복자란?

반복자란 무엇인가 설명..
---

## 멤버 타입(Member types)
```c++
//iterator Synopsis
template <class Category,
					class T,
					class Distance = ptrdiff_t,
					class Pointer = T *,
					class Reference = T &>
struct iterator {
	typedef T					value_type;
	typedef Distance	difference_type;
	typedef Pointer		pointer;
	typedef Reference	reference;
	typedef Category	iterator_category;
};
```

+ 반복자 종류(Category of iterators)

	| iterator tag               | Category of iterators  |
	| -------------------------- | ---------------------- |
	| input_iterator_tag         | Input Iterator         |
	| output_iterator_tag        | Output Iterator        |
	| forward_iterator_tag       | Forward Iterator       |
	| bidirectional_iterator_tag | Bidirectional Iterator |
	| random_access_iterator_tag | Random-access Iterator |
---

### OCF(Orthodox Canoical Form)

#### 생성자 (Constructor)

#### 소멸자 (Destructor)
  
```iterator(void)
```

#### 복사 대입 연산자 (Copy Assignment Operator)
---
### relation operators
---
## Reference

