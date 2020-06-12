/*  Jason Hughes
    Due: 4.6.19
    Rational.cpp class functions 
    class Rational to practice basics of defining and using classes.
 */
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <cctype>
#include <string>
#include "rational8.h"

using namespace std;

//int rational::objects = 0;

//Function Definitions 

/* Constructor function that is given the numerator and denominator either entered or created from the for loop. The function ensures the denominator is not zero aand throws and error if it is. It also keeps track of the number of objects created. If a denom is zero we dont want to create an object.*/
rational::rational(int n, int d) : numerator(n), denominator(d)
{
	if (denominator == 0) {
		cout << "Error: divide by zero." << endl;
		exit(1);
	}
	//objects++;
}

// This function simply returns the number of objects created
//int rational::getObjectCounter()
//{
//	return rational::objects;
//}

/* This function sets the numerator and denomintor equal to n and d which is either entered by the user or created in the for loop. And we ensure the denomintor is not zero again. */
void rational::Set(int n, int d) 
{
	if (d != 0) {
		numerator = n;
		denominator = d;
	}
	else
		cout << "Error: divide by zero." << endl;
}

/* This function sums the rational numbers by using the equation (a*d + b*c) / (b*d) this then returns the sum (s) which of type rational. */
rational Sum(const rational& op1, const rational& op2)
{
	rational s;
	
	s.numerator = (op1.numerator * op2.denominator) + (op1.denominator * op2.numerator);
	s.denominator = op1.denominator * op2.denominator;
	s.simplify();
	return s;
}

/* This function multiplies both the rational numbers together by multiplying the twwo numerators to get the product numerator and the two denominators to get the product denominnator. It is then returned as p of type rational. */
rational Product(const rational& op1, const rational& op2)
{
	rational p;
	p.numerator = op1.numerator * op2.numerator;
	p.denominator = op1.denominator * op2.denominator;
	p.simplify();
	return p;
}

/* This functon check equality of the two rational numbers entered by the user. We check this by cross multiplying. If the two products of the multiplication of the equal are equal then the rationals are equal, this way we avoid simplifying factions. We then return the validity of that arguement */ 
bool equal(const rational& op1, const rational& op2)
{
	return op1.numerator*op2.denominator == op2.numerator*op1.denominator;
}

/* THis function gathers the users input and has the user reenter if they enter bad data. this then sets the first number equal to the numerator and the latter equal to denominator. */
/*void rational::input(istream& in)
{
   char slash;
   int top, bottom;
   bool valid = true;

   // keep reading until valid input is entered
   do 
   {
     in >> top >> slash >> bottom;
     if (slash!='/' || bottom==0)
     {
		cout << "Error: bad rational" << endl;
        valid = false;
     }
    else
    	valid = true;
   } while (valid == false);

   // set the invoking object's numerator, denominator
   numerator = top;
   denominator = bottom;
}*/



// Input (extraction) operator for rational class
// This code uses conditional statement:
//    (bool-expression) ? expr_when_true : expr_when_false ;
istream& operator>> (istream& ins, rational& r)
{
	string s;
	bool isSlash = false, isNegative = false;
	bool isWhole = false;

	// Read a string (can read char by char, but less efficient).
	ins >> s;

	bool isValid = true;
	// Look at every character to see if it is valid
	for (int i = 0; i < s.length() && isValid; i++) 
	{
    	if (s[i] == '-')
		{ 
			// Must be at the beginning only
			isValid = ( i == 0) ? true : false;
			isNegative = (isValid) ? true : false;
		}
		else if (s[i] == '/')
		{
			// Must not be at the beginning or end or duplicated.
			isValid = (i == 0 || i == s.length()-1 || (i == 1 && isNegative ) || isSlash) ? false : true;
			isSlash = true;
		}
		else if (!isdigit(s[i])) {
			// Only valid characters are '-', '/'
			// and digits.
			isValid = false;
		}
	}

	// Set the failbit when not valid.
	if (isValid != true) {
		ins.setstate(ios::failbit);
		cerr << "Invalid rational format!" << endl;
		return ins;
	}

	// Smarter to use temporary variables because there can still be
	// an error with the denominator. We don't want to change the
	// rational if the read was unsucessful.
	int n, d;
	char c;
	istringstream str(s);
	if (isSlash) {
		str >> n >> c >> d;
	}
	else {
		str >> n;
		d = 1;
	}
	if (d == 0) {
		ins.setstate(ios::failbit);
		cerr << "Invalid rational" << endl;
		return ins;
	}
	r.Set(n, d);
	return ins;
}




/* This functon outputs the numbers generated as rationals (p/q)  */
void rational::output(ostream& out) const
{
	out << numerator << "/" << denominator;
}

//Thif function gets the numerato from the input
int rational::get_numerator() const 
{
	return numerator;
}

//This function gets denomintor from input
int rational::get_denominator() const
{
	return denominator;
}

//This function simplifies the rationals by using the GCD calculated 
void rational::simplify()
{
	int gcd = greatestCmnDenom();
	if (gcd > 1)
	{
		numerator = numerator / gcd;
		denominator = denominator / gcd;
	}
}

rational operator + (const rational& op1, const rational& op2)
{
    rational s;
 
    s.numerator = (op1.numerator * op2.denominator) + (op1.denominator * op2.numerator);
	s.denominator = op1.denominator * op2.denominator;
	s.simplify();
	return s;   
}

rational operator - (const rational& op1, const rational& op2)
{
    rational s;
    
    s.numerator = (op1.numerator * op2.denominator) - (op1.denominator * op2.numerator);
    s.denominator = op1.denominator * op2.denominator;
    s.simplify();
    return s;
    
}

rational operator * (const rational& op1, const rational& op2)
{
    rational s;
    
    s.numerator = op1.numerator * op2.numerator;
    s.denominator = op1.denominator * op2.denominator;
    s.simplify();
    
    return s;
    
}

rational operator / (const rational& op1, const rational& op2)
{
    rational s;
    
    s.numerator = op1.numerator * op2.denominator;
    s.denominator = op1.denominator * op2.numerator;
    s.simplify();
    
    return s;
}

bool operator == (const rational& op1, const rational& op2)
{
    int u, v;
    
    u = op1.numerator * op2.denominator;
    v = op1.denominator * op2.numerator;
    
    if (u == v)
        return true;
    else
        return false;
    
}

bool operator >= (const rational& op1, const rational& op2)
{
    double u, v;
    
    u = double(op1.numerator) / double(op1.denominator);
    v = double(op2.numerator) / double(op2.denominator);
    
    if (u>=v)
        return true;
    else
        return false;
        
}

bool operator <= (const rational& op1, const rational& op2)
{
    double u, v;
    
    u = double(op1.numerator) / double(op1.denominator);
    v = double(op2.numerator) / double(op2.denominator);
    
    if (u<=v)
        return true;
    else
        return false;        
}

bool operator != (const rational& op1, const rational& op2)
{
    int u, v;
    
    u = op1.numerator * op2.denominator;
    v = op1.denominator * op2.numerator;
    
    if (u != v)
        return true;
    else
        return false;
}

bool operator > (const rational& op1, const rational& op2)
{
    double u, v;
    
    u = double(op1.numerator) / double(op1.denominator);
    v = double(op2.numerator) / double(op2.denominator);
    
    if (u>v)
        return true;
    else
        return false;
        
}

bool operator < (const rational& op1, const rational& op2)
{
    double u, v;
    
    u = double(op1.numerator) / double(op1.denominator);
    v = double(op2.numerator) / double(op2.denominator);
    
    if (u<v)
        return true;
    else
        return false;
        
}

rational operator -(const rational& op1)
{
    rational s;
    s.numerator = -1 * op1.numerator;
    s.denominator = op1.denominator;
    
    return s;
}



//This function takes the numerator and numerator and claculated the GCD with the equation given in Lab 
int rational::greatestCmnDenom()
{
	int n = numerator, d = denominator;
	while (n!=0 && d!=0)
   	{
      n = n % d;
      if (n!=0)
         d = d % n;
   	}
   	if (n==0)
      return d;
   	if (d==0)
      return n; 
    return 1;
}

