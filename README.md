# Implementasi Algoritma RSA (C++)

## Logika Algoritma
1. **Pembangkitan Kunci**: 
   - $n = p \times q$ (Modulus)
   - $\phi = (p-1) \times (q-1)$ (Totient)
   - $e$ = Kunci Publik (untuk enkripsi)
   - $d$ = Kunci Privat (untuk dekripsi)
2. **Enkripsi**: $C = M^e \pmod n$
3. **Dekripsi**: $M = C^d \pmod n$

## Cara Menjalankan
1. **Kompilasi**:
   ```bash
   g++ -o rsa main.cpp
