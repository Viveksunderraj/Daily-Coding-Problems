#include <stdio.h>

int max(int a, int b) {
  return(a>b?a:b);
}
int findLargestSum(int a[],int n) {
  int maxSum[n];
  maxSum[0]=a[0];

  for (int i=1;i<n;i++) {
    if(i>=2)
    maxSum[i] = max(a[i]+maxSum[i-2],maxSum[i-1]);

    else
    maxSum[i] = max(a[i],maxSum[i-1]);
  }
  return (maxSum[n-1]);
}

int main() {
  int a[] = {5, -1, -1, 0, 100};
  int size = sizeof(a)/sizeof(a[0]);
  printf("The largest maximum sum is %d",findLargestSum(a,size));
}
