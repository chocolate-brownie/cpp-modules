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
    void addNumber(unsigned int value);
    template <typename InputIterator>
    void addNumbers(InputIterator begin, InputIterator end) {
        if (std::distance(begin, end) > (maxCapacity - vec.size()))
            throw InvalidContainerSize();
        vec.insert(vec.end(), begin, end);
    }

    /* ---- Analogy: Runners in a Race 🏃‍♀️ ----
    Think of the numbers in your Span as the positions of several runners on a long track.

    longestSpan() tells you the distance between the runner in first place and the runner
    in last place.

    shortestSpan() tells you the distance between the two runners who are closest
    together, no matter where they are in the pack. */
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
