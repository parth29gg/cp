#include <chrono>
#include <random>
#include<bits/stdc++.h>
using namespace std;
// 64-bit RNG seeded with the system clock
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

// Generates a random integer in the inclusive range [A, B]
int get_rand(int a, int b) {
    return uniform_int_distribution<int>(a, b)(rng);
}

// Custom hash to prevent anti-hash tests on unordered_map/set
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

// Example Usage:
// unordered_map<int, int, custom_hash> safe_map;