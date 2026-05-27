```markdown
# DSA & C++ Quick Reference Notes

---
## C++ String / Character Operations Notes
Header
#include <cctype>
Character Checks
isupper(c)     // A-Z
islower(c)     // a-z
isalpha(c)     // alphabet
isdigit(c)     // 0-9
isalnum(c)     // alphabet or digit
isspace(c)     // space/newline/tab
ispunct(c)     // punctuation
isxdigit(c)    // hexadecimal char

Example:

if(isupper(c)) ...
Character Conversion
toupper(c)     // convert to uppercase
tolower(c)     // convert to lowercase

Example:

c = toupper(c);
ASCII Tricks
'A' -> 65
'a' -> 97

'a' - 'A' = 32

Lowercase to uppercase:

c -= 'a' - 'A';

Uppercase to lowercase:

c += 'a' - 'A';
String Input
string s;
cin >> s;          // single word
getline(cin,s);    // full line
Size / Empty
s.size()
s.length()
s.empty()
Access
s[i]
s.front()
s.back()
Modify
s.push_back(c)
s.pop_back()

s += "abc"
s.append("abc")

s.clear()
Substring
s.substr(pos,len)

Example:

s.substr(2,3)
Find
s.find(x)
s.rfind(x)

Returns:

string::npos

if not found.

Erase / Insert / Replace
s.erase(pos,len)

s.insert(pos,str)

s.replace(pos,len,str)
Reverse
reverse(all(s));
Sort
sort(all(s));
sort(rall(s));
Count
count(all(s),'a')
Unique Characters
sort(all(s));
s.erase(unique(all(s)), s.end());
Convert

String → int

stoi(s)
stoll(s)

Int → string

to_string(x)
Lexicographic Compare
if(a < b)

Dictionary order.

Iterate
for(char c : s)

for(char &c : s)

Use & to modify.

Useful Algorithms
reverse(all(s))

sort(all(s))

next_permutation(all(s))

prev_permutation(all(s))
Palindrome Check
string t = s;
reverse(all(t));

if(t == s)
Frequency Array
vi freq(26);

for(char c : s)
    freq[c-'a']++;
Common CP Tricks
Toggle Case
c ^= 32;
Check lowercase
if('a' <= c && c <= 'z')
Check uppercase
if('A' <= c && c <= 'Z')
Character to digit
int x = c - '0';
Digit to character
char c = x + '0';
# Median Tricks for CP

### 1. Median minimizes absolute deviation
\[
\sum |a_i - x|
\]
is minimized when:
\[
x = \text{median}
\]

---

### 2. Median ≥ x transformation
For odd-length subarrays:

```text
b[i] = +1 if a[i] >= x
       -1 otherwise
```

Then:

\[
\text{median} \ge x
\iff
\sum b_i > 0
\]

Converts median problems into prefix sum problems.

---

### 3. Median = x condition
For odd length segment:

\[
\text{median} = x
\]

iff

```text
count(<x) <= len/2
count(>x) <= len/2
```

Equivalent:

```text
count(<=x) > len/2
count(>=x) > len/2
```

---

### 4. Median is kth smallest
Median is simply:

\[
k = \lfloor n/2 \rfloor
\]

smallest element after sorting.

Useful for:
- order statistics
- nth_element
- PBDS
- quickselect

---

### 5. Running Median
Maintain:
- max heap = left half
- min heap = right half

Invariant:

```text
|size(L)-size(R)| <= 1
```

Median:
- odd → top of larger heap
- even → depends on definition
## compare fractions

// Struct to compare fractions using cross-multiplication safely
struct Frac {
    int num, den;
    bool operator<(const Frac& o) const {
        return num * o.den < o.num * den;
    }
};

## solving regular bracket questions

- open brackets >= closed brackets while going left to right
- if n is odd not possible
-Balance Method

balance += 1 for '('
balance -= 1 for ')'

Invalid if:
- balance < 0 at any point
- final balance != 0
- Final balance must be 0, Number of '(' == number of ')'
- Catalan Number
Number of valid bracket sequences of length 2n:
C_n = (1/(n+1)) * (2n choose n)

## lucas theorum
bool odd_nCr(long long n, long long r) {
    return (r & n) == r;
}
bool divisible(long long n, long long r, int p) {
    while (n || r) {
        if (r % p > n % p)
            return true;   // divisible by p

        n /= p;
        r /= p;
    }
    return false;
}


## 1. 1D,2D mapping
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 4, m = 5; // grid size

    int i = 2, j = 3;

    // 2D -> 1D
    int id = i * m + j;
    cout << "1D index: " << id << "\n";

    // 1D -> 2D
    int x = id / m;
    int y = id % m;
    cout << "2D index: (" << x << ", " << y << ")\n";
}

## 1. Mathematics & Number Theory

### 1.1 Divisibility
- `ℓ, ℓ+1, ℓ+2, …, ℓ+n` is divisible by `1, 2, 3, …, n` (any n+1 consecutive integers)
- `(x+1) % x ≠ 0` for any `x ≠ 1`


- if D | x*y   means D divides xy
then D= d1*d2 where d1|x && d2|y



### 1.2 Sum Formulas
| Formula | Value |
|---|---|
| Σ i (i=1 to n) | n(n+1)/2 |
| Σ i² | n(n+1)(2n+1)/6 |
| Σ i³ | [n(n+1)/2]² |
| Sum of k consecutive integers from a to b | k(a+b)/2 |

**AP Sum:**
```
S = (n/2) × [2a + (n-1)d]
With d=1:  S = (n/2)(a + last_term)
```

### 1.3 GP Sum
```
S = a × (1 - rⁿ) / (1 - r)
```

### 1.4 Consecutive Choices
- Number of ways to choose K consecutive days out of n days = `n - K + 1`

### 1.5 Divisor Counting
```
Count divisible by a           = floor(n/a)
Count divisible by b           = floor(n/b)
Count divisible by both a & b  = floor(n/lcm(a,b))
Count divisible by a OR b      = floor(n/a) + floor(n/b) - floor(n/lcm(a,b))
```

### 1.6 Logarithm Identities
- `ln 2 = 1 - 1/2 + 1/3 - 1/4 + …`  (alternating harmonic series)
- `1 + 1/2 + 1/3 + … + 1/n = Hₙ ≈ ln(n) + γ`  (γ ≈ 0.5772, Euler–Mascheroni constant)

### 1.7 Trailing Zeros / Factor Count in n!
```
Times prime p divides n! = floor(n/p) + floor(n/p²) + floor(n/p³) + …
e.g. times 5 is factor in n! = floor(n/5) + floor(n/25) + floor(n/125) + …
```

### 1.8 Modular Arithmetic
```
(a + b) mod n = ((a mod n) + (b mod n)) mod n
(a - b) mod n = ((a mod n) - (b mod n) + n) mod n   ← add n to avoid negative
(a * b) mod n = ((a mod n) * (b mod n)) mod n
(a + b) % d   = (a%d) + (b%d)
(a - b) % d   = (a%d) - (b%d)
x % x = 0
```

### 1.9 Fermat's Little Theorem
```
If p is prime and gcd(a, p) = 1:
    a^(p-1) ≡ 1 (mod p)
    a^(p-2) ≡ a⁻¹ (mod p)    ← modular inverse

To compute a/b mod p  →  a * pow(b, p-2, p) % p
```

### 1.10 Coin Problem (Chicken McNugget Theorem)
```
For positive a, b with g = gcd(a, b):

If gcd(a, b) = 1:
    Largest number NOT expressible as x*a + y*b  =  a*b - a - b
    All integers > a*b - a - b are expressible

If gcd(a, b) = g > 1:
    Only multiples of g are expressible
```

### 1.11 Tower of Hanoi
```
H(n) = 2*H(n-1) + 1
H(n) = 2ⁿ - 1    (closed form)
```

---

## 2. Bit Manipulation

### 2.1 Bitwise Identities
| Expression | Result |
|---|---|
| `a ^ 0` | `a` |
| `a ^ 1` | `~a` (flips bit) |
| `a ^ a` | `0` |
| `a ^ ~a` | all 1s |
| `0^0, 1^1` | `0` |
| `0^1, 1^0` | `1` |

### 2.2 XOR of 1..n (Cyclic Pattern)
```
n % 4 == 0  →  xor(1..n) = n
n % 4 == 1  →  xor(1..n) = 1
n % 4 == 2  →  xor(1..n) = n + 1
n % 4 == 3  →  xor(1..n) = 0

Range XOR [L..R] = xor(1..R) ^ xor(1..L-1)
```

**Common XOR values:**
`0^1=1, 1^2=3, 3^4=7, 5^6=3, 4^5=1, 6^7=1`

> ⚠️ **Operator Precedence Bug:**
> ```cpp
> // WRONG  → == binds tighter than ^
> if (a ^ b == c)
> // CORRECT
> if ((a ^ b) == c)
> ```

### 2.3 Bit Pattern Generation
| Operation | Code |
|---|---|
| All K bits set to 1 (e.g. `111`) | `(1LL << K) - 1` |
| Only i-th bit set | `(1LL << i)` |
| Clear i-th bit | `x & ~(1LL << i)` |
| Toggle i-th bit | `x ^ (1LL << i)` |
| Check if i-th bit is set | `x & (1LL << i)` |
| Set i-th bit | `x \|= (1LL << i)` |
| Clear last K bits | `x & (~0LL << K)` |
| All bits = 0 | `0` |
| All bits = 1 (64-bit) | `~0LL` |

### 2.4 Multiply Without `*`
```cpp
int multiply(int a, int b) {
    int res = 0;
    while (b > 0) {
        if (b & 1) res += a;
        a <<= 1;
        b >>= 1;
    }
    return res;
}
```

### 2.5 Add Without `+`
```cpp
int add(int a, int b) {
    while (b != 0) {
        int carry = a & b;
        a = a ^ b;
        b = carry << 1;
    }
    return a;
}
```

### 2.6 XOR Swap
```cpp
a = a ^ b;
b = a ^ b;
a = a ^ b;
```

### 2.7 Binary Representation Tricks
```
num % 10^i  = last i decimal digits of num
num % 2^i   = last i bits of num
num / 2^i   = remove last i bits (right shift by i)
x % 2^i     = x & (2^i - 1)      ← bitmask trick

Example:
  (1011)₂ % 2¹ = 1
  (1011)₂ % 2² = (11)₂ = 3
  (1011)₂ % 2³ = (011)₂ = 3
  1101 % 4 = 01  (last 2 bits)
  1101 / 4 = 11  (remove last 2 bits)
```

**Prefix XOR + bit tricks:**
```
x % 2^i     → bottom i bits
x / 2^i     → remove bottom i bits
x ≡ k mod 2^i  means last i bits = k  →  x = m×2^i + k
x & 2^i == x << i
```

### 2.8 Reverse Bits (32-bit)
```cpp
int reverseBits(int n) {
    int rev = 0;
    for (int i = 0; i <= 31; i++) {
        rev <<= 1;
        rev = rev | (n & 1);
        n >>= 1;
    }
    return rev;
}
```

### 2.9 Gray Code
```cpp
int gray = i ^ (i >> 1);
```

### 2.10 Built-in Functions
| Function | Purpose |
|---|---|
| `__builtin_popcount(x)` | Count set bits (32-bit) |
| `__builtin_popcountll(x)` | Count set bits (64-bit) |
| `__builtin_ctz(x)` | Count trailing zeros — e.g. `100₂` → 2 |
| `__builtin_ctzll(x)` | Count trailing zeros (64-bit) |
| `__builtin_clz(x)` | Count leading zeros |

### 2.11 Check Power of 2
```cpp
// x is power of 2  iff:
x > 0 && (x & (x - 1)) == 0
```

### 2.12 nCr via Pascal's Triangle
```cpp
int nCr[32][32];
nCr[0][0] = 1;
for (int i = 1; i <= 31; i++) {
    for (int j = 0; j <= i; j++) {
        if (j == 0 || j == i)
            nCr[i][j] = 1;
        else
            nCr[i][j] = nCr[i-1][j-1] + nCr[i-1][j];
    }
}
```

---

## 3. GCD & LCM

### Properties
| # | Property |
|---|---|
| 1 | `gcd(b₁,b₂,…,bₙ) ≤ gcd(b₁+b₂, b₃, …, bₙ)` |
| 2 | `gcd(a, b) = gcd(a, b ± k*a)` for any k ∈ Z |
| 3 | `gcd(ka, kb) = |k| * gcd(a, b)` |
| 4 | `gcd(a₁,…,aₙ) ≤ gcd(a₁+b, a₂+b, …, aₙ+b)` |
| 5 | If `d = gcd(a₁,a₂,a₃)` then `d \| x₁a₁+x₂a₂+x₃a₃` for x ∈ Z |
| 6 | `gcd(a, b) = gcd(b, a mod b)` ← Euclidean algorithm |
| 7 | `gcd(a, b) ≤ min(\|a\|, \|b\|)` |

---

## 4. Arrays & STL

### 4.1 Prefix Sum
```
if prefix_sum[0] = 0 (1-indexed):
    Sum of first K elements  = prefix_sum[K]
    Sum from a to b          = prefix_sum[b] - prefix_sum[a-1]
```

### 4.2 Sorting
```cpp
sort(a.begin(), a.end());      // same as sort(a, a+n) for arrays

// Sort vector of pairs by 2nd element — lambda (preferred)
sort(v.begin(), v.end(), [](const pair<int,int>& a, const pair<int,int>& b) {
    return a.second < b.second;
});

// With static comparator
static bool cmp(pair<int,int>& a, pair<int,int>& b) {
    return a.second < b.second;
}
sort(v.begin(), v.end(), cmp);
```

### 4.3 Useful STL Calls
| Call | Effect |
|---|---|
| `count(a.begin(), a.end(), 4)` | Count frequency of 4 |
| `next_permutation(s.begin(), s.end())` | Advance to next permutation; returns false on last |
| `.clear()` | Erase all elements of vector / set / map |
| `arr.insert(arr.begin() + pos, val)` | Insert val at index pos |
| `upper_bound(all(arr), r) - lower_bound(all(arr), l)` | Count elements in [l, r] |

### 4.4 next_permutation Details
```cpp
string s = "abc";
next_permutation(s.begin(), s.end());
// s → "acb"  (returns true)
// On last permutation "cba", wraps to "abc" and returns false
```

### 4.5 Insert in Middle
```cpp
vector<int> arr = {1, 2, 4, 5};
arr.insert(arr.begin() + 2, 3);
// arr = {1, 2, 3, 4, 5}
```

### 4.6 Iterate Map in Reverse
```cpp
for (auto it = mp.rbegin(); it != mp.rend(); ++it)
    cout << it->first << " " << it->second;
```

### 4.7 Count Freq of Elements (Counting & Reset)
```cpp
int c = 1;
for (int i = 1; i < n; i++) {
    if (a[i] == a[i-1]) c++;
    else c = 1;
    // use c here (current run length)
}
```

---

## 5. Strings

### 5.1 string::find
```cpp
string s = "hello";
size_t pos = s.find("ll");     // returns 2
if (pos != string::npos) { /* found */ }
// Not found → returns string::npos
```

### 5.2 String from Char
```cpp
char ch = 'z';
string s1 = string(1, ch);    // "z"
string s2 = string(5, ch);    // "zzzzz"
```

### 5.3 s.append
```cpp
s.append(n, ch);   // appends ch exactly n times
```

### 5.4 Binary String → Integer
```cpp
string s = "1011";
int num = stoi(s, nullptr, 2);   // base 2 → 11
// stoi(s, nullptr, 16) for hex
```

### 5.5 Format String (C++20)
```cpp
#include <format>
string result = format("Name: {}, Age: {}", name, age);
```

---

## 6. Algorithms

### 6.1 Kadane's Algorithm — Max Subarray Sum
```cpp
// arr = [-2,-3,4,-1,-2,1,5,-3]  →  answer = 7
int maxi = INT_MIN, sum = 0;
for (int i = 0; i < n; i++) {
    sum += arr[i];
    maxi = max(maxi, sum);
    if (sum < 0) sum = 0;
}
return maxi;
```

### 6.2 Max Subarray Sum — Prefix Sum Approach
```cpp
int pref = 0, min_pref = 0, ans = 0;
for (int i = 0; i < n; i++) {
    pref    += a[i];
    ans      = max(ans, pref - min_pref);
    min_pref = min(min_pref, pref);
}
cout << ans;
```

### 6.3 Count Pairs with Difference K
```cpp
int countPairs(vector<int>& arr, int k) {
    set<int> s(arr.begin(), arr.end());
    int cnt = 0;
    for (int num : s)
        if (s.count(num + k)) cnt++;
    return cnt;
}
```

### 6.4 Sweep Line (Interval Problems)
```
e.g. Maximum overlapping intervals at any point:
→ Treat start as +1, end as -1
→ Sort all events
→ Maintain running count, track maximum

Time: O(n log n)  |  Better for large ranges
```

### 6.5 Ternary Search — O(log₃ n)
```cpp
while (r - l > 3) {
    int mid1 = l + (r - l) / 3;
    int mid2 = r - (r - l) / 3;
    if      (key < arr[mid1]) r = mid1 - 1;
    else if (key > arr[mid2]) l = mid2 + 1;
    else { l = mid1 + 1; r = mid2 - 1; }
}
// Then linear scan [l..r]
```

### 6.6 Min Swaps to Sort Array
```
For distinct elements:
  Min swaps = n − (number of cycles in permutation)
  Each cycle of length k needs k−1 swaps
```

### 6.7 Coordinate Compression
```
Original:   1,  5,  10^8,  10^8,  10^9,  10^9,  10^10
Compressed: 1,  2,  3,     3,     4,     4,     5

Steps:
  1. Sort + deduplicate
  2. Map each value to its rank
  3. Replace originals with ranks
```

### 6.8 Sum of All Edge Distances in a Tree
```
sz[u] = size of subtree at u
Contribution of edge (parent → child) = sz[child] × (n - sz[child])
Total = Σ (over all edges) sz[child] × (n - sz[child])
```

### 6.9 Inverse Permutation
```cpp
// permutation p[0..n-1]:
for (int i = 0; i < n; i++)
    inv[p[i]] = i;
```

### 6.10 Total Subarrays Containing Equal Adjacent Elements
```
Given array a of size n:
= n(n+1)/2  +  Σ i*(n-i)  where a[i] == a[i-1]
```

---

## 7. Trees & Graphs

### 7.1 DFS with Edge Direction Coloring
```
dfs(node, parentNode, color):
    color = 0  →  incoming edge (parent → node)
    color = 1  →  outgoing edge (node → parent)
```

### 7.2 f(i) − i = Constant Trick
```
If f(i) − f(j) = i − j  then  f(i) − i = f(j) − j = constant
→ Group indices by value of (f(i) − i) using a map
→ Count pairs within each group
```

---

## 8. C++ Lambda Functions

### Syntax
```cpp
[capture](parameters) -> return_type { body; }

// Example
auto add = [](int a, int b) { return a + b; };
cout << add(3, 4);   // 7
```

### Capture Clause
| Capture | Meaning |
|---|---|
| `[=]` | All outer vars by value |
| `[&]` | All outer vars by reference |
| `[x]` | Only x by value |
| `[&x]` | Only x by reference |
| `[=, &x]` | All by value, except x by reference |
| `[&, x]` | All by reference, except x by value |

---

## 9. Ordered Set (Policy-Based)

```cpp
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,
             tree_order_statistics_node_update> ordered_set;

ordered_set se;
*se.find_by_order(k)    // k-th smallest (0-indexed)
se.order_of_key(x)      // count of elements strictly less than x
```

### Find Elements in Range [l, r]
```cpp
int cnt = upper_bound(arr.begin(), arr.end(), r)
        - lower_bound(arr.begin(), arr.end(), l);
```

---

## 10. Geometry

### Law of Sines
```
a/sin(A) = b/sin(B) = c/sin(C)
```

### Law of Cosines
```
c² = a² + b² − 2ab·cos(C)
b² = a² + c² − 2ac·cos(B)
a² = b² + c² − 2bc·cos(A)
```

### Rotate n×n Matrix 90° Clockwise
```
1. Transpose matrix
2. Reverse each row

For 90° counter-clockwise:
1. Transpose matrix
2. Reverse each column
```

---

## 11. Miscellaneous C++ Tips

### Ceil Division (Integer Only)
```cpp
int ceil_div = (a + b - 1) / b;

// Smallest multiple of a that is >= l:
int result = ((l + a - 1) / a) * a;

// Floating point:
ceil(a * 1.0 / b)
```

### Random Numbers
```cpp
#include <cstdlib>
srand(time(0));              // seed — call once
int x     = rand();          // [0, RAND_MAX=32767]
int r     = rand() % N;      // [0, N)
```

### Print Fixed Decimal Places
```cpp
double x = 15.4567;
printf("%.3lf", x);                        // 15.457
cout << fixed << setprecision(3) << x;     // same
```

### Complexity Estimation Rule
```
Total ops = Time_Complexity × no_of_test_cases  ≤  10^8

Example:
  500 test cases, limit 10^8 ops
  → ops/testcase = 2×10^5
  → n=100, n²=10^4 < 2×10^5  ✓
```

### Sort using sort()
```cpp
sort(a.begin(), a.end());      // vector
sort(a, a + n);                // raw array
```

### String to Number
```cpp
stoi(s)               // string → int
stoi(s, nullptr, 2)   // binary string → int
stol, stoll           // long, long long variants
```

### Format (C++20)
```cpp
string r = format("Name: {}, Age: {}", name, age);
```

### Swap
```cpp
swap(a, b);    // STL swap
// or XOR swap: a^=b; b^=a; a^=b;
```

### s.append
```cpp
s.append(s.length(), 'x');   // double the string with 'x' chars
```

### Gray Code
```cpp
int gray = i ^ (i >> 1);
```
```