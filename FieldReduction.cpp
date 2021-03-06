//  Copyright © 2017 Dougy Ouyang. All rights reserved.

#include <iostream>
#include <algorithm>

using namespace std;
typedef pair<int, int> pii;
pii cow[50050], rcow[50050], tcow[15];
int n, s=0, t=3, small=1600000000;

void del(int a, int b, int c)
{
    int r1=41000, r2=0, c1=41000, c2=0;
    int i;
    for(i=0;i<n;i++){
        if(cow[i]==tcow[a] || cow[i]==tcow[b] || cow[i]==tcow[c]){
            continue;
        }
        if(cow[i].first<r1)
            r1=cow[i].first;
        if(cow[i].first>r2)
            r2=cow[i].first;
        if(cow[i].second<c1)
            c1=cow[i].second;
        if(cow[i].second>c2)
            c2=cow[i].second;
    }
    if((r2-r1)*(c2-c1)<small)
        small=(r2-r1)*(c2-c1);
    return;
}

int main()
{
    int i, j, k;
    
    cin >> n;
    if(n<=3){
        cout << "0" << endl;
        return 0;
    }
    for(i=0;i<n;i++){
        cin >> cow[i].first >> cow[i].second;
        rcow[i].first=cow[i].second, rcow[i].second=cow[i].first;
    }
    
    sort(cow, cow+n);
    sort(rcow, rcow+n);
    tcow[0]=cow[0], tcow[1]=cow[1], tcow[2]=cow[2];
    i=n-1;
    while(i>=0 && s<3){
        bool used=false;
        for(j=0;j<t;j++){
            if(rcow[i]==tcow[j]){
                used=true, i--;
                break;
            }
        }
        if(!used){
            tcow[t]=cow[i], i--, t++, s++;
        }
    }
    i=0, s=0;
    while(i<n && s<3){
        bool used=false;
        for(j=0;j<t;j++){
            if(rcow[i].first==tcow[j].second && rcow[i].second==tcow[j].first){
                used=true, i++;
                break;
            }
        }
        if(!used){
            tcow[t].first=rcow[i].second, tcow[t].second=rcow[i].first, i++, t++, s++;
        }
    }
    i=n-1, s=0;
    while(i>=0 && s<3){
        bool used=false;
        for(j=0;j<t;j++){
            if(rcow[i].first==tcow[j].second && rcow[i].second==tcow[j].first){
                used=true, i--;
                break;
            }
        }
        if(!used){
            tcow[t].first=rcow[i].second, tcow[t].second=rcow[i].first, i--, t++, s++;
        }
    }
    
    for(i=0;i<t;i++){
        for(j=i+1;j<t;j++){
            for(k=j+1;k<t;k++){
                del(i, j, k);
            }
        }
    }
    
    cout << small << endl;
    
    return 0;
}
