#include <string>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

bool compareSourceToText();
bool changeSourceToCME();
bool replaceInSourceCode();

// split sentence into words:
void splitSentence(string sentence, vector <string>& v);
void vectorToPronunciation(vector <string>& v);

// generate pronounciations:
void splitOnSpace(string s, string & before, string & after);
string toCapital(string w);
string pronounce(string w);
string getPronunciation(string w);




// WOOOO
// HOOOOO!!!!!!!!!!!


bool compareSourceToText(){  //returns false if there is no correct comparison

}

bool changeSourceToCME(){
    
}

bool replaceInSourceCode (){    //should take in a reference to an array or vector that we can edit in the function

}

/* --------------------------------------------- */
/* ----- TURN SENTENCE INTO PRONOUNCIATION ----- */
/* --------------------------------------------- */

// splits the sentence (a string) into a series of words (housed in a vector). Each string of
// non-alphabet and non-space characters gets its own spot in the vector.
void splitSentence(string sentence, vector <string>& v){
  int numWords = 0;

  for (int i = 0; i < sentence.size(); i++){
    
    if (isspace(sentence[i])) {
      if (i > 0 && !isspace(sentence[i-1])){
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

// turns each word in the vector into its CMU Dictionary form
void vectorToPronunciation(vector <string>& v){
  for (int i = 0; i < v.size(); i++){
    if (isalpha(v[i][0]))
      v[i] =  getPronunciation(v[i]);
  }

}

// puts each syllable into its own area of a new vector
void splitPronunciation(vector <string>& vOrig, vector <string>& vSplit){
  int numSyls = 0;
  string temp = "";
  
  for (int i = 0; i < vOrig.size(); i++){
    for (int j = 0; j < vOrig[i].size(); j++){
      if (isspace(vOrig[i][j])) {
        numSyls++;
        vSplit.push_back("");
      }
      else{
        temp = vSplit[numSyls];
        temp += vOrig[i][j];
        vSplit[numSyls] = temp;
        temp = "";
      }
    }
    numSyls++;
    vSplit.push_back("");
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

string getPronunciation(string w){
  w = toCapital(w);
  return pronounce(w);
}

/* ---------------- */
/* ----- MAIN ----- */
/* ---------------- */

int main(){ //define classes of puns and run the program

  string sentence;
  // cin >> w;
  getline(cin, sentence);

  vector <string> v = {""};

  splitSentence(sentence, v);
  vectorToPronunciation(v);

  for (int i = 0; i < v.size(); i++)
    cout << v[i] << ";" << endl;
    
  cout << "---------------------" << endl;

  vector <string> vNew = {""};
  splitPronunciation(v, vNew);

  cout << vNew.size() << endl;

  for (int i = 0; i < vNew.size(); i++)
    cout << vNew[i] << endl;

}