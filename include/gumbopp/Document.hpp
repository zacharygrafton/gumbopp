#ifndef GUMBOPP_DOCUMENT_HPP
#define GUMBOPP_DOCUMENT_HPP

#include "Config.hpp"
#include <gumbopp/Node.hpp>

#include <memory>
#include <string>
#include <boost/iterator/iterator_facade.hpp>

namespace gumbopp {

class Document {
public:
  Document(Document&&);
  ~Document();

  string_view GetName() const;
  string_view GetPublicIdentifier() const;
  string_view GetSystemIdentifier() const;

  Node GetRoot() const;

  class iterator : public boost::iterator_facade<iterator, Node, boost::bidirectional_traversal_tag, const Node> {
  public:
    explicit iterator(std::function<void(iterator&)>&&);
    iterator(const iterator& other);
    ~iterator();

  private:
    friend boost::iterator_core_access;
    friend Document;

    void increment();
    void decrement();
    bool equal(const iterator&) const;
    const Node dereference() const;

    class Pimpl;
    std::unique_ptr<Pimpl> impl;
  };

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
