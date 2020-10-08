//#ifndef _PUNCHCARD_H_
//#define _PUNCHCARD_H_
#pragma once
#include <iostream>
using namespace std;
#include <string>
#include <cstring>
#include <vector>

class PunchCard
{
public:
   //constructor
   PunchCard();
   
   //functions needed in main
   bool isLastCard();
   //display AnswerCard
   void testAnswerCard();
   //display Inserted input
   void displayInsertCard();
   //to see the input card size.
   void getCardSize();
   //to print out the result after decoding.
   string toString() const;
   bool isLast;
   
   void findLastCard();
   friend istream& operator >> (istream& input, PunchCard card);

   friend ostream& operator << (ostream& output, const PunchCard& card);

private:

};

//#endif