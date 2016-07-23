#include <gumbopp/Document.hpp>
#include <gumbopp/Node.hpp>
#include <gumbo.h>
#include "private/DocumentImpl.hpp"
#include "private/NodeImpl.hpp"

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

}
