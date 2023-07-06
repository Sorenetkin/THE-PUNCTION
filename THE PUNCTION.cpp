#include <string>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

bool CompareSourceToText();
bool ChangeSourceToCME();
bool ReplaceInSourceCode();

// WOOOO
// HOOOOO!!!!!!!!!!!


bool CompareSourceToText(){  //returns false if there is no correct comparison

}

bool ChangeSourceToCME(){
    
}

bool ReplaceInSourceCode (){    //should take in a reference to an array or vector that we can edit in the function

}

/* --------------------------------------*/
/* ----- SPLIT SENTENCE INTO WORDS ----- */
/* --------------------------------------*/

// determine the number of words in the sentence

// splits the sentence (a string) into a series of words (housed in a vector),
// counting the number of words along the way (numWords)
void SplitSentence(string sentence, vector <string> v) 
{
  int numWords = 0;

  for (int i = 0; i < sentence.size(); i++) {
    if (isspace(sentence[i])) {
      if (!isspace(sentence[i+1]))
        numWords++;
    }
    
  }

}

/* -------------------------------------*/
/* ----- GENERATE PRONOUNCIATIONS ----- */
/* -------------------------------------*/


//Takes a string and splits it on space, returning the
//before and after values through call by reference
void splitOnSpace(string s, string & before, string & after){
  // reset strings
  before = ""; 
  after = "";
  // accumulate before space
  int i = 0; 
  // skip the space
  while (i < s.size() && !isspace(s[i])){ 
    before += s[i]; 
    i++; 
  }
  i+=2;
  //accumulate after space
  while (i < s.size()){ 
    after += s[i]; 
    i++; 
  }
}

//Takes in a word w and returns word w in all caps
string toCapital(string w){
  for(int i = 0; i < w.size(); i++){
    w[i] = toupper(w[i]);
  }
  return w;
}

//Takes in a word w and returns its pronunciation if 
//it is in the dictionary
string pronounce(string w){
  ifstream file("cmudict.0.7a.txt"); //open dictionary
  string search, word, pronunciation; //dictonary search declarations
  
  //while reading dictionary, split the word from the pronunciation 
  while(getline(file, search)){
    splitOnSpace(search, word, pronunciation);
    //if the word is the same as the user word w, 
    //return pronunciation
    if(word == w){
      return pronunciation;
    }
  }
  file.close();
  return "Not found";//else return "NotFound"
}

string GetPronounciation(string w)
{
  w = toCapital(w);
  return pronounce(w);
}

int main(){ //define classes of puns and run the program
  
  string w;
  cin >> w;

  string result = GetPronounciation(w);
  cout << result;
}