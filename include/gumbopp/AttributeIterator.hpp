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
#ifndef GUMBOPP_ATTRIBUTEITERATOR_HPP
#define GUMBOPP_ATTRIBUTEITERATOR_HPP

#include <gumbopp/Attribute.hpp>
#include <boost/iterator/iterator_facade.hpp>

namespace gumbopp {

class Attributes;

class AttributeIterator
  : public boost::iterator_facade<AttributeIterator, Attribute, boost::bidirectional_traversal_tag, const Attribute> {
public:
  explicit AttributeIterator(std::function<void(AttributeIterator&)>&&);
  AttributeIterator(const AttributeIterator& other);
  ~AttributeIterator();

private:
  friend class boost::iterator_core_access;
  friend class Attributes;

  void increment();
  void decrement();
  bool equal(const AttributeIterator&) const;
  const Attribute dereference() const;

  class Pimpl;
  std::unique_ptr<AttributeIterator::Pimpl> impl;
};
}
#endif
