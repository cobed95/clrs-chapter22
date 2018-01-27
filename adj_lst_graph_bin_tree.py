def adj_lst_graph_bin_tree(A):
    adj_lst = []
    for i in range(len(A)):
        adj_lst.append([])
    for i in range(1, len(A)):
        adj_lst[i].append(A[(i-1)//2])
    for i in range((len(A)//2)-1):
        adj_lst[i].extend([A[(2*i)+1], A[(2*i)+2]])
    if len(A)%2 == 0: 
        adj_lst[(len(A)//2)-1].append(A[len(A)-1])
    else:
        adj_lst[(len(A)//2)-1].extend([A[len(A)-2], A[len(A)-1]])
    return adj_lst

def main():
    A = [6, 5, 4, 3, 2, 1, 0]
    print(adj_lst_graph_bin_tree(A))

if __name__ == '__main__':
    main()
