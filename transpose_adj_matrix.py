def transpose_adj_matrix(A):
    
    transpose = []
    
    for i in range(len(A)):
        transpose.append([])
    
    for i in range(len(A)):
        for j in range(len(A[i])):
            transpose[i].append(A[j][i])

    return transpose

def main():
    A = [[0,0,1,1,1],[1,0,1,0,0],[0,0,0,0,1],[0,1,0,0,0],[0,0,0,1,0]]
    print(transpose_adj_matrix(A))

if __name__ == '__main__':
    main()
