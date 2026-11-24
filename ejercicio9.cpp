#include <cassert>
#include <string>
#include <iostream>
#include <limits>

using namespace std;
int maxLikes(int* convierte,int* likes, int bailo,int*** memo, int k, int r, int d){
    if(r>k){
        return 0;
    }
    if(memo[r][d][bailo]!=-1){
        return memo[r][d][bailo];
    }
    
    int diferenciaN=d+convierte[r];
    int likesBaile=numeric_limits<int>::min();;
    if(diferenciaN>0){
        //atajo?
        //no
        if(bailo==1){
           likesBaile=likes[r]/2 + maxLikes(convierte,likes,1,memo,k,r+1,diferenciaN-1);
        }else{
           likesBaile=likes[r] + maxLikes(convierte,likes,1,memo,k,r+1,diferenciaN-1);

        }

    }
    int likesNoBaile=maxLikes(convierte,likes,0,memo,k,r+1,diferenciaN);
    memo[r][d][bailo]=max(likesNoBaile,likesBaile);
    return memo[r][d][bailo];
}
int main()
{
    int k;
    cin>>k;
    int* convierte=new int[k+1];
    int* likes=new int[k+1];
    int*** memo=new int**[k+1];
    for(int i=1;i<=k;i++){
        int ai;
        cin>>ai;
        convierte[i]=ai;
        memo[i]=new int*[k];
        for(int j=0;j<k;j++){
            memo[i][j]=new int[2];
            for(int m=0;m<2;m++){
                memo[i][j][m]=-1;
            }
        }
    }
    for(int i=1;i<=k;i++){
        int ai;
        cin>>ai;
        likes[i]=ai;
    }
    cout<<maxLikes(convierte,likes,0,memo,k,1,0)<<endl;
    return 0;
}