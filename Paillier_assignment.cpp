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

cpp_int lcm(cpp_int a,cpp_int b){
    cpp_int mul = a*b;
    cpp_int g = __gcd(a,b);

    cpp_int res = mul/g;
    return res;
}

cpp_int L(cpp_int x,cpp_int n){
    cpp_int res = (x-1)/n;
    return res;
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
    cpp_int msg;
    cin>>msg;

    cout<<"Plain Text : "<<msg<<endl;

    //Key generation
    cpp_int p("1900871281664822113126851573935413975471896789968515493666638539088027103802104498957191261465571");
    cpp_int q("1744422866791789587515739091745736846125647110690784971130912224240053649684502779174107135286841");

    cpp_int n = p*q;
    cpp_int lembda = lcm(p-1,q-1);

    cpp_int g = 10;

    cpp_int mu = inverse(L(qpow(g,lembda,(n*n)),n),n);
    //cout<<mu<<endl;

    //Encryption :

    cpp_int r=1;
    while(__gcd(r,n)!=1){
        r++;
    }

    cpp_int fi = qpow(g,msg,n*n);
    cpp_int se = qpow(r,n,n*n);
    cpp_int c = (fi*se)%(n*n);
    cout<<"Cipher Text : "<<c<<endl;

    // Decryption :

    cpp_int dec = L(qpow(c,lembda,(n*n)),n);
    cpp_int mm = (dec*mu)%n;

    cout<<"Decrypted Text : "<<mm<<endl;

    //Checking

    if(msg == mm){
        cout<<"Decrypted text matched the message\n";
    }
    else{
        cout<<"Didn\'t matched\n";
    }

}
