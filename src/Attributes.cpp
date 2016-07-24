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
