#include "stdio.h"
#include "iostream"
using namespace std;

bool isEven(int input);
void RecoderOddEven(int data[],int length)
{
	if(data == NULL || length <= 0)
		return;
	int *pBegin = data;
	int *pEnd = data + length - 1;
	while(pBegin < pEnd)
	{
		while(pBegin < pEnd && !isEven(*pBegin))
		{
			pBegin++;
		}
		while(pBegin < pEnd && isEven(*pEnd))
		{
			pEnd--;
		}
		if(pBegin < pEnd)
		{
			int temp = *pBegin;
			*pBegin = *pEnd;
			*pEnd = temp;
		}
	}
}
bool isEven(int input)
{
	return ((input & 1) == 0);
}
int main()
{
	int data[] = {1,2,3,4,5,6,7,8,9,0};
	int len = sizeof(data)/sizeof(data[0]);
	RecoderOddEven(data,len);
	for(int i = 0; i < len; ++i)
	{
		cout<<data[i]<<',';
	}
	cout<<endl;
	system("pause");
	return 0;
}