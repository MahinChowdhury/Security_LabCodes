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

    cout<<"Enter a message : ";

    cpp_int m;
    cin>>m;

    cpp_int p("100003100019100043100057100069");
    cpp_int g = 2;
    cpp_int x = 5;
    cpp_int h = qpow(g,x,p);
    cpp_int y = 5;

    cpp_int s = qpow(h,y,p);
    cpp_int c1 = qpow(g,y,p);
    cpp_int c2 = (m*s)%p;

    //cout<<c1<<endl;
    //cout<<c2<<endl;

    cpp_int cur = qpow(c1,x,p);
    cpp_int tmp = inverse(cur,p);
    cpp_int ans = (c2 * tmp)%p;

    cout<<"Your decrypted message is : ";
    cout<<ans<<endl;

    if(ans == m) cout<<"Matched.\n";

}
