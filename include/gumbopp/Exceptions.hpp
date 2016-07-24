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
#ifndef GUMBOPP_EXCEPTIONS_HPP
#define GUMBOPP_EXCEPTIONS_HPP

#include <stdexcept>

namespace gumbopp {
  class NotAnElementException : public std::runtime_error {
  public:
    NotAnElementException();
  };

  class NotADocumentException : public std::runtime_error {
  public:
    NotADocumentException();
  };

  class NotATextualElementException : public std::runtime_error {
  public:
    NotATextualElementException();
  };
}

#endif
