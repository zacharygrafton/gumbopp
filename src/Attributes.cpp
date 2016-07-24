#include "private/AttributesImpl.hpp"
#include "private/AttributeIteratorImpl.hpp"
#include "private/AttributeImpl.hpp"

namespace gumbopp {

Attributes::Attributes(std::function<void(Attributes&)>&& populator)
  : impl { std::make_unique<Attributes::Pimpl>() } {
  populator(*this);
}

Attributes::~Attributes() {
}

Attributes::iterator Attributes::begin() const {
  return AttributeIterator {
    [&](AttributeIterator& iter) {
      iter.impl->position = 0;
      iter.impl->vector = impl->data;
    }
  };
}

Attributes::iterator Attributes::end() const {
  return AttributeIterator {
    [&](AttributeIterator& iter) {
      iter.impl->position = impl->data->length;
      iter.impl->vector = impl->data;
    }
  };
}

}
