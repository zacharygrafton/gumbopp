// Copyright 2016 Zachary Grafton
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//  http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
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