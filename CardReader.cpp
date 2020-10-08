#include <iostream>
using namespace std;

#include "PunchCard.h"

//this is a overload on >> operator for user to input on
//terminal as a PunchCard Object
//this has to be outside of the main.


int main (/*int argc, char * const argv[]*/)
{
   PunchCard myCard;
   // myCard.testAnswerCard();


   //this loop will keep outputing the card result as long
   //as the terminal input is not determined as the last card
   //by isLastCard function in PunchCard.cpp
   //while (!myCard.isLastCard()) {

      cin >> myCard;

      cout << myCard;

   //}

   // string A = "Hellow SeiKai";
   // cout << A[5];
   // string max [3];
   // getline(cin, max[0]);
   // cin >> max[1];
   // cin >> max[2];

   // for (int i = 0; i < 3; i++){
   //    for (int j = 0; j < max[i].size(); j++){
   //       cout << max[i][j];
   //    }
   //    cout << endl;
   // }
   

}
