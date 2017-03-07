// reverse rows and then transposition
func rotate(matrix [][]int)  {
    n := len(matrix)
    for i:=0;i<n/2;i++{
        temp:=matrix[i]
        matrix[i]=matrix[n-1-i]
        matrix[n-1-i]=temp
    }
    for i:=0;i<n;i++{
        for j:=i+1;j<n;j++{
            temp:=matrix[i][j]
            matrix[i][j]=matrix[j][i]
            matrix[j][i]=temp
        }
    }
}


// transposition and then reverse colums
func rotate(matrix [][]int)  {
    n := len(matrix)
    for i:=0;i<n;i++{
        for j:=i+1;j<n;j++{
            temp:=matrix[i][j]
            matrix[i][j]=matrix[j][i]
            matrix[j][i]=temp
        }
    }
    for i:=0;i<n;i++{
        for j:=0;j<n/2;j++{
            temp:=matrix[i][j]
            matrix[i][j]=matrix[i][n-1-j]
            matrix[i][n-1-j]=temp
        }
    }
}


// swap for each element of one quadrant with the ones in other three quadrants
func rotate(matrix [][]int)  {
    n := len(matrix)
    a,b:=0,n-1
    for a<b {
        for i:=0;i<b-a;i++{
            matrix[a][a+i], matrix[a+i][b] = matrix[a+i][b], matrix[a][a+i]
            matrix[a][a+i], matrix[b][b-i] = matrix[b][b-i], matrix[a][a+i]
            matrix[a][a+i], matrix[b-i][a] = matrix[b-i][a], matrix[a][a+i]
        }
        a++
        b--
    }
}