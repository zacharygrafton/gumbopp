#ifndef GUMBOPP_ATTRIBUTES_HPP
#define GUMBOPP_ATTRIBUTES_HPP

#include <memory>
#include <functional>

namespace gumbopp {

class Node;
class AttributeIterator;

class Attributes {
public:
  using iterator = AttributeIterator;

  Attributes(const Attributes&);
  ~Attributes();

  iterator begin() const;
  iterator end() const;
private:
  friend class Node;

  Attributes(std::function<void(Attributes&)>&&);

  class Pimpl;
  std::unique_ptr<Attributes::Pimpl> impl;
};

}
#endif
