#include "private/AttributeImpl.hpp"

namespace gumbopp {

Attribute::Attribute(std::function<void(Attribute&)>&& populator)
  : impl { std::make_unique<Pimpl>() } {
  populator(*this);
}

Attribute::~Attribute() {
}

string_view Attribute::GetName() const {
  return string_view { impl->data->name };
}

string_view Attribute::GetValue() const {
  return string_view { impl->data->value };
}

}
