## Time Complexity
> Chapter 2 of antti_book

Use O(x) to estimate the complexity of a program.

## Trick-1
If the program needs to read a large amount of input, we may need to use fast-reading tricks to reduce the IO time.

[SPOJ.com - Problem INTEST](https://www.spoj.com/problems/INTEST/):

```c++
// SPOJ https://www.spoj.com/problems/INTEST/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    // freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k, t=0, x;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>x;
        t = x%k==0? t+1 : t;
    }
    cout<<t<<endl;
    return 0; 
}
```

