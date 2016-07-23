#ifndef GUMBOPP_DOCUMENT_HPP
#define GUMBOPP_DOCUMENT_HPP

#include "Config.hpp"

#include <memory>
#include <string>

namespace gumbopp {

class Node;

class Document {
public:
  Document(const std::string& data);
  ~Document();

  Node GetRoot() const;
private:
  class Pimpl;

  std::unique_ptr<Pimpl> impl;
};
}
#endif
