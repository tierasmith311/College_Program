
#include "price.h"
//#include "array.h"
#include <iostream>
using namespace std;
//this is implementation file, bodies of memeber function

//non default const
Price::Price()
{
  dollar = 0; //initialize to default value, 0
  cent = 0; //intialize to default value, 0
  //  balance = 0;
}

//construct
Price::Price(int d, int c)
{
  dollar = d;
  cent = c;

}
bool Price:: operator>(const Price& p)
{

  if(this->dollar > p.dollar || this->dollar == p.dollar && this->cent > p.cent)
    {
      return true;
    }else{
    return false;
  }

}
//function adding. dont use float or double for currency
/*
 Price operator+( const Price& operand1, const Price& operand2)
{
  Price total1;
  total1.dollar = operand1.dollar + operand2.dollar;
  total1.cent = operand1.cent + operand2.cent;
  
    if (total1.cent >= 100){
        total1.dollar = total1.dollar + (total1.cent / 100); //this adds the amount of dollars over 100 cents($1)
        total1.cent = total1.cent % 100; // this gives the remainder of cents that arent equal to a dollar
    }
    
    return total1;

    }*/
//Price total1 = p1 + p2;
//funct add operator using this->
Price Price::operator+(const Price& p)
{
  //Price total;
  int dollar =  p.dollar + this->dollar ; //this pointer
  int cent = p.cent + this->cent;
    
  if (cent >= 100){
    dollar = dollar + (cent / 100); //adds the appropiate amount of dollars over 100 cents
    cent = cent % 100; //remainder out of 100
  }
  Price sum(dollar, cent);
    
  return sum;
}
/*
 Price operator-(const Price& operand1, const Price& operand2)
{
    Price difference;
    difference.dollar = operand1.dollar + operand2.dollar;
    difference.cent = operand1.cent + operand2.cent;
}
*/
Price Price::operator-(const Price& p)
{
  //Price total;
  int dollar = this->dollar -  p.dollar;
  int cent = this->cent - p.cent;
  //for diff 2 implement "borrowing"
  if(cent < 0)
    {
      cent = 100 + cent;
      dollar--;


    }  
  Price difference(dollar, cent); // creating new object
    
  return difference; //return new object
  }
//cout << "$" << p1 << "-$" << p3 << "=$" << diff2 << endl;
ostream& operator<<(ostream& out, const Price& p1)
{
  out << p1.dollar << ".";
  if (p1.cent < 10){
    out << "0";
  }
  out  << p1.cent << endl;
    
  return out;
}

int Price::getCent()
{
    
  return this->cent;
}

int Price::getDollar()
{
    
  return this->dollar;
}

