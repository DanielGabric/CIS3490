#include <stdio.h>
#include <string.h>
#define EXIT() do{printf("You need one argument to check LP\n");return -1;}while(0)
int main(int argc, char * argv[]){
    if(argc < 2 || argc > 2)EXIT();
    char *sequence=argv[1];
    int N = strlen(sequence),i,j,m[N+1][N+1];
    memset(m,0,sizeof(m));
    /*Longest common subsequence*/
    for(i=1;i<=N;++i)
        for(j=1;j<=N;++j)
            if(sequence[i-1]==sequence[N-j]) m[i][j]=m[i-1][j-1]+1;
            else m[i][j]= ((m[i-1][j])>(m[i][j-1]))?(m[i-1][j]):(m[i][j-1]);
    /*Reading out the longest palindrome*/
    for(i=j=N;i>0&&j>0;)
        if(m[i-1][j]==m[i][j])i--;
        else if(m[i][j-1]==m[i][j])j--;
        else if(m[i][j]-m[i-1][j-1]==1){
            j--;
            i--;
            printf("%c",sequence[i]);
        }
    printf("\n%d\n",m[N][N]);
    return 0;
}