#include "private/AttributeIteratorImpl.hpp"
#include "private/AttributeImpl.hpp"

namespace gumbopp {

AttributeIterator::AttributeIterator(std::function<void(AttributeIterator&)>&& populator)
  : impl { std::make_unique<AttributeIterator::Pimpl>() } {
  populator(*this);
}

AttributeIterator::AttributeIterator(const AttributeIterator& other)
  : impl { std::make_unique<AttributeIterator::Pimpl>() } {
  impl->position = other.impl->position;
  impl->vector = other.impl->vector;
}

AttributeIterator::~AttributeIterator() {
}

void AttributeIterator::increment() {
  impl->position++;
}

void AttributeIterator::decrement() {
  impl->position--;
}

bool AttributeIterator::equal(const AttributeIterator& other) const {
  return impl->position == other.impl->position;
}

const Attribute AttributeIterator::dereference() const {
  return Attribute {
    [&](Attribute& a) {
      a.impl->data = static_cast<GumboAttribute*>(impl->vector->data[impl->position]);
    }
  };
}

}