#define BOOST_TEST_MODULE gumbopp_node
#include <boost/test/included/unit_test.hpp>
#include <gumbopp/Document.hpp>
#include <gumbopp/Node.hpp>

BOOST_AUTO_TEST_CASE( construct_node ) {
  gumbopp::Document doc { "<!DOCTYPE html><html><head><title></title></head><body></body></html>"};
  gumbopp::Node node = doc.GetRoot();

  std::cout << node.GetTag() << std::endl;
  BOOST_CHECK(node.GetTag() == "html");
}