// Bill Wang & Jimmy Huang
// 20778745 & 20778541

#include <cstdlib>
#include <sys/types.h> //gets the sleep function
#include <cmath>
#include "Polynomial.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

class PolynomialTest
{
	public:
	void equalsTest(Polynomial&test)
	{
		cout<<"running equality test"<<endl;
		Polynomial test2 = test;
		//testing equality with the same polynomial (made with copy constructor)
		if(test2 == test)
		{
			cout<<"equality test passed with same polynomials"<<endl;
		}
		else
		{
			cout<<"equality test failed with same polynomials"<<endl;
		}

		int seqA[4] = {0,1,2,3};
		int seqB[4] = {3,2,1,0};
		int seqC[3] = {0,3,2};
		Polynomial test3(seqA,4);
		Polynomial test4(seqB,4);
		Polynomial test5(seqC,3);

		//testing different polynomials of the same order
		if(test3 == test4)
		{
			cout<<"equality test failed with diff poly of same order"<<endl;
		}
		else
		{
			cout<<"equality test passed with diff poly of same order"<<endl;
		}
		//testing different polynomials of different orders
		if(test3 == test5)
		{
			cout<<"equality test failed with diff poly of diff order"<<endl;
		}
		else
		{
			cout<<"equality test passed with diff poly of diff order"<<endl;
		}
	}

	void printTest()
	{
		cout<<"running print test"<<endl;
		int A[] = {1,2,3,4,5,6,7,8};
		Polynomial printee1(A,8);
		int B[] = {1,0,3};
		Polynomial printee2(B,3);
		int C[] = {1,0,0,5};
		Polynomial printee3(C,3);
		cout<<"expecting 8x^7+7x^6+6x^5+5x^4+4x^3+3x^2+2x+1"<<endl;
		printee1.print();
        cout<<"expecting 3x^2+1"<<endl;
        printee2.print();
        cout<<"expecting 5x^3+1"<<endl;
	}

	void parametricConstructorTest()
	{
		cout<<"running parametricConstruct test"<<endl;
		int A[] = {6,1,6,2,6,6,7,8,3};
		Polynomial poly1(A,9);
		bool worked = true;
		for(int index = 0; index<9 && worked; index++)
		{
			if(A[index] != poly1.data[index])
			{
				worked = false;
			}
		}
		if(!worked)
		{
			cout<<"parametric constructor failed"<<endl;
		}
		else
		{
			cout<<"parametric constructor passed"<<endl;
		}
	}

	void emptyConstructorTest()
	{
		cout<<"running emptyConstruct test"<<endl;
		Polynomial poly1;
		poly1.print();
	}

	void fileConstructorTest(ifstream & file)
	{
		cout<<"running fileConstruct test"<<endl;
		Polynomial test1(file);
		cout<<"expected 5x^3+5x^2+7x+8"<<endl;
		test1.print();
	}

	void addTest()
	{
		cout<<"running addition test"<<endl;
		int a[] = {2, -1};
		Polynomial poly1(a, 2);
		int b[] = {1, 4, 2, -3};
		Polynomial poly2(b, 4);
		int c[] = {0,0,0,0};
		Polynomial poly3(c, 4);
		Polynomial result1 = poly1 + poly2;
		Polynomial result2 = poly1 + poly3;
		Polynomial result3 = poly2 + poly3;
		int a1[] = {3, 3, 2, -3};
		Polynomial test1(a1, 4);
		int b1[] = {2, -1};
		Polynomial test2(b1, 2);
		int c1[] = {1, 4, 2, -3};
		Polynomial test3(c1, 4);

		if(result1 == test1)
            cout<<"addition test1 working"<<endl;
        else
            cout<<"addition test1 failed"<<endl;
        if(result2 == test2)
            cout<<"addition test2 working"<<endl;
        else
            cout<<"addition test2 failed"<<endl;
        if(result3 == test3)
            cout<<"addition test3 working"<<endl;
        else
            cout<<"addition test3 failed"<<endl;
	}

	void subtractTest()
	{
		cout<<"running subtract test"<<endl;
		int a[] = {2, -1};
		Polynomial poly1(a, 2);
		int b[] = {1, 4, 2, -3};
		Polynomial poly2(b, 4);
		int c[] = {0,0,0,0};
		Polynomial poly3(c, 4);
		Polynomial result1 = poly1 - poly2;
		Polynomial result2 = poly2 - poly1;
		Polynomial result3 = poly1 - poly3;
		int a1[] = {1, -5, -2, 3};
		Polynomial test1(a1, 4);
		int b1[] = {-1, 5, 2, -3};
		Polynomial test2(b1, 4);
		int c1[] = {2, -1};
		Polynomial test3(c1, 2);

		if(result1 == test1)
            cout<<"subtract test1 working"<<endl;
        else
            cout<<"subtract test1 failed"<<endl;
        if(result2 == test2)
            cout<<"subtract test2 working"<<endl;
        else
            cout<<"subtract test2 failed"<<endl;
        if(result3 == test3)
            cout<<"subtract test3 working"<<endl;
        else
            cout<<"subtract test3 failed"<<endl;
	}

	void multiplyTest()
	{
		cout<<"running multiply test"<<endl;
		int a[] = {1, 2, 3, 4};
		Polynomial poly1(a, 4);
		int b[] = {3, 2, 1};
		Polynomial poly2(b, 3);
		Polynomial result = poly1*poly2;
		cout<<"expected result 4x^5+11x^4+20x^3+14x^2+12x+3 "<<endl;
		result.print();
	}

	void deriveTest()
	{
		cout<<"running deriveTest"<<endl;
        int arr1[] = {3, 2, 5, 6};
        Polynomial poly1(arr1, 4);
        int arr2[] = {3, -2, 5, 0, 1};
        Polynomial poly2(arr2, 5);
        int arr3[] = {5, 1};
        Polynomial poly3(arr3, 2);
		Polynomial derivative1 = poly1.derivative();
        Polynomial derivative2 = poly2.derivative();
		Polynomial derivative3 = poly3.derivative();
        int arr4[] = {2, 10, 18};
        Polynomial test1(arr4, 3);
        int arr5[] = {-2, 10, 0, 4};
        Polynomial test2(arr5, 4);
        int arr6[] = {1};
        Polynomial test3(arr6, 1);

        if(derivative1 == test1)
            cout<<"derive test1 working"<<endl;
        else
            cout<<"derive test1 failed"<<endl;
        if(derivative2 == test2)
            cout<<"derive test2 working"<<endl;
        else
            cout<<"derive test2 failed"<<endl;
            if(derivative3 == test3)
            cout<<"derive test3 working"<<endl;
        else
            cout<<"derive test3 failed"<<endl;
	}
};

int main ()
{
    ifstream file("test.txt");

	Polynomial poly1;

	PolynomialTest test;
	test.parametricConstructorTest();
	test.emptyConstructorTest();
	test.printTest();
	test.fileConstructorTest(file);
	test.equalsTest(poly1);
	test.addTest();
	test.subtractTest();
	test.multiplyTest();
	test.deriveTest();

	system("PAUSE");
	return 0;
}
