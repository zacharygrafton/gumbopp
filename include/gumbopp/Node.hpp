#ifndef GUMBOPP_NODE_HPP
#define GUMBOPP_NODE_HPP

#include "Config.hpp"

#include <functional>
#include <memory>

namespace gumbopp {

class Node {
public:
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
private:
  friend class Document;
  Node(std::function<void(Node&)>&& populator);

  class Pimpl;
  std::unique_ptr<Pimpl> impl;
};

}
#endif //GUMBOPP_NODE_HPP
