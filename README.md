# gumbopp

Gumbopp is a small C++ library for parsing html. It uses the
gumbo-parser library written by Google behind the scenes, however,
you don't need to learn how to use gumbo-parser, or even have the
library installed to use gumbopp.

# Installation

Installation is pretty easy, the only prerequisite for installing
gumbopp is a working Boost installation and a C++ compiler that
support C++14.

The following commands should get everything installed for you:
```
git clone https://github.com/zacharygrafton/gumbopp
cd gumbopp
mkdir build
cd build
cmake -DCMAKE_INSTALL_PREFIX=/usr -DCMAKE_BUILD_TYPE=Release ..
make
make install
```

# Documentation and Usage

Documentation is currently in the works, but the library is
small and easy enough to comprehend, but here is a short example
anyway:

```
#include <iostream>
#include <gumbopp/Parser.hpp>
#include <gumbopp/Document.hpp>
#include <gumbopp/Node.hpp>

int main(int argc, char* argv[]) {
  using namespace gumbopp;
  // Parse some html
  Document doc = Parser.parse("<html><head><title>Test</title></head>"
    "<body><p>Test</p></body></html>");

  // Get the root node of the document, which in this
  // case should be the <html> tag
  Node root = doc.GetRoot();

  // Print out the name of the element, in this case it should
  // be "html"
  std::cout << root.GetElement() << std::endl;
  return 0;
}
```

# Contributing

Contributions are always welcome, just follow some simple guidelines
and I'll accept them without complaint or fuss.

1. Roughly follow the LLVM coding guidelines (I'm not too picky)
2. Issue pull requests against the develop branch, always
3. Be polite
