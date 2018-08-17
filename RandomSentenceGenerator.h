#pragma once
#include "Grammar.h"
#include <iostream>
#include "sstream"
#include "map"
#include "vector"
using std::stringstream;
using namespace std;

class RandomSentenceGenerator{
  public:
    RandomSentenceGenerator(string);
    string randomSentence();
    void printGrammar() ;
  private:
    string randomSentence(string);
    Grammar g;
};
