#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using namespace boost::multiprecision;

int1024_t gcd(int1024_t a, int1024_t b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int1024_t modInverse(int1024_t a, int1024_t m) {
    int1024_t m0 = m, t, q;
    int1024_t x0 = 0, x1 = 1;

    if (m == 1)
        return 0;

    while (a > 1) {
        // q is quotient
        q = a / m;
        t = m;

        // m is remainder now, process same as Euclid's algo
        m = a % m, a = t;
        t = x0;

        x0 = x1 - q * x0;
        x1 = t;
    }

    // Make x1 positive
    if (x1 < 0)
        x1 += m0;

    return x1;
}

int1024_t powerMod(int1024_t base, int1024_t exp, int1024_t mod) {
    int1024_t result = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1)
            result = (result * base) % mod;
        exp = exp >> 1;
        base = (base * base) % mod;
    }
    return result;
}

int main() {
    int1024_t p, q, n, phi, e, d, msg;

    cout << "Enter prime numbers p and q: ";
    cin >> p >> q;
    cout << "Enter the message to be signed: ";
    cin >> msg;

    n = p * q;
    phi = (p - 1) * (q - 1);

    // Find e such that 1 < e < phi and gcd(e, phi) = 1
    for (e = 2; e < phi; e++) {
        if (gcd(e, phi) == 1)
            break;
    }

    // Compute d to satisfy d*e ≡ 1 (mod phi)
    d = modInverse(e, phi);

    cout << "Public Key: " << e << endl;
    cout << "Private Key: " << d << endl;

    // Message signing (encryption with private key)
    int1024_t signature = powerMod(msg, d, n);
    cout << "Message Signing: " << signature << endl;

    // Signature verification (decryption with public key)
    int1024_t verification = powerMod(signature, e, n);
    cout << "Sign Verification: " << verification << endl;

    return 0;
}
