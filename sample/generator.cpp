#include "bits/stdc++.h"
using namespace std;
const int MAX = 3;
int main()
{
	int n=rand()%((int)1e5);
	cout<<"1\n";		//testcase
	cout<<n<<"\n";							// n  
	cout<<(rand()%(n*26))<<" "<<(rand()%(n*26))<<"\n";		// p q
	for(int i=0;i<n;i++)	cout<<'a'+rand()%26;
}