package FirstMissingPositiveNumber;

import java.util.*;

class FirstMissingPositiveInteger
{

   static int findMissingPositiveInteger(int a[], int size) {
     for(int i=0;i<size;i++) {
       if(Math.abs(a[i])-1 < size && a[Math.abs(a[i])-1]>0) {
         a[Math.abs(a[i])-1] = -a[Math.abs(a[i])-1];
       }
     }
     for(int i=0;i<size;i++) {
       if(a[i]>0) {
         return i+1;
       }
     }
     return size+1;

   }

   static int segregate(int a[],int size) {
     int j=0;
     for(int i=0;i<size;i++) {
       if(a[i]<=0) {
         int temp = a[i];
         a[i] = a[j];
         a[j] = temp;
         j++;
       }
     }

     return j;
   }

  static int findMissingInteger(int a[], int size) {
     int positiveIndex = segregate(a,size);
     int b[] = new int[size - positiveIndex];
        int j = 0;
        for (int i = positiveIndex; i < size; i++) {
            b[j] = a[i];
            j++;
        }
      return findMissingPositiveInteger(b,j);
   }

    public static void main(String args[])
    {
        int a[] = { 2, 3, -7, 6, 8, 1, -10, 15 };
        int size = a.length;
        int result = findMissingInteger(a,size);
        System.out.println("The missing integer is " + result);
    }
}
