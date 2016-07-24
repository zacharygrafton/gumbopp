#ifndef GUMBOPP_NODEITERATORIMPL_HPP
#define GUMBOPP_NODEITERATORIMPL_HPP

#include <gumbopp/NodeIterator.hpp>
#include <gumbo.h>

namespace gumbopp {

class NodeIterator::Pimpl {
public:
  std::size_t position;
  GumboVector* vector;
};

}
#endif
