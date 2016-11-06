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
#define BOOST_TEST_MODULE gumbopp_document
#include <boost/test/included/unit_test.hpp>
#include <gumbopp/Document.hpp>
#include <gumbopp/Parser.hpp>

BOOST_AUTO_TEST_CASE( construct_document ) {
  gumbopp::Document document = gumbopp::Parser::Parse("<!DOCTYPE html><html><head><title></title></head><body></body></html>");
}

BOOST_AUTO_TEST_CASE( get_name ) {
  gumbopp::Document document = gumbopp::Parser::Parse("<!DOCTYPE html><html><head><title></title></head><body></body></html>");

  BOOST_CHECK(document.GetName() == "html");
}

BOOST_AUTO_TEST_CASE( iterators ) {
  gumbopp::Document document = gumbopp::Parser::Parse("<!DOCTYPE html><!-- test --><html><head><title></title></head><body></body></html>");

  auto begin = document.begin();
  auto end = document.end();

  auto location = std::find_if(begin, end, [](const auto& n) {
    if(n.IsElement())
      return n.GetElement() == "html";
    return false;
  });

  BOOST_CHECK(location != end);
}
