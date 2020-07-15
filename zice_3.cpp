#include<stdio.h>
#include<iostream>
#include<cmath>
using namespace std;

int main(int argc, char const *argv[])
{
	int num;
	int k;
	int *a;
	a = new int[num];

	cin>>num>>k;
	for(int j=0;j<num;j++)
	{
		cin>>a[j];
	}

	k = k % num;

	for(int i=num-k;i<num;i++)
	{
		cout<<a[i]<<' ';
	}

	for(int i=0;i<num-k-1;i++)
	{
		cout<<a[i]<<' ';
	}

	cout<<a[num-k-1];

	delete []a;

	return 0;
}
