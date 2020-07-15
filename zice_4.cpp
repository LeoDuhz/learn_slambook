#include<stdio.h>
#include<iostream>
#include<cmath>
using namespace std;

int main(int argc, char const *argv[])
{
	unsigned long number;
	unsigned long num3;
	double input;
	cin>>input;
	if(input>4294967295)
	{
		number = (int)(input / 1000000000);
		num3 = (int)(input - number * 1000000000);
	}else
	{
		number = input;
		num3 = input;
	}
	
	cout<<number<<' '<<num3;

	int x;
	unsigned long num = number;
	int c[10] = {13};

	while(1)
	{
		x = num % 10;
		c[x] = x;
		num = num / 10;
		if(num == 0) break;
	}

	unsigned long num2 = number * 2;

	while(1)
	{
		x = num2 % 10;
		if(x != c[x])
		{
			cout<<"No"<<endl;
			cout<<number*2<<endl;
			return 0;
		}
		num2 = num2 / 10;
		if(num2 == 0) break;
	}
	cout<<"Yes"<<endl;
	cout<<number*2<<endl;

	return 0;
}