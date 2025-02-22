class Solution {
    public int[][] onesMinusZeros(int[][] grid) {
        int m=grid.length;
        int n=grid[0].length;
        int [] row1count=new int[m];
        int [] col1count=new int[n];

        for(int i=0;i<m;i++){
            for(int j=0 ;j<n;j++){
                if(grid[i][j]==1){
                    row1count[i]++;
                    col1count[j]++;
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0 ;j<n;j++){
                grid[i][j]=row1count[i]+col1count[j]-(n-row1count[i])-(m-col1count[j]);    
            }
        }
        return grid;
        
    }
}