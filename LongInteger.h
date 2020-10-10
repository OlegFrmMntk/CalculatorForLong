#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
typedef vector <int> longNumb;

class LongInteger
{
	public:
		LongInteger();
        LongInteger(string number);

		friend istream& operator>> (istream &in, LongInteger &longN);
		friend ostream& operator<< (ostream &out, LongInteger &longN);

        LongInteger& operator=(const LongInteger& firstNumber)
        {
            longNumber = firstNumber.longNumber;
            longNumberInString = firstNumber.longNumberInString;
            mark = firstNumber.mark;

            return *this;
        }

        operator int()
        {
			print();

			if (longNumberInString[0] == '-')
			{
                int length = static_cast<int>(longNumberInString.size());
                return -1 * translationToInt(longNumberInString.substr(1, static_cast<unsigned int>(length - 1)));
			}
			else return translationToInt(longNumberInString);
        }

        friend bool operator > (LongInteger& firstNumber, const int& scndNumber);
        friend bool operator < (LongInteger& firstNumber, const int& scndNumber);
        friend bool operator >= (LongInteger& firstNumber, const int& scndNumber);
        friend bool operator <= (LongInteger& firstNumber, const int& scndNumber);
        friend bool operator == (LongInteger& firstNumber, const int& scndNumber);
        friend bool operator != (LongInteger& firstNumber, const int& scndNumber);
		
        friend bool operator > (const int& frstNumber, LongInteger& secondNumber);
        friend bool operator < (const int& frstNumber, LongInteger& secondNumber);
        friend bool operator >= (const int& frstNumber, LongInteger& secondNumber);
        friend bool operator <= (const int& frstNumber, LongInteger& secondNumber);
        friend bool operator == (const int& frstNumber, LongInteger& secondNumber);
        friend bool operator != (const int& frstNumber, LongInteger& secondNumber);

		friend bool operator > (LongInteger& firstNumber, LongInteger& secondNumber);
		friend bool operator < (LongInteger& firstNumber, LongInteger& secondNumber);
		friend bool operator >= (LongInteger& firstNumber, LongInteger& secondNumber);
		friend bool operator <= (LongInteger& firstNumber, LongInteger& secondNumber);
		friend bool operator == (LongInteger& firstNumber, LongInteger& secondNumber);
		friend bool operator != (LongInteger& firstNumber, LongInteger& secondNumber);

		friend LongInteger operator++(LongInteger& firstNumber);
		friend LongInteger operator--(LongInteger& firstNumber);

		friend const LongInteger operator++(LongInteger& i, int);
		friend const LongInteger operator--(LongInteger& firstNumber, int);

        friend LongInteger operator + (const int& frstNumber, LongInteger& secondNumber);
        friend LongInteger operator + (LongInteger& firstNumber, const int& secondNumber);
		friend LongInteger operator + (LongInteger& firstNumber, LongInteger& secondNumber);

        friend LongInteger operator += (LongInteger& firstNumber, const int& scndNumber);
		friend LongInteger operator += (LongInteger& firstNumber, LongInteger& secondNumber);
		
        friend LongInteger operator - (const int& frstNumber, LongInteger& secondNumber);
        friend LongInteger operator - (LongInteger& firstNumber, const int& secondNumber);
		friend LongInteger operator - (LongInteger& firstNumber, LongInteger& secondNumber);

        friend LongInteger operator -= (LongInteger& firstNumber, const int& scndNumber);
		friend LongInteger operator -= (LongInteger& firstNumber, LongInteger& secondNumber);
		
        friend LongInteger operator * (const int& frstNumber, LongInteger& secondNumber);
        friend LongInteger operator * (LongInteger& firstNumber, const int& secondNumber);
		friend LongInteger operator * (LongInteger& firstNumber, LongInteger& secondNumber);

        friend LongInteger operator *= (LongInteger& firstNumber, const int& scndNumber);
		friend LongInteger operator *= (LongInteger& firstNumber, LongInteger& secondNumber);

        friend LongInteger operator / (LongInteger& firstNumber, const int& secondNumber);
		friend LongInteger operator / (LongInteger& firstNumber, LongInteger& secondNumber);

        friend LongInteger operator /= (LongInteger& firstNumber, const int& scndNumber);
		friend LongInteger operator /= (LongInteger& firstNumber, LongInteger& secondNumber);

        string getString();
   protected:
		longNumb longNumber;
		string longNumberInString;
		bool mark;

		void scan();
        void scan_int(int numberInInt);
		void print();
		string translationToString(int numberInInt);
		int translationToInt(string numberInString);
		longNumb sum(longNumb firstNumb, longNumb secondNumb);
		longNumb diff(longNumb firstNumb, longNumb secondNumb);
		longNumb multiplication(longNumb firstNumb, longNumb secondNumb);
		LongInteger divisionLongOnShort(LongInteger firstNumber, int secondNumber);
		LongInteger division(LongInteger firstNumb, LongInteger secondNumb);
		int compare(LongInteger firstNumb, LongInteger secondNumb);
};
