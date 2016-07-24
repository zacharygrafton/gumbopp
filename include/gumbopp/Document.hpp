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
#ifndef GUMBOPP_DOCUMENT_HPP
#define GUMBOPP_DOCUMENT_HPP

#include "Config.hpp"
#include <gumbopp/Node.hpp>
#include <gumbopp/NodeIterator.hpp>

#include <memory>
#include <string>
#include <boost/iterator/iterator_facade.hpp>

namespace gumbopp {

/// \brief Represents a parsed HTML document.
///
/// A Document contains information about the HTML document as well
/// as the ability to iterate over child nodes. Example of iterating
/// over the child elements. When iterating over a Document, you will
/// be given Nodes representing comments that occur before the initial
/// html tag. These elements will not be part of the root Node.
/// \code
/// gumbopp::Document document = gumbopp::Parser::parse("<html><head></head><body></body></html>");
/// for(Node n : document) {
///   std::cout << n.GetElement() << std::endl;
/// }
/// \endcode
/// \author Zachary Grafton
class Document {
public:
  /// \brief The iterator used to iterator over a Document.
  ///
  using iterator = NodeIterator;

  /// \brief Moves a Document object to another Document object.
  ///
  /// \author Zachary Grafton
  Document(Document&&);

  /// \brief Releases resources required for a Document object.
  ///
  /// \author Zachary Grafton
  ~Document();

  /// \brief Gets the name of the root element specified in the doctype.
  ///
  /// @return The name of the root element specified in the doctype.
  /// \author Zachary Grafton
  string_view GetName() const;

  /// \brief Get the public identifier specified in the doctype.
  ///
  /// @return The public identifier specified in the doctype.
  /// \author Zachary Grafton
  string_view GetPublicIdentifier() const;

  /// \brief Get the system identifier specified in the doctype.
  ///
  /// @return The system identifier specified in the doctype.
  /// \author Zachary Grafton
  string_view GetSystemIdentifier() const;

  /// \brief Get the root Node of the Document.
  ///
  /// The root Node is the tag specified in the doctype.
  /// @return The root Node fo the Document.
  /// \author Zachary Grafton
  Node GetRoot() const;

  /// \brief Get a NodeIterator that points to the first child Node.
  ///
  /// @return A NodeIterator that points to the first child Node.
  /// \author Zachary Grafton
  iterator begin() const;

  /// \brief Get a NodeIterator that points to the end of the child Nodes.
  ///
  /// @return A NodeIterator that points to the end of the child Nodes.
  /// \author Zachary Grafton
  iterator end() const;
private:
  friend class Parser;
  Document(std::function<void(Document&)>&&);

  class Pimpl;
  std::unique_ptr<Pimpl> impl;
};
}
#endif
