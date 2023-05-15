#include "UIConverter.hpp"

UIConverter::UIConverter(std::string filePath)
{
  cout << filePath << endl;
  try
  {
    xml_document<> doc;
    // Read the xml file into a vector
    ifstream theFile(filePath);
    vector<char> buffer((istreambuf_iterator<char>(theFile)), istreambuf_iterator<char>());
    buffer.push_back('\0');
    // Parse the buffer using the xml file parsing library into doc
    doc.parse<0>(&buffer[0]);
    // Find our root node
    xml_node<> *rootNode = doc.first_node("div");
    
    tree = new Shape(
      stoi(getNodeAttr(rootNode, "x").value_or("0")),
      stoi(getNodeAttr(rootNode, "y").value_or("0")),
      stoi(getNodeAttr(rootNode, "width").value_or("0")),
      stoi(getNodeAttr(rootNode, "height").value_or("0"))
    );
    traverseNode(rootNode, tree);
  }
  catch (exception e)
  {
    cout << "parse error: " << e.what() << endl;
  }
}

UIConverter::~UIConverter() {}

optional<string> UIConverter::getNodeAttr(xml_node<>* node, string attrName) {
  string attrStr;
  xml_attribute<char> *xattr = node->first_attribute(attrName.c_str());
  if (xattr) {
    attrStr = xattr->value();
  }
  if (attrStr == "") {
    attrStr = "0";
  }
  // cout << attrName << ": " << attrStr << endl;
  return optional<reference_wrapper<string>>{attrStr};
}

void UIConverter::traverseNode(xml_node<> *node, Shape *shape)
{
  for (xml_node<> *subNode = node->first_node("div"); subNode; subNode = subNode->next_sibling())
  {
    Shape* subShape = new Shape(
      stoi(getNodeAttr(subNode, "x").value_or("0")),
      stoi(getNodeAttr(subNode, "y").value_or("0")),
      stoi(getNodeAttr(subNode, "width").value_or("0")),
      stoi(getNodeAttr(subNode, "height").value_or("0"))
    );

    shape->children.push_back(subShape);
    if (subNode->first_node("div") != nullptr) {
      traverseNode(subNode, subShape);
    }
  }
}