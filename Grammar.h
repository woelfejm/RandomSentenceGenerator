#pragma once
#include <iostream>
#include "sstream"
#include "map"
#include "vector"
using std::stringstream;
using namespace std;

class Grammar{
  //I made all methods public for testing purposes. Normally, everything would
  //be private except for constructor and getRandomRHS
  public:
    Grammar();
    string const getRandomRHS( string nonTerm );
    bool containsNonTerminal( string nonTerm ) const;
    map<string,vector<string>> gramMap;
    void addProduction( string nonTerm, string rhs );
    string toString() ; //method I added

  private:
  
};
