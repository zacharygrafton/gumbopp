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

bool Node::IsElement() const {
  return impl->data->type == GUMBO_NODE_ELEMENT;
}

bool Node::IsComment() const {
  return impl->data->type == GUMBO_NODE_COMMENT;
}

bool Node::IsText() const {
  return impl->data->type == GUMBO_NODE_TEXT;
}

bool Node::IsCDATA() const {
  return impl->data->type == GUMBO_NODE_CDATA;
}

bool Node::IsWhitespace() const {
  return impl->data->type == GUMBO_NODE_WHITESPACE;
}

string_view Node::GetElement() const {
  if(impl->data->type == GUMBO_NODE_ELEMENT)
    return string_view { gumbo_normalized_tagname(impl->data->v.element.tag) };

  throw NotAnElementException();
}

string_view Node::GetText() const {
  if(IsComment() || IsText() || IsWhitespace() || IsComment())
    return string_view { impl->data->v.text.text };

  throw NotATextualElementException();
}

}
