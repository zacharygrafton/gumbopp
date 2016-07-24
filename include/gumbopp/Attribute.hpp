#ifndef GUMBOPP_ATTRIBUTE_HPP
#define GUMBOPP_ATTRIBUTE_HPP

#include "Config.hpp"
#include <memory>
#include <functional>

namespace gumbopp {

class AttributeIterator;
class Attributes;

class Attribute {
public:
  Attribute(const Attribute&);
  ~Attribute();

  string_view GetName() const;
  string_view GetValue() const;
private:
  friend class AttributeIterator;
  friend class Attributes;

  Attribute(std::function<void(Attribute&)>&&);

  class Pimpl;
  std::unique_ptr<Attribute::Pimpl> impl;
};

}

#endif
