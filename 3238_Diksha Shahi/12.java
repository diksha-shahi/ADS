//heap and shell sort

import java.util.Scanner;

class HeapSort
{

 void sort(int arr[],int len)
 {
  int i;
  for(i=len/2-1; i>0; i--)
   heapify(arr,len,i);
   
  for(int j=len-1; j>=0; j--)
  {
   int temp=arr[0];
   arr[0]=arr[i];
   arr[i]=temp;
   
   heapify(arr,j,0);
  } 
}
 
 void heapify(int arr[],int len,int i)
 {
  int max=i;
  int left =2*i+1;
  int right=2*i+2;
  
  if(left<len && arr[left]>arr[max])
    max=left;
    
  if(right<len && arr[right]>arr[max])
    max=right;
    
  if(max!=i)		//largest not root
  {
   int temp1 = arr[i];
   arr[i]=arr[max];
   arr[max]=temp1;
   
   heapify(arr,len,max);
  }
 }

 
}


class ShellSort
{
 void ssort(int arr[],int len)
 {
  for(int gap=len/2;gap>0;gap=gap/2)
  {
   for(int i=gap;i<len;i++)
   {
    int temp=arr[i];
    int j;
    for(j=i; j>=gap && arr[j-gap]>temp; j -=gap)
      arr[j]=arr[j-gap];
      
    arr[j]=temp;   
   }
  }
 }

}


class Sorting
{


 static void display(int arr[],int len)
 {
  for(int i=0;i<len;i++)
   System.out.print(arr[i]+" ");
 }


 public static void main(String args[])
 {
  Scanner scan = new Scanner(System.in); 
  System.out.println("total nos.: ");
  int len = scan.nextInt();
  int arr[] = new int[len];
  
  
  System.out.println("Input array elements");
  System.out.println();
  
  for(int j=0;j<len;j++)
  {
    arr[j] = scan.nextInt();
  }
  
  System.out.println("1.Heap Sort");
  System.out.println("2.Shell Sort");
  System.out.println("Enter choice: ");
  int ch = scan.nextInt();
  
  switch(ch)
  {
   case 1:
   	HeapSort h = new HeapSort();
  	h.sort(arr,len);
  	Sorting.display(arr,len);
  	break;

   case 2:
   	ShellSort s = new ShellSort();
   	s.ssort(arr,len);
   	Sorting.display(arr,len);
   	break;
  }
 
 }


}



