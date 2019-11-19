#include <iostream>
#include <queue>
using namespace std;

//findLongestSubstring uses a queue[FIFO] based algorithm to find the longest subString
int findLongestSubstring(char a[],int n, int k) {
  queue <char> subString;
  int max = 0;
  int len = 0;
  int curDist = 0;
  int count[26] = {0};
  for(int i=0;i<n;i++) {
    subString.push(a[i]);
    if(count[a[i]-97] == 0) {
      curDist++;
    }
    count[a[i]-97]++;
    len++;
    if(curDist==k) {
      max=len;
    }
    else if(curDist>k) {

      count[subString.front()-97]--;
      if(count[subString.front()-97]==0) {
        curDist--;
      }
      len--;
      subString.pop();
    }
  }
  return max;
}

int main() {
  char a[] = "aaabbb";
  int k=3;
  int size = strlen(a);
  cout<<"The longest substring is of size "<<findLongestSubstring(a,size,k);
}
