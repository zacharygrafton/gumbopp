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
#ifndef GUMBOPP_NODE_HPP
#define GUMBOPP_NODE_HPP

#include "Config.hpp"

#include <functional>
#include <memory>

namespace gumbopp {
class NodeIterator;
class Attributes;

/// \brief Represents a Node in a HTML document.
///
/// A Node can be a tag element, a comment element, whitespace,
/// text, or CDATA. It is recommended that you check the type of
/// the element before calling any methods on the Node object. If
/// you call a method on an inappropriate Node, it will throw an
/// exception.
/// \author Zachary Grafton
class Node {
public:
  /// \brief The iterator used to iterate over the child nodes.
  ///
  using iterator = NodeIterator;

  /// \brief Initializes a Node with no state
  ///
  /// \author Zachary Grafton
  Node();

  /// \brief Copies the internal data of a Node to another Node.
  ///
  /// \author Zachary Grafton
  Node(const Node& other);

  /// \brief Releases resources acquired by the Node object.
  ///
  /// \author Zachary Grafton
  ~Node();

  /// \brief Copies the internal data of a Node to another Node.
  ///
  /// \author Zachary Grafton
  Node& operator=(const Node& other);

  /// \brief Get the parent Node of this Node.
  ///
  /// \author Zachary Grafton
  Node GetParent();

  /// \brief Is this Node an element?
  ///
  /// \author Zachary Grafton
  bool IsElement() const;

  /// \brief Is this Node a comment?
  ///
  /// \author Zachary Grafton
  bool IsComment() const;

  /// \brief Is this Node whitespace?
  ///
  /// \author Zachary Grafton
  bool IsWhitespace() const;

  /// \brief Is this Node text?
  ///
  /// \author Zachary Grafton
  bool IsText() const;

  /// \brief Is this Node CDATA?
  ///
  /// \author Zachary Grafton
  bool IsCDATA() const;

  /// \brief Get the text of the element.
  ///
  /// @throws NotAnElementException The Node isn't an element that has text.
  /// @return The text of the element
  /// \author Zachary Grafton
  string_view GetText() const;

  /// \brief Get the string representation of the tag.
  ///
  /// The string representation of a tag is the name of the element without
  /// any surround characters, for example <html lang="en"> would be represented
  /// as "html".
  /// @return The string representation of the tag.
  /// \author Zachary Grafton
  string_view GetElement() const;

  /// \brief Get a NodeIterator pointing to the first child Node.
  ///
  /// @return A NodeIterator pointing to the first child Node.
  /// \author Zachary Grafton
  iterator begin() const;

  /// \brief Get a NodeIterator pointing past the last child Node.
  ///
  /// @return A NodeIterator pointing past the last child Node.
  /// \author Zachary Grafton
  iterator end() const;

  /// \brief Get the Attributes of the Node.
  ///
  /// @return Attributes of the element
  /// \author Zachary Grafton
  Attributes GetAttributes() const;
private:
  friend class Document;
  friend class NodeIterator;
  Node(std::function<void(Node&)>&& populator);

  class Pimpl;
  std::unique_ptr<Pimpl> impl;
};

}
#endif //GUMBOPP_NODE_HPP
