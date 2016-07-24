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
#ifndef GUMBOPP_ATTRIBUTES_HPP
#define GUMBOPP_ATTRIBUTES_HPP

#include <memory>
#include <functional>

namespace gumbopp {

class Node;
class AttributeIterator;

/// \brief Represents the attributes of a Node.
///
/// This class is designed to act like a container of Attribute
/// and allows iteration of html attributes of a tag.
/// \author Zachary Grafton
class Attributes {
public:
  /// \brief The iterator used for iterating over Attributes
  ///
  using iterator = AttributeIterator;

  /// \brief Copies a set of attributes.
  ///
  /// Copies a set of attributes, but there is very little memory allocation,
  /// just enough for storing a pointer and a position.
  /// \author Zachary Grafton
  Attributes(const Attributes&);

  /// \brief Releases resources acquired by an Attributes object.
  ///
  /// \author Zachary Grafton
  ~Attributes();

  /// \brief Get an AttributeIterator pointing to the first Attribute.
  ///
  /// @return An AttributeIterator pointing to the first Attribute.
  /// \author Zachary Grafton
  iterator begin() const;

  /// \brief Get an AttributeIterator pointing past the last Attribute.
  ///
  /// @return An AttributeIterator pointing past the last Attribute.
  /// \author Zachary Grafton
  iterator end() const;
private:
  friend class Node;

  Attributes(std::function<void(Attributes&)>&&);

  class Pimpl;
  std::unique_ptr<Attributes::Pimpl> impl;
};

}
#endif
