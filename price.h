#ifndef PRICE_H
#define PRICE_H
#include <string>
using namespace std;



class Price
{


 private:
  int dollar;
  int cent;
  //  Price balance;
 public:
  Price();
  Price(int d, int c);
  bool operator>(const Price&);
  Price operator+(const Price&);
  Price operator-(const Price&);
  //friend Price operator-(const Price&, const Price& );
  //friend Price operator+( const Price&, const Price& );
  friend ostream& operator<<(ostream& , const Price& );
  int getDollar();
  int getCent();
  // friend ostream& operator=( const Price& );

};




#endif
