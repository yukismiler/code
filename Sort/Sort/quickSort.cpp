#include<stdio.h>
#include<iostream>
using namespace std;

int partion(int *arr, int start, int end)
{
	int x = start;
	int y = end;
	int Index = arr[start];
	while(x < y)
	{
		while(x < y && arr[y] >= Index)
		{
			y--;
		}
		if(x < y)
		{
			arr[x] = arr[y];
			x++;
		}
		while(x < y && arr[x] <= Index)
		{
			x++;
		}
		if(x < y)
		{
			arr[y] = arr[x];
			y--;
		}
	}
	arr[x] = Index;
	return x;
}
void quickSort(int *arr,int low,int high)
{
	if(low >= high)
		return;
	int j = partion(arr, low, high);
	quickSort(arr,low,j-1);
	quickSort(arr,j+1,high);
}
int main()
{
	int array[] = {24,2,56,23,6,7,9};
	quickSort(array, 0, 6);
	for(int i = 0; i < 7; ++i)
		cout<<array[i]<<",";
	cout<<endl;
	system("pause");
	return 0;
}