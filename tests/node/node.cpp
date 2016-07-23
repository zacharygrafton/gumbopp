#define BOOST_TEST_MODULE gumbopp_node
#include <boost/test/included/unit_test.hpp>
#include <gumbopp/Document.hpp>
#include <gumbopp/Parser.hpp>
#include <gumbopp/Node.hpp>

BOOST_AUTO_TEST_CASE( construct_node ) {
  gumbopp::Document document = gumbopp::Parser::parse("<html><head><title></title></head><body></body></html>");
  gumbopp::Node node = document.GetRoot();

  std::cout << node.GetTag() << std::endl;
  BOOST_CHECK(node.GetTag() == "html");
}