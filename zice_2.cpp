#include<stdio.h>
#include<iostream>
#include<cmath>
using namespace std;

int test(int i)
{
	if(i <= 1)
		return 0;
	if(i == 2)
		return 1;
	if(i % 2 == 0)
		return 0;
	for(int k=3;k<sqrt(i)+1;k=k+2)
	{
		if(i%k == 0) return 0;
	}
	return 1;
}

int main(int argc, char const *argv[])
{
	int num;
	cin>>num;

	int count = 0;
	for(int i=3;i<=num;i=i+2)
	{
		if(test(i))
		{
			if(test(i-2))
				count++;
		}
	}

	cout<<count<<endl;

	return 0;
}

