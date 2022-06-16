# 맵(map)

## 목차(Contents)

### [1. `std::map`, 맵 컨테이너란?]
### [2. `std::map` 클래스]
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

`트리(tree)` 구조란

# `std::map` 클래스

+ `Key`

+ `T`

+ `Compare`

+ `Allocator`

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

