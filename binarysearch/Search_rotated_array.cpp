/*
 ==============================================================================================================================
 Name        : main.cpp
 Author      : Siddhata Patil
 Copyright   : Copyright © InterviewBit for the question.
 Copyright   : Copyright ©  Siddhata Patil. Sourcecode rights reserved.
 Question    : You are given a target value to search. If found in the array, return its index, otherwise return -1.
 Example     : (i.e., 0 1 2 4 5 6 7  might become 4 5 6 7 0 1 2 ). Input : [4 5 6 7 0 1 2] and target = 4 o/p=0
 ==============================================================================================================================
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  int search(const vector<int> &A, int B)  ;
}obj;

int find(const vector<int> &A, int number_to_be_searched , int start, int end){
    while(start<=end)
    {
        int mid=(start+end)/2;
        if(A[mid]==number_to_be_searched) return mid;
        if(A[mid]<number_to_be_searched) start=mid+1;
        else end=mid-1;
    }
    return -1;
}

int Solution::search(const vector<int> &A, int B) {
    int number_to_be_searched = B;
    int start=0;
    int end=A.size()-1;
    while(start<=end)
    {
        if(A[start]<=A[end])
        {
          return find(A, number_to_be_searched , start, end);
        }

        int mid = (start+end)/2;

        if(A[start]<A[mid])
        {
            if(A[start]<=B && B<=A[mid])
            {
              end=mid;
            }
            else start=mid+1;
        }
        else
        {
            if(A[mid+1]<=B && B<=A[end])
            {
               start=mid+1;
            }
            else end=mid;
        }
    }
    return -1;
}
int main()
{
  int A1[7] = {4 ,5, 6, 7, 0, 1, 2};
  vector<int> A(A1,A1+sizeof(A1)/sizeof(A1[0]));
  int result=0;
  result = obj.search(A,7);
  cout<<"In A1[7] = {4 ,5, 6, 7, 0, 1, 2} "<<endl;
  cout<<"7 is found at Index =  ";
  cout<<result<<endl;
  return 0;
}
