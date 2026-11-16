# ICPC Notes — Math & Geometry (Part 1: *When, Where & Which Pattern*)

> **Scope of this document**
> Row covered: **Math & Geometry** → Number Theory, Combinatorics, FFT/NTT, Game Theory, All Geometry.
> Supporting prerequisites (second column of your table): **Basic Graph Theory** and **Basic DP**.
>
> **This is Variation 1 only:** *where a topic is useful, which problem patterns point to it, which cases/constraints trigger it, and which traps to avoid.*
> **Variation 2 (C++ implementation and usage) is intentionally NOT included here.**

---

## 0. How to Use These Notes

1. Read the problem → underline **keywords**, **constraints**, and **what is being asked** (count / construct / decide / optimize / who wins).
2. Look up the keyword in **§0.1 (signal → technique table)**.
3. Check the constraints against **§0.2 (constraint → complexity cheat-sheet)**.
4. Open the matching section and read **"Recognise it when…"**, **"Typical patterns"**, **"Not useful when…"**, **"Pitfalls"**.
5. Before coding, run the **Pre-code checklist in §9**.

Each topic below uses the same template:

| Block | Meaning |
|---|---|
| **What it gives you** | The one-line power of the tool |
| **Recognise it when…** | Statement wording / constraints / structure that signals it |
| **Typical patterns** | The disguised forms in which it appears |
| **Useful cases** | Concrete situations where it is the right tool |
| **Not useful / wrong tool when…** | Where people waste time |
| **Combines with** | Other techniques it commonly pairs with |
| **Pitfalls** | Typical WA/TLE/overflow reasons |

---

### 0.1 Master Table: Problem Signal → Technique

| If the statement says / smells like… | Think first of… | Section |
|---|---|---|
| "answer modulo 1e9+7 / 998244353", count arrangements/ways | Combinatorics (factorials, inverses), DP, inclusion–exclusion | §2 |
| "modulo 998244353" **and** large n (≥ 1e5) with sums over i+j=k | NTT / polynomial ops | §3 |
| "gcd", "lcm", "coprime", "divisible by", "multiples of" | Number theory, Möbius, sieve | §1 |
| "number of divisors / sum of divisors / φ(n)" for many queries | Sieve + multiplicative functions | §1.5 |
| n up to 1e12–1e18, factorize / primality | Miller–Rabin, Pollard-rho, trial division up to √n | §1.4 |
| "remainder", "x ≡ a (mod m)", systems of congruences | CRT, extended Euclid | §1.3 |
| "find smallest x such that aˣ ≡ b (mod m)" | Baby-step giant-step (discrete log) | §1.6 |
| "binomial coefficient mod p", n up to 1e18, p small prime | Lucas theorem | §1.7 / §2.2 |
| "number of permutations with no fixed points / none of the bad properties" | Inclusion–exclusion, derangements | §2.3 |
| "balanced brackets", "paths not crossing diagonal" | Catalan, reflection principle | §2.4 |
| "partition into k non-empty groups" / "distribute distinct items" | Stirling numbers of 2nd kind | §2.5 |
| "necklaces / bracelets / rotations & reflections considered the same" | Burnside / Pólya | §2.6 |
| "linear recurrence, n up to 1e18" | Matrix exponent / Kitamasa / Berlekamp–Massey | §2.7 |
| "sum of i^k for i=1..n, n huge" | Lagrange interpolation (polynomial of degree k+1) | §2.7 |
| "number of labelled trees / spanning trees" | Cayley, Prüfer, Matrix-Tree theorem | §2.9 |
| "expected value", "probability" mod p | Linearity of expectation, modular inverse | §2.8 |
| "for every k count pairs (i,j) with i+j=k / a_i·b_j" | FFT/NTT convolution | §3 |
| "XOR / AND / OR of pairs, count for each value" | Walsh–Hadamard / zeta (bitwise convolution) | §3.4 |
| "string matching with wildcards / with mismatches ≤ k per alignment" | FFT correlation | §3.3 |
| "multiply two huge numbers" | FFT / NTT | §3.2 |
| "two players, optimal play, who wins" | Win/lose DP, Sprague–Grundy, nim variants | §4 |
| "points, polygon, area, intersection, convex, circle, angle" | Computational geometry | §5 |
| "closest pair / farthest pair / smallest enclosing circle" | Divide & conquer, rotating calipers, Welzl | §5.4–5.6 |
| "number of lattice points inside / on boundary" | Pick's theorem, gcd on segments | §5.3 |
| "shortest path / reachability / components / cycles" | Graph basics | §6 |
| "choose items, maximise / count, small capacity or small n" | DP (knapsack, bitmask, interval, digit) | §7 |

---

### 0.2 Constraint → Expected Complexity Cheat-Sheet

| n (main size) | Typical OK complexity | What it usually hints in math/geometry problems |
|---|---|---|
| ≤ 10 | O(n!) / O(n^6) | Brute force over permutations, geometry with all-triples checks |
| ≤ 20 | O(2ⁿ·n) | Bitmask DP, subset enumeration, inclusion–exclusion over subsets |
| ≤ 40 | O(2^(n/2)) | Meet in the middle |
| ≤ 100 | O(n⁴) | Floyd–Warshall style, Gaussian elimination mod p, cubic geometry |
| ≤ 500 | O(n³) | Matrix multiplication/exponent, Floyd, interval DP |
| ≤ 5000 | O(n²) | Pairwise geometry, DP on pairs, Pascal's triangle |
| ≤ 1e5 | O(n log n) / O(n log² n) | Sort-based geometry (hull, sweep), BIT, **FFT/NTT** |
| ≤ 1e6 | O(n) / O(n log n) | Sieve, linear precomputation of factorials, **FFT up to ~2e6 total length** |
| ≤ 1e7–1e8 | O(n) light | Linear sieve (≤1e7), simple loops |
| ≤ 1e9 | O(√n) / O(log n) / O(n^(2/3)) | Trial division, formula, floor-block sums, Min_25-like |
| ≤ 1e12 | O(√n) | Factorization by trial division, divisor enumeration |
| ≤ 1e18 | O(log n) / O(n^(1/4)) | Fast exponentiation, Miller–Rabin, Pollard-rho, matrix-power |
| "t test cases ≤ 1e5 / 1e6" | O(1) or O(log) per test after precompute | Precompute factorials/sieve once |
| Modulus 998244353 | | NTT-friendly (prime = 119·2²³ + 1, primitive root 3) |
| Modulus 1e9+7 | | Prime but not NTT-friendly (needs 3-mod NTT or split-FFT for convolution) |
| Modulus is **not prime** | | Beware: no general modular inverse, use CRT/prime-power tricks |

---

## 1. NUMBER THEORY

### 1.1 Divisibility, GCD / LCM, Euclid, Bézout

**What it gives you:** Reduces "structure of integers under division" to a few invariants: gcd, lcm, and linear combinations.

**Recognise it when…**
- Statement contains: *gcd, lcm, divisible, multiple, coprime, relatively prime, remainder, common divisor, reduce fraction*.
- You are asked whether you can reach a value using steps of fixed sizes (a, b) → reachable set is multiples of gcd(a, b) (plus bounds).
- A process repeatedly replaces (a, b) by (a−b, b), (a mod b, b), etc. → Euclid in disguise.
- "Minimum number of operations to make all elements equal using ±x" → remainder classes mod x.

**Typical patterns**
1. **gcd of a set / range:** gcd(a₁…aₙ), gcd over sliding windows or ranges → sparse table / segment tree / "gcd changes at most log times" argument.
2. **gcd of prefix/suffix with removal:** "remove one element to maximise gcd" → prefix + suffix gcd arrays.
3. **Reachability with steps:** with steps a and b you can reach exactly the multiples of g = gcd(a,b) (on infinite line); on bounded/circular structures, think of cycles of length (n / gcd(n, step)).
4. **Circular jumping:** "start at 0, jump k positions on cycle of n" → visits n / gcd(n,k) distinct positions, forms gcd(n,k) cycles.
5. **Bézout / extended Euclid:** a·x + b·y = c solvable iff gcd(a,b) | c; need *a particular solution* then general solution family (x₀ + t·b/g, y₀ − t·a/g).
6. **lcm blow-ups:** lcm of 1..n grows fast (exceeds 1e18 around n≈43) → use that to cap or early-exit in problems with "lcm of a range".
7. **gcd with equalities:** gcd(a, b) = gcd(a, b − a), gcd(a+b, b) = gcd(a, b), gcd(Fₘ, Fₙ) = F_gcd(m,n) (Fibonacci), gcd(aⁿ−1, aᵐ−1) = a^gcd(n,m) − 1.
8. **Counting pairs with a given gcd:** (see §1.5 Möbius / φ).
9. **Reduce fractions / compare fractions exactly:** store as (num, den) with gcd normalisation; compare using cross multiplication with 128-bit.

**Useful cases:** Reachability puzzles, water-jug type problems, circular scheduling, array-operation problems where all numbers must be divisible by a common g, "make gcd of array equal to 1 with min operations".

**Not useful when…** The operation is not linear (e.g. multiplication/min/max rules) — then gcd structure doesn't capture the reachable set.

**Combines with:** Segment tree/sparse table (range gcd), sieve (prime factor view), CRT, DP over divisors.

**Pitfalls:** gcd(0, x) = x; lcm overflow (compute a / gcd * b); negative numbers in extended Euclid; forgetting that general solutions must satisfy bounds (x ≥ 0, y ≥ 0).

---

### 1.2 Modular Arithmetic (the "language" of counting problems)

**What it gives you:** Keeps numbers small, makes huge answers printable, and gives algebraic structure (rings/fields).

**Recognise it when…**
- "Print the answer modulo …" — almost always combinatorics/DP/NT.
- "Find x such that …≡…", "remainder when …", "last digits of …", "is aᵇ divisible by …".
- n, exponent up to 1e18 → fast exponentiation or periodicity.

**Typical patterns**
1. **Fast power (binary exponentiation):** aᵇ mod m for b up to 1e18; also matrix power, polynomial power, function-composition power ("apply operation k times").
2. **Modular inverse:**
   - Prime modulus → Fermat: a^(p−2).
   - Any coprime modulus → extended Euclid.
   - Many inverses 1..n → linear recurrence `inv[i] = -(p/i) * inv[p % i]`.
   - Many arbitrary inverses → batch inverse (prefix products trick).
3. **Division in modular expressions:** every "÷" in a formula (e.g. n!/(k!(n−k)!), expected values p/q) needs an inverse. If the denominator is a multiple of the modulus → special handling (Lucas / count p-adic valuation).
4. **Reducing exponent:** aᵇ mod m with huge b → use Euler: if gcd(a,m)=1 then b mod φ(m); if not coprime, use the generalised form (b ≥ log₂ m → b mod φ(m) + φ(m)).
5. **Last k digits / leading digits:** mod 10ᵏ for last digits; leading digits via logarithms (fractional part of b·log₁₀ a).
6. **Periodicity (Pisano-like):** sequences mod m are eventually periodic; Fibonacci mod m has period ≤ 6m → "find F(n) mod m for n up to 1e18" has two solutions: matrix power or period.
7. **Parity/mod-small invariants:** mod 2, mod 3, mod 4 invariants prove impossibility ("can you reach state X?").
8. **Negative mod:** ((x % m) + m) % m.

**Useful cases:** every "count mod p" task, hashing (polynomial rolling hash with mod), RSA-style problems, cycle detection of x → f(x) mod m.

**Not useful when…** The problem requires actual comparison of big numbers (e.g. "is the answer ≥ 1e18?") — you need big integers, doubles/logs, or saturating arithmetic, not modulo.

**Combines with:** Combinatorics (§2), matrix exponent, FFT/NTT (§3), hashing.

**Pitfalls:**
- Multiplication overflow when mod ~1e18 → use `__int128` or Montgomery/mulmod.
- Using Fermat inverse when modulus is composite (WRONG).
- Dividing by something that is 0 mod p.
- Forgetting `% mod` after subtraction / after multiplication chains.

---

### 1.3 Linear Congruences & Chinese Remainder Theorem (CRT)

**What it gives you:** Solve ax ≡ b (mod m); merge several modular conditions into one.

**Recognise it when…**
- "x leaves remainder rᵢ when divided by mᵢ" for several i.
- "Find smallest non-negative x such that …" with multiple modular conditions.
- Circular/periodic events with different periods meeting simultaneously (e.g. two clocks with periods p₁, p₂ and offsets).
- The modulus is composite and you want to solve independently modulo prime powers then combine (e.g. nCr mod composite).

**Typical patterns**
1. **Linear congruence ax ≡ b (mod m):** solvable iff gcd(a,m) | b; number of solutions mod m = gcd(a,m).
2. **CRT, coprime moduli:** unique solution mod M = ∏mᵢ.
3. **CRT, non-coprime moduli (generalised):** merge pairwise; may be inconsistent → "no solution".
4. **Garner's algorithm:** reconstruct a number from residues mod several primes (3-mod NTT result reconstruction, big-number mod computations).
5. **"Answer mod composite M"** → split M = ∏pᵢ^eᵢ, compute answer mod each pᵢ^eᵢ, combine with CRT.
6. **Time/meeting problems:** "two trains with period a and b, starting at s₁, s₂ — when do they first coincide?" = CRT.
7. **Periodic schedules / Josephus with k-step in cycles** often reduce to congruences.

**Not useful when…** The conditions involve inequalities rather than exact remainders.

**Pitfalls:** Overflow of M (lcm may exceed 64 bits — detect and cap or use `__int128`); wrong handling when residues are inconsistent; returning a solution outside the requested range (shift by lcm).

---

### 1.4 Primes: Sieve, Primality Test, Factorization

**What it gives you:** Prime structure of numbers: factorization, counting primes, divisors.

**Recognise it when…**
- "prime", "composite", "factor", "divisor count", "smallest prime factor", "square-free", "perfect square", "number of primes ≤ n".
- Range [L, R] with R up to 1e12 and R−L ≤ 1e6 → **segmented sieve**.
- Many queries "is n prime?" with n ≤ 1e18 → **Miller–Rabin (deterministic bases)**.
- Factorize one or a few numbers up to 1e18 → **Pollard-rho**.
- Factorize many numbers ≤ 1e6/1e7 → **smallest-prime-factor (SPF) sieve**.

**Typical patterns**
| Pattern | Tool | Constraint |
|---|---|---|
| All primes up to N | Sieve of Eratosthenes / **linear sieve** | N ≤ 1e7–1e8 (bitset ≤ 1e9 w/ care) |
| Prime/factor info for many queries | SPF array → factor in O(log n) | n ≤ 1e7 |
| Primes in [L,R] huge | Segmented sieve with primes up to √R | R ≤ 1e12–1e14, R−L ≤ ~1e7 |
| Single large number factorization | Trial division up to √n | n ≤ 1e12 |
| Single huge number | Miller–Rabin + Pollard-rho | n ≤ 1e18 |
| Count primes ≤ n (n up to 1e10–1e12) | Meissel–Lehmer / Lucy_Hedgehog / Min_25 | n large, only count needed |
| Prefix sums over multiplicative f | Sieve + prefix | n ≤ 1e7 |
| Divisor enumeration | From prime factorization (all products) | #divisors ≤ ~1e5 for n ≤ 1e18 |
| Number of divisors / sum / φ | From exponents | — |
| Goldbach-like / twin primes | Sieve then pair scan | N ≤ 1e7 |
| Prime gaps | Gap ≤ ~1500 below 1e18 → bounded search for "next prime" | — |

**Useful cases:**
- "Find the smallest prime ≥ n" → loop with Miller–Rabin (gaps are small).
- "n has at most 15 distinct prime factors if n ≤ 1e18" → bitmask over prime factors for inclusion–exclusion.
- "Sum over d | n" with n ≤ 1e18 → enumerate divisors from factorization (number of divisors ≤ 103680 for n ≤ 1e18).
- Square-free test, "perfect power" test, "is n = aᵏ".

**Not useful when…** You only need divisibility of a given pair → gcd is cheaper. Don't sieve to 1e9 when you only need a few primality tests.

**Pitfalls:** Memory of sieve (use bitset / odd-only / `vector<bool>` / segmented); Miller–Rabin with wrong base sets for 64-bit; Pollard-rho cycles failing on prime powers/small factors (strip small primes first); forgetting that 1 is not prime.

---

### 1.5 Multiplicative Functions, Dirichlet Convolution, Möbius Inversion

**What it gives you:** Computing "sum over divisors / sum over pairs with gcd condition" fast.

**Key functions:** φ (Euler totient), μ (Möbius), σ (sum of divisors), τ/d (number of divisors), id, 1, ε (identity under convolution).

**Recognise it when…**
- "Count pairs (i, j) with gcd(i, j) = 1 / = g / divisible by …", i,j ≤ N with N up to 1e6–1e7 or sum over many tests.
- Expression ∑_{i=1..n} ∑_{j=1..m} f(gcd(i,j)) or lcm(i,j).
- "Sum of φ(i) for i ≤ n" with n up to 1e9–1e11 → **Dirichlet-hyperbola / Du-jiao sieve (O(n^{2/3}))**.
- "Sum over d | n of …" repeatedly → Dirichlet convolution view.
- "Count numbers ≤ N coprime to M" → inclusion–exclusion via divisors of M (μ).
- "Number of arrays with gcd exactly g" → Möbius / inclusion-exclusion over multiples.

**Typical patterns**
1. **Count coprime pairs ≤ N:** ∑_{d} μ(d)·⌊N/d⌋² — O(N) with sieve, O(√N) per query with prefix sums of μ + block decomposition.
2. **Count pairs with gcd = g:** reduce to coprime pairs ≤ N/g.
3. **Sum of gcd(i, N) over i:** ∑_{d|N} d·φ(N/d) (Pillai's function).
4. **Sum of lcm(i, j):** transforms through gcd → Möbius + block decomposition.
5. **"Number of arrays of length k with gcd = 1, values ≤ m":** ∑_d μ(d)·⌊m/d⌋^k.
6. **Divisor-sum DP:** `g[d] = (# tuples where all elements are multiples of d)`, then exact-gcd counts via *Möbius from the top* (`f[d] = g[d] − ∑ f[kd]`).
7. **Floor-block (quotient) trick:** ⌊N/i⌋ takes only O(√N) distinct values → sums of the form ∑ f(i)·⌊N/i⌋ computed in O(√N) given prefix sums of f.
8. **Dirichlet prefix sums:** "for each d, ∑ over multiples" in O(N log log N) — like SOS-DP over primes.
9. **φ properties:** ∑_{d|n} φ(d) = n; φ multiplicative; counts reduced fractions (Farey sequence length = 1 + ∑φ(k)).
10. **Burnside + φ:** rotation counting of necklaces uses ∑ φ(d)·k^(n/d).

**Useful cases:** Anything asking "pairs/tuples with gcd/lcm condition", "coprime", "number of fractions", "Farey", "visible points from origin" (lattice points with gcd(x,y)=1).

**Not useful when…** Condition isn't about gcd/divisibility structure, or N is small enough (≤ 2000) that O(N²) brute force with gcd is fine.

**Combines with:** Sieve (linear sieve computing μ, φ), prefix sums, floor-block iteration, Burnside, DP over divisors, FFT (for sum-over-pairs with gcd structure in special cases).

**Pitfalls:** Off-by-one when dividing by g (pairs (i,j) with i,j ≤ N/g); forgetting ordered vs unordered pairs; double counting (i,i); using int where products overflow before mod.

---

### 1.6 Primitive Roots, Discrete Log, Discrete Roots, Quadratic Residues

**What it gives you:** Treat multiplication mod p like addition via logarithms; solve aˣ ≡ b, xᵏ ≡ a, x² ≡ a.

**Recognise it when…**
- "Find smallest x ≥ 0 such that aˣ ≡ b (mod m)" → **BSGS** (O(√m)); with non-coprime a, m use extended BSGS.
- "Find x such that xᵏ ≡ a (mod p)" → discrete root (via primitive root + discrete log + linear congruence).
- "Is a a perfect square mod p?" → Legendre/Euler criterion; "find √a mod p" → **Tonelli–Shanks / Cipolla**.
- Order of an element ("smallest k with aᵏ ≡ 1") → divisors of φ(m).
- NTT roots, "roots of unity mod p" → primitive root.
- Problems where multiplication and exponent structure appears in a product like ∏ over powers, and you want to convert to additive convolution (using logs mod p).

**Typical patterns**
1. Multiplicative group mod prime p is cyclic of order p−1; generator found by testing factors of p−1.
2. Convert products to sums by taking discrete logs of everything → then convolution (e.g. "count pairs whose product ≡ k mod p" → NTT on discrete-log indices).
3. Order of a: divides φ(m); find by dividing out prime factors.
4. Cycle length of x → a·x mod m.

**Not useful when…** Modulus is huge (>1e14) with no special structure; BSGS needs memory O(√m).

**Pitfalls:** a ≡ 0 mod m special case; non-coprime a and m; m not prime → group may not be cyclic.

---

### 1.7 Lucas, Kummer, Legendre, Factorials Modulo Primes

**What it gives you:** Binomials/factorials modulo a **small prime p** (or prime power) when n is huge or the denominator vanishes mod p.

**Recognise it when…**
- "C(n, k) mod p" with n up to 1e18 and p ≤ 1e6 → **Lucas theorem**.
- "How many trailing zeros of n!" or "highest power of p dividing n!" → **Legendre's formula** (∑⌊n/pⁱ⌋).
- "Is C(n,k) odd?" → Kummer/Lucas for p = 2: (k & (n−k)) == 0 ⇔ k & n == k.
- "n! mod p" where n ≥ p → 0; where n < p but large (p ~ 1e7–1e9) → Wilson-based or √p log p algorithms.
- Modulus composite, e.g. 1e6 = 2⁶·5⁶ → Granville's generalisation (factorial without p-factors), then CRT.

**Typical patterns**
- Lucas: C(n, k) mod p = ∏ C(nᵢ, kᵢ) over base-p digits.
- p-adic valuation of C(n,k) = (number of carries when adding k and n−k in base p) — Kummer.
- Trailing zeros in base b: factor b, min over exponents (valuation of n! / prime power).
- Wilson's theorem: (p−1)! ≡ −1 mod p; use to compute factorial of values near p.

**Not useful when…** Modulus is a large prime (≥ 1e5–1e6) *and* n < p → plain factorial precomputation (§2.2) is easier.

**Pitfalls:** Table of factorials must go up to p−1; Lucas needs n,k in base p; composite modulus requires prime-power handling — the plain Lucas doesn't apply.

---

### 1.8 Diophantine Equations, Frobenius, Pell

**Recognise it when…**
- "Find integers x, y such that ax + by = c" (often with bounds on x,y, or minimal |x|+|y|).
- "What is the largest amount that cannot be formed with coins a and b?" → Frobenius number ab − a − b (coprime).
- "Number of non-negative solutions to ax + by = n".
- Three or more variables: reduce modulo smallest coefficient → shortest path (**"Dijkstra on residues" / round-robin Frobenius**) when coefficients are small but target is huge.
- x² − D·y² = 1 → **Pell** (continued fractions).
- "Sum of squares" (two squares: factorisation by primes ≡ 3 mod 4), Pythagorean triples (m² − n², 2mn, m² + n²).

**Typical patterns**
1. Use extended Euclid to get a particular solution, then shift by (b/g, −a/g) to satisfy bounds.
2. Counting solutions in an interval → floor/ceil arithmetic on parameter t.
3. Coin problem with small coin value m: states = residues mod m, edges add other coins, find min reachable value per residue.
4. Floor-sum (∑⌊(a·i + b)/m⌋) — arises in counting lattice points under a line (also in geometry §5.10).

**Pitfalls:** sign handling; ceil/floor on negatives; bounds that make the solution set empty.

---

### 1.9 Number Representation, Digits, Bits, Periodicity

**Recognise it when…**
- "Digit sum", "numbers with property in decimal/binary", "numbers ≤ N such that …" → **digit DP** (see §7), but closed forms exist for special cases.
- "Is n a palindrome / repunit / perfect power?"
- Base conversion, balanced ternary, Zeckendorf (Fibonacci) representation, Gray code.
- Bit tricks: n & (n−1), lowbit, popcount, XOR properties:
  - XOR from 1..n in O(1) by n mod 4.
  - XOR is addition without carry → nim-sum (§4), linear basis over GF(2) (max XOR subset).
  - a + b = (a ^ b) + 2·(a & b).
- Periodic digit patterns: last digit of aᵇ has period ≤ 4; Fibonacci mod 10 has period 60.

**Useful cases:** Anything about "binary representation of n", "number of 1-bits", "operations by powers of two".

---

### 1.10 Number Theory in Constructive / Ad-hoc / Invariant Problems

**Recognise it when…** A problem says "construct", "is it possible", or "prove impossible":
- Parity of sum, parity of permutations (swap changes parity), colour/chessboard parity.
- Mod-k invariants: an operation changes values by multiples of k → remainder multiset invariant.
- Sum constraints: if sum of n numbers each ≥ 1 equals S, it's feasible iff S ≥ n, etc.
- gcd invariant: operations preserve gcd of whole array.
- Divisor-based construction: choose numbers that are multiples/divisors in a chain (a, 2a, 4a …) to satisfy lcm/gcd constraints.
- "Product / sum of digits" constructions with 9's: mod 9 invariants.

---

### 1.11 Number Theory — Master Pitfalls List

1. **Overflow:** products up to 1e18·1e18 → `__int128`; or use mulmod with long double trick.
2. **Mod 1e9+7 vs 998244353:** only the latter supports plain NTT.
3. **Composite modulus:** inverses may not exist; use CRT on prime powers or avoid division.
4. **Negative numbers in % and extended Euclid.**
5. **Sieve limits:** memory/time, use segmented sieve when range is huge but window is small.
6. **Number of test cases:** precompute once, answer fast; do not re-sieve per test.
7. **Edge values:** n = 0, 1, prime powers, perfect squares (divisor count parity!), n = mod.
8. **Floor-block sums:** cases where N/i repeats → iterate with `j = N / (N / i)`.
9. **Exactness:** using `double` for √n / pow may be off by 1 → fix with adjustments.
10. **Don't over-engineer:** if n ≤ 1e5 and O(n√n) passes, trial division suffices.

---

## 2. COMBINATORICS

### 2.1 Counting Fundamentals

**What it gives you:** A vocabulary for turning "how many ways" into formulas.

**Recognise it when…** "Number of ways / arrangements / sequences / subsets / assignments / selections" with a modulus.

**Decision table — what kind of object are you counting?**

| Question | Ordered? | Repetition? | Formula family |
|---|---|---|---|
| Arrange r of n distinct items | yes | no | P(n, r) = n!/(n−r)! |
| Choose r of n distinct items | no | no | C(n, r) |
| Sequences of length r over n symbols | yes | yes | nʳ |
| Multiset of size r from n types | no | yes | C(n + r − 1, r) (stars and bars) |
| Arrangements of multiset | yes | partly | n! / (c₁! c₂! …) (multinomial) |
| Distribute r identical items into n boxes | — | — | stars & bars; with lower bounds shift; with upper bounds use inclusion–exclusion |
| Distribute distinct items into labelled boxes | — | — | nʳ (each item picks a box) |
| Distribute distinct items into unlabelled non-empty groups | — | — | Stirling S(r, n) |
| Distribute identical items into unlabelled groups | — | — | integer partitions p(r, n) (DP) |

**Typical patterns**
1. **Rule of product on independent choices** (choose position of X, then colour, then …).
2. **Complement counting:** total − bad (very common — then bad is often easier).
3. **Fix an element, recurse:** gives DP/recurrence (Pascal-like).
4. **Bijection:** map objects to lattice paths / bracket sequences / subsets with simple counting.
5. **Contribution technique:** instead of counting structures, count how many structures each element/edge/pair contributes to. Sum of "something over all subsets/permutations/trees" → ∑ (value) × (number of structures containing it).
6. **Symmetry:** by symmetry each position has equal probability → divide total by something.

**Pitfalls:** Ordered vs unordered; distinct vs identical; labelled vs unlabelled; empty groups allowed or not; "at least one" vs "exactly".

---

### 2.2 Binomial Coefficients (the core computational tool)

**Recognise it when…** Any closed form that involves C(n, k), "choose k out of n", lattice paths, stars and bars.

**Which method for which constraints?**

| Situation | Method |
|---|---|
| n ≤ ~5000, many queries, any modulus | Pascal's triangle O(n²) |
| n ≤ ~1e6–1e7, prime modulus > n | Precompute factorials & inverse factorials, O(1) per query |
| n huge (≤ 1e18), prime modulus p small (≤ ~1e6) | Lucas theorem |
| Modulus composite | Factor modulus → prime powers → Granville/Andrew-style factorial with p-parts removed, then CRT |
| k tiny (≤ ~20), n huge, prime modulus > k | Multiply k terms and divide by k! (inverse) |
| Exact value (no modulus) up to 1e18 | Multiplicative formula with gcd reduction at each step, or `__int128`, or Pascal with saturation |
| Need all C(n, k) for fixed n, k = 0..n | Row via factorials O(n); via multiplicative recurrence C(n,k+1) = C(n,k)·(n−k)/(k+1) |
| Need C(i, k) for many i with fixed k | Hockey-stick/prefix, or polynomial in i of degree k (interpolation) |
| Many queries of ∑_{j≤k} C(n, j) | Mo's-like movement on (n,k) using Pascal identity (O(n√q)) |

**Key identities to recognise**
- **Symmetry:** C(n,k) = C(n, n−k).
- **Pascal:** C(n,k) = C(n−1,k−1) + C(n−1,k) — DP and paths on grid.
- **Hockey stick:** ∑_{i=r..n} C(i, r) = C(n+1, r+1) — "sum of binomials with fixed lower index".
- **Vandermonde:** ∑ C(m, i)·C(n, k−i) = C(m+n, k) — "split a selection across two groups".
- **Sum of row:** ∑ C(n,k) = 2ⁿ; alternating sum = 0 (n ≥ 1).
- **Absorption:** k·C(n,k) = n·C(n−1,k−1) — turns "∑ k·C(n,k)" into n·2^(n−1).
- **Multinomial:** n!/(a!b!c!…).
- **Lattice paths:** C(a+b, a) paths in a×b grid (right/down), with blocked/forbidden diagonal → reflection (§2.4); with several forbidden points → sort points + DP with inclusion–exclusion.
- **Sum over n of C(n,k)·xⁿ** etc. → generating functions (§2.7).

**Not useful when…** Counting objects with complicated constraints that don't reduce to selecting positions — use DP.

**Pitfalls:** n < k → 0; negative arguments; factorial array size; modulus smaller than n; inverse of factorial computed from the top.

---

### 2.3 Inclusion–Exclusion Principle (IEP)

**What it gives you:** Count "none of the bad properties" or "at least one of …" as a signed sum of easier counts.

**Recognise it when…**
- Phrases: "no element is in its original position", "no two adjacent …", "all values used at least once", "none of the conditions hold", "number of arrays where **at least one** …".
- There are ~≤ 20 "bad events" (iterate over subsets, 2ⁿ), or the events have a *symmetric* structure so the count depends only on the subset size k (then the sum collapses to a single sum ∑ (−1)^k C(m, k)·f(k)).
- Counting numbers ≤ N coprime to M, M has few prime factors → IEP over subsets of prime factors.
- "Count surjections n → k" = ∑ (−1)^i C(k,i)(k−i)ⁿ.

**Typical patterns**
1. **Derangements:** D(n) = ∑ (−1)^i n!/i! ; recurrence D(n) = (n−1)(D(n−1)+D(n−2)).
2. **Partial derangements / rencontres:** exactly m fixed points = C(n,m)·D(n−m).
3. **Surjection / all colours used:** ∑ (−1)^i C(k,i)(k−i)ⁿ.
4. **Count strings avoiding patterns:** IEP + DP/automaton (Aho–Corasick) when patterns few.
5. **Coprime counting:** #(x ≤ N, gcd(x, M)=1) = ∑_{d | rad(M)} μ(d) ⌊N/d⌋.
6. **Upper-bounded stars & bars:** x₁+…+x_k = n, xᵢ ≤ cᵢ → ∑_{S⊆[k]} (−1)^{|S|} C(n − ∑_{i∈S}(cᵢ+1) + k − 1, k − 1).
7. **Forbidden positions/rook polynomial:** permutations avoiding a set of positions.
8. **Subset-sum over supersets (SOS / zeta transform):** "count tuples whose AND is exactly mask" = Möbius on subset lattice.
9. **Union of events probability:** P(∪Aᵢ) = ∑ (−1)^{|S|+1} P(∩_{i∈S} Aᵢ).
10. **Counting by "exact" from "at least":** f_exact(k) = ∑_{j ≥ k} (−1)^{j−k} C(j,k) f_atleast(j) (binomial inversion).

**Not useful when…** There are too many bad events (> 25) with no symmetry; then use DP over states directly.

**Combines with:** Möbius function (it *is* IEP on divisor lattice), bitmask enumeration, DP, FFT (the symmetric sum as a convolution of factorial-weights).

**Pitfalls:** Sign errors; including the empty set; forgetting that each term must itself be easy to compute (otherwise IEP didn't help).

---

### 2.4 Catalan Family, Ballot, Reflection Principle

**Recognise it when…**
- "Balanced parentheses", "Dyck path", "path never goes below/above the diagonal/line", "number of binary trees with n nodes", "triangulations of an (n+2)-gon", "non-crossing partitions/matchings", "stack-sortable permutations", "mountain ranges".
- Prefix condition "at every prefix, #A ≥ #B".

**Typical patterns**
1. **Catalan Cₙ = C(2n,n)/(n+1) = C(2n,n) − C(2n,n+1).**
2. **Paths from (0,0) to (a,b) not touching line y = x + c:** reflection principle → C(a+b, a) − C(a+b, a + c')-type formula (reflect start point across the line).
3. **Ballot problem:** candidate A gets a votes, B gets b < a; probability A strictly ahead throughout = (a − b)/(a + b).
4. **Bracket sequences with fixed prefix / with k types / with forced positions:** combination of reflection and DP over prefix balance (DP O(n²)).
5. **Non-crossing structures** → Catalan-style recurrence C_{n+1} = ∑ C_i·C_{n−i}.
6. **Narayana numbers:** Dyck paths with k peaks.
7. **Motzkin / Schröder / Delannoy:** Dyck-like paths with extra step types — DP or generating function.

**Not useful when…** The balance condition changes by variable amounts per step (then DP / generating function / kernel method).

---

### 2.5 Stirling, Bell, Partition, Eulerian Numbers

**Recognise it when…**
- "Partition n labelled objects into k non-empty unlabelled subsets" → **S(n,k)** (2nd kind).
- "Arrange n objects into k cycles" or "permutations with exactly k cycles" → **c(n,k)** (unsigned 1st kind).
- "Number of set partitions of n elements" → **Bell(n)**.
- "Number of ways to write n as sum of positive integers (order irrelevant)" → **partition number p(n)** (O(n√n) via pentagonal numbers).
- "Permutations with k ascents/descents" → **Eulerian numbers**.

**Typical patterns**
- S(n,k) = k·S(n−1,k) + S(n−1,k−1); closed form k!·S(n,k) = ∑ (−1)^i C(k,i)(k−i)ⁿ (surjections).
- Row of S(n, ·) for fixed n via **one convolution** (FFT/NTT) — see §3.
- Falling/rising factorial conversions between power basis and falling-factorial basis use Stirling numbers → "sum of kⁿ" type problems.
- Counting functions n → k that are surjective, set partitions with limited sizes, "put n balls in k boxes, no empty box".
- Cycle structure of random permutations: expected cycles = Hₙ (harmonic number).

**Not useful when…** Items are identical (use partitions instead) or boxes are labelled-but-can-be-empty (use kⁿ).

---

### 2.6 Burnside's Lemma & Pólya Enumeration

**Recognise it when…**
- "Count distinct necklaces/bracelets/colourings **up to rotation / reflection / permutation**".
- "Two configurations are the same if one can be transformed into the other by …" (rotation of a cube, flipping a board, cyclic shifts).
- Small group of symmetries (n rotations, 2n rotations+reflections, 24 cube rotations, …).

**Typical patterns**
1. **Number of orbits = (1/|G|)·∑_{g ∈ G} Fix(g).**
2. For necklaces of length n with k colours (rotations only): (1/n)∑_{d|n} φ(n/d)·kᵈ.
3. With reflections added: average the rotation part with reflection contributions (case n odd/even).
4. Pólya: Fix(g) = k^{cycles(g)} where cycles(g) = number of cycles of g acting on positions.
5. Constraint "exactly c_i beads of colour i" → coefficient extraction from cycle-index polynomial.
6. 2D grids with rotation by 90°: group of size 4 (or 8 with reflections).

**Not useful when…** There's no symmetry equivalence, or group is huge and orbit structure is unclear.

**Pitfalls:** Dividing by |G| needs modular inverse; forgetting reflection element types for even vs odd n.

---

### 2.7 Generating Functions, Recurrences, Interpolation

**What it gives you:** Tools to count when direct DP is O(n²) or too slow, or n ≈ 1e18.

**Recognise it when…**
- "dp[i] = ∑ dp[j]·w[i−j]" (convolution recurrence) → **FFT/NTT + online / CDQ divide & conquer** (§3).
- "Linear recurrence f(n) = a₁f(n−1)+…+a_k f(n−k), n up to 1e18" → matrix exponent O(k³ log n), **Kitamasa** O(k² log n) or O(k log k log n) with FFT, **Berlekamp–Massey** when you only have first 2k terms.
- "Sum of i^k for i = 1..n", n ≤ 1e18 or large, k ≤ ~1e6 → polynomial of degree k+1 → **Lagrange interpolation** with n ≤ k+2 sample points computed in O(k).
- "Number of ways grows polynomially in n" and small n values are computable by brute force/DP → interpolate polynomial (check degree bound!).
- Counting with multiple independent "pieces" → multiply generating functions (ordinary for unlabelled / exponential for labelled).

**Typical patterns**
| Pattern | Technique |
|---|---|
| Coin change / partitions with allowed part sizes | OGF product ∏ 1/(1 − x^a); NTT-based "exp of log" or DP |
| Labelled structures (permutations, set partitions, trees) | EGF; exp/log of series |
| Counting items with sum constraint ∑ xᵢ = n, 0 ≤ xᵢ ≤ cᵢ | Product of (1 + x + … + x^{cᵢ}) |
| "Coefficient of xⁿ in P(x)/Q(x)" with n huge | **Bostan–Mori** / Kitamasa |
| Fibonacci-like with huge n | Fast doubling / matrix power |
| Walks of length L in a graph with ≤ 100 nodes | Matrix power of adjacency matrix |
| Longest path / shortest path of exactly k edges with small graph | (min,+) matrix power |
| Probability of reaching state in Markov chain | Matrix power or linear system (Gaussian elimination mod p) |
| Sum of polynomial-of-i over geometric progression | Closed form or interpolation |

**Not useful when…** Recurrence has variable coefficients dependent on i (then P-recursive / DP), or the transition graph is huge.

**Pitfalls:** Matrix size too large; mod issues when dividing by (x−xᵢ) in Lagrange with xᵢ ≡ xⱼ mod p; assuming polynomial of lower degree than true.

---

### 2.8 Probability & Expected Value Modulo p

**Recognise it when…** "Expected number of …", "probability that …", "output p·q⁻¹ mod 998244353".

**Typical patterns**
1. **Linearity of expectation** (no independence needed): E[∑Xᵢ] = ∑E[Xᵢ] → split into indicators; this is *the* most common trick (expected inversions = C(n,2)/2; expected cycles = Hₙ; expected fixed points = 1).
2. **Contribution of each element/pair** ("probability element i is the maximum of its prefix = 1/i").
3. **Expected value DP:** E[state] = 1 + ∑ p·E[next] with DAG ordering (process in reverse); for cyclic Markov chains solve linear system (Gaussian elimination mod p) or use the "gambler's ruin" structure.
4. **Geometric-distribution waiting:** expected trials to first success = 1/p (coupon collector = n·Hₙ).
5. **Probability = favourable/total** → count both with combinatorics, divide using modular inverse.
6. **Bayes / conditional counting.**
7. **Random permutations facts:** position of a fixed element uniform; probability pair (i,j) inverted = 1/2; record-values (left-to-right maxima) expected Hₙ.
8. **Expected value of max/min of random picks:** E[max] = ∑_{k} P(max ≥ k).
9. **Tail-sum / tail-probability formula:** E[X] = ∑_{k≥1} P(X ≥ k).

**Pitfalls:** Not reducing fractions before mod (fine if denominator invertible); denominators ≡ 0 mod p; mixing "probability" with "count / total" when the total is 0 mod p.

---

### 2.9 Counting Graph/Tree Structures

**Recognise it when…** "Number of labelled trees", "spanning trees of a graph", "forests", "Eulerian orientations", "paths in a DAG".

**Typical patterns**
- **Cayley:** number of labelled trees on n vertices = n^{n−2}. Forest with specified roots / degrees → Prüfer sequences give nᵏ-type formulas (number of trees with given degrees dᵢ = (n−2)!/∏(dᵢ−1)!).
- **Matrix-Tree theorem:** number of spanning trees = any cofactor of the Laplacian (determinant mod p via Gaussian elimination, n ≤ ~400–500).
- **Counting trees connecting given components:** n^{k−2}·∏ sᵢ (component sizes sᵢ, k components).
- **LGV lemma:** number of vertex-disjoint path systems in a DAG = determinant of path-count matrix (non-intersecting lattice paths).
- **BEST theorem** (Eulerian circuits count in directed graphs) = t_w(G)·∏(deg(v)−1)!.
- **Counting by degree sequence / handshake:** ∑deg = 2m.
- **Counting paths in a DAG** → DP in topological order; with k steps → matrix power.

**Not useful when…** Graph is too large for determinants and has no structure.

---

### 2.10 Permutations & Their Statistics

**Recognise it when…** "Permutation", "inversion", "cycle", "lexicographic order", "next permutation", "k-th permutation", "parity of permutation".

**Typical patterns**
1. **Cycle decomposition:** operations like "apply permutation k times" → cycles of length L, rotate by k mod L. Minimum swaps to sort = n − #cycles.
2. **Inversions:** count with BIT / merge sort (O(n log n)); parity = sign (−1)^{inv}; adjacent swaps needed = inversions.
3. **Lehmer code / factorial number system:** rank ↔ permutation; "k-th permutation" with n ≤ 20 direct, larger n via BIT and factorial base (since k < n! is capped).
4. **Counting permutations with property:** fixed points, derangements, cycles (Stirling), inversions (Mahonian numbers via DP/prefix sums), longest increasing subsequence (RSK/Young tableaux — hook length formula).
5. **Order of a permutation** = lcm of cycle lengths (hence maximum order ≈ Landau function; "largest lcm of partition of n").
6. **Constructing permutations satisfying constraints:** greedy with sets, matching (Hall's theorem), parity arguments.

---

### 2.11 Combinatorial Reasoning Techniques

| Technique | When |
|---|---|
| **Pigeonhole** | "Prove/decide existence among many items" — forces repeats (e.g. among n+1 numbers two have the same residue mod n → subarray sum divisible by n). |
| **Double counting** | Count same quantity two ways → identity or bound (handshake, pair sums). |
| **Invariants / monovariants** | "Can we reach configuration X?" or "does the process terminate?" |
| **Bijective proofs** | Replace a hard-to-count set by an equinumerous easy set. |
| **Extremal principle** | Consider min/max element to design induction/greedy. |
| **Induction + construction** | Constructive outputs for all n (build n from n−1 or n/2). |
| **Symmetry / pairing** | Pair up objects so exactly half satisfy a property. |
| **Meet in the middle** | n ≤ 40 subset-type counting. |
| **Gray code / de Bruijn** | Traversal of all subsets with one change at a time; shortest string containing all k-bit patterns. |
| **Probabilistic method / random hashing** | Randomised verification, XOR-hash to compare multisets, random permutation tricks. |

---

### 2.12 Combinatorics — Pattern Recognition Checklist ("which formula?")

1. Is the answer a *single closed form*? Try identities (stars/bars, Catalan, Stirling, Burnside).
2. Is there a *forbidden property*? Try complement or inclusion–exclusion.
3. Is there a *prefix condition* (balance ≥ 0)? Catalan/reflection/DP over balance.
4. Is there *symmetry equivalence*? Burnside.
5. Is there a *convolution-shaped recurrence*? Generating functions + NTT.
6. Is n *astronomically large* with a linear recurrence? Matrix power / Kitamasa.
7. Does the answer behave *like a polynomial in n*? Compute small values, interpolate.
8. Expected value? Linearity & contribution technique.
9. Too complex for formulas? **DP with careful state**, then optimise (prefix sums, FFT).

---

## 3. FFT / NTT & POLYNOMIAL TECHNIQUES

### 3.1 What a Convolution Is and Why It Appears Everywhere

**What it gives you:** For two arrays A and B, compute C[k] = ∑_{i+j=k} A[i]·B[j] for **all** k in O((n+m) log(n+m)) instead of O(n·m).

**Recognise it when…**
- The answer for each k is "number/sum over pairs whose **index sum** (or difference, or product via logs) equals k".
- You have two sets/arrays of size ~1e5 and need an all-pairs summary by *sum*.
- A DP of the form `dp[n] = ∑_{i+j=n} f[i]·g[j]` and n up to ~1e5–1e6.
- "How many ways to pick one element from each group so that the total is k?" with total value range up to ~1e5–1e6.

**Typical patterns (disguises)**
| Disguise | Reduction |
|---|---|
| Count pairs (i, j) with a[i] + b[j] = s | Indicator arrays cntA[v], cntB[v], convolve |
| Count pairs with a[i] − b[j] = d | Reverse one array (index n−j) then convolve (cross-correlation) |
| Count triples a+b+c = s | Convolve twice (or cube of the indicator polynomial) |
| Subset-sum counting with values ≤ V, n items | Product of (1 + x^{aᵢ}) via divide & conquer FFT or log/exp |
| Count ways to get sum k with dice/cards | Power of polynomial (fast power with NTT or log/exp) |
| Matching score of a pattern vs. text for each shift | Cross-correlation: ∑ p[j]·t[i+j] |
| Multiply two big integers / polynomials | Direct convolution (carry afterwards) |
| Products modulo prime p: count pairs with a·b ≡ k | Discrete logs (§1.6) turn product → sum, then convolve |
| "Sum of f(i−j)·g(j)" over j for every i | Convolution |
| Number of paths of given length in structure with translation invariance | Convolution/power of step polynomial |

**Not useful when…**
- n is tiny (≤ ~3000): O(n²) is simpler and exact.
- Needed values are not "sum-of-indices" structured (e.g. condition i+j ≤ k with extra pair constraints).
- Values in arrays are astronomically large and precision matters (FFT with doubles → prefer NTT/modular).

**Pitfalls:** Array size must be ≥ n+m−1 (power of two); index shifting for negative differences; confusing the length of the output; precision (below).

---

### 3.2 Which Transform? FFT vs NTT vs Arbitrary-mod

| Situation | Choose | Why |
|---|---|---|
| Answers needed mod 998244353 (or 167772161, 469762049 …) | **NTT** | Exact, fast, no precision issues |
| Answers needed mod 1e9+7 or any arbitrary modulus | **3-prime NTT + CRT (Garner)** or **split-FFT (15-bit split, 4 FFTs)** | 1e9+7 is not NTT-friendly |
| Exact integer results with moderate magnitude (≤ ~1e15 total) | **FFT (double / long double)** | Fine when n·max²  stays below precision (≈ 1e14–1e15) |
| 0/1 or small-count arrays (counting pairs) | **FFT with doubles** (round to nearest) | Values small, result ≤ 1e11 |
| Huge numbers multiplication | FFT with base 1e3/1e4, or NTT with 3 primes | Carries after |
| Multiplying many polynomials | **D&C with sorted-by-size merging (Huffman style)** | O(N log² N) |
| Small length (≤ 64) | Naive | Constants better |
| Bitwise convolution | **FWHT / zeta** (§3.4) | Different algebra |

**Precision rules of thumb:** double FFT is safe if (max coefficient)² · length ≲ 1e14–1e15; otherwise split numbers into low/high 15-bit halves or move to NTT.

**Pitfalls:** Using NTT for modulus whose p−1 isn't divisible by 2^k with k ≥ log₂(size); overflow in butterfly multiplications; forgetting to take `round()` not `floor()` for FFT; reusing arrays without clearing.

---

### 3.3 String Problems Solved by FFT

**Recognise it when…**
- Pattern matching with **wildcards** ("?" matches anything).
- Count, for **each shift**, the number of mismatching/matching characters (Hamming distance between pattern and every window).
- "Find all positions where pattern matches with at most k mismatches" (alphabet small → one FFT per symbol, or randomised sum-of-squares trick).
- Longest common substring-like quantities with *shifts*, e.g. "for each cyclic shift, number of equal positions".
- "Count of pairs (i, j) with s[i] = c₁, t[j] = c₂ and i + j = k" for each k.

**Typical patterns**
1. **Wildcard matching:** ∑ (pᵢ − tᵢ₊ⱼ)²·pᵢ·tᵢ₊ⱼ = 0 expands into three correlations with p², t², p, t, p³, t³ — or random-weight trick.
2. **Mismatch count per shift:** one correlation per alphabet letter (if alphabet small, e.g. 4 letters in DNA) = FFT on indicator arrays, sum results.
3. **Cyclic shift comparisons:** double one array, correlate.
4. **Hashing alternatives:** If only exact matching, KMP/Z/hash is simpler. FFT is for *approximate* or *aggregate* matching.

**Not useful when…** Exact matching only; alphabet very large with many letters (too many FFTs) — use bitset or sqrt-decomposition.

---

### 3.4 Bitwise Convolutions (XOR / AND / OR), Subset Convolution

**Recognise it when…**
- "For each value x, count pairs (i, j) with a[i] ^ b[j] = x" (values < 2^k, k ≤ ~20) → **Walsh–Hadamard Transform (FWHT)**.
- AND / OR versions → **superset / subset zeta transform** (SOS) and Möbius inverse.
- "Count pairs (i,j) with a[i] & a[j] = 0" or subsets of disjoint masks → subset convolution (rank-by-popcount trick, O(2^k·k²)).
- "Number of ways to choose k elements with XOR/AND/OR equal to X" — repeated power of the transform (pointwise power, then inverse).
- Linear recurrence/game on XOR of piles combined with counting → FWHT of indicator arrays (e.g., counting positions that are losing in a Nim game with many piles drawn from a set).

**Typical patterns**
| Task | Transform |
|---|---|
| XOR of two chosen numbers | FWHT, pointwise multiply, inverse |
| k-fold XOR (choose k items with replacement) | FWHT, pointwise power, inverse |
| Number of subsets with XOR = X (subset, no replacement) | Pointwise ∏ (1 + wᵢ(x)) where wᵢ(x) = ±1 per element, then inverse |
| OR / AND convolution | Subset/superset zeta; pointwise multiply; Möbius |
| Sum over all submasks / supermasks | SOS DP (zeta) |
| Subset convolution (disjoint union) | Ranked zeta with popcount |
| Count "triples (i,j,k) with i&j = k" etc. | Combination of zetas |

**Not useful when…** Value range > 2^22 (memory/time) — use bitwise-trie or meet-in-the-middle.

---

### 3.5 Formal Power Series (FPS) Toolkit

**Recognise it when…** The editorial/solution mentions: "inverse", "log", "exp", "sqrt", "power", "composition", "multipoint evaluation", "interpolation".

| Operation | Where it appears |
|---|---|
| **Inverse 1/P(x) mod xⁿ** | Division of polynomials, counting with denominators, Bernoulli numbers, recurrences like dp = 1 + ∑ … |
| **Polynomial division / mod** | Linear-recurrence nth term (Bostan–Mori), CRT for polynomials |
| **ln P(x)** | Turn products into sums: "number of multisets", counting connected structures from all structures |
| **exp P(x)** | Turn sums into products: EGF of "sets of structures" (e.g. all graphs → connected graphs ↔ exp/log) |
| **P(x)^k** | Number of sequences of k independent choices (dice, Egyptian-fraction style counts) |
| **sqrt** | Catalan-like GF solution of quadratic functional equations |
| **Multipoint evaluation** | Evaluate polynomial at many points; speeding up Lagrange for non-consecutive points |
| **Interpolation (general points)** | Recover polynomial from values (problems claiming "polynomial of degree d") |
| **Taylor shift P(x+c)** | Counting with shifts, Stirling-related conversions |
| **Composition P(Q(x))** | Rare, advanced (Lagrange inversion, trees counting) |
| **Chirp-Z transform** | Evaluate at geometric progression points; convolution-based DFT of arbitrary length |
| **Online (relaxed) convolution / CDQ-FFT** | dp[n] depends on dp[0..n−1] via convolution (e.g. counting permutations/graphs with self-referential recurrences) |
| **Stirling number rows, Bell, partition numbers** | One or two NTT multiplications |
| **Factorial mod p in O(√p log p)** | For huge p with n! needed |
| **Sum of powers / Bernoulli numbers** | Inverse of exponential series |

**Not useful when…** n ≤ ~2000: plain O(n²) DP is fine and less error-prone.

---

### 3.6 FFT/NTT — Complexity & Size Reality Check (ICPC)

| Total length | Feasible? |
|---|---|
| ≤ 2¹⁸ (262k) | Easily, multiple transforms |
| ≤ 2²⁰ (1M) | Fine, ~10–20 transforms in 1–2 seconds |
| ≤ 2²² (4M) | Tight; few transforms only; memory ~ 64–128 MB |
| 2²⁴+ | Typically impossible; rethink |

**Heuristic:** "n up to 2e5, mod 998244353, DP with sum over j" → NTT is almost certainly intended.

---

### 3.7 FFT/NTT — Master Pitfalls List

1. Using FFT when the modulus demands exactness (large coefficients) → wrong due to rounding.
2. Using 998244353 NTT for 1e9+7 problems (wrong answers).
3. Not handling **index offsets** for negative differences or reversed arrays.
4. Output length mismatch; forgetting trailing zero trimming.
5. Calling FFT on tiny arrays in tight loops (D&C) without switching to naive for small sizes.
6. Mixing counts with weights — convolution multiplies values, so convolve **indicator** arrays when counting.
7. Not reducing coefficients mod p before NTT.

---

## 4. GAME THEORY

### 4.1 First Questions to Ask About Any Game Problem

| Question | Why it matters |
|---|---|
| Is it **impartial** (both players have the same moves from every position) or **partizan** (different moves per player)? | Impartial → Sprague–Grundy works. Partizan → special structure / DP over full state. |
| **Normal play** (last mover wins) or **misère** (last mover loses)? | Grundy theory is for normal play; misère needs special-casing (usually differs only near trivial positions). |
| Is the game **finite / acyclic**? | Cycles → positions may be draws (retrograde analysis). |
| Is it a **sum of independent games** (several piles/components, a move touches exactly one)? | Then XOR the Grundy values. |
| Is it **win/lose only**, or is there a **score** to maximise? | Scores → minimax DP over the difference of scores. |
| Is **state space small** (≤ 1e6–1e7 states)? | Straight DP over states (win/lose or Grundy). |
| Are values huge (1e9–1e18)? | Pattern/period of the Grundy/win function — brute force small values and *look for the pattern*. |
| Is it **interactive** (you play against the judge)? | Need an explicit winning strategy, not just who wins. |

---

### 4.2 Win/Lose DP (Backward Induction)

**Recognise it when…** "Two players alternate; the player who cannot move loses/wins; determine the winner."

**Rule:** A position is **winning** if at least one move leads to a **losing** position; **losing** if all moves lead to winning positions (terminal with no moves = losing under normal play).

**Useful cases**
- One heap with allowed subtraction set S → dp over heap size (periodic eventually).
- Game on a DAG/grid with a token (move right/down, forbidden cells) → DP in topological order.
- Game on string/array with prefix/suffix removals → interval DP.
- Two coordinates (a, b) state with moves decreasing either → 2D table, look for pattern (e.g. Wythoff).

**Not useful when…** State space is enormous and no structure — look for invariants/symmetry or decomposition.

**Patterns seen in simple one-heap games**
- **Bash game** (take 1..k): losing iff n mod (k+1) = 0.
- **Subtraction game with set S:** sequence of win/lose is eventually periodic; find period by brute force.
- **Take-away with divisor/multiple rules:** often reduces to parity (e.g. "subtract a proper divisor": the player with an even number wins).
- **Euclid-like games** (subtract a multiple of the smaller number from the larger): analyse along the Euclid algorithm, winning if quotient ≥ 2 at some step.

---

### 4.3 Nim and the Sprague–Grundy Theorem

**What it gives you:** Any impartial game under normal play is equivalent to a single Nim heap of size **g = mex of the Grundy numbers of reachable positions**. A sum of games is losing for the player to move iff the **XOR of their Grundy numbers is 0**.

**Recognise it when…**
- Several independent piles/components, each move changes **exactly one** component.
- "Two players, several heaps/stones/chains/graphs; optimal play; who wins?"
- Moves in a single component depend only on that component's state.

**Typical patterns**
1. **Classic Nim:** Grundy(pile n) = n; losing iff XOR of piles = 0; winning move: reduce a pile so XOR becomes 0.
2. **Allowed-move variants:** Take any number from 1..k (Grundy = n mod (k+1)); take from fixed set S (compute mex DP; often periodic).
3. **Splitting games:** a move removes some and splits the rest into several heaps (Grundy's game, Kayles, Dawson's Kayles, Lasker's Nim) → Grundy of a heap = mex over XOR of resulting parts; sequences are usually (eventually) periodic → compute small values and detect period.
4. **Games on a tree/forest (Green Hackenbush):** Grundy(node) = XOR over children of (Grundy(child) + 1). Cyclic components use the fusion principle (contract cycles).
5. **Graph token games (token moves along DAG edges, several tokens):** Grundy per token position via DP on DAG; XOR over tokens.
6. **Coin-turning games** (flip a coin from heads to tails and optionally flip another coin to the left): Grundy of the whole = XOR of Grundy of each head position (Turning Turtles, Ruler game).
7. **Sum of identical sub-games** (e.g. n chains each with same Grundy g): XOR is g if n odd, 0 if n even.
8. **Counting winning positions** over choices of heaps: count tuples with XOR ≠ 0 → total − (#tuples with XOR 0), often via **FWHT** or DP over bits (§3.4).

**Not useful when…** Players have different move sets (partizan), or a move can affect several components, or the game is **misère** with large piles.

**Known Nim variants (recognise by statement):**
| Variant | Rule of thumb |
|---|---|
| **Misère Nim** | If all piles ≤ 1: first player wins iff number of 1-piles is even. Otherwise same as normal Nim (XOR ≠ 0 wins). |
| **Moore's Nim_k** (take from up to k piles) | Write piles in binary; for each bit position, sum of bits must be ≡ 0 mod (k+1) for a losing position. |
| **Staircase Nim** (move coins down a staircase) | Only odd-numbered steps matter: XOR of coins on odd steps. |
| **Wythoff's game** (take from one pile, or equal from both) | Losing positions (⌊kφ⌋, ⌊kφ²⌋) with φ golden ratio; brute-force to discover. |
| **Nim with a cap on each move / bounded take** | Grundy = pile mod (cap+1). |
| **Nim with moves that can also add (limited)** | Often the player can reverse additions → ignore additions (reversible moves argument). |
| **Poker Nim / "add or remove"** | Same as Nim if adding is bounded and reversible. |
| **Kayles** | Grundy sequence is eventually periodic with period 12. |
| **Dawson's Kayles** | Grundy sequence periodic with period 34. |
| **Grundy's game (split into two unequal heaps)** | No simple closed form; brute force small, values stay small. |

**Pitfalls:** Forgetting the empty/terminal Grundy = 0; computing mex incorrectly; mixing misère with normal play; assuming Grundy equals size when moves are restricted; not noticing that components are **not independent** (e.g. moves that touch two heaps).

---

### 4.4 Cyclic Game Graphs (Draws) — Retrograde Analysis

**Recognise it when…** Moves may return to earlier positions (cycles), and the statement mentions **draw**, "infinite game", "if the game never ends".

**Method (pattern):** Label terminal losing positions; propagate backward — a position is **Win** if some move reaches a **Lose**; **Lose** if all moves reach **Win**; remaining positions are **Draw**. Implemented with BFS from terminals using out-degree counters.

**Useful cases:** Games on general digraphs, "cat and mouse" pursuit, token on a graph where both can move.

**Not useful when…** Graph is a DAG (plain DP suffices).

---

### 4.5 Scoring Games & Minimax DP

**Recognise it when…** Players collect points; "both play optimally to maximise their own total"; "find the final score difference."

**Typical patterns**
1. **Take from either end of an array** → interval DP where `dp[l][r]` = best (my score − opponent score) from segment [l..r]; recurrence `max(a[l] − dp[l+1][r], a[r] − dp[l][r−1])`. If n is huge: sometimes parity/greedy collapses it (e.g. even length first player can always take all odd or all even indices).
2. **Take from top of several stacks / sorted greedy** → sort all "gains" and alternate picks when moves are independent and equally available (classic: both pick largest remaining value).
3. **Zero-sum with sum constraint** → work with the *difference*; define dp[state] as best margin for the player to move.
4. **Games with tempo/stalling** (some moves "pass") → combinatorial game values/temperature (rare; usually small DP on state is accepted).
5. **Alpha–beta / pruning** for small boards (tic-tac-toe, 4×4 variants), memoisation over bitmask board states (≤ 2²⁰–2²⁵ states).
6. **Game with a "last move" dependence** (next move cannot be same as previous) → add last-move to state.

---

### 4.6 Strategy-Style Arguments (No DP Needed)

| Idea | When it solves the problem |
|---|---|
| **Symmetry / mirroring** | Second player copies first player's move in a symmetric structure (even number of identical heaps, centrally symmetric board). |
| **Pairing strategy** | Partition positions into pairs so every move by one is answered in the pair. |
| **Strategy stealing** | First player can't lose in many symmetric-rule games (existence argument; construct if interactive). |
| **Parity of total moves** | If total number of moves is fixed regardless of play (e.g. every move removes exactly one stone from a fixed pool) → winner determined by parity. |
| **Reversible moves** | If a move can be undone by the opponent, ignore it for outcome analysis. |
| **Greedy / dominance** | Taking the largest available is always optimal in "choose from a shared pool" games. |
| **Potential function** | Show a quantity strictly decreases to analyse termination and parity. |

---

### 4.7 Finding Patterns by Experimentation (Very Common in ICPC)

When n is huge and the state space is "nice":
1. Write a brute force (win/lose or Grundy) for small n (≤ 60–200).
2. Print the sequence; look for: period, arithmetic progression, powers of two, dependence on n mod k, Fibonacci/golden-ratio structure.
3. Verify on all small values; then prove or trust and implement the closed form.
4. For two-parameter games (a, b), print the 2D table and look for diagonals/lines.

---

### 4.8 Interactive & Optimal-Move Output

**Recognise it when…** Judge plays against you; you must *output* moves.
- Compute the winning move (e.g. Nim: reduce a pile so XOR = 0), keep invariant "after my move the position is losing for the opponent".
- When you are in a losing position, make a *delaying* move (smallest change) hoping for an error if the judge is imperfect — but usually the interactor ensures you are winning.

---

### 4.9 Game Theory — Pitfalls

1. Applying Sprague–Grundy to partizan games.
2. Forgetting that terminal position under misère is winning for the mover who is *not* to move (depends on definition).
3. XORing Grundy values for components that are not independent.
4. Overflow in Grundy bounds (values can be large: ≤ number of options).
5. Assuming brute-force pattern holds beyond tested range without a sanity argument.

---

## 5. GEOMETRY (ALL)

### 5.0 General Geometry Workflow & Precision Policy

**Choose the number type first:**
| Coordinates | Prefer |
|---|---|
| Integers up to ~1e9 | `long long` for dot/cross of differences if |coords| ≤ ~1e9 (cross up to 4e18 fits borderline); beyond that `__int128` |
| Integers up to ~1e4–1e6 | `long long`, all exact |
| Real input / need sqrt / angles | `long double` (or `double`) with epsilon (typically 1e-9…1e-12 relative) |
| Rational exact results needed (areas, intersections) | Keep numerator/denominator in integers (avoid divisions until the end) |

**Golden rules**
1. Use **cross product signs** (orientation) instead of angles or slopes — no division, no precision loss.
2. Avoid `atan2` and `sqrt` unless needed; compare **squared distances**.
3. Epsilon only for floating coordinates; never mix epsilon logic with integer exact predicates.
4. Handle **degenerate cases explicitly**: collinear points, duplicate points, zero-length segments, vertical lines, polygons with collinear vertices, zero area.
5. Watch input orientation (CW vs CCW) — normalise (take absolute area or reverse).
6. When the answer is "count" over geometric objects, prefer **sorting + sweep** to O(n²) checks.

---

### 5.1 Points, Vectors, Dot/Cross Product, Orientation

**What it gives you:** The primitive predicates for all geometry.

**Recognise it when…** Any problem with coordinates; "left/right turn", "clockwise", "collinear", "angle between", "perpendicular", "parallel", "area of triangle".

**Core uses**
| Quantity | Tool | Meaning |
|---|---|---|
| Cross(a, b) > 0 | Orientation | b is CCW from a (left turn) |
| Cross = 0 | Collinear/parallel | |
| Dot(a, b) = 0 | Perpendicular | |
| Dot(a, b) > 0 | Acute angle | |
| |Cross|/2 | Triangle area | |
| Cross/|b| | Signed distance from point to line | |
| Dot/|b|² | Projection parameter | |

**Typical patterns**
1. **Angle sorting around a point** (polar sort): sort by half-plane then by cross product; used for counting triangles, visibility, angular sweep, convex hull (Graham scan).
2. **Counting collinear points / lines through ≥ k points:** normalise direction by gcd and sign → hash map (O(n²) for n ≤ ~2000–5000).
3. **Counting right/acute/obtuse triangles among n points:** sort by angle around each point; use two pointers.
4. **Complex numbers** as 2D vectors (rotation by multiplication).
5. **Rotation by 90°:** (x, y) → (−y, x) — useful for perpendicular directions in integer problems.
6. **Slope comparisons:** compare using cross-multiplication, never floating division.

**Pitfalls:** Overflow of cross product; mixing signed/unsigned; atan2 precision; −0.0 outputs.

---

### 5.2 Lines, Rays, Segments

**Recognise it when…** "Intersect", "distance from point to segment", "reflect", "projection", "do these two segments cross", "minimum distance between segments", "line through two points".

**Typical patterns**
1. **Point on segment test:** collinear + within bounding box (or dot-product test).
2. **Segment–segment intersection (yes/no):** orientation tests on 4 triples + special collinear overlap cases.
3. **Intersection point of two lines:** solve with cross products; parallel/coincident cases flagged first.
4. **Distance point–line, point–segment:** projection clamped to [0,1].
5. **Distance segment–segment:** if they intersect 0; else min of 4 point–segment distances.
6. **Line representation choices:** (point, direction) for geometry; ax+by+c=0 with integer normalisation (divide by gcd, fix sign) when you need to **hash/compare lines** exactly.
7. **Reflection / mirror problems** (light rays, billiards): unfold the plane by reflecting the target instead of the ray.
8. **Half-plane tests:** "is point inside the convex region defined by lines?" → all cross products ≥ 0.
9. **Ray shooting / visibility:** sort by angle and sweep.

**Not useful when…** Many segments (≥ 1e5) and you need *all* intersections — use sweep line (§5.5).

---

### 5.3 Polygons

**Recognise it when…** "Polygon", "area", "inside/outside", "convex", "simple", "vertices given in order", "perimeter", "centroid", "cut", "lattice points".

**Typical patterns**
1. **Area (shoelace formula):** sum of cross products; sign tells orientation. Use doubled area as an integer to stay exact.
2. **Point in polygon:** ray casting / winding number (handle boundary explicitly); for convex polygons use binary search O(log n) after fan triangulation from vertex 0.
3. **Convexity check:** all consecutive cross products have the same sign (allow zero for collinear).
4. **Centroid** (area-weighted triangles) — be careful with zero area.
5. **Pick's theorem:** A = I + B/2 − 1, with B = ∑ gcd(|dx|, |dy|) over edges → count interior lattice points, or area from lattice counts.
6. **Polygon clipping/cutting by a line** (Sutherland–Hodgman for convex): used for "area of region that satisfies half-plane constraints".
7. **Triangulation / ear clipping** and **area decomposition**: sum signed triangle areas from a fixed origin (works for non-convex polygons too).
8. **Polygon intersection area** (convex∩convex via half-plane intersection or clipping; general via sweep — rare).
9. **Minkowski sum of two convex polygons:** merge edge vectors by angle — O(n+m). Appears in "collision / can shape A fit with translation", "sum of vectors choice", and in DP optimisations.
10. **Point-to-polygon distance, polygon diameter/width:** convex → calipers.
11. **Simple polygon properties:** self-intersection test (O(n log n) sweep or O(n²) brute for small n), orientation, kernel (half-plane intersection of all edges → "star-shaped" polygon test).
12. **Triangle counting with polygon:** number of triangles containing origin / inside polygon via angular sorting and complement counting.

**Pitfalls:** Duplicate/collinear vertices; polygon given CW; large coordinates → overflow in shoelace (use `__int128` or long double).

---

### 5.4 Convex Hull & Everything Built on It

**What it gives you:** The outer boundary; most extremal geometric questions live on the hull.

**Recognise it when…**
- "Smallest enclosing convex shape", "perimeter of the fence", "farthest pair", "largest triangle/quadrilateral area", "minimum bounding rectangle", "maximise a linear function over points" (answer lies on hull).
- Queries "max of ax + by over a set of points" repeated → hull + binary search / ternary search.
- Dynamic point insertion with hull queries → dynamic hull / Li Chao.

**Typical patterns**
| Task | Tool |
|---|---|
| Hull of n points | Andrew's monotone chain O(n log n); decide whether to keep collinear points on hull |
| Diameter (farthest pair) | **Rotating calipers** on hull |
| Minimum-area/perimeter bounding rectangle | Rotating calipers (edge-aligned rectangles) |
| Width / minimum distance between parallel supporting lines | Calipers |
| Largest-area triangle / quadrilateral inscribed | Hull + two-pointer/calipers |
| Minkowski sum | Merge hull edges by angle |
| Tangents from a point to a convex polygon | Binary search on hull |
| Point in convex polygon | O(log n) binary search |
| Maximise a·x + b·y over a point set, many queries | Hull + binary search by angle / ternary search |
| **Convex Hull Trick** (lines version, DP optimisation) | Dual of hull of points (lines y = mx + c); monotone slopes → deque, else Li Chao tree |
| Dynamic hull | Balanced BST / Li Chao / offline divide & conquer |
| 3D hull | Incremental O(n²)/O(n log n) — rare |
| Layers of hull ("onion peeling") | Repeated hull — rare |
| Pair of points with max/min dot/cross | Hull + calipers |

**Not useful when…** The answer is not extremal (e.g. needs interior points) or number of points tiny.

**Pitfalls:** Duplicate points; all points collinear (hull degenerate → 1–2 points); handling `≤` vs `<` in the turn test; calipers when hull has < 3 points.

---

### 5.5 Sweep Line & Divide-and-Conquer Geometry

**Recognise it when…** n up to 1e5–1e6 objects, and question involves overlaps/proximity: "closest pair of points", "do any two segments intersect", "area of union of rectangles", "number of intersecting pairs", "skyline", "maximum overlap".

| Problem | Technique |
|---|---|
| Closest pair of points | Divide & conquer on x with strip of width d (O(n log n)); or sweep line with an ordered set |
| Any pair of segments intersects? | Shamos–Hoey sweep (ordered set of segments by y at sweep x) |
| Report all intersections | Bentley–Ottmann O((n+k) log n) |
| Union area of axis-aligned rectangles | Sweep over x with segment tree on compressed y (cover count + covered length) |
| Perimeter of union of rectangles | Sweep with same tree or two passes |
| Max overlap of intervals/rectangles | Event sort + counter / segment tree with range add + max |
| Count points in rectangles (many queries) | Offline sweep + BIT (2D dominance counting) |
| Skyline | Sweep with multiset of heights |
| Largest empty rectangle | Sweep/stack-based on sorted coordinates |
| Interval scheduling on a line | Greedy by end time |
| Visibility from a point | Angular sweep with a heap/set of nearest segments |
| Manhattan-distance problems | Rotate (x, y) → (x+y, x−y) → Chebyshev; then sorting + BIT |

**Pitfalls:** Event ordering at equal coordinates (open before close or vice versa); coordinate compression; segment comparator consistency in ordered sets.

---

### 5.6 Circles

**Recognise it when…** "Circle", "radius", "tangent", "disc coverage", "smallest enclosing circle", "circles intersect", "area of union of discs".

**Typical patterns**
1. **Circle–line intersection:** project centre onto line, compare distance to radius, compute half-chord.
2. **Circle–circle intersection:** distance d vs r₁ + r₂, |r₁ − r₂|; intersection points along the centre line; area of lens via circular segment formulas.
3. **Tangents:** from a point to a circle (2 or 1 or 0); common tangents of two circles (up to 4).
4. **Circle through three points** (circumcircle) — intersection of perpendicular bisectors; used for Delaunay/enclosing circle.
5. **Minimum enclosing circle:** Welzl's randomised algorithm, expected O(n); or ternary-search nested (small n).
6. **Is a point inside any of n circles** / coverage decisions: sort by angle, intervals on circle (angular intervals + union).
7. **Maximum number of points covered by a unit circle** (given points): for each point as boundary, angular sweep of intervals over other points within 2r → O(n² log n).
8. **Area of union of circles:** Green's theorem on arcs (angular intervals).
9. **Circle–polygon intersection area:** sum over polygon edges of signed area of triangle(centre, edge) ∩ circle.
10. **Inversion:** transforms circles through the inversion centre into lines — used in tangent-circle chain problems (Apollonius, Descartes' theorem for curvatures: (k₁+k₂+k₃+k₄)² = 2(k₁²+…+k₄²)).
11. **Binary search on radius / answer** with geometric feasibility check (e.g. "smallest r such that circles of radius r around points cover…").

**Pitfalls:** Tangent cases (d = r₁+r₂) with epsilon; negative values under sqrt (clamp to 0); angle wrap-around when merging arcs.

---

### 5.7 Triangles, Trigonometry & Classical Constructions

**Recognise it when…** "triangle with sides a, b, c", "angles", "incircle/circumcircle", "centroid", "orthocenter".

**Useful facts**
- Area: Heron's formula; ½·a·b·sin C; cross product.
- Law of cosines / sines for reconstructing triangles from sides/angles.
- Centres: centroid (average of vertices), circumcentre (perpendicular bisectors), incentre (side-length-weighted average of vertices), orthocentre (H = A + B + C − 2O).
- Euler line: centroid divides O–H in ratio 1:2.
- Triangle inequality for feasibility; "can these lengths form a triangle / polygon?" (largest < sum of rest).
- Isoperimetric/extremal facts: with fixed perimeter, max area for regular polygon; maximum of ab sin C etc. (ternary search on unimodal functions).
- Pick/lattice/complex-number representations for equilateral and rotation constructions.

**Typical ICPC uses:** Building geometric primitives (circumcircle for Delaunay/enclosing circle), computing areas/volumes with sides given, constructing coordinates from side lengths (place first edge on the x-axis, compute others by law of cosines).

---

### 5.8 Nearest Neighbours, Voronoi, Delaunay, kd-tree

**Recognise it when…** "For each point find the nearest other point", "minimum spanning tree of points in the plane (Euclidean)", "largest empty circle", "nearest facility to each query".

| Task | Tool |
|---|---|
| Closest pair | D&C (§5.5) |
| All-nearest-neighbours / nearest-to-query | kd-tree (average fast; worst-case bad), grid hashing if distances bounded |
| Euclidean MST for n ≈ 1e5 | Delaunay triangulation (O(n log n) edges ≤ 3n) → Kruskal |
| Manhattan MST | Sweep in 4 (or 8 octant) directions + BIT → O(n log n) candidate edges → Kruskal |
| Largest empty circle / Voronoi cell areas | Voronoi diagram (dual of Delaunay) / half-plane intersection per point (O(n² log n) for small n) |
| Nearest point within radius, many points on dense grid | Uniform grid bucketing |
| Offline nearest-neighbour with insertions | kd-tree / sqrt decomposition |

**Not useful when…** Contest limits allow O(n²) (n ≤ 3000).

---

### 5.9 Half-Plane Intersection & Linear Constraints in 2D

**Recognise it when…** "Region satisfying many linear inequalities", "does a point exist that satisfies all constraints", "kernel of polygon", "feasible region area", "LP with 2 variables", "largest circle inscribed in convex region".

**Typical patterns**
1. **Half-plane intersection (sort by angle + deque, O(n log n)):** yields convex polygon (maybe empty/unbounded — add bounding box).
2. **2D linear programming:** maximise a·x + b·y subject to constraints → HPI then evaluate hull vertices, or randomised incremental LP (Seidel).
3. **Kernel of a star-shaped polygon:** HPI of all edges' left half-planes.
4. **Voronoi cell:** HPI of bisectors.
5. **Binary search + HPI:** "maximise r such that shrunk constraints still feasible" (e.g. largest inscribed circle: shift each half-plane inward by r and check non-empty).

**Pitfalls:** Parallel same-direction lines (keep the tighter one), unbounded regions, empty intersection detection, epsilon.

---

### 5.10 Counting & Combinatorial Geometry Patterns

**Recognise it when…** "How many triangles / lines / pairs / lattice points …" among n points or in a region.

| Task | Method |
|---|---|
| Lattice points on a segment (including endpoints) | gcd(|dx|, |dy|) + 1 |
| Lattice points inside a polygon | Pick's theorem |
| Lattice points under a line / in a triangle | **Floor sum** (∑⌊(a·i + b)/m⌋) via Euclid-like recursion |
| Number of distinct lines determined by n points | Normalised direction hashing |
| Number of triangles with positive area | C(n,3) − collinear triples (hash by line / slopes around each point) |
| Number of triangles containing the origin | Total − triangles within a half-plane (angular sort, two pointers) |
| Number of right triangles | For each vertex, group vectors by direction, pair perpendicular groups (hash by normalised direction) |
| Number of parallelograms | Hash midpoints of all pairs |
| Number of squares / rectangles from points | Hash set + enumerate diagonal pairs (O(n²)) |
| Pairs of points at distance exactly d | Hash/grid |
| Pairs of segments intersecting | Sweep + BIT (O(n log n)) |
| Max points on a line | Slope-hashing O(n²) |
| Max points in a unit disk / rectangle | Angular sweep / sliding window over sorted coordinates |
| Visible points from origin | Count lattice points with gcd(x,y) = 1 (Möbius / φ) |
| Regions formed by chords/lines | Euler's formula V − E + F = 2 with intersection counting (e.g. n lines in general position → 1 + n + C(n,2) regions) |
| Number of paths in grid with geometric constraints | Combinatorics (§2.2/2.4) |
| Minimum number of lines to cover points | Bitmask DP for small n |

---

### 5.11 3D Geometry & Spherical Geometry

**Recognise it when…** (x, y, z) points; "plane", "sphere", "polyhedron", "volume", "latitude/longitude", "great-circle distance".

**Typical patterns**
1. **3D cross/dot products:** normal of a plane, volume of tetrahedron (scalar triple product / 6), distance point-plane.
2. **Line–plane / line–sphere / sphere–sphere intersection:** solve quadratics; volume of sphere intersection (lens/caps).
3. **Convex hull in 3D:** surface area/volume/diameter — incremental algorithm (n ≤ ~1000–2000).
4. **Great-circle distance:** convert lat/long → unit vectors, angle = atan2(|cross|, dot) (more stable than acos) times radius; **points on a sphere visible/within cap**, spherical excess for triangle area.
5. **Rotation of points about an axis** (Rodrigues' formula), quaternions in rotation-heavy tasks.
6. **Projection / shadow problems:** reduce to 2D by projecting along an axis.
7. **Volume of union of boxes / spheres:** coordinate compression + sweep, or Monte-Carlo-free decompositions.

**Pitfalls:** acos domain errors (clamp to [−1, 1]); lat/long degree/radian mixing; wrap-around of longitude at ±180°.

---

### 5.12 Geometry + Optimisation Tricks

| Trick | When |
|---|---|
| **Binary search on answer + geometric feasibility** | "Minimise the maximum distance / radius / time" and feasibility is monotone |
| **Ternary search** | Unimodal (convex) function of a continuous parameter, e.g. minimise distance to polygon, optimal point on a segment/line |
| **Nested ternary search** | Convex in two variables (small precision demands) |
| **Gradient/Simulated annealing** | Last resort for continuous optimisation with loose tolerance |
| **Coordinate transforms** | Rotate 45° for Manhattan→Chebyshev; scale axes; translate to origin to reduce magnitude |
| **Duality** (point ↔ line) | Convert point-hull queries ↔ line queries, CHT |
| **Affine invariance** | Shear/scale to simplify (areas ratios preserved) |
| **Angular sweep** | Circular intervals, visibility, "max points within an angle" |
| **Randomised incremental** | Smallest enclosing circle, LP, hull — expected linear/log |
| **Pick + Euler + Shoelace** | Area/lattice counting identities |
| **Pigeonhole/grid hashing** | Closest-pair-like tasks with bounded density |

---

### 5.13 Geometry — Master Pitfalls List

1. Using `double` with `==`; comparing floats without epsilon (or using epsilon with integer predicates unnecessarily).
2. Overflow in cross products for coordinates ≥ 1e9.
3. Not handling degenerate polygons (zero area, repeated vertices, all collinear).
4. Ties in sorting (angle sort with same direction → sort by distance).
5. Mishandling the "pointing exactly at a vertex" case in ray casting.
6. `acos`/`asin` of values slightly outside [−1, 1] → NaN; `sqrt` of tiny negative.
7. Printing `-0.000` (add +0.0 or fix).
8. Forgetting that segment intersection includes touching endpoints (problem may or may not count them).
9. Assuming general position — always check parallel/vertical/coincident cases.
10. Choosing O(n²) with n = 1e5 — look for sort + sweep/hull.

---

## 6. BASIC GRAPH THEORY (Supporting Prerequisite)

> These are the "basic" tools that Math & Geometry problems frequently lean on (graphs hidden inside number-theory, game, or geometry problems).

### 6.1 Recognising a Graph Hidden in the Statement

| Statement smell | Graph model |
|---|---|
| "States and transitions", "reachable configurations", "minimum steps to transform X into Y" | Vertices = states, edges = moves → BFS |
| Numbers with "x → y if gcd/divides/differs by …" | Graph on integers (often implicit) |
| "Dependencies", "must come before" | DAG → topological sort |
| "Pairs that conflict", "two groups / teams / colours" | Bipartite check / 2-colouring |
| "Cities and roads / cables / connect all cheaply" | MST |
| "Network connectivity, critical nodes/edges" | Bridges/articulation points |
| "Functional graph: each node has exactly one outgoing edge (i → f(i))" | Cycle + trees hanging; cycle detection, binary lifting; also number-theory `x → x² mod m` sequences |
| "Game on a graph" | DAG DP / retrograde (§4.4) |
| "Moving on a grid" | Implicit graph, BFS/Dijkstra |
| "Points in the plane connected if distance ≤ d" | Geometric graph: grid hashing, DSU, MST (Delaunay) |

### 6.2 Traversals: BFS / DFS

- **BFS:** shortest path in unweighted graph / implicit state space; multi-source BFS (distance to nearest special cell); **0-1 BFS** for weights 0/1; BFS on bitmask states.
- **DFS:** connected components, cycle detection, tree DP, topological order, bridge-finding, Euler tour (subtree = interval).
- **Useful cases:** reachability, parity colouring (bipartite), counting components, finding order of processing.
- **Not useful when:** weights vary (use Dijkstra), or graph is implicit and astronomically large (look for structure).
- **Pitfalls:** recursion depth (1e5–1e6 nodes → iterative DFS); resetting visited between tests.

### 6.3 Shortest Paths

| Weights / constraints | Algorithm |
|---|---|
| Unweighted | BFS |
| 0/1 weights | 0-1 BFS |
| Non-negative, one source | Dijkstra O((V+E) log V) |
| Negative edges, single source | Bellman–Ford (also detects negative cycles); SPFA with care |
| All pairs, V ≤ ~400–500 | Floyd–Warshall O(V³) (also transitive closure, minimax paths) |
| DAG | DP in topological order (also longest path) |
| "Exactly k edges", small V | Matrix (min,+) power |
| Few distinct weights / small distance range | Dial's / bucket BFS |
| Implicit residue graph (coin problem, "reachable sums mod m") | Dijkstra on residues (see §1.8) |

**Pitfalls:** overflow of INF + weight; negative cycles; multiple edges/self-loops; disconnected nodes.

### 6.4 DSU (Union–Find) & MST

- **DSU:** dynamic connectivity (only unions), components counting, Kruskal, offline "connectivity over time" (with rollback or reverse time), parity/weighted DSU (bipartiteness, relative offsets, "x − y = d" consistency).
- **MST (Kruskal/Prim):** minimum bottleneck path = path on MST; "minimum maximum edge"; second-best MST; Euclidean/Manhattan MST (§5.8).
- **Number-theory use:** DSU over integers connected via common prime/divisor ("a_i and a_j share a factor") → union each number with its prime factors.
- **Pitfalls:** path compression + union by size; forgetting to count only component roots.

### 6.5 Trees

| Need | Tool |
|---|---|
| Distance between nodes, path queries | LCA (binary lifting / Euler tour + sparse table) |
| Diameter, farthest nodes | Two BFS/DFS or DP |
| Subtree sums/queries | Euler tour (tin/tout) + BIT/segment tree |
| Path queries with updates | HLD (heavy-light) |
| DP over tree (independent set, counting colourings, matching) | Tree DP (post-order) |
| Answer for every root | Rerooting DP |
| Counting pairs at distance k / with property | Centroid decomposition, small-to-large merging |
| Tree isomorphism/hash | Canonical hash |
| Counting labelled trees | Cayley/Prüfer (§2.9) |

### 6.6 Connectivity Structures

- **SCC (Tarjan/Kosaraju):** condensation DAG; 2-SAT (satisfiability of pairwise clauses) → implication graph + SCC.
- **Bridges / articulation points / biconnected components:** "critical road", "which single failure disconnects".
- **Bipartite matching:** (Kuhn/Hopcroft–Karp), König's theorem (min vertex cover = max matching), Hall's theorem (existence of perfect matching), assignment problems.
- **Max-flow / min-cut:** capacity problems, bipartite matching generalisation, project selection (min-cut), edge-disjoint paths.
- **Euler path/circuit:** degree-parity conditions; "draw without lifting pen", constructing strings with all pairs (de Bruijn).
- **Hamiltonian-type brute force:** bitmask DP for V ≤ 20 (TSP).

### 6.7 Basic Graph Theory — Pitfalls

1. Directed vs undirected confusion; multi-edges/self-loops.
2. Using adjacency matrix when V = 1e5.
3. Not resetting global arrays across test cases.
4. Choosing recursion for deep graphs.
5. Missing implicit edges (grids' diagonals, wrap-around).

---

## 7. BASIC DP (Supporting Prerequisite)

### 7.1 When DP Is the Right Tool

**Recognise it when…**
- Choices at each step with overlapping subproblems; "maximise / minimise / count the number of ways".
- Greedy fails on small cases (counter-examples exist).
- Constraints suggest polynomial: n ≤ 5000 (O(n²)), n ≤ 500 (O(n³)), n·W ≤ 1e7 (knapsack), n ≤ 20 (bitmask), digits ≤ 19 (digit DP).
- The statement has a **prefix/suffix/interval/subset/tree/DAG structure** you can define states on.

**DP design checklist**
1. **State:** what minimal information describes the sub-problem? (index, remaining capacity, mask, last choice, tight flag …)
2. **Transition:** which previous states feed this one?
3. **Base cases / order of evaluation.**
4. **Answer extraction:** which state(s) form the answer.
5. **Complexity:** states × transitions; check against constraints; look for optimisation (prefix sums, monotonic queue, bitset).

### 7.2 Classic DP Families (Pattern → Recognition)

| Family | Recognise it when… | Complexity (typical) |
|---|---|---|
| **0/1 knapsack** | Choose items each once; weight limit W | O(nW); bitset for feasibility |
| **Unbounded knapsack / coin change** | Items reusable; count ways or min coins | O(nW) |
| **Bounded knapsack** | Multiple copies per item | Binary splitting / monotone queue |
| **Subset sum / partition** | "Can a subset sum to S?" | bitset O(nS/64) |
| **LIS / LNDS** | Longest increasing subsequence; patience sorting | O(n log n) |
| **LCS / edit distance** | Two strings/sequences, alignment | O(nm) |
| **Grid paths** | Moves right/down, obstacles, collect max | O(nm) (or combinatorics if no obstacles) |
| **Interval DP** | Merge/split segments: matrix chain, palindromic partitions, "remove blocks", game on ends | O(n³) (Knuth → O(n²)) |
| **Bitmask DP** | n ≤ 20: TSP, assignment, set covering, tiling | O(2ⁿ·n) / O(3ⁿ) for subset-of-subset |
| **Broken-profile (SOS) DP** | Tilings of grid with narrow width (≤ 10–12) | O(nm·2^w) |
| **Digit DP** | Count/sum numbers ≤ N with digit property | O(digits × states × 10) |
| **Tree DP** | Independent set, subtree counting, rerooting | O(n) |
| **DP on DAG** | Longest/shortest path, counting paths | O(V+E) |
| **Probability / expected value DP** | Expected steps, probability of outcome | state-size dependent |
| **Counting DP with modulus** | "Number of sequences/arrays/strings with property mod p" | often O(n·k); optimise with prefix sums |
| **Partition / composition DP** | Split array into k segments minimising cost | O(n²k) → D&C / CHT / Knuth optimisation |
| **Matrix-exponent DP** | Linear transitions, n up to 1e18 | O(k³ log n) |
| **Sum-over-subsets (SOS) DP** | For each mask, aggregate over submasks/supermasks | O(2ⁿ·n) |
| **String DP with automaton** | Count strings avoiding patterns | KMP/Aho–Corasick states |

### 7.3 DP Optimisation Pointers (When Basic DP Is Too Slow)

| Symptom | Optimisation |
|---|---|
| dp[i] = min_j (dp[j] + cost) with cost = f(i)·g(j) (lines) | **Convex hull trick / Li Chao** (§5.4 duality) |
| dp[i][j] = min_{k<j}(dp[i−1][k] + C(k,j)) with monotone opt | **Divide & conquer optimisation** |
| Interval DP with quadrangle inequality | **Knuth optimisation** |
| Transition is sum over a range | **Prefix sums** / sliding-window |
| Transition min/max over a sliding window | **Monotone deque** |
| dp over values with convolution structure | **FFT/NTT** (§3) |
| dp over subsets with subset-of-subset | **SOS / subset convolution** |
| Many states are unreachable | Hash-map DP / memoised recursion |
| Feasibility with large sums | **Bitset** |
| Layers depend only on previous layer | **Rolling array** (memory) |

### 7.4 Basic DP — Pitfalls

1. Wrong state (missing info that affects future decisions).
2. Counting the same configuration twice (order ambiguity) — fix by canonical ordering.
3. Modulo missing in additions; negative values after subtraction.
4. Uninitialised/INF handling (INF + cost overflow).
5. Greedy vs DP confusion — test on small cases with brute force.

---

## 8. CROSS-TOPIC GUIDE: HOW THE TOPICS COMBINE

### 8.1 Frequent Combinations in ICPC

| Combination | Typical problem |
|---|---|
| Number theory + combinatorics | Counting arrays with gcd/lcm condition mod p (Möbius + powers) |
| Combinatorics + DP | Counting with constraints, optimise DP with factorial formulas |
| Combinatorics + FFT | Stirling/partition rows, Lagrange/Taylor shifts, "count paths with weights" |
| Number theory + FFT | Modular product counting via discrete log; Dirichlet-style transforms |
| Game theory + XOR/FWHT | Count winning/losing arrangements of piles |
| Game theory + DP/pattern | Compute Grundy values to find period |
| Geometry + sorting/sweep | Hull, closest pair, union area, angular sweep |
| Geometry + binary search | Minimise max radius/time with feasibility check |
| Geometry + number theory | Lattice points, gcd of vectors, Pick's theorem, floor sums |
| Graph + number theory | Implicit graphs on integers, DSU on prime factors, functional graphs (cycles of x→f(x) mod m) |
| Graph + geometry | Euclidean MST, visibility graph + Dijkstra, planar graph Euler formula |
| DP + geometry | Convex hull trick, polygon triangulation DP (O(n³)), travelling-salesman on points |
| Probability + linear algebra | Markov chains → Gaussian elimination mod p |

### 8.2 Decision Flow (Quick Triage)

```
Read statement
 ├─ Two players / optimal play? ──► §4 Game theory
 ├─ Coordinates / shapes / angles? ──► §5 Geometry
 ├─ "Count mod p"? 
 │    ├─ small n, DP state clear ──► §7 DP
 │    ├─ closed form likely (selection, arrangement) ──► §2 Combinatorics
 │    ├─ gcd / divisor / coprime in the condition ──► §1.5 Möbius / inclusion–exclusion
 │    ├─ sum over i+j=k, n ≥ 1e5 ──► §3 NTT
 │    └─ n up to 1e18 with recurrence ──► §2.7 matrix / Kitamasa
 ├─ Big numbers / primes / remainders? ──► §1 Number theory
 ├─ Objects connected / reachable / ordering? ──► §6 Graph
 └─ Otherwise: search for invariants, parity, monotonicity, binary search on answer
```

### 8.3 What Appears Most in ICPC Regionals (Practical Frequency Guide)

| Tier | Topics | Comment |
|---|---|---|
| **Almost every contest** | Modular arithmetic, binomials, sieve/gcd, basic geometry (hull, polygon area, segment intersection), DP, graphs | Must be fluent |
| **Common** | Möbius/φ, Catalan/IEP, Lucas, CRT, nim/Grundy, closest pair/sweep, point-in-polygon, circle intersections | Know the recognition cues |
| **Occasional** | NTT/FFT, Burnside, Pollard-rho, matrix-tree, half-plane intersection, Minkowski sum, rotating calipers, Lagrange interpolation | Have templates ready |
| **Rare / elite** | Min_25, Delaunay, bitwise subset convolution, FPS exp/log/composition, partizan CGT, 3D hull | Know they exist; study if time permits |

### 8.4 Time-Box Strategy in Contest

1. Identify topic in ≤ 2 minutes using §0.1.
2. Verify constraints against §0.2 *before* committing.
3. Write brute force for small cases whenever the topic is "pattern-finding" (games, recurrences, polynomial interpolation).
4. If a formula is derived, test on 3–4 small cases by hand/brute force.
5. Pre-decide integer type & modulus handling; write helper functions once.

---

## 9. PRE-CODE CHECKLISTS

### 9.1 Universal Checklist
- [ ] Re-read constraints; choose target complexity.
- [ ] Multiple test cases? Precompute shared data once; reset state.
- [ ] Edge cases: n = 0/1, all equal, max values, empty input, answer 0.
- [ ] Overflow analysis (int / long long / `__int128`).
- [ ] Modulus type: prime? NTT-friendly? composite?
- [ ] Output format: modulo, precision digits, "−1" for impossible.

### 9.2 Number Theory
- [ ] Is the modulus prime? Do I need inverses?
- [ ] Is a sieve limit acceptable? Memory?
- [ ] Is a divisor-sum/Möbius transform better than brute force?
- [ ] Do I need 64-bit multiplication safety?

### 9.3 Combinatorics
- [ ] Ordered/unordered? Distinct/identical? Labelled/unlabelled?
- [ ] Complement or inclusion–exclusion simpler?
- [ ] Factorials large enough? n < mod?
- [ ] Verified formula on small n by brute force?

### 9.4 FFT/NTT
- [ ] Mod 998244353-friendly? If not, 3-mod or split.
- [ ] Output size and padding to power of two.
- [ ] Precision check for FFT (max value²·length).
- [ ] Indicator arrays for counting.

### 9.5 Game Theory
- [ ] Impartial? Normal vs misère? Independent components?
- [ ] Brute-force small cases to detect pattern.
- [ ] Draw states possible?

### 9.6 Geometry
- [ ] Integer vs floating; epsilon plan.
- [ ] Degenerate cases (collinear, duplicates, zero area).
- [ ] Polygon orientation, closed vs open, boundary included?
- [ ] Sorting ties; angle wrap-around.
- [ ] Is an O(n log n) sweep/hull available instead of O(n²)?

---

## 10. TOPIC → PRACTICE SOURCES (Where to Drill Each Pattern)

> Section names below refer to well-known public problem collections. Problem IDs are intentionally omitted to avoid mistakes — search by section/topic name.

| Topic | Where to practise |
|---|---|
| Number theory fundamentals | CSES Problem Set — *Mathematics* section; Codeforces problems tagged `number theory` |
| Sieve/Möbius/φ | Codeforces tag `number theory` (rating 1800+), SPOJ classical (e.g. coprime-pairs, GCD sum style) |
| Modular arithmetic, CRT, discrete log | Library Checker (Discrete Logarithm, Sqrt Mod, Factorize, Primality Test) |
| Combinatorics | CSES *Mathematics* (binomial, Catalan/bracket, Stirling-type, distribution problems); AtCoder ABC/ARC "count mod 998244353" problems |
| Generating functions / FFT / NTT / FPS | Library Checker — *Convolution*, *Convolution mod 1e9+7*, *Inv/Log/Exp of Formal Power Series*, *Multipoint Evaluation*, *Bitwise XOR Convolution*, *Subset Convolution*; AtCoder Library Practice Contest (convolution) |
| Game theory | CSES *Mathematics* game problems (Nim Game I/II, Stair Game, Grundy's Game); Codeforces tag `games` |
| Geometry | CSES *Geometry* section (point location, segment intersection, polygon area/lattice points, point in polygon, convex hull, closest pair, Manhattan distances); Codeforces tag `geometry`; Kattis geometry problems |
| Basic graph | CSES *Graph Algorithms*, *Tree Algorithms* |
| Basic DP | CSES *Dynamic Programming*; AtCoder Educational DP Contest (26 problems A–Z) |
| ICPC-style mixed | Past ICPC regionals (ICPC Live Archive, Codeforces Gym), Kattis |

**Suggested drilling order:** (1) modular arithmetic + binomials → (2) sieve + gcd + Möbius → (3) inclusion–exclusion + Catalan → (4) game theory (Nim → Grundy) → (5) geometry primitives → hull → sweep → circles → (6) NTT basics → FPS → (7) advanced (Burnside, Pollard-rho, HPI, Min_25).

---

## 11. ONE-PAGE REVISION SHEET

**Number theory:** gcd/lcm → Euclid; mod arithmetic → inverse via Fermat (prime) / ext. Euclid; CRT for merged congruences; sieve for ≤ 1e7; Miller–Rabin/Pollard-rho for ≤ 1e18; Möbius/φ for gcd-pair counting; BSGS for aˣ ≡ b; Lucas for small prime moduli.

**Combinatorics:** stars & bars; binomials via factorial tables; complement/IEP for "none/at least"; Catalan/reflection for prefix constraints; Stirling for set partitions; Burnside for symmetry; linear recurrence → matrix/Kitamasa; polynomial sum → Lagrange; expected values → linearity.

**FFT/NTT:** anything "sum over i+j = k" with n ≥ 1e5; mod 998244353 → NTT; other mod → 3-mod/split; wildcard matching → FFT; XOR/AND/OR pair counting → FWHT/zeta; DP with convolution recurrence → CDQ-FFT.

**Game theory:** impartial normal play → Grundy/XOR; Nim variants table; scoring → minimax DP; cyclic → retrograde; unknown pattern → brute-force and detect.

**Geometry:** cross-product orientation; polygons by shoelace/Pick; hull + calipers for extremal; sweep for large n overlaps; circles via distance cases; HPI for linear regions; binary/ternary search for continuous optimisation; precision policy (integers first).

**Graph basics:** BFS/DFS, Dijkstra, DSU/MST, tree tools (LCA, diameter), SCC/2-SAT, matching/flow.

**DP basics:** state–transition–order–answer; knapsack, LIS/LCS, interval, bitmask, digit, tree, DAG, optimisations (prefix sums, CHT, D&C, bitset).

---

*End of Variation 1 — "Where / When / Which pattern". Variation 2 (C++ implementations and usage) can follow the exact same topic numbering (§1–§7) so the two files line up one-to-one.*

