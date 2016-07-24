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
#ifndef GUMBOPP_NODEITERATOR_HPP
#define GUMBOPP_NODEITERATOR_HPP

#include <gumbopp/Node.hpp>
#include <boost/iterator/iterator_facade.hpp>

namespace gumbopp {

class Document;

class NodeIterator
  : public boost::iterator_facade<NodeIterator, Node, boost::bidirectional_traversal_tag, const Node> {
public:
  explicit NodeIterator(std::function<void(NodeIterator&)>&&);
  NodeIterator(const NodeIterator& other);
  ~NodeIterator();

private:
  friend boost::iterator_core_access;
  friend Node;
  friend Document;

  void increment();
  void decrement();
  bool equal(const NodeIterator&) const;
  const Node dereference() const;

  class Pimpl;
  std::unique_ptr<Pimpl> impl;
};

}

#endif
