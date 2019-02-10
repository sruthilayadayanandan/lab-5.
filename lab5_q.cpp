#include<iostream>
using namespace std;

int partition(int ar[],int low,int high)
{
	int i=low;
	int temp,
	pivot=high;
	while(i<pivot)
	{
		if(ar[i]>ar[pivot])
		{	
			temp=ar[i];
			ar[i]=ar[pivot-1];
			ar[pivot-1]=ar[pivot];
			ar[pivot]=temp;
			pivot=pivot-1;
		}
		
		else 
		i++;
	}
	return pivot;
}

void QS(int ar[],int low,int high)
{
	if (low>=high)
	return;
	else
	{
		int k = partition(ar,low,high);
		QS(ar,low,k-1);
		QS(ar,k+1,high);
	}	
}

int main()
{
	int ar[10];
	int n;int i;
	cout<<"Enter the size of array";
	cin>>n;
	cout<<endl<<"Enter array elements";
	for(i=0;i<n;i++)
	cin>>ar[i];
	cout<<endl;
	QS(ar,0,n-1);
	cout<<"Printing sorted array"<<endl;
	for(i=0;i<n;i++)
	cout<<ar[i]<<" ";
	cout<<endl;
	return 0;
}