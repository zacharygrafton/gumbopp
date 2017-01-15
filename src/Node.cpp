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
#include "private/NodeImpl.hpp"
#include "private/NodeIteratorImpl.hpp"
#include "private/AttributesImpl.hpp"
#include <gumbopp/Exceptions.hpp>
#include <gumbo.h>

namespace gumbopp {

Node::Node() : impl { std::make_unique<Pimpl>() } {
  impl->data = nullptr;
}

Node::Node(const Node& other) : impl { std::make_unique<Pimpl>() }{
  impl->data = other.impl->data;
}

Node& Node::operator=(const Node& other) {
  impl = std::make_unique<Pimpl>();
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
