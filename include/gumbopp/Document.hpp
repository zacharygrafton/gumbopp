#ifndef GUMBOPP_DOCUMENT_HPP
#define GUMBOPP_DOCUMENT_HPP

#include <memory>
#include <string>

namespace gumbopp {

class Document {
public:
  Document(const std::string& data);
private:
  class Pimpl;

  std::unique_ptr<Pimpl> impl;
};
}
#endif
