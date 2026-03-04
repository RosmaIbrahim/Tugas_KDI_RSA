#include <iostream>
#include <vector>

// Perpangkatan Modulo
long long power(long long base, long long exp, long long mod) {
    long long res = 1;
    base %= mod;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return res;
}

int main() {
    // --- LANGKAH DASAR PEMBUATAN KUNCI ---
    long long p = 61, q = 53;      // Dua bilangan prima
    long long n = p * q;           // Modulus (3233)
    long long phi = (p-1) * (q-1); // Totient (3120)
    long long e = 17;              // Kunci Publik (e)
    long long d = 2753;            // Kunci Privat (d) - (Hasil dari: d*e % phi = 1)

    std::cout << "1. Modulus (n) = " << n << "\n";
    std::cout << "2. Totient (phi) = " << phi << "\n";
    std::cout << "3. Kunci Publik (e) = " << e << "\n";
    std::cout << "4. Kunci Privat (d) = " << d << "\n\n";

    // PLAINTEXT
    std::cout << "Plaintext = KDI "<< std::endl;
    
    // --- PROSES ENKRIPSI ---
    std::string msg = "KDI";
    std::vector<long long> ct;
    std::cout << "Enkripsi (M^e % n):\n";
    for (char m : msg) {
        long long c = power(m, e, n);
        ct.push_back(c);
        std::cout << m << " -> " << c << "\n";
    }

    // --- PROSES DEKRIPSI ---
    std::cout << "\nDekripsi (C^d % n):\nResult: ";
    for (long long c : ct) {
        std::cout << (char)power(c, d, n);
    }
    std::cout << "\n";

    return 0;
}
