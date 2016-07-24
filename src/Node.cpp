#include "private/NodeImpl.hpp"
#include "private/NodeIteratorImpl.hpp"
#include "private/AttributesImpl.hpp"
#include <gumbopp/Exceptions.hpp>
#include <3rdParty/include/gumbo.h>

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

Node::iterator Node::begin() const {
  return iterator {
    [&](iterator& iter) {
      iter.impl->position = 0;
      iter.impl->vector = &impl->data->v.element.children;
    }
  };
}

Node::iterator Node::end() const {
  return iterator {
    [&](iterator& iter) {
      iter.impl->position = impl->data->v.element.children.length;
      iter.impl->vector = &impl->data->v.element.children;
    }
  };
}

Attributes Node::GetAttributes() const {
  return Attributes {
    [&](Attributes& attrs) {
      attrs.impl->data = &impl->data->v.element.attributes;
    }
  };
}

}
