#ifndef GUMBOPP_NODEITERATOR_HPP
#define GUMBOPP_NODEITERATOR_HPP

#include <gumbopp/Node.hpp>
#include <boost/iterator/iterator_facade.hpp>

namespace gumbopp {

class Document;

class NodeIterator
  : public boost::iterator_facade<NodeIterator, Node, boost::bidirectional_traversal_tag, const Node> {
public:
  explicit NodeIterator(std::function<void(NodeIterator&)>&&);
  NodeIterator(const NodeIterator& other);
  ~NodeIterator();

private:
  friend boost::iterator_core_access;
  friend Node;
  friend Document;

  void increment();
  void decrement();
  bool equal(const NodeIterator&) const;
  const Node dereference() const;

  class Pimpl;
  std::unique_ptr<Pimpl> impl;
};

}

#endif
