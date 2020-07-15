#include<stdio.h>
#include<iostream>
using namespace std;

int main()
{
	int num;
	char ch;
	cin>>num>>ch;

	int k=0;
	while(1)
	{
		if(num<2*k*k-1)
		{
			k--;
			break;
		}
		k++;
	}


	for(int i=0;i<k;i++)
	{
		for(int j=0;j<i;j++)
		{
			cout<<' ';
		}

		for(int j=0;j<2*k-1-2*i;j++)
		{
			cout<<ch;
		}

		
		cout<<endl;
	}

	for(int i=k-2;i>=0;i--)
	{
		for(int j=0;j<i;j++)
		{
			cout<<' ';
		}

		for(int j=0;j<2*k-1-2*i;j++)
		{
			cout<<ch;
		}

		
		cout<<endl;
	}
	cout<<num-2*k*k+1<<endl;
	


}




*****
 ***
  *
 ***
*****
2

*****
 *** 
  *  
 *** 
*****
2