#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

int main(){
  //initialize Variables
  char header[100];
  char words[100];
  char encodedText[100];
  int currentLetter=0;
  int currentHeader=0;
  int headerLength=0;
  int wordLength=0;
  //open file
  ifstream inputFile("encode.dat");
  //check if file is open
    if (!inputFile.is_open()){
      cout << "no file";
    }else{
      //read in all necasary information
      inputFile >> header;
      //show the header
      cout <<  header << endl;

      while (!inputFile.eof()){
         
        inputFile >> words[currentLetter];

        if(90>=words[currentLetter] && words[currentLetter]>=65){
           
          currentLetter++;
         
        }
      }
    }
    //show the words
    cout << words << endl; 
    currentLetter=0;
    //strlen(header);
    //cout <<  strlen(header) << endl;
    //determine the length of both strings
    headerLength = strlen(header);
    wordLength = strlen(words);
    //encode the text
    for (currentLetter=0; currentLetter<=wordLength; currentLetter++){

      if(currentHeader<headerLength){

        if ((words[currentLetter]+(header[currentHeader]-'A'))>'Z'){
        
        words[currentLetter]=words[currentLetter]+(header[currentHeader]-('Z'+1));
        //cout << words[currentLetter] << endl;
        currentHeader++;

        } else {

        words[currentLetter]=words[currentLetter]+(header[currentHeader]-'A');
        //cout << words[currentLetter] << endl;
        currentHeader++;

        }
      } else {

        currentHeader=0;

        if ((words[currentLetter]+(header[currentHeader]-'A'))>'Z'){

        words[currentLetter]=words[currentLetter]+ (header[currentHeader]-('Z'+1));
        //cout << words[currentLetter] << endl;
        currentHeader++;

        } else {

        words[currentLetter]=words[currentLetter]+(header[currentHeader]-'A');
        //cout << words[currentLetter] << endl;
        currentHeader++;

        }
      }



    }
    //print the encoded text and close the file
    cout << words << endl;
    inputFile.close();




 



  return 0;
}