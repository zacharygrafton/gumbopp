#ifndef GUMBOPP_ATTRIBUTESIMPL_HPP
#define GUMBOPP_ATTRIBUTESIMPL_HPP

#include <gumbopp/Attributes.hpp>
#include <gumbo.h>

namespace gumbopp {

class Attributes::Pimpl {
public:
  GumboVector* data;
};

}
#endif
