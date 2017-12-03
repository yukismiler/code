#include <iostream>  
#include <stack>  
#include <queue>  
  
using namespace std;  
  
void HeapAdjust (int data[], int length, int k)  
{  
    int tmp = data[k];  
    int i=2*k+1;  
    while (i<length) {  
        if (i+1<length && data[i]<data[i+1]) //ѡȡ��С�Ľ��λ��  
            ++i;  
        if (tmp > data[i]) //���ý���  
            break;  
        data[k] = data[i]; //����ֵ  
        k = i; //��������  
        i = 2*k+1;  
    }  
    data[k] = tmp;  
}  
  
void HeapSort (int data[], int length)  
{  
    if (data == NULL || length <= 0)  
        return;  
    for (int i=length/2-1; i>=0; --i) {  
        HeapAdjust(data, length, i); //�ӵڶ��㿪ʼ����  
    }  
  
    for (int i=length-1; i>=0; --i) {  
        std::swap(data[0], data[i]);  
        HeapAdjust(data, i, 0); //�Ӷ��㿪ʼ����, �������һ��  
    }  
  
    return;  
}  
  
int main2 (void)  
{  
    int data[] = {49, 38, 65, 97, 76, 13, 27, 49};  
    int length = 8;  
    HeapSort(data, length);  
    for (int i=0; i<length; ++i) {  
        std::cout << data[i] << " ";  
    }  
  
    std::cout << std::endl;  
	system("pause");
    return 0;  
}  
