#include <stdio.h>
int row_constraints[9][10]={0},col_constraints[9][10]={0}, square_constraints[3][3][10]={0};
int solve(int sudoku[9][9], int val){
    /*Skip over all taken squares*/
    for(;val<=80&&sudoku[val/9][val%9];++val);
    int i,y = val/9,x = val%9;
    if(val >= 81)return 1;
    /*Check constraints for every single number from 1-9 and recurse*/
    /*If promising*/
    for(i=1; i<=9; ++i)
        if(!row_constraints[y][i]&&!col_constraints[x][i]&&!square_constraints[y/3][x/3][i]){
            sudoku[y][x] = i;
            row_constraints[y][i]=col_constraints[x][i]=square_constraints[y/3][x/3][i]=1;
            if(solve(sudoku,val+1))return 1;
            sudoku[y][x]=row_constraints[y][i]=col_constraints[x][i]=square_constraints[y/3][x/3][i]=0;
        }
    return 0;
}
int main(){
    /*To read and write from input.sudoku and output.sudoku*/
    /*Use input/output redirection with '>', and '<'*/
    int i,j,sudoku[9][9];
    /*Read in values from stdin and update row/col/square constraints*/
    for(i=0;i<9;++i)
        for(j=0;j<9;++j){
            scanf("%d",&sudoku[i][j]);     
            if(sudoku[i][j])     
                row_constraints[i][sudoku[i][j]]=col_constraints[j][sudoku[i][j]]=square_constraints[i/3][j/3][sudoku[i][j]]=1; 
        }
    solve(sudoku,0);
    /*Print to stdout*/
    for(i=0;i<9;++i){
        for(j=0;j<9;++j)
            printf("%d ",sudoku[i][j]);
        printf("\n");
    }
    return 0;
}
