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

**맵(map)**이란 `키(key)`와 `값(value)`의 조합으로 이루어진 데이터를 특정 순서로 저장하는 `연관 컨테이너(associate container)` 입니다.

<img src="./images/map_node.png">


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

