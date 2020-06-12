/* 
 * labrational8.cpp:
 *    A driver program that tests the class rational. This file contains your main function.
 *    The program should have a big main do-while loop that does the following:
 *    	1. Give the user a list of operators and read in an operator. No numbers allowed.
 *    	2. Validate that the operator is OK then read in the number of rational operands. Use the operator>>
 *    	3. Apply the operator to the operands and print out the equation or relation with the result.
 *    	4. Loop while the user says Continue?(y or n)
 */

#include <iostream>
#include <cctype>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <string>
#include "Rational8.cpp"

using namespace std;

void outs(string op, rational p, rational q, rational ans);
void outv(string op, rational p, rational q, bool val);
//main program 
int main ()
{
    
    string op;
    bool val;
    rational p;
    rational q;
    rational ans;
    
    
	cout << "Welcome to Rational World!" <<endl;
	cout << endl;

	// Extra credit: in rational class operator>>
	// [5 pts] In the input operator>>, allow the user to enter the value as follows:
	// 	0.45 - You should figure out the numerator is 45, denominator is 100. 
	// 	0.3  - You should figure out the numerator is then 3, denominator is 10.
	//  2.4  - You should figure out the numerator is 24, denominator is 10.
	
    char rerun;

	do{
		// ToDo: Declare necessary local variables
        
		// ToDo: Print "Enter operator ( +,-,*,/,==,>=,<=,!=,<,>,-1 for negation}: "
		// read in operator string.
		cout << "Enter operator (+,-,*,/,==,>=,<=,!=,<,>,-1 for negation): ";
        cin >> op;
		// ToDo: Get operands as rationals using the operator>> 
        

		// ToDo: Big multiway-if or switch statement with every operator to evaluate
		// and print the answer using operator<< ex. (n1/d1)+(n2/d2)=n2/d3
		if (op == "+")
		{
		    cout << "Enter the two operands (ex. 1/2 or -3/4): ";
		    cin >> p >> q;
		    //p.input(cin);
		    //q.input(cin);
		    ans = p + q;
		    outs(op,p,q,ans);
		}
		else if (op == "-")
		{
		    cout << "Enter the two operands (ex. 1/2 or -3/4): ";
		    cin >> p >> q;
		    //p.input(cin);
		    //q.input(cin);
		    ans = p - q;
		    outs(op,p,q,ans);
		}
		else if (op == "*")
		{
		    cout << "Enter the two operands (ex. 1/2 or -3/4): ";
		    cin >> p >> q;
		    //p.input(cin);
		    //q.input(cin);
		    ans = p * q;
		    outs(op,p,q,ans);
		    
		}
		else if (op == "/")
		{
		    cout << "Enter the two operands (ex. 1/2 or -3/4): ";
		    cin >> p >> q;
		    //p.input(cin);
		    //q.input(cin);
		    ans = p / q;
		    outs(op,p,q,ans);
		}
		else if (op == "==")
		{
		    cout << "Enter the two operands (ex. 1/2 or -3/4): ";
		    cin >> p >> q;
		    //p.input(cin);
		    //q.input(cin);
		    val = p == q;
		    outv(op,p,q,val);
		}
		else if (op == ">=")
		{
		    cout << "Enter the two operands (ex. 1/2 or -3/4): ";
		    cin >> p >> q;
		    //p.input(cin);
		    //q.input(cin);
		    val = p >= q;
		    outv(op,p,q,val);
		}
		else if (op == "<=")
		{
		    cout << "Enter the two operands (ex. 1/2 or -3/4): ";
		    cin >> p >> q;
		    //p.input(cin);
		    //q.input(cin);
            val = p <= q;
		    outv(op,p,q,val);
		}
		else if (op == "!=")
		{
		    cout << "Enter the two operands (ex. 1/2 or -3/4): ";
		    cin >> p >> q;
		    //p.input(cin);
		    //q.input(cin);
		    val = p != q;
		    outv(op,p,q,val);
		}
		else if (op == ">")
		{
		    cout << "Enter the two operands (ex. 1/2 or -3/4): ";
		    cin >> p >> q;
		    //p.input(cin);
		    //q.input(cin);
		    val = p > q;
		    outv(op,p,q,val);
		    
		}
		else if (op == "<")
		{
		    cout << "Enter the two operands (ex. 1/2 or -3/4): ";
		    cin >> p >> q;
		    //p.input(cin);
		    //q.input(cin);
		    val = p < q;
		    outv(op,p,q,val);
		}
        else if (op == "-1")
        {
            cout << "Enter the operand (ex. 1/2 or -3/4): ";
		    cin >> p;
		    //p.input(cin);
		    ans = -p;
		    cout <<"-(";
		    p.output(cout);
		    cout <<")=";
		    ans.output(cout);
        }
        else
        {
            cout << "Invalid operator!";
        }
		// Use this in case the operator>> fails.
		if (cin.fail()) {
			cin.clear();
			cin.ignore();
		}

		// ToDo: Prompt the user to rerun the simulation 
		cout << "\nContinue(y/n): \n";
		cin >> rerun; 

	} while (rerun == 'y'|| rerun == 'Y'); 

	cout << "Have a nice day!" <<endl;

	return 0;
}

void outs (string op, rational p, rational q, rational ans)
{
    cout<<"("; p.output(cout); cout<<")";
    cout << op;
    cout<<"("; q.output(cout); cout <<")";
    cout<<"=";
    ans.output(cout); 
}

void outv (string op, rational p, rational q, bool val)
{
    cout<<"("; p.output(cout); cout<<")";
    cout << op;
    cout<<"("; q.output(cout); cout <<")";
    cout<<"=";
    if (val == true)
		        cout << "True";
		    else
		        cout << "False";
    
}

