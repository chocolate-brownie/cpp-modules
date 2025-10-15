#ifndef SPAN_HPP
#define SPAN_HPP

#include <exception>
#include <iterator>
#include <vector>
class Span {
  private:
    unsigned int maxCapacity;
    std::vector<unsigned int> vec;
    std::vector<unsigned int>::iterator minIt;
    std::vector<unsigned int>::iterator maxIt;

  public:
    template <typename InputIterator>
    void addNumbers(InputIterator begin, InputIterator end) {
        if (std::distance(begin, end) > static_cast<long int>(maxCapacity - vec.size()))
            throw InvalidContainerSize();

        /* The third argument, std::back_inserter(vec), is an output iterator. Its job is
        to tell the std::copy algorithm where to place the copied elements.
        Specifically, it adapts the vec container so that std::copy effectively calls
        vec.push_back() for each element it copies. */
        std::copy(begin, end, std::back_inserter(vec));
    }

    /* ---- Analogy: Runners in a Race 🏃‍♀️ ----
    Think of the numbers in your Span as the positions of several runners on a long track.

    longestSpan() tells you the distance between the runner in first place and the runner
    in last place.

    shortestSpan() tells you the distance between the two runners who are closest
    together, no matter where they are in the pack. */
    void addNumber(unsigned int value);
    unsigned int shortestSpan();
    unsigned int longestSpan();

    const std::vector<unsigned int>::iterator getMinIt();
    const std::vector<unsigned int>::iterator getMaxIt();

    Span(unsigned int N);
    Span(const Span& other);
    Span& operator=(const Span& other);
    ~Span();

    class ContainerIsFull : public std::exception {
      public:
        const char* what() const throw();
    };

    class InvalidContainerSize : public std::exception {
      public:
        const char* what() const throw();
    };
};

#endif
