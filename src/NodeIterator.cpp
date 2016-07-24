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
#include <gumbopp/NodeIterator.hpp>
#include "private/NodeIteratorImpl.hpp"
#include "private/NodeImpl.hpp"

namespace gumbopp {

NodeIterator::NodeIterator(std::function<void(NodeIterator&)>&& populator)
  : impl { std::make_unique<Pimpl>() } {
  populator(*this);
}

NodeIterator::NodeIterator(const NodeIterator& other)
  : impl { std::make_unique<Pimpl>() } {
  impl->position = other.impl->position;
  impl->vector = other.impl->vector;
}

NodeIterator::~NodeIterator() {
}

void NodeIterator::increment() {
  impl->position++;
}

void NodeIterator::decrement() {
  impl->position--;
}

bool NodeIterator::equal(const NodeIterator& other) const {
  return impl->position == other.impl->position;
}

const Node NodeIterator::dereference() const {
  return Node {
    [&](Node& n) {
      n.impl->data = static_cast<GumboNode*>(impl->vector->data[impl->position]);
    }
  };
}

}