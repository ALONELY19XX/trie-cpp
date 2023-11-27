#include <iostream>
#include <algorithm>
#include <string>

#include "Trie.h"
#include "Node.h"

using namespace triecpp;

Trie::Trie(char specialSymbol) {
   this->specialSymbol = specialSymbol;
   this->root = std::make_shared<Node>(Node{specialSymbol, {}});
}

void Trie::registerWord(const std::string& word) {
   std::shared_ptr<Node> currentNode = this->root;

   for(const char& symbol: word) {
      currentNode =  currentNode->addChild(symbol);
   }

   auto leaf = std::make_shared<Node>(Node{this->specialSymbol, {}});
   currentNode->children.push_back(leaf);
}


std::shared_ptr<Node> Trie::traversePrefix(std::string& prefix) {
   std::shared_ptr<Node> currentNode = this->root;

   for(const char& symbol: prefix) {
      currentNode = currentNode->getChildBySymbol(symbol);
      
      if(currentNode == nullptr) {
         break;
      }
   }

   return currentNode;
}

void Trie::populate(std::vector<std::string>& words) {
   for(const auto& word: words) {
      this->registerWord(word);
   }
}

void Trie::collectWordsRecursively(std::shared_ptr<Node> currentNode, std::string wordBuffer, std::vector<std::string>& collection) {
   for(auto& child: currentNode->children) {

      if(child->symbol == this->specialSymbol) {
         collection.push_back(wordBuffer);
      } 
      
      else {
         collectWordsRecursively(child, wordBuffer + child->symbol, collection);
      }
   }
}

std::vector<std::string> Trie::findMatches(std::string prefix)  {
   std::vector<std::string> matches = {};
   
   auto prefixSubtreeRoot = this->traversePrefix(prefix);

   this->collectWordsRecursively(prefixSubtreeRoot, prefix, matches);

   return matches;
}
