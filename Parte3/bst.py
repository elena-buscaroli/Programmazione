class Node():
    def __init__(self, key):
        self.left = None  # punta al nodo a sinistra
        self.right = None  # punta al nodo a destra
        self.val = key


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


def search(root, key):
    # caso base: la radice è NULL (albero vuoro) o la chiave è alla radice
    if root is None or root.val == key:
        return root

    # caso 1: la chiave è maggiore della chiave alla radice
    if root.val < key:
        return search(root.right, key)  # continuo la ricerca nell'sotto-albero destro

    # caso 2: la chiave è minore della chiave alla radice
    return search(root.left, key)  # continuo la ricerca nell'sotto-albero sinistro


def inorder(root):  # per visitare in ordine
    if root:
        inorder(root.left)
        print(root.val)
        inorder(root.right)


def preorder(root):
    if root == None:  # se la radice è Null ritorno
        return
    print(root.val)  # printo il valore della root
    preorder(root.left)  # prima traverso il sotto-albero sinistro
    preorder(root.right)  # poi il sotto-albero destro


def postorder(root):
    if root == None:
        return
    postorder(root.left)  # prima traverso il sotto-albero sinistro
    postorder(root.right)  # poi il sotto-albero destro
    print(root.val)  # printo il valore della root


## min, max

def minimo(root):
    current = root
    # itera fino al nodo più a sinistra
    while current.left is not None:
        current = current.left
    return current


def massimo(root):
    current = root
    # itera fino al nodo più a sinistra
    while current.right is not None:
        current = current.right
    return current


def successore(node):
    if node.right is not None:
        return minimo(node.right)

    else:
        curr = node
        par = node.parent
        while par is not None and par.right is curr:
            curr = par
            par = par.parent
        return par


def rimuovi(root, key):
    # caso base
    if root is None:
        return root

    # se la chiave da rimuovere è minore della chiave della root
    # cerchiamo nel sotto-albero sinistro
    if key < root.val:
        root.left = rimuovi(root.left, key)
    # se la chiave da rimuovere è maggiore della chiave della root
    # cerchiamo nel sotto-albero destro
    elif key > root.val:
        root.right = rimuovi(root.right, key)
    # se la chiave da rimuovere è uguale a quella della root
    else:
        # nodo con un figlio o nessuno
        if root.left is None:
            tmp = root.right 
            root = None
            return tmp
        elif root.right is None:
            tmp = root.left
            root = None
            return tmp

        # nodo con due figli -> cerchiamo il successore
        tmp = minimo(root.right)
        # copiamo il suo valore nel nodo corrente
        root.val = tmp.val
        # rimuoviamo il nodo successore
        root.right = rimuovi(root.right, tmp.val)

    return root


if __name__=="__main__":
    bst = Node(15)
    bst = insert(bst, 7)
    bst = insert(bst, 4)
    bst = insert(bst, 23)
    bst = insert(bst, 32)
    bst = insert(bst, 11)

    inorder(bst) 
    print("\n")
    preorder(bst)
    print("\n")
    postorder(bst)
    print("\n")

    node = search(bst, 11)

    print("Il nodo con valore minimo è:", minimo(bst).val, "\n")
    print("Il nodo con valore massimo è:", massimo(bst).val, "\n")
    
    print("Il nodo successore di 11 è: ", successore(node).val)
