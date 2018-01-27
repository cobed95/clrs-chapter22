def transpose_adj_lst(A):
    
    transpose = []
    
    for i in range(len(A)):
        transpose.append([])
    
    for i in range(len(A)):
        for j in range(len(A[i])):
            transpose[A[i][j]].append(i)

    return transpose
           
def main():
    A = [[2,3,4],[0,2],[4],[1],[3]]
    print(transpose_adj_lst(A))

if __name__ == '__main__':
    main()
