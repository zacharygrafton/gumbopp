#ifndef GUMBOPP_ATTRIBUTEITERATORIMPL_HPP
#define GUMBOPP_ATTRIBUTEITERATORIMPL_HPP

#include <gumbopp/AttributeIterator.hpp>
#include <gumbo.h>

namespace gumbopp {

class AttributeIterator::Pimpl {
public:
  std::size_t position;
  GumboVector* vector;
};

}
#endif
