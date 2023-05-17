#ifndef _FLOW_H
#define _FLOW_H

#include "../shapes/Node.hpp"

class Flow: public Node {
  public:
    bool wrap;

    Flow();
    ~Flow();
};

#endif