//  Jason Hughes
//    Due: 4.5.19
//    class rational to practice basics of defining and using classes.


#include <iostream>
using namespace std;

#ifndef _RATIONAL_
#define _RATIONAL_
/*
 * class rational
 *    represents a rational number. Remember rational means ratio-nal
 *    which means there is a numerator and denominator implemented using
 *    integer values. Using good ADT techniques, we have made member
 *    variable private (also known as instance variables) and made member
 *    functions public.
 */
class rational
{
public:
    rational (int p = 0, int q = 1);
    //constructor that takes two ints as parameter. Verify q is not zero

    //void input(istream& ins);
    // read value for the object from standard input 
    
    friend istream& operator>> (istream& ins, rational& r);

    void output(ostream& out) const;
    // display the value of the object to standard output 


    //Todo: declare an accessor (getter function) that returns the numerator
	int get_numerator() const;
    
    //Todo: declare an accessor (getter function) that returns the denominator
    int get_denominator() const;
    
	void Set(int n, int d);
	// Set the current object's value to the n/d.
	
    friend rational Sum(const rational& op1, const rational& op2);
    // set current object's value to be the sum of num1 and num2 

	friend rational Product(const rational& op1, const rational& op2);
	// set current object's value to be the product of num1 and num2.

    friend bool equal(const rational& op1, const rational& op2);
    // test if two rational numbers are equal.

    friend rational operator+(const rational& op1, const rational& op2);
    
    friend rational operator-(const rational& op1, const rational& op2);
    
    friend rational operator*(const rational& op1, const rational& op2);
    
    friend rational operator/(const rational& op1, const rational& op2);
    
    friend bool operator ==(const rational& op1, const rational& op2);

    friend bool operator >=(const rational& op1, const rational& op2);
    
    friend bool operator <=(const rational& op1, const rational& op2);
    
    friend bool operator !=(const rational& op1, const rational& op2);
    
    friend bool operator <(const rational& op1, const rational& op2);
    
    friend bool operator >(const rational& op1, const rational& op2);
    
    friend rational operator -(const rational& op1);
	//static int getObjectCounter();
	// Returns the count of objects created during program execution.
private:
    int numerator;
    int denominator;
	int greatestCmnDenom();
	void simplify();
	//static int objects;
}; 
#endif
