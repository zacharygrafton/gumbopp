#ifndef GUMBOPP_ATTRIBUTEITERATOR_HPP
#define GUMBOPP_ATTRIBUTEITERATOR_HPP

#include <gumbopp/Attribute.hpp>
#include <boost/iterator/iterator_facade.hpp>

namespace gumbopp {

class Attributes;

class AttributeIterator
  : public boost::iterator_facade<AttributeIterator, Attribute, boost::bidirectional_traversal_tag, const Attribute> {
public:
  explicit AttributeIterator(std::function<void(AttributeIterator&)>&&);
  AttributeIterator(const AttributeIterator& other);
  ~AttributeIterator();

private:
  friend class boost::iterator_core_access;
  friend class Attributes;

  void increment();
  void decrement();
  bool equal(const AttributeIterator&) const;
  const Attribute dereference() const;

  class Pimpl;
  std::unique_ptr<AttributeIterator::Pimpl> impl;
};
}
#endif
