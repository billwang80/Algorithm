// Bill Wang & Jimmy Huang
// 20778745 & 20778541

#include <cstdlib>
#include <sys/types.h> //gets the sleep function
#include <cmath>
#include "lab1_polynomial.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

Polynomial::Polynomial()
{
	srand(time(0));
	int order = rand() % 1001;
	for(int index = 0; index<=order; index++)
	{
		data.push_back(rand()%2001-1000);
	}
}

Polynomial::Polynomial(int A[], int size)
{
	for(int index = 0; index<size; index++)
	{
		data.push_back(A[index]);
	}
}

Polynomial::Polynomial(string fileName)
{
	ifstream file(fileName);
	if(!file)
	{
		cout<<"Could not find file";
	}
	int input;
	while(file>>input)
	{
		data.push_back(input);
	}
	file.close();
}

void Polynomial::print()
{
	for(int order = data.size()-1; order>=0; order--)
	{
		if(data[order] != 0)
		{
			if(order != data.size()-1 && data[order]>0)
			{
				cout<<"+";
			}
			if(order !=0)
			{
				if(data[order] == -1)
				{
					cout<<"-";
				}
				else if(data[order != 1])
				{
					cout<<data[order];
				}
			}
			else
			{
				cout<<data[0];
			}

			if(order > 1)
			{
				cout<<"x^"<<order;
			}
			else if(order == 1)
			{
				cout<<"x";
			}
		}
	}
	cout<<endl;
}

bool Polynomial::operator==(const Polynomial& other) const
{
	if(data.size() != other.data.size())
	{
		return false;
	}

	for(int index = 0; index<data.size(); index++)
	{
		if(data[index] != other.data[index])
		{
			return false;
		}
	}
	return true;
}

Polynomial Polynomial::operator+(const Polynomial& target) const
{
    vector<int> result;

    int size1 = data.size();
    int size2 = target.data.size();
    int difference = fabs(size1 - size2);
    int largerSize = 0;
    bool isOneLarger = true;

    if(size1 > size2){
        largerSize = size1;
    }
    else{
        largerSize = size2;
        isOneLarger = false;
    }

    for(int i = 0; i < largerSize; i++)
    {
        if(i < largerSize - difference)
        {
            if(isOneLarger)
                result[i] = data[i] + target.data[i - difference];
            else
                result[i] = data[i - difference] + target.data[i];
        }
        else
        {
            if(isOneLarger)
                result[i] = data[i];
            else
                result[i] = target.data[i];
        }
    }
    int arr[result.size()];

    for(int count = 0; count < result.size(); count++)
    {
        arr[count] = result[count];
    }
    Polynomial poly(arr, result.size());

    return poly;
}

Polynomial Polynomial::operator-(const Polynomial& target) const
{
    vector<int> result;

    int size1 = data.size();
    int size2 = target.data.size();
    int difference = fabs(size1 - size2);
    int largerSize = 0;
    bool isOneLarger = true;

    if(size1 > size2){
        largerSize = size1;
    }
    else{
        largerSize = size2;
        isOneLarger = false;
    }

    for(int i = 0; i < largerSize; i++)
    {
        if(i < largerSize - difference)
        {
            if(isOneLarger)
                result[i] = data[i] - target.data[i - difference];
            else
                result[i] = data[i - difference] - target.data[i];
        }
        else
        {
            if(isOneLarger)
                result[i] = data[i];
            else
                result[i] = -1*target.data[i];
        }
    }
    int arr[result.size()];

    for(int count = 0; count < result.size(); count++)
    {
        arr[count] = result[count];
    }
    Polynomial poly(arr, result.size());

    return poly;
}

Polynomial Polynomial::operator*(const Polynomial& target) const
{
    int resultSize = data.size() + target.data.size();
    vector<int> result;

    for(int i = 0; i < data.size(); i++)
    {
        for(int j = 0; j < target.data.size(); j++)
        {
            int degree1 = i;
            int degree2 = j;

            if(i == 0 && j == 0)
            {
                for(int count = 0; count < resultSize; count++)
                {
                    result[count] = 0;
                }
            }
            int currentResultIndex = degree1 + degree2;
            result[currentResultIndex] = result[currentResultIndex] + data[i]*target.data[j];
        }
    }

    int arr[result.size()];

    for(int count = 0; count < result.size(); count++)
    {
        arr[count] = result[count];
    }
    Polynomial poly(arr, result.size());

    return poly;
}

Polynomial Polynomial::derivative()
{
    data.erase(data.begin());
    for(int i = 0; i < data.size(); i++)
    {
        data[i] = (i+1)*data[i];
    }
    return *this;
}
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
		Polynomial printee(A,8);
		cout<<"expecting 8x^7+7x^6+6x^5+5x^4+4x^3+3x^2+2x+1"<<endl;
		printee.print();
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

	void fileConstructorTest(string fileName)
	{
		cout<<"running fileConstruct test"<<endl;
		Polynomial test1(fileName);
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
		Polynomial result = poly1 + poly2;
		cout<<"expected result -3x^3+2x^2+3x+3"<< endl;
		result.print();
	}

	void subtractTest()
	{
		cout<<"running subtract test"<<endl;
		int a[] = {2, -1};
		Polynomial poly1(a, 2);
		int b[] = {1, 0, 2, -3};
		Polynomial poly2(b, 4);
		Polynomial result = poly1 - poly2;
		cout<<"expected result 3x^3-x^2-5x+1"<<endl;
		result.print();
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

	void deriveTest(Polynomial test)
	{
		cout<<"running deriveTest"<<endl;
		test.print();
		Polynomial derivative = test.derivative();
		derivative.print();
	}
};

int main ()
{
	Polynomial poly1;
	int arr[] = {3, 2, 5, 6};
	Polynomial poly2(arr, 4);

	PolynomialTest test;
	test.parametricConstructorTest();
	test.emptyConstructorTest();
	test.printTest();
	test.fileConstructorTest("test.txt");
	test.equalsTest(poly1);
	test.addTest();
	test.subtractTest();
	test.multiplyTest();
	test.deriveTest(poly2);

	system("PAUSE");
	return 0;
}
