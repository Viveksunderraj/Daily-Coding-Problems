#include <stdio.h>
#include <string.h>

int findDecodings(char a[], int n) {
  if(n==0 || n==1) {
    return 1;
  }
  if(a[0]=='0') {
    return 0;
  }
  int count=0;
  if(a[n-1]>'0') {
    count = findDecodings(a,n-1);
  }

  if(a[n-1]<'7' && (a[n-2]=='1' || a[n-2]=='2')) {
    count+=findDecodings(a,n-2);
  }
  return count;
}

int main() {
  char a[]= "1234";
  int size = strlen(a);
  int result = findDecodings(a,size);
  printf("The possible decodinsg is %d\n", result);
}
