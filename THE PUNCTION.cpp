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

// splits the sentence (a string) into a series of words (housed in a vector). Each string of
// non-alphabet and non-space characters gets its own spot in the vector.
void splitSentence(string sentence, vector <string>& v) 
{
  int numWords = 0;

  for (int i = 0; i < sentence.size(); i++) {
    
    if (isspace(sentence[i])) {
      if (i > 0 && !isspace(sentence[i-1])) {
        numWords++;
        v.push_back(""); // Is this the most efficient way to do this?
        } 
    }
    else if (!isalpha(sentence[i])) {
      if (i > 0 && isalpha(sentence[i - 1])){
        numWords++;
        v.push_back("");
      }
      v[numWords] += sentence[i];
    }
    else {
      if (i > 0 && !isalpha(sentence[i - 1]) && !isspace(sentence[i - 1])){
        numWords++;
        v.push_back("");
      }
      v[numWords] += sentence[i];// adds to the end of the vector
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

string getPronounciation(string w)
{
  w = toCapital(w);
  return pronounce(w);
}

int main(){ //define classes of puns and run the program
  
  string w;
  // cin >> w;
  getline(cin, w);
  vector <string> v = {""};

  splitSentence(w, v);
  // string result = getPronounciation(w);
  // cout << result;

cout << v.size() << endl;
  for (int i = 0; i < v.size(); i++)
    cout << v[i] << endl;



}