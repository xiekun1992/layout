#include "UIConverter.hpp"

UIConverter::UIConverter(std::string filePath)
{
  // cout << filePath << endl;
  try
  {
    rapidxml::xml_document<> doc;
    // Read the xml file into a vector
    std::ifstream theFile(filePath);
    std::vector<char> buffer((std::istreambuf_iterator<char>(theFile)), std::istreambuf_iterator<char>());
    buffer.push_back('\0');
    // Parse the buffer using the xml file parsing library into doc
    doc.parse<0>(&buffer[0]);
    // Find our root node
    rapidxml::xml_node<> *rootNode = doc.first_node("root");
    
    tree = new Node(
      stoi(getNodeAttr(rootNode, "x").value_or("0")),
      stoi(getNodeAttr(rootNode, "y").value_or("0")),
      stoi(getNodeAttr(rootNode, "width").value_or("0")),
      stoi(getNodeAttr(rootNode, "height").value_or("0"))
    );
    traverseNode(rootNode, tree);
  }
  catch (std::exception e)
  {
    std::cout << "parse error: " << e.what() << std::endl;
  }
}

UIConverter::~UIConverter() {}

std::optional<std::string> UIConverter::getNodeAttr(rapidxml::xml_node<>* node, std::string attrName) {
  std::string attrStr;
  rapidxml::xml_attribute<char> *xattr = node->first_attribute(attrName.c_str());
  if (xattr) {
    attrStr = xattr->value();
  }
  if (attrStr == "") {
    attrStr = "0";
  }
  // cout << attrName << ": " << attrStr << endl;
  return std::optional<std::reference_wrapper<std::string>>{attrStr};
}

void UIConverter::traverseNode(rapidxml::xml_node<> *node, Node *shape)
{
  for (rapidxml::xml_node<> *subNode = node->first_node("node"); subNode; subNode = subNode->next_sibling())
  {
    Node* subShape = new Node(
      std::stoi(getNodeAttr(subNode, "x").value_or("0")),
      std::stoi(getNodeAttr(subNode, "y").value_or("0")),
      std::stoi(getNodeAttr(subNode, "width").value_or("0")),
      std::stoi(getNodeAttr(subNode, "height").value_or("0"))
    );

    shape->children.push_back(subShape);
    if (subNode->first_node("node") != nullptr) {
      traverseNode(subNode, subShape);
    }
  }
}