#include <iostream>
#include <string>
using namespace std;

void menu();
void question1();
void question2();
void question3();
void question4();
void question5();
void question6();
void question7();
int wordCounter(string sentence);
string sentenceCapitalizer(string line);
string nameArranger(string firstName, string middleName, string lastName);
int sumOfDigits(string numberSequence);
string replanceSubstring(string &sentence, string &selectedSubstring,  string &replacedSubstring) ;
bool numOfCharacters(string password);
bool uppercaseChar(string password);
bool lowercaseChar(string password);
bool digit(string password);
void passwordVerifier(string password);