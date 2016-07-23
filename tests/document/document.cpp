#define BOOST_TEST_MODULE gumbopp_document
#include <boost/test/included/unit_test.hpp>
#include <gumbopp/Document.hpp>
#include <gumbopp/Parser.hpp>

BOOST_AUTO_TEST_CASE( construct_document ) {
  gumbopp::Document document = gumbopp::Parser::parse("<!DOCTYPE html><html><head><title></title></head><body></body></html>");
}

BOOST_AUTO_TEST_CASE( get_name ) {
  gumbopp::Document document = gumbopp::Parser::parse("<!DOCTYPE html><html><head><title></title></head><body></body></html>");

  BOOST_CHECK(document.GetName() == "html");
}


