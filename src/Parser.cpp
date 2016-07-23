#include <gumbopp/Parser.hpp>
#include <gumbopp/Document.hpp>
#include "private/DocumentImpl.hpp"

namespace gumbopp {

Document Parser::parse(const std::string& data) {
  Document document { [&](Document& doc) { doc.impl->data = gumbo_parse(data.c_str()); } };
  return document;
}

}