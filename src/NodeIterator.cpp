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