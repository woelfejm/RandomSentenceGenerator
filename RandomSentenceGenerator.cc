/*John Woelfel
 *CS 343 Murphy Spring 2018
 *PA#5

*/
#include "RandomSentenceGenerator.h"
#include <iostream>
#include <algorithm> //remove semicolon
#include "fstream"
#include "sstream"
#include "algorithm"
#include <ctype.h>


using std::stringstream;
using namespace std;

RandomSentenceGenerator::RandomSentenceGenerator(string fname){
  ifstream inFile;
  inFile.open(fname);

  if (!inFile) {
       cout << "Unable to open file";
       exit(1); // terminate with error
   }

   string word;
   while (inFile >> word) {
       //start of a new terminal
       string nonTerm; //holds the nonTerm string value
       if(word[0] == '{'){
           inFile >> word; //read Nonterminal
           nonTerm = word;

           inFile >> word; //read Nonterminal
           stringstream ss;
           while(word[0] != '}'){ //checks to see if we are at end of line
             //read next line
             ss<<word<<" ";

             inFile>>word;

             //end of sentence
             if(word[0] == ';'){
               g.addProduction(nonTerm, ss.str());
               //clear stringstream
               ss.clear();
               ss.str(std::string());
               inFile>>word;
             }
           }
       }
   }
}

string RandomSentenceGenerator::randomSentence(){
  return randomSentence("<start>"); //call recursive method
}

string RandomSentenceGenerator::randomSentence(string nonTerm){
  string option = g.getRandomRHS(nonTerm);
  loop:
  if(option.find('<') == -1){
    return option;
  }
  else{
    //find first nonterminal from whole sentence
    int nonTermStart = option.find_first_of('<');
    int nonTermFin = option.find_first_of('>');
    string nextNonTerm = option.substr(nonTermStart, nonTermFin-nonTermStart + 1);

    //remove and replace nonToken with
    option.erase(nonTermStart, nonTermFin-nonTermStart + 1);
    option.insert(nonTermStart, randomSentence(nextNonTerm));

  }
  if(option.find('<') != -1){
    goto loop;
  }
  else {
    return option;
  }

}


void RandomSentenceGenerator::printGrammar() {
  cout<<"************************Grammar Rules*******************"<<endl;
  cout<<g<<endl;
}
