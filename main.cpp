#include <cstdio>
#include <iostream>
using namespace std;
int primos[] = {2,3,5,7,11,13,17,19,23,29,31,37,41};
int N, Case = 0, ans[20] = {1};
bool isPrime(int a)
{
    for (int n : primos)
        if (n == a) return true;
    return false;
}
void backtracking(int L, bool visit[])
{
    if (L == N) {
        if (!isPrime(ans[N-1] + 1))
            return;
        printf("1");
        for (int i = 1; i < N; ++i)
            cout << " " <<  ans[i];
        cout << endl;
        return;
    }
    for (int i = 2; i <= N; ++i) {
        if (visit[i]) continue;
        if (isPrime(i + ans[L - 1])) {
            visit[i] = 1;
            ans[L] = i;
            backtracking(L + 1, visit);
            visit[i] = 0;
        }
    }
}
int main()
{
    while (cin >> N) {
        if (Case++)
            cout << endl;
        cout<<"Case "<<Case<<":"<< endl;
        bool visit[20] = {0};
        backtracking(1, visit);
    }
}
