/*
 ==============================================================================================================================
 Name        : main.cpp
 Author      : Siddhata Patil
 Copyright   : Copyright © InterviewBit for the question.
 Copyright   : Copyright ©  Siddhata Patil. Sourcecode rights reserved.
 Question    : Implement pow(x, n) % d
 Example     : Input : x = 2, n = 3, d = 3 Output : 2 -----> 2^3 % 3 = 8 % 3 = 2.
 ==============================================================================================================================
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  int pow(int, int, int) ;
}obj;

int Solution::pow(int x, int n, int d)
{
  long long result = 1;
  long long base = x;
  int power = n;
  int modulus_of = d;

    if (power == 0)
    {
      return 1 % modulus_of;
    }

    while (power > 0)
    {
                // We need (base ** n) % p.
                // Now there are 2 cases.
                // 1) n is even. Then we can make base = base^2 and n = n / 2.
                // 2) n is odd. So we need base * base^(n-1)
                if (power % 2 == 1)
                {
                    result = (result * base) % modulus_of;
                    power--;
                  }
                  else
                  {
                    base = (base * base) % modulus_of;
                    power /= 2;
                  }
    }
            if (result < 0)
            {
              result = (result + modulus_of) % modulus_of;
            }

return result;
}

int main()
{
  int result=0;
  result = obj.pow(2,4,3);
  cout<<"(2 ^ 4) % 3=  ";
  cout<<result<<endl;
  return 0;
}
