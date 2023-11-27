#pragma once

#include <memory>
#include <vector>
#include <string>

#include "Node.h"

namespace triecpp {
   class Trie {
      public:
         Trie(char specialSymbol);
         void populate(std::vector<std::string>& words);
         void registerWord(const std::string& word);
         std::vector<std::string> findMatches(std::string prefix) ;
      private:
         std::shared_ptr<Node> root;
         char specialSymbol;
         std::shared_ptr<Node> traversePrefix(std::string& prefix);
         void collectWordsRecursively(std::shared_ptr<Node> currentNode, std::string wordBuffer, std::vector<std::string>& collection);
   };
}