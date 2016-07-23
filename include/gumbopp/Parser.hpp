#ifndef GUMBOPP_PARSER_HPP
#define GUMBOPP_PARSER_HPP

#include "Config.hpp"
#include <functional>
#include <memory>

namespace gumbopp {

class Document;

class Parser {
public:
  static Document parse(const std::string&);
private:
  Parser();
};

}
#endif
