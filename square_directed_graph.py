def square_directed_graph_adj_lst(A):

    square = []
    
    for i in range(len(A)):
        square.append([])

    for i in range(len(A)):
        
        book = [0] * (len(A))

        for j in range(len(A[i])):
            book[A[i][j]] += 1

        square_members = [0] * (len(A))

        for k in range(len(A)):
            if book[k] != 0:
                for l in range(len(A[k])):
                    square_members[A[k][l]] += 1
        
        for m in range(len(square_members)):
            if square_members[m] != 0:
                square[i].append(m)

    return square

def square_directed_graph_adj_matrix(A):

    square = []

    for i in range(len(A)):
        square.append([])

    for i in range(len(A)):
        for j in range(len(A[i])):
            aux_sum = 0
            for k in range(len(A[i])):
                aux_sum += A[i][k]*A[k][j]
            square[i].append(aux_sum)

    return square

def main():
    A = [[0,1,0,1,1,0],[0,0,1,0,0,0],[0,0,0,0,1,0],[0,1,0,0,0,1],[0,0,0,0,0,1],[0,0,1,0,0,0]]
    print(square_directed_graph_adj_matrix(A))
    
if __name__ == '__main__':
    main()
