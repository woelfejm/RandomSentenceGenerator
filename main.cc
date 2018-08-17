/*
John Woelfel
Spring 2018
4/17/2018
PA#5
Sources Used-
Special Instructions: Make sure the grammar file has a space between the end of a Sentence
and the semi colon.
Known Bugs- There is extra white space in the output
*/
#include "Grammar.cpp"
#include "RandomSentenceGenerator.cc"
#include <iostream>
#include "sstream"
using std::stringstream;
using namespace std;

int main(int argc, char *argv[]){
  if(argc < 2){
    cout<<"include grammar file as command line arguement";
    exit(1);
  }

  RandomSentenceGenerator* r = new RandomSentenceGenerator(argv[1]);
  r->printGrammar();
  cout<<endl;

  cout<<"***********************3 random sentences ********************"<<endl;
  cout<<r->randomSentence()<<endl;
  cout<<endl;
  cout<<r->randomSentence()<<endl;
  cout<<endl;
  cout<<r->randomSentence()<<endl;



  /*
  Testing stuff
  cout<<"Grammar Testing"<<endl;
  Grammar* g = new Grammar();


//testing for Grammar files
  //cout<<"\naddProduct test"<<endl;
  g->addProduction("Test", "taco tuesday");
  g->addProduction("Test", "pickup truck");
  g->addProduction("Test", "guitar center");
  g->addProduction("Test2", "No thanks");

  cout<<"\ncontainsNonTerminal Test"<<endl;
  cout<<g->containsNonTerminal("Test")<<endl;
  cout<<g->containsNonTerminal("Test234")<<endl;
  cout<<g->containsNonTerminal("Test2")<<endl;

  cout<<"\ngetRandomRHS test"<<endl;
  cout<<g->getRandomRHS("Test")<<endl;
  cout<<g->getRandomRHS("Test2")<<endl;
  cout<<g->getRandomRHS("Test2234")<<endl;


  //test << overload
  cout<<"\n"<<(*g) <<endl;

//testing for randomSentenceGenerator
  cout<<"************************************************************************************\n"<<endl;
  //RandomSentenceGenerator* r = new RandomSentenceGenerator("trump.g");
  RandomSentenceGenerator* r = new RandomSentenceGenerator("Dear-John-letter.g");

  r->printGrammar();

  cout<<"Random Sentence: "<<r->randomSentence()<<endl;
  */
}
