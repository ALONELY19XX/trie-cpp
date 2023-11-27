#pragma once

#include <vector>
#include <string>
#include <memory>

namespace triecpp {
   struct Node {
      char symbol;
      std::vector<std::shared_ptr<Node>> children;

      bool operator==(const Node& rhs) const;
      std::shared_ptr<Node> getChildBySymbol(char symbol);
      std::shared_ptr<Node> addChild(char symbol);
   };
}