#ifndef _UICONVERTER_H
#define _UICONVERTER_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <optional>
#include "./shapes/Shape.hpp"
#include "../../include/rapidxml/rapidxml.hpp"

using namespace rapidxml;
using namespace std;

class UIConverter {
  public:
    UIConverter(std::string filePath);
    ~UIConverter();
    void traverseNode(xml_node<>* node, Shape* shape);
    optional<string> getNodeAttr(xml_node<>* node, string attrName);
};

#endif