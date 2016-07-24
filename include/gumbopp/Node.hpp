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

class Node {
public:
  using iterator = NodeIterator;

  Node(const Node& other);
  ~Node();
  Node GetParent();

  bool IsElement() const;
  bool IsComment() const;
  bool IsWhitespace() const;
  bool IsText() const;
  bool IsCDATA() const;

  string_view GetText() const;
  string_view GetElement() const;

  iterator begin() const;
  iterator end() const;

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
