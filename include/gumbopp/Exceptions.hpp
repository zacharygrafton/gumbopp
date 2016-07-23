#ifndef GUMBOPP_EXCEPTIONS_HPP
#define GUMBOPP_EXCEPTIONS_HPP

#include <stdexcept>

namespace gumbopp {
  class NotAnElementException : public std::runtime_error {
  public:
    NotAnElementException();
  };

  class NotADocumentException : public std::runtime_error {
  public:
    NotADocumentException();
  };
}

#endif
