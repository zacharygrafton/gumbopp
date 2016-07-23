#include <gumbopp/Document.hpp>
#include <gumbo.h>
#include "private/DocumentImpl.hpp"

namespace gumbopp {

Document::Document(const std::string& data)
  : impl { std::make_unique<Pimpl>() } {
  impl->root = gumbo_parse(data.c_str());
}

Document::~Document() {
  gumbo_destroy_output(&kGumboDefaultOptions, impl->root);
}

}
