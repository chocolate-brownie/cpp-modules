#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

/*
--- What is std::stack? ---
* It does not support direct iteration.
* It is designed to only access the top element or remove it.
* Behind the scenes, it uses a container like deque, but you can specify your
own container if needed, e.g.:

std::stack<int, std::vector<int>> customStack;
-----------------------------------------------------------------------------------------
 --- What does std::deque do? ---
* It provides efficient insertion and removal at both front (push_front(),
pop_front()) and back (push_back(), pop_back()).
* During its operation, std::deque stores elements in multiple blocks, unlike
std::vector which stores elements contiguously—this makes growth at either end
faster in many cases.

std::deque is suitable in scenarios where you need efficient insertion/deletion
at both ends.
*/

#include <stack>

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container> {
public:
  /* typedef typename Container::iterator iterator;
  This is the most direct path. It says, "Take the Container type that this
  MutantStack is built with, and give me its iterator type." It's clean, simple,
  and easy to read.*/
  typedef typename Container::iterator iterator;
  typedef typename Container::const_iterator const_iterator;
  typedef typename Container::reverse_iterator reverse_iterator;
  typedef typename Container::const_reverse_iterator const_reverse_iterator;

  iterator begin() { return this->c.begin(); }
  iterator end() { return this->c.end(); }

  const_iterator begin() const { return this->c.begin(); }
  const_iterator end() const { return this->c.end(); }

  reverse_iterator rbegin() { return this->c.rbegin(); }
  reverse_iterator rend() { return this->c.rend(); }

  const_reverse_iterator rbegin() const { return this->c.rbegin(); }
  const_reverse_iterator rend() const { return this->c.rend(); }
};

#endif
