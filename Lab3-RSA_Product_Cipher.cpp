#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using namespace boost::multiprecision;

int main() {
	int1024_t p, q, n, phi, i, j, e, d, m1, m2, m=1, mm1=1, mm2=1, cc =1,  c1, c2, cc1 = 1, cc2 = 1, c;
	 
	cin>>p>>q;
	
	n = p * q;
	phi = (p-1)*(q-1);
	
	i = 2;
	
	for(i; i<phi; i++) {
		if(gcd(i, phi)==1) {
			e = i;
			break;
		}
	}
	
	cout<<"e : "<<e<<endl;
	
	for(i = 1; ; i++) {
		if((1+i*phi)%e == 0) {
			d = (1+i*phi)/e;
			break;
		}
	}
	
	cout<<"d : "<<d<<endl;
	
	m1 = 12;
	m2 = 15;
	
	cout<<"m1, m2, m = "<<m1<<", "<<m2<<", "<<m1*m2<<endl;
	
	for(int i=1; i<=e; i++) {
		mm1 *= m1;
		mm2 *= m2;
	}
	
	c1 = mm1 % n;
	c2 = mm2 % n;
	
	c = (mm1 * mm2) % n;
	
	cout<<"c = "<<c<<", c1 = "<<c1<<", c2 = "<<c2<<endl;	
	
	for(int i=1; i<=d; i++) {
		cc1 *= c1;
		cc2 *= c2;
		cc *= c;
	}
	
	// cout<<cc2<<endl;
	
	m1 = cc1 % n;
	m2 = cc2 % n;
	m = cc % n;
	
	cout<<"m = "<<m<<", m1 = "<<m1<<", m2 = "<<m2<<endl;;
}


