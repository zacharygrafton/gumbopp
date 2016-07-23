#include <gumbopp/Exceptions.hpp>

namespace gumbopp {

NotAnElementException::NotAnElementException() : std::runtime_error("Node is not an element.") {
}

NotADocumentException::NotADocumentException() : std::runtime_error("Node is not a document.") {
}

}