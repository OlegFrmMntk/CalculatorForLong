//#pragma once
#include "LongInteger.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>

using namespace std;

typedef vector <int> longNumb;

LongInteger::LongInteger()
{
	longNumber.clear();
	scan_int(0);
	mark = true;
}

LongInteger::LongInteger(string number)
{
   longNumberInString = number;
   scan();
}

/////////////////////////////////////////////////////////////////////////////////////

istream& operator>> (istream& in, LongInteger& longN)
{
	in >> longN.longNumberInString;

	longN.scan();	

	return in;
}

ostream& operator<< (ostream& out, LongInteger& longN)
{
	longN.print();

	out << longN.longNumberInString;
	
	return out;
}

string LongInteger::getString()
{
    print();
    return longNumberInString;
}

///////////////////////////////////////////////////////////////////////////////////

bool operator > (LongInteger& firstNumber, LongInteger& secondNumber)
{
	int temp = firstNumber.compare(firstNumber, secondNumber);

	if (temp == 1) return true;
	else return false;
}

bool operator > (const int& frstNumber, LongInteger& secondNumber)
{
	LongInteger firstNumber;
	firstNumber.scan_int(frstNumber);

	int temp = firstNumber.compare(firstNumber, secondNumber);

	if (temp == 1) return true;
	else return false;
}

bool operator > (LongInteger& firstNumber, const int& scndNumber)
{
	LongInteger secondNumber;
	secondNumber.scan_int(scndNumber);

	int temp = firstNumber.compare(firstNumber, secondNumber);

	if (temp == 1) return true;
	else return false;
}

bool operator >= (LongInteger& firstNumber, LongInteger& secondNumber)
{
	int temp = firstNumber.compare(firstNumber, secondNumber);

	if (temp != 2) return true;
	else return false;
}

bool operator >= (const int& frstNumber, LongInteger& secondNumber)
{
	LongInteger firstNumber;
	firstNumber.scan_int(frstNumber);

	int temp = firstNumber.compare(firstNumber, secondNumber);

	if (temp != 2) return true;
	else return false;
}

bool operator >= (LongInteger& firstNumber, const int& scndNumber)
{
	LongInteger secondNumber;
	secondNumber.scan_int(scndNumber);

	int temp = firstNumber.compare(firstNumber, secondNumber);

	if (temp != 2) return true;
	else return false;
}

bool operator < (LongInteger& firstNumber, LongInteger& secondNumber)
{
	int temp = firstNumber.compare(firstNumber, secondNumber);

	if (temp == 2) return true;
	else return false;
}

bool operator < (LongInteger& firstNumber, const int& scndNumber)
{
	LongInteger secondNumber;
	secondNumber.scan_int(scndNumber);

	int temp = firstNumber.compare(firstNumber, secondNumber);

	if (temp == 2) return true;
	else return false;
}

bool operator < (const int& frstNumber, LongInteger& secondNumber)
{
	LongInteger firstNumber;
	firstNumber.scan_int(frstNumber);

	int temp = firstNumber.compare(firstNumber, secondNumber);

	if (temp == 2) return true;
	else return false;
}

bool operator <= (LongInteger& firstNumber, LongInteger& secondNumber)
{
	int temp = firstNumber.compare(firstNumber, secondNumber);

	if (temp != 1) return true;
	else return false;
}

bool operator <= (LongInteger& firstNumber, const int& scndNumber)
{
	LongInteger secondNumber;
	secondNumber.scan_int(scndNumber);

	int temp = firstNumber.compare(firstNumber, secondNumber);

	if (temp != 1) return true;
	else return false;
}

bool operator <= (const int& frstNumber, LongInteger& secondNumber)
{
	LongInteger firstNumber;
	firstNumber.scan_int(frstNumber);

	int temp = firstNumber.compare(firstNumber, secondNumber);

	if (temp != 1) return true;
	else return false;
}

bool operator == (LongInteger& firstNumber, const int& scndNumber)
{
	LongInteger secondNumber;
	secondNumber.scan_int(scndNumber);

	int temp = firstNumber.compare(firstNumber, secondNumber);

	if (temp == 3) return true;
	else return false;
}

bool operator == (LongInteger& firstNumber, LongInteger& secondNumber)
{
	int temp = firstNumber.compare(firstNumber, secondNumber);

	if (temp == 3) return true;
	else return false;
}

bool operator == (const int& frstNumber, LongInteger& secondNumber)
{
	LongInteger firstNumber;
	firstNumber.scan_int(frstNumber);

	int temp = firstNumber.compare(firstNumber, secondNumber);

	if (temp == 3) return true;
	else return false;
}

bool operator != (LongInteger& firstNumber, const int& scndNumber)
{
	LongInteger secondNumber;
	secondNumber.scan_int(scndNumber);

	int temp = firstNumber.compare(firstNumber, secondNumber);

	if (temp != 3) return true;
	else return false;
}

bool operator != (LongInteger& firstNumber, LongInteger& secondNumber)
{
	int temp = firstNumber.compare(firstNumber, secondNumber);

	if (temp != 3) return true;
	else return false;
}

bool operator != (const int& frstNumber, LongInteger& secondNumber)
{
	LongInteger firstNumber;
	firstNumber.scan_int(frstNumber);

	int temp = firstNumber.compare(firstNumber, secondNumber);

	if (temp != 3) return true;
	else return false;
}
///////////////////////////////////////////////////////////////////////////////////

LongInteger operator++(LongInteger& firstNumber)
{
	LongInteger secondNumber;
	secondNumber.scan_int(1);

	if (firstNumber.mark == true)
	{
		firstNumber.longNumber = firstNumber.sum(firstNumber.longNumber, secondNumber.longNumber);
	}
	else
	{
		firstNumber.longNumber = firstNumber.diff(firstNumber.longNumber, secondNumber.longNumber);
	}

	return firstNumber;
}

LongInteger operator--(LongInteger& firstNumber)
{
	LongInteger secondNumber;
	secondNumber.scan_int(1);

	if (firstNumber.mark == true)
	{
		firstNumber.longNumber = firstNumber.diff(firstNumber.longNumber, secondNumber.longNumber);
	}
	else
	{
		firstNumber.longNumber = firstNumber.sum(firstNumber.longNumber, secondNumber.longNumber);
	}

	return firstNumber;
}

const LongInteger operator++(LongInteger& firstNumber, int)
{
	LongInteger x(firstNumber), secondNumber;
	
	secondNumber.scan_int(1);
	
	if (firstNumber.mark == true)
	{
		firstNumber.longNumber = firstNumber.sum(firstNumber.longNumber, secondNumber.longNumber);
	}
	else
	{
		firstNumber.longNumber = firstNumber.diff(firstNumber.longNumber, secondNumber.longNumber);
	}

	return x;
}

const LongInteger operator--(LongInteger& firstNumber, int)
{
	LongInteger x(firstNumber);
	LongInteger secondNumber;
	secondNumber.scan_int(1);
	if (firstNumber.mark == true)
	{
		firstNumber.longNumber = firstNumber.diff(firstNumber.longNumber, secondNumber.longNumber);
	}
	else
	{
		firstNumber.longNumber = firstNumber.sum(firstNumber.longNumber, secondNumber.longNumber);
	}
	return firstNumber;


}

///////////////////////////////////////////////////////////////////////////////////

LongInteger operator+(const int& frstNumber, LongInteger& secondNumber)
{
	LongInteger firstNumber, thirdNumber;
	firstNumber.scan_int(frstNumber);

	if (!firstNumber.mark && secondNumber.mark)
	{
		firstNumber.mark = true;
		int key = thirdNumber.compare(firstNumber, secondNumber);

		if (key == 1)
		{
			thirdNumber.longNumber = thirdNumber.diff(firstNumber.longNumber, secondNumber.longNumber);
			thirdNumber.mark = false;
		}
		else
		{
			thirdNumber.longNumber = thirdNumber.diff(secondNumber.longNumber, firstNumber.longNumber);
			thirdNumber.mark = true;
		}

		firstNumber.mark = false;
	}
	else if (firstNumber.mark && !secondNumber.mark)
	{
		secondNumber.mark = false;
		int key = thirdNumber.compare(firstNumber, secondNumber);

		if (key == 1)
		{
			thirdNumber.longNumber = firstNumber.diff(firstNumber.longNumber, secondNumber.longNumber);
			thirdNumber.mark = true;
		}
		else if (key == 2)
		{
			thirdNumber.longNumber = thirdNumber.diff(secondNumber.longNumber, firstNumber.longNumber);
			thirdNumber.mark = false;
		}
		else
		{
			thirdNumber.longNumber = thirdNumber.diff(secondNumber.longNumber, firstNumber.longNumber);
			thirdNumber.mark = true;
		}

		secondNumber.mark = true;
	}
	else if (firstNumber.mark && secondNumber.mark)
	{
		thirdNumber.longNumber = thirdNumber.sum(firstNumber.longNumber, secondNumber.longNumber);
		thirdNumber.mark = true;
	}
	else if (firstNumber.mark == false && secondNumber.mark == false)
	{
		thirdNumber.longNumber = thirdNumber.sum(firstNumber.longNumber, secondNumber.longNumber);
		thirdNumber.mark = false;
	}

	return thirdNumber;
}

LongInteger operator+(LongInteger& firstNumber, const int& scndNumber)
{
	LongInteger secondNumber, thirdNumber;
	secondNumber.scan_int(scndNumber);

	if (!firstNumber.mark && secondNumber.mark)
	{
		firstNumber.mark = true;
		int key = thirdNumber.compare(firstNumber, secondNumber);

		if (key == 1)
		{
			thirdNumber.longNumber = thirdNumber.diff(firstNumber.longNumber, secondNumber.longNumber);
			thirdNumber.mark = false;
		}
		else
		{
			thirdNumber.longNumber = thirdNumber.diff(secondNumber.longNumber, firstNumber.longNumber);
			thirdNumber.mark = true;
		}

		firstNumber.mark = false;
	}
	else if (firstNumber.mark && !secondNumber.mark)
	{
		secondNumber.mark = false;
		int key = thirdNumber.compare(firstNumber, secondNumber);

		if (key == 1)
		{
			thirdNumber.longNumber = firstNumber.diff(firstNumber.longNumber, secondNumber.longNumber);
			thirdNumber.mark = true;
		}
		else if (key == 2)
		{
			thirdNumber.longNumber = thirdNumber.diff(secondNumber.longNumber, firstNumber.longNumber);
			thirdNumber.mark = false;
		}
		else
		{
			thirdNumber.longNumber = thirdNumber.diff(secondNumber.longNumber, firstNumber.longNumber);
			thirdNumber.mark = true;
		}

		secondNumber.mark = true;
	}
	else if (firstNumber.mark && secondNumber.mark)
	{
		thirdNumber.longNumber = thirdNumber.sum(firstNumber.longNumber, secondNumber.longNumber);
		thirdNumber.mark = true;
	}
	else if (firstNumber.mark == false && secondNumber.mark == false)
	{
		thirdNumber.longNumber = thirdNumber.sum(firstNumber.longNumber, secondNumber.longNumber);
		thirdNumber.mark = false;
	}

	return thirdNumber;
}

LongInteger operator+(LongInteger& firstNumber, LongInteger& secondNumber)
{
	LongInteger thirdNumber;

	if (!firstNumber.mark && secondNumber.mark)
	{
		firstNumber.mark = true;
		int key = thirdNumber.compare(firstNumber, secondNumber);

		if (key == 1)
		{
			thirdNumber.longNumber = thirdNumber.diff(firstNumber.longNumber, secondNumber.longNumber);
			thirdNumber.mark = false;
		}
		else
		{
			thirdNumber.longNumber = thirdNumber.diff(secondNumber.longNumber, firstNumber.longNumber);
			thirdNumber.mark = true;
		}

		firstNumber.mark = false;
	}
	else if (firstNumber.mark && !secondNumber.mark)
	{
		secondNumber.mark = false;
		int key = thirdNumber.compare(firstNumber, secondNumber);

		if (key == 1)
		{
			thirdNumber.longNumber = firstNumber.diff(firstNumber.longNumber, secondNumber.longNumber);
			thirdNumber.mark = true;
		}
		else if (key == 2)
		{
			thirdNumber.longNumber = thirdNumber.diff(secondNumber.longNumber, firstNumber.longNumber);
			thirdNumber.mark = false;
		}
		else 
		{
			thirdNumber.longNumber = thirdNumber.diff(secondNumber.longNumber, firstNumber.longNumber);
			thirdNumber.mark = true;
		}

		secondNumber.mark = true;
	}	
	else if (firstNumber.mark && secondNumber.mark)
	{
		thirdNumber.longNumber = thirdNumber.sum(firstNumber.longNumber, secondNumber.longNumber);
		thirdNumber.mark = true;
	}
	else if (firstNumber.mark == false && secondNumber.mark == false)
	{
		thirdNumber.longNumber = thirdNumber.sum(firstNumber.longNumber, secondNumber.longNumber);
		thirdNumber.mark = false;
	}

	return thirdNumber;
}

///////////////////////////////////////////////////////////////////////////////////

LongInteger operator+=(LongInteger& firstNumber, const int& scndNumber)
{
	LongInteger secondNumber, thirdNumber;
	secondNumber.scan_int(scndNumber);

	if (!firstNumber.mark && secondNumber.mark)
	{
		firstNumber.mark = true;
		int key = firstNumber.compare(firstNumber, secondNumber);

		if (key == 1)
		{
			firstNumber.longNumber = firstNumber.diff(firstNumber.longNumber, secondNumber.longNumber);
			firstNumber.mark = false;
		}
		else
		{
			firstNumber.longNumber = firstNumber.diff(secondNumber.longNumber, firstNumber.longNumber);
			firstNumber.mark = true;
		}
	}
	else if (firstNumber.mark && !secondNumber.mark)
	{
		secondNumber.mark = false;
		int key = firstNumber.compare(firstNumber, secondNumber);

		if (key == 1)
		{
			firstNumber.longNumber = firstNumber.diff(firstNumber.longNumber, secondNumber.longNumber);
			firstNumber.mark = true;
		}
		else if (key == 2)
		{
			firstNumber.longNumber = firstNumber.diff(secondNumber.longNumber, firstNumber.longNumber);
			firstNumber.mark = false;
		}
		else
		{
			firstNumber.longNumber = firstNumber.diff(secondNumber.longNumber, firstNumber.longNumber);
			firstNumber.mark = true;
		}

		secondNumber.mark = true;
	}
	else if (firstNumber.mark && secondNumber.mark)
	{
		firstNumber.longNumber = firstNumber.sum(firstNumber.longNumber, secondNumber.longNumber);
		firstNumber.mark = true;
	}
	else if (firstNumber.mark == false && secondNumber.mark == false)
	{
		firstNumber.longNumber = firstNumber.sum(firstNumber.longNumber, secondNumber.longNumber);
		firstNumber.mark = false;
	}

	return firstNumber;
}

LongInteger operator+=(LongInteger& firstNumber, LongInteger& secondNumber)
{

	if (!firstNumber.mark && secondNumber.mark)
	{
		firstNumber.mark = true;
		int key = firstNumber.compare(firstNumber, secondNumber);

		if (key == 1)
		{
			firstNumber.longNumber = firstNumber.diff(firstNumber.longNumber, secondNumber.longNumber);
			firstNumber.mark = false;
		}
		else
		{
			firstNumber.longNumber = firstNumber.diff(secondNumber.longNumber, firstNumber.longNumber);
			firstNumber.mark = true;
		}
	}
	else if (firstNumber.mark && !secondNumber.mark)
	{
		secondNumber.mark = false;
		int key = firstNumber.compare(firstNumber, secondNumber);

		if (key == 1)
		{
			firstNumber.longNumber = firstNumber.diff(firstNumber.longNumber, secondNumber.longNumber);
			firstNumber.mark = true;
		}
		else if (key == 2)
		{
			firstNumber.longNumber = firstNumber.diff(secondNumber.longNumber, firstNumber.longNumber);
			firstNumber.mark = false;
		}
		else
		{
			firstNumber.longNumber = firstNumber.diff(secondNumber.longNumber, firstNumber.longNumber);
			firstNumber.mark = true;
		}

		secondNumber.mark = true;
	}
	else if (firstNumber.mark && secondNumber.mark)
	{
		firstNumber.longNumber = firstNumber.sum(firstNumber.longNumber, secondNumber.longNumber);
		firstNumber.mark = true;
	}
	else if (firstNumber.mark == false && secondNumber.mark == false)
	{
		firstNumber.longNumber = firstNumber.sum(firstNumber.longNumber, secondNumber.longNumber);
		firstNumber.mark = false;
	}

	return firstNumber;
}

//////////////////////////////////////////////////////////////////////////////////

LongInteger operator- (LongInteger& firstNumber, LongInteger& secondNumber)
{
	LongInteger thirdNumber;
	int temp = firstNumber.compare(firstNumber, secondNumber);
	if (firstNumber.mark == false && secondNumber.mark == false)
	{
		if (temp == 1 || temp == 3)
		{
			thirdNumber.longNumber = firstNumber.diff(secondNumber.longNumber, firstNumber.longNumber);
			thirdNumber.mark = true;
		}
		else
		{
			thirdNumber.longNumber = firstNumber.diff(firstNumber.longNumber, secondNumber.longNumber);
			thirdNumber.mark = false;
		}
	}
	else if (firstNumber.mark == true && secondNumber.mark == true)
	{
		if (temp == 1 || temp == 3)
		{
			thirdNumber.longNumber = firstNumber.diff(firstNumber.longNumber, secondNumber.longNumber);
			thirdNumber.mark = true;
		}
		else
		{
			thirdNumber.longNumber = firstNumber.diff(secondNumber.longNumber, firstNumber.longNumber);
			thirdNumber.mark = false;
		}
	}
	else if (firstNumber.mark == true && secondNumber.mark == false)
	{
		thirdNumber.longNumber = firstNumber.sum(firstNumber.longNumber, secondNumber.longNumber);
		thirdNumber.mark = true;
	}
	else if (firstNumber.mark == false && secondNumber.mark == true)
	{
		thirdNumber.longNumber = firstNumber.sum(firstNumber.longNumber, secondNumber.longNumber);
		thirdNumber.mark = false;
	}

	return thirdNumber;
}

LongInteger operator- (LongInteger& firstNumber, const int& scndNumber)
{
	LongInteger secondNumber, thirdNumber;
	secondNumber.scan_int(scndNumber);
	int temp = firstNumber.compare(firstNumber, secondNumber);
	if (firstNumber.mark == false && secondNumber.mark == false)
	{
		if (temp == 1 || temp == 3)
		{
			thirdNumber.longNumber = firstNumber.diff(secondNumber.longNumber, firstNumber.longNumber);
			thirdNumber.mark = true;
		}
		else
		{
			thirdNumber.longNumber = firstNumber.diff(firstNumber.longNumber, secondNumber.longNumber);
			thirdNumber.mark = false;
		}
	}
	else if (firstNumber.mark == true && secondNumber.mark == true)
	{
		if (temp == 1 || temp == 3)
		{
			thirdNumber.longNumber = firstNumber.diff(firstNumber.longNumber, secondNumber.longNumber);
			thirdNumber.mark = true;
		}
		else
		{
			thirdNumber.longNumber = firstNumber.diff(secondNumber.longNumber, firstNumber.longNumber);
			thirdNumber.mark = false;
		}
	}
	else if (firstNumber.mark == true && secondNumber.mark == false)
	{
		thirdNumber.longNumber = firstNumber.sum(firstNumber.longNumber, secondNumber.longNumber);
		thirdNumber.mark = true;
	}
	else if (firstNumber.mark == false && secondNumber.mark == true)
	{
		thirdNumber.longNumber = firstNumber.sum(firstNumber.longNumber, secondNumber.longNumber);
		thirdNumber.mark = false;
	}

	return thirdNumber;
}

LongInteger operator- (const int& frstNumber, LongInteger& secondNumber)
{
	LongInteger firstNumber, thirdNumber;
	firstNumber.scan_int(frstNumber);
	int temp = firstNumber.compare(firstNumber, secondNumber);

	if (firstNumber.mark == false && secondNumber.mark == false)
	{
		if (temp == 1 || temp == 3)
		{
			thirdNumber.longNumber = firstNumber.diff(secondNumber.longNumber, firstNumber.longNumber);
			thirdNumber.mark = true;
		}
		else
		{
			thirdNumber.longNumber = firstNumber.diff(firstNumber.longNumber, secondNumber.longNumber);
			thirdNumber.mark = false;
		}
	}
	else if (firstNumber.mark == true && secondNumber.mark == true)
	{
		if (temp == 1 || temp == 3)
		{
			thirdNumber.longNumber = firstNumber.diff(firstNumber.longNumber, secondNumber.longNumber);
			thirdNumber.mark = true;
		}
		else
		{
			thirdNumber.longNumber = firstNumber.diff(secondNumber.longNumber, firstNumber.longNumber);
			thirdNumber.mark = false;
		}
	}
	else if (firstNumber.mark == true && secondNumber.mark == false)
	{
		thirdNumber.longNumber = firstNumber.sum(firstNumber.longNumber, secondNumber.longNumber);
		thirdNumber.mark = true;
	}
	else if (firstNumber.mark == false && secondNumber.mark == true)
	{
		thirdNumber.longNumber = firstNumber.sum(firstNumber.longNumber, secondNumber.longNumber);
		thirdNumber.mark = false;
	}
	return thirdNumber;
}

//////////////////////////////////////////////////////////////////////////////////

LongInteger operator-= (LongInteger& firstNumber, LongInteger& secondNumber)
{
	int temp = firstNumber.compare(firstNumber, secondNumber);
	if (firstNumber.mark == false && secondNumber.mark == false)
	{
		if (temp == 1 || temp == 3)
		{
			firstNumber.longNumber = firstNumber.diff(secondNumber.longNumber, firstNumber.longNumber);
			firstNumber.mark = true;
		}
		else
		{
			firstNumber.longNumber = firstNumber.diff(firstNumber.longNumber, secondNumber.longNumber);
			firstNumber.mark = false;
		}
	}
	else if (firstNumber.mark == true && secondNumber.mark == true)
	{
		if (temp == 1 || temp == 3)
		{
			firstNumber.longNumber = firstNumber.diff(firstNumber.longNumber, secondNumber.longNumber);
			firstNumber.mark = true;
		}
		else
		{
			firstNumber.longNumber = firstNumber.diff(secondNumber.longNumber, firstNumber.longNumber);
			firstNumber.mark = false;
		}
	}
	else if (firstNumber.mark == true && secondNumber.mark == false)
	{
		firstNumber.longNumber = firstNumber.sum(firstNumber.longNumber, secondNumber.longNumber);
		firstNumber.mark = true;
	}
	else if (firstNumber.mark == false && secondNumber.mark == true)
	{
		firstNumber.longNumber = firstNumber.sum(firstNumber.longNumber, secondNumber.longNumber);
		firstNumber.mark = false;
	}

	return firstNumber;
}

LongInteger operator-= (LongInteger& firstNumber, const int& scndNumber)
{
	LongInteger secondNumber;
	secondNumber.scan_int(scndNumber);
	int temp = firstNumber.compare(firstNumber, secondNumber);
	if (firstNumber.mark == false && secondNumber.mark == false)
	{
		if (temp == 1 || temp == 3)
		{
			firstNumber.longNumber = firstNumber.diff(secondNumber.longNumber, firstNumber.longNumber);
			firstNumber.mark = true;
		}
		else
		{
			firstNumber.longNumber = firstNumber.diff(firstNumber.longNumber, secondNumber.longNumber);
			firstNumber.mark = false;
		}
	}
	else if (firstNumber.mark == true && secondNumber.mark == true)
	{
		if (temp == 1 || temp == 3)
		{
			firstNumber.longNumber = firstNumber.diff(firstNumber.longNumber, secondNumber.longNumber);
			firstNumber.mark = true;
		}
		else
		{
			firstNumber.longNumber = firstNumber.diff(secondNumber.longNumber, firstNumber.longNumber);
			firstNumber.mark = false;
		}
	}
	else if (firstNumber.mark == true && secondNumber.mark == false)
	{
		firstNumber.longNumber = firstNumber.sum(firstNumber.longNumber, secondNumber.longNumber);
		firstNumber.mark = true;
	}
	else if (firstNumber.mark == false && secondNumber.mark == true)
	{
		firstNumber.longNumber = firstNumber.sum(firstNumber.longNumber, secondNumber.longNumber);
		firstNumber.mark = false;
	}

	return firstNumber;
}

//////////////////////////////////////////////////////////////////////////////////

LongInteger operator* (LongInteger& firstNumber, LongInteger& secondNumber)
{
	LongInteger thirdNumber;
	if (firstNumber.mark == secondNumber.mark)
	{
		thirdNumber.longNumber = firstNumber.multiplication(firstNumber.longNumber, secondNumber.longNumber);
		thirdNumber.mark = true;
	}
	else if (firstNumber.mark != secondNumber.mark)
	{
		thirdNumber.longNumber = firstNumber.multiplication(firstNumber.longNumber, secondNumber.longNumber);
		thirdNumber.mark = false;
	}
	return thirdNumber;
}

LongInteger operator* (LongInteger& firstNumber, const int& scndNumber)
{
	LongInteger thirdNumber, secondNumber;
	secondNumber.scan_int(scndNumber);
	if ((firstNumber.mark == false && secondNumber.mark == false) || (firstNumber.mark == true && secondNumber.mark == true))
	{
		thirdNumber.longNumber = firstNumber.multiplication(firstNumber.longNumber, secondNumber.longNumber);
		thirdNumber.mark = true;
	}
	else if ((firstNumber.mark == false && secondNumber.mark == true) || (firstNumber.mark == true && secondNumber.mark == false))
	{
		thirdNumber.longNumber = firstNumber.multiplication(firstNumber.longNumber, secondNumber.longNumber);
		thirdNumber.mark = false;
	}
	return thirdNumber;
}

LongInteger operator* (const int& frstNumber, LongInteger& secondNumber)
{
	LongInteger thirdNumber, firstNumber;
	firstNumber.scan_int(frstNumber);
	if ((firstNumber.mark == false && secondNumber.mark == false) || (firstNumber.mark == true && secondNumber.mark == true))
	{
		thirdNumber.longNumber = firstNumber.multiplication(firstNumber.longNumber, secondNumber.longNumber);
		thirdNumber.mark = true;
	}
	else if ((firstNumber.mark == false && secondNumber.mark == true) || (firstNumber.mark == true && secondNumber.mark == false))
	{
		thirdNumber.longNumber = firstNumber.multiplication(firstNumber.longNumber, secondNumber.longNumber);
		thirdNumber.mark = false;
	}
	return thirdNumber;
}

//////////////////////////////////////////////////////////////////////////////////////////

LongInteger operator*= (LongInteger& firstNumber, LongInteger& secondNumber)
{
	if (firstNumber.mark == secondNumber.mark)
	{
		firstNumber.longNumber = firstNumber.multiplication(firstNumber.longNumber, secondNumber.longNumber);
		firstNumber.mark = true;
	}
	else if (firstNumber.mark != secondNumber.mark)
	{
		firstNumber.longNumber = firstNumber.multiplication(firstNumber.longNumber, secondNumber.longNumber);
		firstNumber.mark = false;
	}

	return firstNumber;
}

LongInteger operator*= (LongInteger& firstNumber, const int& scndNumber)
{
	LongInteger  secondNumber;
	secondNumber.scan_int(scndNumber);

	if ((firstNumber.mark == false && secondNumber.mark == false) || (firstNumber.mark == true && secondNumber.mark == true))
	{
		firstNumber.longNumber = firstNumber.multiplication(firstNumber.longNumber, secondNumber.longNumber);
		firstNumber.mark = true;
	}
	else if ((firstNumber.mark == false && secondNumber.mark == true) || (firstNumber.mark == true && secondNumber.mark == false))
	{
		firstNumber.longNumber = firstNumber.multiplication(firstNumber.longNumber, secondNumber.longNumber);
		firstNumber.mark = false;
	}
	return firstNumber;
}

/////////////////////////////////////////////////////////////////////////////////////////

LongInteger operator/ (LongInteger& firstNumber, LongInteger& secondNumber)
{
	LongInteger thirdNumber;

	if (firstNumber.mark == secondNumber.mark)
	{
		thirdNumber = thirdNumber.division(firstNumber, secondNumber);
		thirdNumber.mark = true;
	}
	else 
	{
		thirdNumber = thirdNumber.division(firstNumber, secondNumber);
		thirdNumber.mark = false;
	}

	bool tempF = firstNumber.mark, tempS = secondNumber.mark;

	firstNumber.mark = true;
	secondNumber.mark = true;

	if (firstNumber < secondNumber) thirdNumber.scan_int(0);

	firstNumber.mark = tempF;
	secondNumber.mark = tempS;

	return thirdNumber;
}

LongInteger operator/ (LongInteger& firstNumber, const int& scndNumber)
{
	LongInteger secondNumber, thirdNumber;
	secondNumber.scan_int(abs(scndNumber));
	
	if (abs(scndNumber) > 1000000000) thirdNumber = firstNumber / secondNumber;
	else thirdNumber = thirdNumber.divisionLongOnShort(firstNumber, abs(scndNumber));
	
	secondNumber.scan_int(scndNumber);
	
    if ((firstNumber.mark = secondNumber.mark)) thirdNumber.mark = true;
	else thirdNumber.mark = false;
	
	bool tempF = firstNumber.mark, tempS = secondNumber.mark;

	firstNumber.mark = true;
	secondNumber.mark = true;

	if (firstNumber < secondNumber) thirdNumber.scan_int(0);

	firstNumber.mark = tempF;
	secondNumber.mark = tempS;

	return thirdNumber;
}

/////////////////////////////////////////////////////////////////////////////////////////

LongInteger operator/= (LongInteger& firstNumber, LongInteger& secondNumber)
{

	if (firstNumber.mark == secondNumber.mark)
	{
		firstNumber = firstNumber.division(firstNumber, secondNumber);
		firstNumber.mark = true;
	}
	else
	{
		firstNumber = firstNumber.division(firstNumber, secondNumber);
		firstNumber.mark = false;
	}

	bool tempF = firstNumber.mark, tempS = secondNumber.mark;

	firstNumber.mark = true;
	secondNumber.mark = true;

	if (firstNumber < secondNumber) firstNumber.scan_int(0);

	firstNumber.mark = tempF;
	secondNumber.mark = tempS;

	return firstNumber;
}

LongInteger operator/= (LongInteger& firstNumber, const int& scndNumber)
{
	LongInteger secondNumber;
	secondNumber.scan_int(abs(scndNumber));

	if (abs(scndNumber) > 1000000000) firstNumber = firstNumber / secondNumber;
	else firstNumber = firstNumber.divisionLongOnShort(firstNumber, abs(scndNumber));

	secondNumber.scan_int(scndNumber);

    if ((firstNumber.mark = secondNumber.mark)) firstNumber.mark = true;
	else firstNumber.mark = false;

	bool tempF = firstNumber.mark, tempS = secondNumber.mark;

	firstNumber.mark = true;
	secondNumber.mark = true;

	if (firstNumber < secondNumber) firstNumber.scan_int(0);

	firstNumber.mark = tempF;
	secondNumber.mark = tempS;

	return firstNumber;
}

/////////////////////////////////////////////////////////////////////////////////////////

int LongInteger::translationToInt(string numberInString)
{
	int numberInInt = 0;
	
    if (numberInString[0] == '-') numberInString.erase(0, 1);
    for (int index = 0; index < static_cast<int>(numberInString.size()); index++)
	{
		numberInInt *= 10;
        numberInInt += (numberInString[static_cast<unsigned int>(index)] - '0');
	}

	return numberInInt;
}

string LongInteger::translationToString(int numberInInt)
{
	string numberInString = "";

	while (numberInInt)
	{
		numberInString += ((numberInInt % 10) + '0');
		numberInInt /= 10;
	}

	reverse(numberInString.begin(), numberInString.end());

	return numberInString;
}

///////////////////////////////////////////////////////////////////////////////////////////

void LongInteger::scan()
{
	if (longNumberInString[0] == '-') mark = false;
	else mark = true;

	if (longNumberInString[0] == '-' || longNumberInString[0] == '+') longNumberInString.erase(0, 1);

	longNumber.clear();

    for (int index = static_cast<int>(longNumberInString.size()); index > 0; index -= 9)
    {
        if (index < 9) longNumber.push_back(translationToInt(longNumberInString.substr(0, static_cast<unsigned int>(index))));
        else longNumber.push_back(translationToInt(longNumberInString.substr(static_cast<unsigned int>(index) - 9, 9)));
    }
	while (longNumber.size() > 1 && !longNumber.back())
		longNumber.pop_back();

}

void LongInteger::scan_int(int numberInInt)
{
	if (numberInInt < 0)
	{
		mark = false;
		longNumberInString = "-";
	}
	else
	{
		longNumberInString = "";
		mark = true;
	}

	longNumberInString += translationToString(abs(numberInInt));

    for (int index = static_cast<int>(longNumberInString.size()); index > 0; index -= 9)
    {
        if (index < 9) longNumber.push_back(translationToInt(longNumberInString.substr(0, static_cast<unsigned int>(index))));
        else longNumber.push_back(translationToInt(longNumberInString.substr(static_cast<unsigned int>(index) - 9, 9)));
    }
    while (longNumber.size() > 1 && !longNumber.back())
    {
		longNumber.pop_back();
    }
}

void LongInteger::print()
{	
    if (!mark && static_cast<int>(longNumber.size())) longNumberInString = "-";
	else longNumberInString = "";

    if (static_cast<int>(longNumber.size())) longNumberInString += translationToString(longNumber.back());
	else longNumberInString = "0";

    for (int index = int(static_cast<int>(longNumber.size()) - 2); index >= 0; --index)
	{
        string temp = translationToString(longNumber[static_cast<unsigned int>(index)]);

		reverse(temp.begin(), temp.end());

        while (static_cast<int>(temp.size()) < 9)
			temp += "0";

		reverse(temp.begin(), temp.end());

		longNumberInString += temp;
	}

	if (longNumberInString.empty()) longNumberInString = "0";
}

//////////////////////////////////////////////////////////////////////////////////////////

longNumb LongInteger::sum(longNumb firstNumber, longNumb secondNumber)
{
	int carry = 0;

    for (unsigned int index = 0; index < max(static_cast<unsigned int>(firstNumber.size()), static_cast<unsigned int>(secondNumber.size())) || carry; ++index)
	{
        if (static_cast<unsigned int>(firstNumber.size()) == index) firstNumber.push_back(0);
        firstNumber[static_cast<unsigned int>(index)] += carry;
        if (static_cast<unsigned int>(secondNumber.size()) > index) firstNumber[index] += secondNumber[index];
        carry = firstNumber[static_cast<unsigned int>(index)] / 1000000000;
        if (carry) firstNumber[static_cast<unsigned int>(index)] -= 1000000000;
	}

	return firstNumber;
}

longNumb LongInteger::diff(longNumb firstNumber, longNumb secondNumber)
{
	int carry = 0;
    for (unsigned int index = 0; index < static_cast<unsigned int>(firstNumber.size()) || carry; ++index)
	{
        if (index < static_cast<unsigned int>(secondNumber.size())) firstNumber[index] -= carry + secondNumber[index];
		else firstNumber[index] -= carry;

		carry = firstNumber[index] < 0;
		if (carry)  firstNumber[index] += 1000000000;
	}

    while (static_cast<int>(firstNumber.size()) > 1 && !firstNumber.back())
		firstNumber.pop_back();

	return firstNumber;
} 

longNumb LongInteger::multiplication(longNumb firstNumber, longNumb secondNumber)
{
	longNumb thirdNumber(firstNumber.size() + secondNumber.size());

    for (int index = 0; index <static_cast<int>(firstNumber.size()); ++index)
        for (int j = 0, carry = 0; j < static_cast<int>(secondNumber.size()) || carry; ++j) {
            long long lgN = thirdNumber[static_cast<unsigned int>(index + j)] + firstNumber[static_cast<unsigned int>(index)] * 1ll * (j < static_cast<int>(secondNumber.size()) ? secondNumber[static_cast<unsigned int>(j)] : 0) + carry;
            thirdNumber[static_cast<unsigned int>(index + j)] = int(lgN % 1000000000);
			carry = int(lgN / 1000000000);
		}

    while (static_cast<int>(thirdNumber.size()) > 1 && !thirdNumber.back())
		thirdNumber.pop_back();

	return thirdNumber;
}

LongInteger LongInteger::divisionLongOnShort(LongInteger firstNumber, int secondNumber)
{
	int carry = 0;
	
    for ( int index = static_cast<int>(firstNumber.longNumber.size()) - 1; index >= 0; --index)
	{
        long long cur = firstNumber.longNumber[static_cast<unsigned int>(index)] + carry * 1ll * 1000000000;
        firstNumber.longNumber[static_cast<unsigned int>(index)] = int(cur / secondNumber);
		carry = int(cur % secondNumber);
	}

    while (static_cast<int>(firstNumber.longNumber.size()) > 1 && !firstNumber.longNumber.back())
		firstNumber.longNumber.pop_back();

	if (firstNumber.longNumber.empty()) firstNumber.longNumber.push_back(0);

	*this = firstNumber;
	return *this;
}

LongInteger LongInteger::division(LongInteger firstNumber, LongInteger secondNumber)
{
	firstNumber.mark = true;
	secondNumber.mark = true;

	LongInteger left, right = firstNumber;
	LongInteger  tempDiv = right - left;

	int one = 1, two = 2;
	while (tempDiv > one)
	{
		LongInteger temp = left + right, mid = temp / two;

		temp = mid * secondNumber;
        string s = temp.getString(), firstString = firstNumber.getString();
        string sL = left.getString(), sR = right.getString();

		if (temp >= firstNumber) right = mid;
		else left = mid;

        sL = left.getString();
        sR = right.getString();

		tempDiv = right - left;
	}

	tempDiv = right * secondNumber;
	if (tempDiv <= firstNumber) return right;
	else return left;
} 

//////////////////////////////////////////////////////////////////////////////////////////

int LongInteger::compare(LongInteger firstNumber, LongInteger secondNumber)
{
	firstNumber.print();
	secondNumber.print();

    string sF = firstNumber.getString(), sS = secondNumber.getString();
	if (firstNumber.mark && secondNumber.mark)
	{
        if (sF.size() > sS.size()) return 1;
        else if (sF.size() < sS.size()) return 2;
		else
		{
			if (firstNumber.longNumberInString > secondNumber.longNumberInString) return 1;
			else if (firstNumber.longNumberInString < secondNumber.longNumberInString) return 2;
			else return 3;
		}
	}
	else if (!firstNumber.mark && !secondNumber.mark)
	{
		string first = firstNumber.longNumberInString, second = secondNumber.longNumberInString;

		first.erase(0, 1);
		second.erase(0, 1);

        if (first.size() > second.size()) return 2;
        else if (first.size() < second.size()) return 1;
		else
		{
			if (first < second) return 1;
			else if (first > second) return 2;
			else return 3;
		}
	}
	else if (!firstNumber.mark && secondNumber.mark)
	{
		return 2;
	} 
	else if (firstNumber.mark && !secondNumber.mark)
	{
		return 1;
	}

	return 0;
}

