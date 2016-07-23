#ifndef GUMBOPP_DOCUMENTIMPL_HPP
#define GUMBOPP_DOCUMENTIMPL_HPP

#include <gumbopp/Document.hpp>
#include <gumbo.h>

namespace gumbopp {

class Document::Pimpl {
public:
  explicit Pimpl(GumboOutput*);
  std::unique_ptr<GumboOutput, void(*)(GumboOutput*)> root;
};

}

#endif
