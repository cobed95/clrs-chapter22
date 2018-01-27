def equivalent_of_multigraph(A):
    
    equivalent = []

    for i in range(len(A)):
        equivalent.append([])

    for i in range(len(A)):
        
        book = [0] * len(A)
        
        for j in range(len(A[i])):
            if A[i][j] != i:
                book[A[i][j]] += 1
        
        for k in range(len(book)):
            if book[k] != 0:
                equivalent[i].append(k)

    return equivalent

def main():
    A = [[1,1,3,3,4],[0,0,4],[2,2,4,5,5],[0,0,4,4,5],[0,1,2,3,3],[2,2,3,5]]
    print(equivalent_of_multigraph(A))

if __name__ == '__main__':
    main()
