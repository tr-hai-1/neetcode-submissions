#pragma GCC optimize("O3,fast-math,unroll-loops")

#include <bits/stdc++.h>
using namespace std;

static constexpr size_t max_align = alignof(max_align_t);
alignas(max_align) static unsigned char BUFFER[64 * 1024 * 1024];
static size_t pos = 0;

void *operator new(const size_t size) {
    const size_t padding = (max_align - (pos % max_align)) % max_align;
    pos += padding + size;
    return static_cast<void *>(&BUFFER[pos - size]);
}

void *operator new[](const size_t size) { return operator new(size); }
void operator delete(void *) noexcept {}
void operator delete[](void *) noexcept {}
void operator delete(void *, size_t) noexcept {}
void operator delete[](void *, size_t) noexcept {}

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();

class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> chars;
        int maxFreq = 1;
        int res = 0;
        int last = 0;

        for (int i = 0; i < s.length(); ++i) {
            ++chars[s[i]];
            maxFreq = max(maxFreq, chars[s[i]]); 

            if ((i - last + 1) - maxFreq > k) {
                --chars[s[last++]];
            }

            res = max(res, i - last + 1);
        }

        return res;
    }
};