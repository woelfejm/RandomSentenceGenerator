/*John Woelfel
 *CS 343 Murphy Spring 2018
 *PA#5

*/

#pragma once
#include "Grammar.h"
#include <iostream>
#include "sstream"
#include "vector"
#include "map"

//includes for random number
#include <cstdlib>
#include <ctime>

using std::stringstream;
using namespace std;


Grammar::Grammar(){
  //initialize seed once so each random number is different
  srand (time(0));
}

/* Returns a random string from the vector at key nonTerm
 * Uses srand() to get random number
 * @return string of randomly selected rhs
 */
string const Grammar::getRandomRHS( string nonTerm ){

  if(!this->containsNonTerminal(nonTerm)){
    cout<<"!this->containsNonTerminal("<<nonTerm<<") isn't true"<<endl;
    return "invalid nonterminal";
  }
  int max = gramMap[nonTerm].size(); //size of vector

  int randomNum = (rand() % max); //random number
  return gramMap[nonTerm][randomNum];
}


/*Adds a rhs to the string vector of the map with key nonTerm.
 *
 */
void Grammar::addProduction( string nonTerm, string rhs ){
    gramMap[nonTerm].push_back(rhs);
    return;
}

/*This method checks if a nonterminal is in our dictionary by checking
 *if the map contains that key
 *@return- true if it contains key
 */
bool Grammar::containsNonTerminal(string nonTerm) const{
  if(gramMap.count(nonTerm)){
    return true;
  }
  cout<<"string: "<<nonTerm<<" isn't a terminal"<<endl;
  return false;

}

/*Returns a string representation of a Grammar. Nonterminals have carrot brackets
 * ex: <nonTerm>
 *        this <object> <verb> hello
 */
string Grammar::toString() {
  stringstream ss;
  for(map<string,vector<string>>::iterator it = gramMap.begin(); it != gramMap.end(); ++it) {
    //gramMap.push_back(it->first);
    ss <<it->first << "\n";
    for(string& temp : gramMap[it->first]){
      ss<<"\t"<<temp<<endl;
    }
  }
  return ss.str();
}

ostream& operator<<( ostream& os, Grammar& g){
  cout<<g.toString();
  return os;
}
