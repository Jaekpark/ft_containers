# 스택(Stack)

## 목차(Contents)

### [1. 스택(Stack)이란?](#스택stack이란)
### [2. `std::stack` 클래스]
+ [멤버 타입 (Member types)]
+ [멤버 함수 (Member functions)]
  + [OCF (Orthodox Canonical Form)]
  + [Iterator]
  + [Element access]
  + [Modifiers]
+ [비-멤버 함수 (Non-menber Function)]
### [3. 참고 자료 (Reference)](#reference)
---
# `스택(Stack)`이란?

일반적으로 `스택(Stack)`은 컴퓨터 과학 분야에서 데이터를 구조적으로 표현하는 방식인 `추상적 자료형(Abstract Data Type, ADT)`이자  `자료구조`의 한 종류로써 사용되고 있습니다.

추상적 자료형이란 자료들과 이 자료들에 대한 연산(동작, behavior)을 수학적으로 정의한 이론적인 형태를 말합니다. 이해하기 슆게 구체적인 예를 들면, ``

따라서, `C++ 스택 컨테이너` 재구현이 목표인 이번 프로젝트를 진행하기 위해서는 추상적 자료형 스택의 이론적 개념과 이 개념을 바탕으로 구현된 자료구조 스택이라는 두 관점에서 개념을 이해할 필요가 있습니다.

---
## 추상적 자료형 : 스택(Stack as a data structure)

![stack](https://cdn.programiz.com/sites/tutorial2program/files/stack.png)

`스택(stack)`은 `후입선출(LIFO, Last-Input-First-Out)`
## `C++ STL 컨테이너`의 스택(Stack as a STL Container)
content...

# `std::stack` 클래스


+ `T`

+ `Allocator`

---
## 멤버 타입(Member types)

```c++
// Stack Synopsis


```


---
## 멤버 함수(Member Function)

### OCF(Orthodox Canoical Form)

#### 생성자 (Constructor)

#### 소멸자 (Destructor)
  
```c++
~stack(void)
```

#### 복사 대입 연산자 (Copy Assignment Operator)

```c++
stack& operator=(const stack& x);
```
---
### Capacity

---
### Element access


---
### Modifiers
---
## 비-멤버 함수 (Non-menber Function)
---
## Reference

