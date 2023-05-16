#ifndef _UICONVERTER_H
#define _UICONVERTER_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <optional>
#include "./shapes/Node.hpp"
#include "../../include/rapidxml/rapidxml.hpp"

class UIConverter {
  public:
    Node* tree;

    UIConverter(std::string filePath);
    ~UIConverter();
    void traverseNode(rapidxml::xml_node<>* node, Node* shape);
    std::optional<std::string> getNodeAttr(rapidxml::xml_node<>* node, std::string attrName);
};

#endif