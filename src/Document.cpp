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
