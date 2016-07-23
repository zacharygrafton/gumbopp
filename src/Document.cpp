#include <gumbopp/Document.hpp>
#include <gumbopp/Node.hpp>
#include <gumbo.h>
#include "private/DocumentImpl.hpp"
#include "private/NodeImpl.hpp"

namespace gumbopp {

Document::Document(const std::string& data)
  : impl { std::make_unique<Pimpl>() } {
  impl->root = gumbo_parse(data.c_str());
}

Document::~Document() {
  gumbo_destroy_output(&kGumboDefaultOptions, impl->root);
}

Node Document::GetRoot() const {
  return Node { [&](Node& n) { n.impl->data = impl->root->document; }};
}

}
