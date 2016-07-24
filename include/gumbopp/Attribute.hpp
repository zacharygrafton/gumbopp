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