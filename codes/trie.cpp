#include <bits/stdc++.h>
using namespace std;

const int N = 2e6 + 5;

int nxt[N][26];
int cnt[N];
int endmark[N];
int nodes = 1;

void insert(string s){
    int cur=0;
    for(char ch:s){
        int c=ch-'a';
        if(!nxt[cur][c]) nxt[cur][c]=nodes++;
        cur=nxt[cur][c];
        cnt[cur]++;
    }
    endmark[cur]++;
}

bool search(string s){
    int cur=0;
    for(char ch:s){
        int c=ch-'a';
        if(!nxt[cur][c]) return false;
        cur=nxt[cur][c];
    }
    return endmark[cur]>0;
}

bool startsWith(string s){
    int cur=0;
    for(char ch:s){
        int c=ch-'a';
        if(!nxt[cur][c]) return false;
        cur=nxt[cur][c];
    }
    return true;
}

int prefixCount(string s){
    int cur=0;
    for(char ch:s){
        int c=ch-'a';
        if(!nxt[cur][c]) return 0;
        cur=nxt[cur][c];
    }
    return cnt[cur];
}

void erase(string s){
    if(!search(s)) return;
    int cur=0;
    for(char ch:s){
        int c=ch-'a';
        cur=nxt[cur][c];
        cnt[cur]--;
    }
    endmark[cur]--;
}