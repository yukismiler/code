#include<stdio.h>
#include<iostream>
using namespace std;

void HeapAdjust(int *data, int length, int k)
{
	int i = 2*k + 1;
	while(i < length)
	{
		if(i+1 < length && data[i] < data[i+1])
			i++;
		if(data[k] > data[i])
			break;
		int temp = data[k];
		data[k] = data[i];
		data[i] = temp;
		k = i;
		i = 2*k + 1;
	}
}
void HeapSort(int *data, int length)
{
	if(data == NULL || length <= 0)
		return;
	for(int i = length/2 - 1; i >= 0; --i)
	{
		HeapAdjust(data, length, i);
	}
	for(int i = length -1; i >=0; --i)
	{
		std::swap(data[0],data[i]);
		HeapAdjust(data, i, 0);
	}
}
int main1()
{
	int data[] = {4, 3, 6, 9, 7, 13, 27, 49};
	int length = 8;
	HeapSort(data, length);
	for(int i = 0; i < length; ++i)
	{
		cout<<data[i]<<",";
	}
	cout<<endl;
	system("pause");
	return 0;
}