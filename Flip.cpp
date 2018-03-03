#include <bits/stdc++.h>

using namespace std;

int N, K;
char S[10000];

void _main(int TEST)
{
    scanf("%d%s", &K, S);
    N=strlen(S);
    int ans=0;
    for(int i=0; i+K-1<N; i++) if(S[i]=='0')
    {
        for(int j=0; j<K; j++)
            S[i+j]^='0'^'1';
        ans++;
    }
    for(int i=0; i<N; i++) if(S[i]=='0')
        ans=-1;
    if(ans==-1)
        printf("IMPOSSIBLE\n");
    else
        printf("%d\n", ans);
}

int main()
{
	
    int TEST;
    scanf("%d", &TEST);
    for(int i=1; i<=TEST; i++)
    {
        //cerr << i << endl;
        printf("Case #%d: ", i);
        _main(i);
    }
    return 0;
}
