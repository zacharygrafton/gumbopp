#ifndef GUMBOPP_DOCUMENT_HPP
#define GUMBOPP_DOCUMENT_HPP

#include "Config.hpp"

#include <memory>
#include <string>

namespace gumbopp {

class Node;

class Document {
public:
  Document(Document&&);
  ~Document();

  Node GetRoot() const;
private:
  friend class Parser;
  Document(std::function<void(Document&)>&&);

  class Pimpl;
  std::unique_ptr<Pimpl> impl;
};
}
#endif
