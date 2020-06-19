//This is The Coding Area
#include<iostream>
#include <vector>
using namespace std;

vector<long long> extended_euclid_gcd(long long a, long long b) {
    long long s = 0; long long old_s = 1;
    long long t = 1; long long old_t = 0;
    long long r = b; long long old_r = a;

    while(r != 0) {
        long long quotient = old_r/r;
        long long temp = r;
        r = old_r - quotient*r;
        old_r = temp;
        temp = s;
        s = old_s - quotient*s;
        old_s = temp;

        temp = t;
        t = old_t - quotient*t;
        old_t = temp;
    }
    vector<long long> result;
    result.push_back(old_r);
    result.push_back(old_s);
    result.push_back(old_t);
    return result;
}

long long modulo(long long A, long long M) {
    vector<long long> v = extended_euclid_gcd(A, M);

    long long gcd = v[0];
    long long x = v[1];
    long long y = v[2];

    if(x < 0) {
        x += M;
    }
    
    return x;
}

int GCD(int x, int y){
	if(x == 1 || y == 1)
		return 1;
	while(x != y){
		if (x > y)
			x = x -y;
		else
			y = y-x;
	}
	return x;
}

bool coPrime(int x, int y){
	if(GCD(x, y) == 1)
		return true;
	else
		return false;
}

int main(){
	int N,T,M;
	cin>>N;
  	cin>>T;
  	cin>>M;
	
	if(coPrime(M, T)){
		long long mod = 1000000007;
		long long q = modulo(T, mod);
		long long p = M * q;
		cout<<p%mod<<"\n";
	}else{
    	cout<<M/T<<"\n";
    }

	return 0;
}