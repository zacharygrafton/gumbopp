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
#include "private/AttributeImpl.hpp"

namespace gumbopp {

Attribute::Attribute(std::function<void(Attribute&)>&& populator)
  : impl { std::make_unique<Pimpl>() } {
  populator(*this);
}

Attribute::Attribute(const Attribute& other)
  : impl { std::make_unique<Pimpl>() } {
  impl->data = other.impl->data;
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
