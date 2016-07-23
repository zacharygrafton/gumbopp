#include <gumbopp/Node.hpp>
#include "private/NodeImpl.hpp"
#include <gumbopp/Exceptions.hpp>

namespace gumbopp {

Node::Node(const Node& other) : impl { std::make_unique<Pimpl>() }{
  impl->data = other.impl->data;
}

Node::~Node() {
}

Node::Node(std::function<void(Node &)> &&populator) : impl { std::make_unique<Pimpl>() } {
  populator(*this);
}

string_view Node::GetTag() const {
  if(impl->data->type == GUMBO_NODE_ELEMENT)
    return string_view { gumbo_normalized_tagname(impl->data->v.element.tag) };

  throw NotAnElementException();
}

}
