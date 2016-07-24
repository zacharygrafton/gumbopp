#ifndef GUMBOPP_DOCUMENT_HPP
#define GUMBOPP_DOCUMENT_HPP

#include "Config.hpp"
#include <gumbopp/Node.hpp>
#include <gumbopp/NodeIterator.hpp>

#include <memory>
#include <string>
#include <boost/iterator/iterator_facade.hpp>

namespace gumbopp {

class Document {
public:
  using iterator = NodeIterator;
  Document(Document&&);
  ~Document();

  string_view GetName() const;
  string_view GetPublicIdentifier() const;
  string_view GetSystemIdentifier() const;

  Node GetRoot() const;

  iterator begin() const;
  iterator end() const;
private:
  friend class Parser;
  Document(std::function<void(Document&)>&&);

  class Pimpl;
  std::unique_ptr<Pimpl> impl;
};
}
#endif
