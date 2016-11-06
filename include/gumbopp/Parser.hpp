// Copyright 2016 Zachary Grafton
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//  http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
#ifndef GUMBOPP_PARSER_HPP
#define GUMBOPP_PARSER_HPP

#include "Config.hpp"
#include <functional>
#include <memory>

namespace gumbopp {

class Document;

/// \brief Represents a HTML parser.
///
/// A simple class used for parsing HTML input. Example usage:
/// \code
/// gumbopp Document document = Parser::parse("<html><head></head><body></body></html>");
/// \endcode
/// \author Zachary Grafton
class Parser {
public:
  /// \brief Parse the HTML in a given std::string.
  ///
  /// @param The string to parse
  /// @return A Document containing the results of the parse.
  /// \author Zachary Grafton
  static Document Parse(const std::string&);
private:
  Parser();
};

}
#endif
