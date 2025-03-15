#include <stdio.h>

int main(){
    int t;
    scanf("%i", &t);
    while(t--){
        long long n,m,q;
        scanf("%lld %lld %lld",&n, &m, &q);
        long long arr1[n];
        long long arr2[m];
        for (long long i = 0; i < n; i++)
        {
            scanf("%lld",&arr1[i]);
        }
        for (long long i = 0; i < m; i++)
        {
            scanf("%lld",&arr2[i]);
        }
        long long index = 0;
        bool flg = 1;
        for (long long i = 0; i < m; i++)
        {
            for (long long j = 0; j <= index; j++)
            {
                if (arr2[i]==arr1[j])
                {
                    break;
                }
                else if (arr2[i]!=arr1[j] && j==index)
                {
                    if (arr2[i]==arr1[j+1])
                    {
                        index ++;
                    }
                    else{
                        printf("TIDAK\n");
                        flg = 0;
                    }
                    
                }
                
            }
            
        }
        if(flg) printf("YA\n");
    }
    return 0;
}