import sys

class Node(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

def insert(root, key):
    # root è il nodo della radice
    # key è la chiave da inserire
    if root is None:  # se l'albero è vuoto
        return Node(key)  # creo un nodo con chiave=key
    else:
        if root.val == key:  # se la chiave da inserire è presente e corrisponde alla radice, ritorno il nodo esistente
            return root
        elif key > root.val:  # se la chiave da inserire è maggiore della chiave della root
            if root.right is None:  # posso inserire nel nodo a destra
                root.right = Node(key)
            else:
                root.right = insert(root.right, key)  # chiamo ricorsivamente la funzione sul sotto-albero destro
            root.right.parent = root
        else:
            if root.left is None:  # posso inserire nel nodo a sinistra
                root.left = Node(key)
            else:
                root.left = insert(root.left, key)  # # chiamo ricorsivamente la funzione sul sotto-albero sinistro
            root.left.parent = root
    return root

##### Esercizio 1
def array_to_bst(array):
    if not array:
        return None
    mid_num = len(array)//2
    node = Node(array[mid_num])
    node.left = array_to_bst(array[:mid_num])
    node.right = array_to_bst(array[mid_num+1:])
    return node

def preorder(node):
    if not node:
        return
    print(node.val)
    preorder(node.left)
    preorder(node.right)

def inorder(root):  # per visitare in ordine
    if root:
        inorder(root.left)
        print(root.val)
        inorder(root.right)


##### Esercizio 2
def is_bst(root):
    if root is None:
        return True

    # false se il nodo sinistro è > della root
    if root.left is not None and root.left.val > root.val:
        return False
     
    # false se il nodo destro è < della root
    if root.right is not None and root.right.val < root.val:
        return False
     
    # false se ricorsivamente, il sotto-albero sinistro/destro non è un bst
    if not is_bst(root.left) or not is_bst(root.right):
        return False
     
    return True


##### Esercizio 3
def kth_smallest(root, k):
    if root is None:  # caso base
        return None, k

    left, k = kth_smallest(root.left, k)  # cerchiamo nel sotto-albero sinistro
    if left is not None:  # se è stato trovato
        return left, k

    k -= 1
    if k == 0:
        return root, k

    return kth_smallest(root.right, k)  # cerchiamo nel sotto-albero destro


##### Esercizio 4
class Graph():
    INF = sys.maxsize
    def __init__(self, num_vertices):
        self.V = num_vertices
        # self.graph = [[0 for col in range(num_vertices)] for row in range(num_vertices)]  # crea la matrice di adiacenza

    def set_graph(self, adj_mat):
        self.graph = adj_mat

    def min_dist(self, dist, U):
        min = self.INF
        for v in range(self.V):  # per ogni vertice
            if dist[v] < min and v not in U:
                min = dist[v]
                min_index = v
        return min_index

    def prims(self):
        dist = [self.INF for _ in range(self.V)]  # used to pick minimum weight edge
        dist[0] = 0  # pick a random vertex, ie 0

        T = [None for _ in range(self.V)]  # used to store MST
        T[0] = -1  # set the first node to the root (ie have a parent of -1)

        U = []  # lista dei vertici visitati

        for _ in range(self.V):
            u = self.min_dist(dist, U)  # 1. selezioniamo il vertice a distanza minima
            U.append(u)  # 2. aggiungiamo il vertice al minimum spanning tree

            # iteriamo tra i vertici per aggiornare le distanze tra T e gli altri vertici
            for v in range(self.V):
                if self.graph[u][v] > 0 and v not in U and dist[v] > self.graph[u][v]:
                    dist[v] = self.graph[u][v]
                    T[v] = u
        self.T = T

    def print_prims(self):
        print ("Edge\tWeight")
        for dest, src in enumerate(self.T):
            if dest == 0:
                continue
            print (src, "-", dest, "\t", self.graph[src][dest])


if __name__ == "__main__":
    #### Esercizio 1
    print("Esercizio 1")
    array = [1, 2, 3, 4]
    bst1 = array_to_bst(array)
    print("\nArray to balanced BST:")
    inorder(bst1)

    #### Esercizio 2
    print("\nEsercizio 2")
    bst2 = Node(15)
    bst2 = insert(bst2, 7)
    bst2 = insert(bst2, 4)
    bst2 = insert(bst2, 23)
    bst2 = insert(bst2, 32)
    bst2 = insert(bst2, 11)
    inorder(bst2)
    print(is_bst(bst2), "\n")

    bst2b = Node(15)
    bst2b = insert(bst2b, 7)
    bst2b = insert(bst2b, 4)
    bst2b = insert(bst2b, 23)
    bst2b = insert(bst2b, 32)
    bst2b = insert(bst2b, 11)
    bst2b.val = 1
    inorder(bst2b)
    print(is_bst(bst2b))

    #### Esercizio 3
    print("\nEsercizio 3")
    bst3 = Node(20)
    keys = [ 8, 22, 4, 12, 10, 14 ]
    for x in keys:
        bst3 = insert(bst3, x)
    
    k = 4
    res = kth_smallest(bst3, k)
    if res is not None:
        inorder(bst3)
        print(f"{k}-th Smallest Element is", res[0].val)

    #### Esercizio 4
    print("\nEsercizio 4")
    g = Graph(5)
    g.graph = [ [0, 2, 0, 6, 0],
                [2, 0, 3, 8, 5],
                [0, 3, 0, 0, 7],
                [6, 8, 0, 0, 9],
                [0, 5, 7, 9, 0]]
    
    g.prims()
    g.print_prims()
