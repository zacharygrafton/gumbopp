#define BOOST_TEST_MODULE gumbopp_document
#include <boost/test/included/unit_test.hpp>
#include <gumbopp/Document.hpp>
#include <gumbopp/Parser.hpp>

BOOST_AUTO_TEST_CASE( construct_document ) {
  gumbopp::Document document = gumbopp::Parser::parse("<html><head><title></title></head><body></body></html>");
}
