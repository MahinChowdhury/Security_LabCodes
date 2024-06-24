#include<boost/multiprecision/cpp_int.hpp>
#include<bits/stdc++.h>

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

cpp_int inverse(cpp_int a, cpp_int n) {
    cpp_int t = 0, new_t = 1;
    cpp_int r = n, new_r = a;
    while (new_r != 0) {
        cpp_int quotient = r / new_r;
        t -= quotient * new_t;
        r -= quotient * new_r;
        swap(t, new_t);
        swap(r, new_r);
    }
    if (r > 1)
        throw "a is not invertible";
    if (t < 0)
        t += n;
    return t;
}

int main(){

    cout<<"Enter message1 : ";
    cpp_int m1;cin>>m1;
    cout<<"Enter message2 : ";
    cpp_int m2;cin>>m2;

    cpp_int mm = m1*m2;
    cout<<"Message Product : "<<mm<<endl;

    cpp_int p("100003100019100043100057100069");
    cpp_int g = 2;
    cpp_int r1 = 5;
    cpp_int r2 = 5;

    cpp_int x = 2;
    cpp_int y = 2;

    cpp_int h = qpow(g,x,p);

    cpp_int c11 = qpow(g,r1,p);
    cout<<"C11 : "<<c11<<endl;
    cpp_int c12 =  (m1 * qpow(h,r1,p))%p;
    cout<<"C12 : "<<c12<<endl;

    cpp_int m1_dec = (c12 * inverse(qpow(c11,x,p),p))%p;
    cout<<"Decrypted m1 : "<<m1_dec<<endl;

    cpp_int c21 = qpow(g,r2,p);
    cpp_int c22 = (m2 * qpow(h,r2,p))%p;

    cpp_int c1 =  (c11*c21)%p;
    cout<<"C1 : "<<c1<<endl;
    cpp_int c2 = ((m1*m2) * qpow(h,r1+r2,p))%p;
    cout<<"C2 : "<<c2<<endl;`

    cpp_int m2_dec = (c22 * inverse(qpow(c21,x,p),p))%p;
    cout<<"Decrypted m2 : "<<m2_dec<<endl;

    cpp_int mm_old = (m1_dec * m2_dec)%p;
    cout<<"Message of the product : "<<mm_old<<endl;


    cpp_int mm_dec = (c2 * (inverse(qpow(c1,x,p),p)))%p;

    cout<<"Decrypted message product : "<<mm_dec<<endl;

    if(mm == mm_dec){
        cout<<"Matched.\n";
    }
    else cout<<"Didn't matched.\n";

}
