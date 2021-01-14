#include <iostream>

using namespace std;

 
int main(int argc, char *argv[])
{	
	int n;
	cin >> n;

	for(int i=1; i<=n; i++){
		int part = i;
		int res = i;
		while(part){
			res += part%10;
			part /= 10;
		}
		if(n == res){
			cout << i << endl;
			return 0;
		}
	}

	cout << "0" << endl;
	return 0;
}
