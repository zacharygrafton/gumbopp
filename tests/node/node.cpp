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
#define BOOST_TEST_MODULE gumbopp_node
#include <boost/test/included/unit_test.hpp>
#include <gumbopp/Document.hpp>
#include <gumbopp/Parser.hpp>
#include <gumbopp/Node.hpp>
#include <gumbopp/Attributes.hpp>
#include <gumbopp/Attribute.hpp>
#include <gumbopp/AttributeIterator.hpp>

BOOST_AUTO_TEST_CASE( construct_node ) {
  gumbopp::Document document = gumbopp::Parser::parse("<html><head><title></title></head><body></body></html>");
  gumbopp::Node node = document.GetRoot();

  BOOST_CHECK(node.GetElement() == "html");
}

BOOST_AUTO_TEST_CASE( get_attributes ) {
  gumbopp::Document document = gumbopp::Parser::parse("<html lang=\"en\"><head><title></title></head><boyd></html>");
  gumbopp::Node node = document.GetRoot();

  gumbopp::Attributes attrs = node.GetAttributes();
  std::string name;
  std::string value;

  for(const gumbopp::Attribute& attr : attrs) {
    name = attr.GetName().to_string();
    value = attr.GetValue().to_string();
  }

  BOOST_CHECK(name == "lang");
  BOOST_CHECK(value == "en");
}