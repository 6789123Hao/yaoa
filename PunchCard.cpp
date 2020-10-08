#include "PunchCard.h"


const int lines = 6;
const int letters = 4;
const int asRow = 4;
const int asEle = 10;
//Set up the values in answerCard for output
string answerCard [asRow][asEle]  = {
   {" ", "1", "2", "3", "4", "5", "6", "7", "8", "9"},
   {"&", "A", "B", "C", "D", "E", "F", "G", "H", "I"},
   {"-", "J", "K", "L", "M", "N", "O", "P", "Q", "R"},
   {"0", "/", "S", "T", "U", "V", "W", "X", "Y", "Z"}
};
bool isLast = false;
//temp to store the card info.

string matrix[lines];

//default construtor
//build a matrix with 12 lines of 80 char in each lines.
//I want to load every line of text into the matrix first as char
PunchCard::PunchCard()
{
   cout << "Please Load Your Card by" << lines << "lines (" << letters <<" characters per lines)" << endl;

}


//test print to see the EBCD code
void PunchCard::testAnswerCard()
{
   cout << "Here is the EBCD Code:" << endl;
   for(int i = 0; i < asRow; i++){
      for(int j = 0; j < asEle; j++){
         cout << answerCard[i][j] << " ";
      }
      cout << endl;
   }
}

//display inserts helper
void PunchCard::displayInsertCard()
{
   cout << "Here is the insert card:" << endl;
   for(int i = 0; i < lines; i++){
      for(int j = 0; j < matrix[i].size(); j++){
         cout << matrix[i][j] << " ";
      }
      cout << endl;
   }
}

//if the input on the first column is all "X"s,
//return true for last card, else false
void PunchCard::findLastCard()
{
   cout << "Last Card Found" << endl;
   isLast = true;
   isLastCard();
}

// boolean check for while loop in main
bool PunchCard::isLastCard()
{
   return isLast;
}

//card size getter
void PunchCard::getCardSize()
{
   cout << "Current Card Size: " << lines << " lines by " << letters << " letters." << endl;
}

//helper function to see if the first lane char is through out the column or not
//helps on defining "space" and LastCard.
bool sameCharColumn (int times, char letter, int col)
{
         // cout << "SAMECLO" << endl;
   for (int i = 0; i < times; i++){
      if (matrix[i][col] != letter){
         return false;
      }
   }
   return true;
}

//helper function to find and return the line number of the section X in the same column
//set column, it will return the line number which is still 3 units larger than
//the answer card element size anEle.
int findSecondXLine (int col)
{
   // cout << "enter FINDSEC" << endl;      
   for(int j = 3; j < lines; j++) {
      if (matrix[j][col] == 'X') {
         // cout << "FINDSEC" << endl;
         return j;
      }
   } 
   return -1;
}

/*
Print toString corsponding to the AnswerCard.

check every column
   if the first line(lane Y) first to be ' '
      if sameCharColum
         add " " to toReturn  
   else if the first line(lane Y) first to be X
      if sameCharColum
         it's LastCard
      else
         if there is X in line 3-11
            add letter to toReturn
         else
            add "&"
      
   else if the second line(lane X) first to be X
      if sameCharColum  
         it's LastCard
      else
         if there is X in line 3-11
            add letter to toReturn
         else
            add "-"
   else if the third line(lane 0) is first to be X
      add "0"
   else
      for each line in the column
         if X
            add number

*/
//print out all the letters corsponding to the AnswerCard

//ERROR  seems like it's not entering the if conditions
// string PunchCard::toString () const
// {
   // cout << "Here is the Your Card:" << endl;
   // string toReturn = "HAHA"; //return string for output
   // for (int i = 0; i < letters; i++){
   //    if (matrix[0][i] = ' '){
   //       if(sameCharColumn(lines, ' ', i)){
   //          toReturn += " ";
   //       }
   //    } else if (matrix[0][i] = 'X'){
   //       if(sameCharColumn(lines, 'X', i)){
            
   //       } else {
   //          cout << "Here is X at 0 and " << i << endl;//checking output
   //          toReturn += answerCard[1][findSecondXLine(i)-3];
   //       }
   //    } else if (matrix[1][i] = 'X'){
   //          toReturn += answerCard[2][findSecondXLine(i)-3];
   //    } else if (matrix[2][i] = 'X'){
   //       toReturn += "0";

   //    } else {
   //       toReturn += answerCard[0][findSecondXLine(i)-3];
   //    }
   // }
   // return toReturn;
// }



//get input to char matrix and store
istream& operator >> (istream& input, PunchCard card){
   for (int i = 0; i < lines; i++){
      StartAgain:
      cout << "Line " << i+1 << ":";
      string tempLine = "";
      getline(cin, tempLine);
      if(tempLine.size() > letters){
         cout << "Try again, Maxium letter allowed is " << letters << endl;
         goto StartAgain;
      }
      
      matrix[i] = tempLine;

   }



   // for (int i = 0; i < lines; i++){
   //    cout << "Line " << i+1 << ":";
   //    //get line input as strings
   //    getline(cin, inputs); 
   //    //convert strings into chars in 2d matrix
   //    strcpy(card.matrix[i], inputs.c_str());
   // }     
   card.displayInsertCard();
   return input;
}

//TODO  CHECK CONST*************************************************************************************
ostream& operator << (ostream& output, const PunchCard& card){
   // string toReturn = "HAHA"; //return string for output
   for (int i = 0; i < letters; i++){
      if (matrix[0][i] == ' '){
         if(sameCharColumn(lines, ' ', i)){
            output << " ";
         }
      } else if (matrix[0][i] == 'X'){
         if(sameCharColumn(lines, 'X', i)){
            isLast = true;
         } else {
            cout << "Here is X at 0 and " << i << endl;//checking output
            output << answerCard[1][findSecondXLine(i)-3];
         }
      } else if (matrix[1][i] == 'X'){
            output << answerCard[2][findSecondXLine(i)-3];
      } else if (matrix[2][i] == 'X'){
         output << "0";

      } else {
         output << answerCard[0][findSecondXLine(i)-3];
      }
   }
      // cout << "CHECK OUT" << endl;
   return output;
}

