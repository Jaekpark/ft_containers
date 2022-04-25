# Summary

This is a project to re-implement some `C++ STL Containers` to understand them.

Some requirements for this project are as follow:

Re-implement 

+ `std::vector`
+ `std::map`
+ `std::stack`
+ `std::set`
+ `std::iterators_traits`
+ `std::reverse_iterator`
+ `std::enable_if`
+ `std::is_integral`
+ `std::equal` and/or `std::lexicographical_compare`
+ `std::pair`
+ `std::make_pair`

# What is STL? <sup>[1]

> The `Standard Template Library (STL)` is a set of `C++ template classes` to privde common programming data structures and fuctions such as `list`, `stack`, `vector`, etc <sup>[1]

> `STL` has four components
> + [Algorithms](#algorithms)
> + [Containers](#containers)
> + [Functions(Functor)](#functionsfunctor)
> + [Iterators](#iterators)

This project is designed to implement a few containers, functions, and iterators in the C++98.

## Algorithms

> The header algorithm defines a collection of functions especially designed to be used on ranges of elements. They act on containers and privide means for various operations for the contents of the containers. <sup>[1]

> Algorithims
>	+ Sorting
> 	+ Searching
> 	+ partition
> 	+ etc.

## Containers

> Containers or container classes store objects and data. There are in total 7 standard "first-class" container classes and 3 container adaptor classes and only seven header files that provide access to these containers or container adaptors. <sup>[1]

| sequence containers                                                     | container adaptors                                       | associative containers                                                               | unordered associative containers`(c++11)`                        |
| ----------------------------------------------------------------------- | -------------------------------------------------------- | ------------------------------------------------------------------------------------ | ---------------------------------------------------------------- |
| implement data structures whici can be accessed in a sequential manner. | provide a different interface for sequential containers. | implement sorted data structures that can be quickly searched(O(long n) complexity). | implement unordered data structures that can be quickly searched |
| vector                                                                  | queue                                                    | set                                                                                  | unordered_set `(c++11)`                                          |
| list                                                                    | priority queue                                           | mutiset                                                                              | unordered_mutiset `(c++11)`                                      |
| deque                                                                   | stack                                                    | map                                                                                  | unordered_map `(c++11)`                                          |
| arrays`(c++11)`                                                         | multimap                                                 |                                                                                      | unordered_mutimap `(c++11)`                                      |
| forward lists`(c++11)`                                                  |

> Flowchart of Adaptive containers and Unordered Containers <sup>[1]
>![Flowchart of Adaptive containers and Unordered Containers](https://media.geeksforgeeks.org/wp-content/uploads/20191111161536/Screenshot-from-2019-11-11-16-13-18.png)
>
> Flowchart of Sequence containers and Ordered Containers <sup>[1]
>![Flowchart of Sequence containers and Ordered Containers](https://media.geeksforgeeks.org/wp-content/uploads/20191111161627/Screenshot-from-2019-11-11-16-15-07.png)

## Functions(Functor)

> The STL includes classes that overload the function call operator. Instances of such classes are called function objects or functors. Functors allow the working of the associated function to be customized with the help of parameters to be passed. <sup>[1]

## Iterators

> As the name suggests, iterators are used for working upon a sequence of values. They are the major feature that allow generality in STL. <sup>[1]
# Reference
<a nmae="what-is-stl">1</a>: ["The C++ Standard Template Library (STL)", GeeksforGeeks, last modified Nov 19, 2021, accessed Apr 25, 2022, "https://www.geeksforgeeks.org/the-c-standard-template-library-stl/?ref=lbp"](https://www.geeksforgeeks.org/the-c-standard-template-library-stl/?ref=lbp)