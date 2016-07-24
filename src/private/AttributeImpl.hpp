#ifndef GUMBOPP_ATTRIBUTEPIMPL_HPP
#define GUMBOPP_ATTRIBUTEPIMPL_HPP

#include <gumbopp/Attribute.hpp>
#include <gumbo.h>

namespace gumbopp {

class Attribute::Pimpl {
public:
  GumboAttribute* data;
};

}

#endif
