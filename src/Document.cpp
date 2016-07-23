#include <gumbopp/Document.hpp>
#include <gumbo.h>
#include "private/DocumentImpl.hpp"
#include "private/NodeImpl.hpp"
#include <gumbopp/Exceptions.hpp>

namespace gumbopp {

class Document::iterator::Pimpl {
public:
  std::size_t position;
  GumboVector vector;
};

Document::iterator::iterator(std::function<void(iterator&)>&& populator)
  : impl { std::make_unique<Document::iterator::Pimpl>() } {
  populator(*this);
}

Document::iterator::iterator(const Document::iterator& other)
  : impl { std::make_unique<Document::iterator::Pimpl>() } {
  impl->position = other.impl->position;
  impl->vector = other.impl->vector;
}

Document::iterator::~iterator() {
}

void Document::iterator::increment() {
  impl->position++;
}

void Document::iterator::decrement() {
  impl->position--;
}

bool Document::iterator::equal(const Document::iterator& other) const {
  return impl->position == other.impl->position;
}

const Node Document::iterator::dereference() const {
  return Node {
    [&](Node& n) {
      n.impl->data = static_cast<GumboNode*>(impl->vector.data[impl->position]);
    }
  };
}

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
    iter.impl->vector = impl->data->document->v.document.children;
  } };
}

Document::iterator Document::end() const {
  return iterator { [&](iterator& iter) {
    iter.impl->position = impl->data->document->v.document.children.length;
    iter.impl->vector = impl->data->document->v.document.children;
  } };
}

}
