#ifndef GUMBOPP_NODE_HPP
#define GUMBOPP_NODE_HPP

#include "Config.hpp"

#include <functional>
#include <memory>

namespace gumbopp {
class NodeIterator;
class Attributes;

class Node {
public:
  using iterator = NodeIterator;

  Node(const Node& other);
  ~Node();
  Node GetParent();

  bool IsElement() const;
  bool IsComment() const;
  bool IsWhitespace() const;
  bool IsText() const;
  bool IsCDATA() const;

  string_view GetText() const;
  string_view GetElement() const;

  iterator begin() const;
  iterator end() const;

  Attributes GetAttributes() const;
private:
  friend class Document;
  friend class NodeIterator;
  Node(std::function<void(Node&)>&& populator);

  class Pimpl;
  std::unique_ptr<Pimpl> impl;
};

}
#endif //GUMBOPP_NODE_HPP
