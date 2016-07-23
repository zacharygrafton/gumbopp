#include <gumbopp/Exceptions.hpp>

namespace gumbopp {

NotAnElementException::NotAnElementException() : std::runtime_error("Node is not an element.") {
}

NotADocumentException::NotADocumentException() : std::runtime_error("Node is not a document.") {
}

NotATextualElementException::NotATextualElementException()
  : std::runtime_error { "Element is not a textual element."} {
}
}