#include <string>
#include <iostream>
#include <fstream>
using namespace std;

bool CompareSourceToText();

// WOOOO
// HOOOOO!!!!!!!!!!!


bool CompareSourceToText(){  //returns false if there is no correct comparison

}

bool ChangeSourceToCME(){
    
}

bool ReplaceInSourceCode (){    //should take in a reference to an array or vector that we can edit in the function

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
  i++;
  //accumulate after space
  while (i < s.size()){ 
    after += s[i]; 
    i++; 
  }
}

//Takes in a word w and returns word w in all caps
string toCapital(string w){
  for(int i = 0; i < w.size(); i++){
    if((w[i] >= 'a') && (w[i] <= 'z')){
      w[i] = (char)((int)w[i] -32);
    }
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

int main(){ //define classes of puns and run the program
  string w;
  cin >> w; 
  w = toCapital(w);
  //Runs Pronounce
  cout << "Pronounce: " << pronounce(w) << endl;
  return 0;
}