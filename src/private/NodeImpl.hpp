#ifndef GUMBOPP_NODEIMPL_HPP
#define GUMBOPP_NODEIMPL_HPP

#include <gumbo.h>
#include <gumbopp/Node.hpp>

namespace gumbopp {

class Node::Pimpl {
public:
  GumboNode* data;
};

}
#endif
