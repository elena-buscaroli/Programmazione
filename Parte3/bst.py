class Node():
    def __init__(self, key):
        self.left = None  # punta al nodo a sinistra
        self.right = None  # punta al nodo a destra
        self.val = key

def insert(root, key):
    # root è il nodo della radice
    # key è la chiave da inserire
    if root is None:  # se l'albero è vuoto
        return Node(key)  # creto un nodo con chiave=key
    else:
        if root.val == key:  # se la chiave da inserire è presente e corrisponde alla radice, ritorno il nodo esistente
            return root
        elif key > root.val:  # se la chiave da inserire è maggiore della chiave della root
            if root.right is None:  # posso inserire nel nodo a destra
                root.right = Node(key)
            else:
                root.right = insert(root.right, key)  # chiamo ricorsivamente la funzione sul sotto-albero destro
        else:
            if root.left is None:  # posso inserire nel nodo a sinistra
                root.left = Node(key)
            else:
                root.left = insert(root.left, key)  # # chiamo ricorsivamente la funzione sul sotto-albero sinistro
    return root


def search(root, key):
    # caso base: la radice è NULL (albero vuoro) o la chiave è alla radice
    if root is None or root.val == key:
        print(root.val)
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

    search(bst, 11)