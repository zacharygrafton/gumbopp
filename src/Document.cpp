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
#include <gumbo.h>
#include "private/DocumentImpl.hpp"
#include "private/NodeImpl.hpp"
#include "private/NodeIteratorImpl.hpp"
#include <gumbopp/Exceptions.hpp>

namespace gumbopp {

Document::Document(std::function<void(Document&)>&& populator)
  : impl { std::make_unique<Pimpl>() } {
  populator(*this);
}

Document::Document(Document&& other) : impl { std::move(other.impl) } {
}

Document::~Document() {
  gumbo_destroy_output(&kGumboDefaultOptions, impl->data);
}

Node Document::GetRoot() const {
  return Node { [&](Node& n) { n.impl->data = impl->data->root; }};
}

string_view Document::GetName() const {
  if(impl->data->document->type != GUMBO_NODE_DOCUMENT)
    throw NotADocumentException();

  return string_view { impl->data->document->v.document.name };
}

string_view Document::GetPublicIdentifier() const {
  if(impl->data->document->type != GUMBO_NODE_DOCUMENT)
    throw NotADocumentException();

  return string_view { impl->data->document->v.document.public_identifier };
}

string_view Document::GetSystemIdentifier() const {
  if(impl->data->document->type != GUMBO_NODE_DOCUMENT)
    throw NotADocumentException();

  return string_view { impl->data->document->v.document.system_identifier };
}

Document::iterator Document::begin() const {
  return iterator { [&](iterator& iter) {
    iter.impl->position = 0;
    iter.impl->vector = &impl->data->document->v.document.children;
  } };
}

Document::iterator Document::end() const {
  return iterator { [&](iterator& iter) {
    iter.impl->position = impl->data->document->v.document.children.length;
    iter.impl->vector = &impl->data->document->v.document.children;
  } };
}

}
