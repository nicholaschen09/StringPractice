#include <iostream>
#include <string>
using namespace std;


// FUNCTIONS //
//---------------------------
    //  QUESTION 1 
//---------------------------

int wordCounter(string sentence) {
  
  int words = 0;
  int count = 0;
  for (int i = 0; i < sentence.size(); i++) {
    char letter = sentence[i];
    if(isspace(letter)){ //checks for spaces
      count++;
    }
  }
  words = count + 1; //add one to count words instead of spaces
  return words;
}

//---------------------------
    //  QUESTION 2 
//---------------------------


string sentenceCapitalizer(string line) {
  
 for (int i = 0; i < line.size(); i++) { 
   //turns the first letter to uppercase
   line[0] = toupper(line[0]); 
    if (line[i] == '.' || line[i] == '?' || line[i] == '!') { //checks for punctuation marks in the sentence
      line[i+2] = toupper(line[i+2]); //converts 2 plus the index at which it has a punctuation mark to uppercase
      }
   }
  return line;
}



      
    //---------------------------
    //  QUESTION 3 
//---------------------------
    
    
string nameArranger(string firstName, string middleName, string lastName) {
  
    string fullName;

   firstName[0] = toupper(firstName[0]); 
   middleName[0] = toupper(middleName[0]);
   lastName[0] = tolower(lastName[0]); 
  fullName = lastName + ", " + firstName + " " + middleName;
  return fullName;

  
}


    //---------------------------
    //  QUESTION 4 
//---------------------------

  int sumOfDigits(string numberSequence) {
    int totalSum=0;
  int num = stoi(numberSequence);

  //adding the digits in a number
  while(num !=0)
  {
    totalSum = totalSum + (num % 10);
    num = num/10;
  }//end while
  return totalSum + 1;
    
}//.. end nameArranger


//---------------------------
    //  QUESTION 5
//---------------------------

string replaceSubstring(string str1, string str2, string str3)
{
  //spaces to verify between words that have similar spelling such as "the" and "they"
  str1 = str1+" ";
  str2 = str2+" ";
  str3 = str3+" "; 
  int length = str2.size();
  int pos=0;
  
  //finding the word to replace and replacing with another word
  
  
  do
    {
      pos = str1.find(str2, pos);
      if(pos != -1) 
      {
        str1.replace(pos,length,str3);
        pos += length;
      }//..end if
    }while(pos != -1);//..end do-while

  return str1;
}//.. end replaceSubstring

//function to see if the password is long enough
bool numOfChar(string password)
{
  //returning true if the password is longer than 5 characters
  if(password.length()>5)
    return true;
  else 
    return false;
}//..end numOfChar

//function to see if the password has at least one uppercase letter
bool uppercaseChar(string password)
{
  bool upper = false;
  for(int i =0;i<password.size();i++)
    {
      //returning true if it has an uppercase letter
      if(isupper(password[i]))
       {
        upper= true;
        break;
       }//..end if 
    }//.. end for loop
  return upper;
}//.. end uppercaseChar

//function to see if the passwords has at least one lowercase letter
bool lowercaseChar(string password)
{  
  bool lower = false;
  for(int i =0;i<password.size();i++)
    {
      //returning true if it has an lowercase letter
      if(islower(password[i]))
        {
          lower= true;
          break;
        }//..end if
    }//..end for loop
  return lower;
}//..end lowercaseChar

//function to see if the password has at least one digit
bool digit(string password)
{
  bool digit = false;
  for(int i=0;i<password.size();i++)
    {
      //returning true if it has a digit
      if(isdigit(password[i]))
      {
        digit = true;
        break;
      }//..end if
    }//..end for loop
  return digit;
}//..end digit

//function to see if the password has at least one special charcter
bool specialCharacter(string password)
{
  bool special = false;
  for(int i =0;i<password.size();i++)
    {
       //returning true if it has a special character
      if(!isalnum(password[i]))
      {
        special=true;
        break;
      }
      }
  return special;
}



// QUESTIONS //

void question1() {
 string sentence;
      cout << "Enter a sentence of words: ";
         cin.ignore();
      getline(cin, sentence);
      cout << wordCounter(sentence) << endl;

  }

void question2() {
  
  string line;
      cout << "Enter a sentence of words: ";
      getline(cin, line);
      cout << sentenceCapitalizer(line) << endl;

  }

void question3() {
  
  string firstName, middleName, lastName;
      cout << "Enter your first name: ";
        cin >> firstName;
      cout << "Enter your middle name: ";
        cin >> middleName;
      cout << "Enter your last name: ";
        cin >> lastName;
   
       cout << nameArranger(firstName, middleName, lastName) <<  endl;
  }

 void question4() {

   string numberSequence;
cout << "enter a series of numbers: ";
         cin.ignore();
getline(cin, numberSequence);
  cout << sumOfDigits(numberSequence) << endl;
   }

void question5()
{
  string sentence, wordReplace , wordReplaceWith;
  
  //user input
  cout<<"Enter a line: ";
  getline(cin, sentence);
  cout<<"Enter a word you want replaced: ";
  cin>>wordReplace;
  cout<<"Enter a word to replace that selected word: ";
  cin>>wordReplaceWith;
  cout<<replaceSubstring(sentence,wordReplace,wordReplaceWith) << endl;
  
  }

void question6()
{
  string password; 
  cout << "Enter a password: ";
  cin >> password; 

  bool caseLower = lowercaseChar(password);
  bool caseUpper = uppercaseChar(password); 
  bool hasDigits = digit(password);
  bool numOfCharacters = numOfChar(password); 
  bool characterSpecial = specialCharacter(password);

  //Determines if the password is valid or invalid, and if invalid, tells the user what is wrong and lets them reenter the password 
  while(!caseLower || !caseUpper || !hasDigits || !numOfCharacters|| !characterSpecial){

    //Tells user there is no lowercase letter
    if(!caseLower){
      while(!caseLower){
    cout << "Program does not have at least one lower case, try again: ";
    cin >> password; 
    caseLower = lowercaseChar(password);
    caseUpper = uppercaseChar(password); 
    hasDigits = digit(password);
    numOfCharacters = numOfChar(password);
    characterSpecial = specialCharacter(password); 
        }
      }

    //Tells user there is no uppercase letter
    if(!caseUpper){
      while(!caseUpper){
        cout << "Password does not have at least one upper case, try again: ";
        cin >> password; 
        caseLower = lowercaseChar(password);
        caseUpper = uppercaseChar(password); 
        hasDigits = digit(password);
        numOfCharacters = numOfChar(password);
        characterSpecial = specialCharacter(password);
        }
      }

    //Tells user there is no digit
    if(!hasDigits){
      while(!hasDigits){
        cout << "Password does not have at least one digit, enter another password: ";
        cin >> password; 
        caseLower = lowercaseChar(password);
        caseUpper = uppercaseChar(password); 
        hasDigits = digit(password);
        numOfCharacters = numOfChar(password);
        characterSpecial = specialCharacter(password);
      }//..end while loop 
    }//..end if statement

    //Tells user the password is shorter than 6 characters
    if(!numOfCharacters){
      while(!numOfCharacters){
        cout << 
      "Password needs to have at least six characters, enter another password: ";
        cin >> password; 
        caseLower = lowercaseChar(password);
        caseUpper = uppercaseChar(password); 
        hasDigits = digit(password);
        numOfCharacters = numOfChar(password);
        characterSpecial = specialCharacter(password);    
      }//..end while loop 
    }//..end if statement 

    //Tells user there are no special characters
    if(!characterSpecial){
      while(!characterSpecial){
        cout << 
        "Password doesn't have a special character, enter another password: ";
        cin >> password; 
        caseLower = lowercaseChar(password);
        caseUpper = uppercaseChar(password); 
        hasDigits = digit(password);
        numOfCharacters = numOfChar(password);
        characterSpecial = specialCharacter(password);
      }//..end while loop 
    }//..end if statement
}//..end while loop 
  cout << "Valid Password" << endl << endl;
  
}//..end question6 function 


  void question7() {    
      cout << "quit" << endl;
    }
      
// MENU //

void menu()
{
  int choice;
  do {
  cout << "1. Word Counter" << endl;
  cout << "2. Sentence Capitalizer" << endl;
  cout << "3. Name Arranger" << endl;
  cout << "4. Sum of Digits in a String"<< endl;
  cout << "5. replaceSubstring Function"<< endl;
  cout << "6. Password Verifier" << endl;
  cout << "7. Quit" << endl;
  cout << "Enter a number: ";

  cin >> choice;
  cin.ignore();
  switch(choice)
    {
      case 1:question1();break;
      case 2:question2();break;
      case 3:question3();break;
      case 4:question4();break;
      case 5:question5();break;
      case 6:question6();break;
      case 7:question7();break;
    }
  } while (choice!=7);

}//..end menu