#define BOOST_TEST_MODULE gumbopp_document
#include <boost/test/included/unit_test.hpp>
#include <gumbopp/Document.hpp>

BOOST_AUTO_TEST_CASE( construct_document ) {
  gumbopp::Document doc { "<!DOCTYPE html><html><head><title></title></head><body></body></html>"};
}
