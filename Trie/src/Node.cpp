#include <algorithm>
#include <memory>

#include "Node.h"

namespace triecpp {
   bool Node::operator==(const Node& rhs) const {
      return symbol == rhs.symbol;
   }

   std::shared_ptr<Node> Node::getChildBySymbol(char symbol) {
      auto it = std::find_if(
          this->children.begin(), 
          this->children.end(), 
          [&](std::shared_ptr<Node> node) { return node->symbol == symbol; }
       );

      if(it == children.end()) {
         return nullptr;
      }

      return *it;
   }

   std::shared_ptr<Node> Node::addChild(char symbol) {
      auto existingChild = this->getChildBySymbol(symbol); 

      if(existingChild == nullptr) {
         auto child = std::make_shared<Node>(Node{symbol, {}});
         this->children.push_back(child);
         return child;
      }

      return existingChild;
   }
}
