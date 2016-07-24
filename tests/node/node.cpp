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