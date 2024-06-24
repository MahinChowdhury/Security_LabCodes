#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using namespace boost::multiprecision;

cpp_int qpow(cpp_int a, cpp_int b, cpp_int mod){

    a %= mod;
    cpp_int res = 1;
    while(b){
        if(b&1) res = (res*a)%mod;
        a = (a*a)%mod;
        b/=2;
    }

    return res%mod;
}

int main() {

	cpp_int p("22953686867719691230002707821868552601124472329079");
	cpp_int q("30762542250301270692051460539586166927291732754961");

	cout<<"Enter first message : ";
	cpp_int m1;cin>>m1;
	cout<<"Enter second message : ";
	cpp_int m2;cin>>m2;

	cpp_int n = p * q;
	cpp_int phi = (p-1)*(q-1);

	cpp_int e,d;
	cpp_int i;

	for(i=2 ; i<phi; i++) {
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


	cpp_int c1 = qpow(m1,e,n);
	cpp_int c2 = qpow(m2,e,n);

    //Get m1*m2 from prodcut cipher C.
	cpp_int c = c1*c2;
	cpp_int mm_dec = qpow(c,d,n);

	//Get m1 and m2 from c1 and c2

	cpp_int m1_old = qpow(c1,d,n);
	cpp_int m2_old = qpow(c2,d,n);

	//Product of m1 and m2 which we decrypted from c1 , c2
	cpp_int mm_old = m1_old*m2_old;



	cout<<mm_old<<" "<<mm_dec<<endl;

	if(mm_old == mm_dec) printf("Matched.\n");
	else printf("Didn\'nt matched.\n");


}


