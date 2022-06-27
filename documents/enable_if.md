# 일반화 프로그래밍(Generic Programming)

`일반화 프로그래밍`이란 컴퓨터 프로그래밍의 한 유형으로, 특정 객체(인터페이스, 클래스, 메소드 등)의 `타입`이 `작성 단계에서 정해지지 않고`, 후에 제공되는 `파라미터의 타입에 따라 그에 맞게 인스턴스화` 되도록 프로그램을 작성하는 것입니다.

`c++`에서 일반화 프로그래밍은 `템플릿(template)`을 이용해 이루어 집니다.

```c++
// 함수 템플릿
template <typename T>
T add(T t1, T t2) { return t1 + t2; }

// 클래스 템플릿
template <class T>
class Calculator {
public:
  T add(T t1, T t2) { return t1 + t2; }
  T sub(T t1, T t2) {	return t1 - t2; }
  T mul(T t1, T t2) { return t1 * t2; }
  T div(T t1, T t2) { return t1 / t2; }
};
```

> 위의 예시에서 함수 템플릿 `add`는 템플릿 매개변수가 `typename`으로 선언되어있고, 클래스 템플릿 `Calculator`는 `class`로 선언되어 있습니다. 템플릿 매개변수를 선언할 때 사용하는 `typename`과 `class`는 동일한 의미를 같습니다. 하지만 `typename` 키워드 템플릿 매개변수가 아닌 곳에서 사용 될 때는 별도의 기능을 가지고 있습니다.

위의 예시처럼 `template` 키워드와 선언과 함께 `<typename T>` 혹은 `<class T>`와 같은 형식으로 `템플릿 매개변수`를 선언하고 이를 `int, char`와 같은 자료형의 타입처럼 사용할 수 있습니다.

위의 예시에서 템플릿 매개변수 `T`는 사용자가 원하는 타입에 따라 컴파일 단계에서 컴파일러가 해당 타입으로 치환시킨 새로운 함수 혹은 클래스를 생성하게 됩니다.

```c++
// <typename T = int>
add<int>(a, b);

T add(T t1, T t2) { return t1 + t2; }
// compile
int add(int t1, int t2) { return t1 + t2; }
```
```c++
// <class T = int>
Calculator<int> calc;
```
```c++
// Compile
class Calculator {
public:
  int add(int t1, int t2) { return t1 + t2; }
  int sub(int t1, int t2) { return t1 - t2; }
  int mul(int t1, int t2) { return t1 * t2; }
  int div(int t1, int t2) { return t1 / t2; }
}
```

위의 예시처럼 작성된 `Calculator` 클래스 템플릿은 `+, -, *, /` 연산이 가능한 모든 타입에 대응 할 수 있습니다.

이처럼 템플릿을 사용한 일반화 프로그래밍은 `코드의 효율성`을 높이기 위해 사용합니다. 특정 알고리즘이나 구현하고자 하는 객체를 템플릿으로 작성하면 다양한 타입에 따라 컴파일러가 객체를 생성해주기 때문에 프로그래머가 직접 인스턴스를 추가 작성하거나 오버로딩 할 필요가 없어지기 때문에 `코드의 재사용성`을 크게 높여줍니다.

템플릿 매개변수는 필요에 따라 2개 이상을 선언해 다양하게 이용 할 수 있습니다.

```c++
template <class T1, class T2>
class pair {
public:
  T1 first;
  T2 second;
};
```
```c++
pair<char, int> p;
```
```c++
// compile
// <class T1 = char, class T2 = int>
class pair {
public:
  char first;
  int second;
};
```

# 템플릿 메타 프로그래밍(Template meta programming - TMP)

앞서 `C++`에서 일반화 프로그래밍은 `템플릿(template)` 키워드를 사용해 다양한 `타입`에 컴파일러가 대응 할 수 있도록 하는 프로그래밍 방식이라고 설명했습니다. 이 때 `타입`은 일반적으로 어떤 객체에 어떠한 데이터를 저장할건지를 나타내는 형식으로 사용됩니다. `int, char, double, string 등`의 자료형이 대표적인 예시라고 할 수 있습니다. 이 때의 `타입` 자체는 어떤 특정한 값을 지니지 않습니다.

하지만 템플릿을 사용할 때, `반드시 특정 자료형만을 템플릿 매개변수로 사용해야 하는 것은 아닙니다.` 템플릿으로 선언된 타입 또한 활용할 수 있습니다. 이 때 템플릿으로 선언된 타입은 `객체를 생성하지 않더라도 특정 값을 가질 수 있고`, 이 타입을 템플릿 매개변수로 활용해 프로그래밍을 할 수 있습니다. 타입은 `컴파일 타임에 확정`되어야만 하므로 템플릿을 활용해 컴파일 타임 생성되는 코드로 프로그래밍 하는 것을 `템플릿 메타 프로그래밍(Template meta programming)`이라고 합니다.

이해하기 쉽도록 `int`형 데이터 `10`을 출력하는 예시를 일반화 프로그래밍과 TMP를 사용한 예시를 들어보겠습니다.

+ generic programming

  ```c++
  template <class T>
  struct something {
    T value;
    something(T v = 0) : value(v) {}
  };

  int main() {
    something<int> a(10); // 런타임에 something<int> 타입의 a객체 생성
    std::cout << a.value << std::endl; // 출력 결과 : 10
  }
  ```

	위의 코드에서는 `프로그램 실행시(런타임)`에 `something<int>` 타입의 객체 `a`가 생성됩니다. 이 때 생성자 매개변수로 `10`이 전달되고, `a` 객체의 멤버 변수 `value`는 `10`으로 초기화 됩니다. `객체의 생성은 런타임에 이루어지고` 생성된 객체는 별도의 메모리 해제가 이루어지지 않는한 콜 스택 혹은 프로그램과 수명을 함께 하기 때문에, 이 과정은 프로그램 실행시에 이루어지고, `런타임 오버헤드가 발생`합니다.

+ TMP

  ```c++
  template <class T, T v>
  struct something {
    static const T value = v;
  };

  int main() {
    typedef something<int, 10> value_t; // 컴파일 타임에 타입 정의
    std::cout << value_t::value << std::endl; // 출력 결과 : 10
  }
  ```

	위의 코드에서 `something`은 템플릿 매개변수로 타입 `T`와 `T` 타입의 값 `v`를 받습니다. 그리고 `v`는 `something` 멤버 변수 `value`의 값으로 초기화 됩니다. 따라서 템플릿 매개변수 `int`와 `10`을 전달 받은 `value_t`를 `정의(typedef)`하게 되면 해당 타입을 참조해 `10`이라는 값을 얻을 수 있고, `타입은 컴파일 과정에서 확정`되기 때문에 이 과정은 모두 컴파일 과정에서 이루어집니다. 이 경우, `컴파일 시간이 증가` 할 수 있지만, 런타임 오버헤드는 줄일 수 있습니다.

+ TMP의 다양한 예시

  ```c++
  // 템플릿의 재귀적 활용 : factorial 계산하기
  template <int N>
  struct factorial {
    static const int result = N * factorial<N - 1>::result;
  };
  // 재귀 탈출 조건, 템플릿 특수화(template specialization)
  template <>
  struct factorial<1> {
    static const int result = 1;
  };
  ```

  ```c++
  // 템플릿의 재귀적 활용 : 유클리드 호제법을 사용한 최대 공약수, 최소 공배수 구하기
  template <int X, int Y>
  struct euclidean {
    static const int gcd = euclidean<Y, X % Y>::gcd; // 최대 공약수
    static const int lcm = (X * Y) / gcd; // 최소 공배수
  };

  // 재귀 탈출 조건
  template <int X>
  struct euclidean<X, 0> {
    static const int gcd = X;
  };
  ```

### integral_constant

```c++
template <class T, T v>
struct integral_constant {
	static const T value = v;
	typedef T value_type;
	typedef integral_constant type;
	operator value_type() { return value; }
	const value_type operator()() const { return value; }
}

typedef integral_constant<bool, true> true_type;
typedef integral_constant<bool, false> false_type;
```

위의 클래스 템플릿은 

# Reference

https://www.definitions.net/definition/generic+programming Unknown
https://www.geeksforgeeks.org/generics-in-c/ 01 APR, 2019