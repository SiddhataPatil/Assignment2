/*
 ==============================================================================================================================
 Name        : main.cpp
 Author      : Siddhata Patil
 Copyright   : Copyright © InterviewBit for the question.
 Copyright   : Copyright ©  Siddhata Patil. Sourcecode rights reserved.
 Question    : Search for range in a sorted array
 Example     : For A[6] = {5, 7, 7, 8, 8, 10} Range for no. 7 is [ 1  2  ]
 ==============================================================================================================================
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  vector<int> searchRange(const vector<int> &A, int B);
}obj;

vector<int> Solution::searchRange(const vector<int> &A, int B)
{
        int number_whose_range_is_to_be_found = B;
        int array_size = A.size();
        int start = 0;
        int end = array_size - 1;
        vector<int> result(2, -1);
        // Search for the left one

        while (start < end)
        {
            int mid = (start + end) /2;
            if (A[mid] < number_whose_range_is_to_be_found)
              {
                start = mid + 1;
              }
            else
            {
              end = mid;
            }
        }

        if (A[start]!=number_whose_range_is_to_be_found)
        {
          cout<<"*************"<<endl;
          return result;
        }

        else
        {
          result[0] = start;
        }
        // Search for the right one
        end = array_size-1;  // We don't have to set i to 0 the second time.

        while (start < end)
        {
            int mid = (start + end) /2 + 1;   // Make mid biased to the right
            if (A[mid] > number_whose_range_is_to_be_found)
            {
              end = mid - 1;
            }
            else
            {
              start= mid;               // So that this won't make the search range stuck.
            }
        }

        result[1] = end;
        return result;
    }

int main()
{	int A1[6] = {5, 7, 7, 8, 8, 10};
	vector<int> A(A1, A1+sizeof(A1)/sizeof(A1[0]));
  vector<int>result;
  result = obj.searchRange(A, 7);
  cout<<"For A[6] = {5, 7, 7, 8, 8, 10}"<<endl;
  cout<<"Range for no. 7 is "<<endl;
  cout<<"[ ";
  for(int i=0; i<result.size();i++)
  {
    cout<<result[i]<<"  ";
  }
  cout<<"]"<<endl;
  return 0;
}
