#include <stdio.h>
#define END -1
#define N 100

void printSequence(int prev[N],int sequence[N],int i,int final){
    int properSequence[final];
    int j,k;
    for(j=final-1;j>=0;--j){
        properSequence[j]=i;
        i=prev[i];
    }
    for(j=0;j<final;++j){
        if(j%10==0&&j!=0)printf("\n");
        printf("%d ",sequence[properSequence[j]]);
    }
}

int main(){
    int i,j;
    int final = 1;
    int optimalEnd = 0;
    int lengths[N];
    int prev[N];
    int sequence[N];
    int c=1;
    lengths[0] = 1;
    prev[0] = END;
    freopen("List.txt","r",stdin);
    scanf("%d",&i);
    for(i=0;i<N;++i)scanf("%d",&sequence[i]);
    for (i = 1; i < N; i++){
        lengths[i] = 1;
        prev[i] = END;
        for (j = i - 1; j >= 0; --j){
            if (sequence[j] <= sequence[i]&&lengths[j] + 1 > lengths[i]){
                lengths[i] = lengths[j] + 1;
                prev[i] = j;
            }
        }
        if (lengths[i] > final){
            optimalEnd = i;
            final = lengths[i];
        }
    }
    printf("%d\n",final);
    printSequence(prev,sequence,optimalEnd,final);
    printf("\n");
    return 0;
}
