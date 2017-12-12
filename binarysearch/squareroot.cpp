/*
 ==============================================================================================================================
 Name        : main.cpp
 Author      : Siddhata Patil
 Copyright   : Copyright © InterviewBit for the question.
 Copyright   : Copyright ©  Siddhata Patil. Sourcecode rights reserved.
 Question    : Squareroot of an int
 Example     : A=25 result:5
 ==============================================================================================================================
 */

#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

class Solution
{
public:
  int sqrt(int A);
}obj;

int Solution::sqrt(int A)
{     //A=25
     if (A == 0)
     {
     return 0;
     }

    int start = 1;
    int end = A; //end=25
    int result=0;
            while (start <= end) //1<=25 Y ...1<=11 Y.. 1<=5 Y ..4<=5 Y ..5<=5 Y
            {
                int mid = (start + end) / 2; // 12... 6.. 3..4..5
                cout<<"mid="<<mid<<endl;
                if (mid <= A / mid) // 12<= 25/12 N...6<=25/6 N..3<=25/3 Y..4<=6 Y..y
                {
                    start = mid + 1; // start = 4..start = 5..start=6
                    cout<<"start"<<start<<endl;
                    result = mid; //result =3 // 4 // 5
                    cout<<"result="<<result<<endl;
                }
                else
                {
                    end = mid - 1; // end = 11 .. end= 5
                }
            }
    return result;
}
int main()
{int result;
  result = obj.sqrt(25);
  cout<<"Square root of 25 : "<<result<<endl;
  return 0;
}

