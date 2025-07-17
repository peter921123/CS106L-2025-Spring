#include "spellcheck.h"

#include <algorithm>
#include <iostream>
#include <numeric>
#include <ranges>
#include <set>
#include <vector>

template <typename Iterator, typename UnaryPred>
std::vector<Iterator> find_all(Iterator begin, Iterator end, UnaryPred pred);

Corpus tokenize(std::string& source) {
  std::vector<std::string::iterator> iterVector = find_all(source.begin(), source.end(), ::isspace);
  
  auto func1 = [&source](std::string::iterator it1, std::string::iterator it2){
    return Token{source, it1, it2};
  };

  std::set<Token> tokens;
  std::transform(iterVector.begin(), iterVector.end()-1,
                 iterVector.begin()+1, std::inserter(tokens, tokens.end()), func1);

  auto func2 = [](const Token& token) {
    return token.content.empty();
  };
  std::erase_if(tokens, func2);

  return Corpus(tokens);
}

std::set<Misspelling> spellcheck(const Corpus& source, const Dictionary& dictionary) {
  
  auto func1 = [dictionary](const auto& token) {
    return (dictionary.find(token.content) == dictionary.end());
  };
  
  auto func2 = [dictionary](const auto& token) {

    auto func3 = [token](auto& word) {
      return levenshtein(token.content, word) == size_t(1);
    };

    auto view = dictionary 
      | std::ranges::views::filter(func3);

    std::set<std::string> suggestions(view.begin(), view.end());

    return Misspelling {token, suggestions};
  };

  auto func4 = [](const auto& misspelling) {
    return !(misspelling.suggestions.empty());
  };

  auto view = source 
    | std::ranges::views::filter(func1)
    | std::ranges::views::transform(func2)
    | std::ranges::views::filter(func4);

  return std::set<Misspelling>(view.begin(), view.end());
};

/* Helper methods */

#include "utils.cpp"