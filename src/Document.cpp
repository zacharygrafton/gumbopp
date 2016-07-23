#include <gumbopp/Document.hpp>
#include <gumbo.h>
#include "private/DocumentImpl.hpp"

namespace gumbopp {

Document::Pimpl::Pimpl(GumboOutput *output)
  : root { output, [](GumboOutput* o) { gumbo_destroy_output(&kGumboDefaultOptions, o); } }{
}

Document::Document(const std::string& data)
  : impl { std::make_unique<Pimpl>(gumbo_parse(data.c_str())) } {
}

}
