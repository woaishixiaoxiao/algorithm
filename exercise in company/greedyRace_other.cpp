#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=1005;

int a[maxn],b[maxn];

int main()
{
     int n;
     while(scanf("%d",&n)&&n)
     {
         for(int i=0;i<n;i++)
             scanf("%d",&a[i]);
         for(int i=0;i<n;i++)
             scanf("%d",&b[i]);
         sort(a,a+n);
         sort(b,b+n);
         int tq=n-1,ts=0,kq=n-1,ks=0;
         int sum=0;
         for(int i=0;i<n;i++)
         {
             if(a[tq]>b[kq])
             {
                 sum+=1;
                 tq--;
                 kq--;
             }
             else
             {
                 if(a[tq]<b[kq])
                 {
                     sum-=1;
                     ts++;
                     kq--;
                 }
                 else
                 {
                     if(a[ts]>b[ks])
                     {
                         sum+=1;
                         ts++;
                         ks++;
                     }
                     else
                     {
                         if(a[ts]<b[kq])
                         sum-=1;
                         ts++;
                         kq--;
                     }
                 }
             }
         }
         printf("%d\n",sum);
     }
     return 0;
}
