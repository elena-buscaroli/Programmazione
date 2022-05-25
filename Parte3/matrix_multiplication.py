from shutil import register_unpack_format


class Matrix():
    def __init__(self, A):
        '''
        `A` -> lista di liste, dove ogni lista `a_i` corrisponde alla riga `i`
        della nostra matrice.
        m = Matrix(A) 
        m._A 
        m.n_righe
        '''
        self._A = A  # _A significa che l'attributo non dovrebbe essere modificato
        self.n_righe = len(self._A) 
        self.n_cols = len(self._A[0]) 

    def __getitem__(self, y):
        '''
        Definiamo il dunder method "__getitem__" che ci permetterà di accedere 
        ad un elemento dell'oggetto tramite lo "slice".
        In questo caso, definiamo il methodo in modo che torni la riga all'indice `y`.
        
        `y` -> intero, indice della riga che vogliamo ottenere
        '''
        return self._A[y]  # riga all'indice y

    def __repr__(self):
        '''
        Dunder method che viene utilizzato quando chiamo la funzione "print" su un 
        oggetto della classe Matrix.
        '''
        return '\n'.join('{}'.format(row) for row in self._A)

    def __add__(self, A): 
        '''
        Definendo il dunder method "__add__", stiamo definendo l'operazione di somma
        tra due matrici. In questo modo possiamo chiamare l'oprando "+" tra due oggetti
        Matrix A e B come A+B.
        In questo caso, quando sommo due matrici A e B, voglio ottenere una matrice 
        C = A + B per cui ogni elemento C[i,j] sia uguale a A[i,j] + B[i,j].

        `A` -> Matrix, The matrix to be summed up
        '''
        self_mat = self.copy()
        for y in range(self.n_righe):
            for x in range(self.n_cols):
                self_mat[y][x] += A[y][x]
        return self_mat

    def __sub__(self, A):
        '''
        Definendo il dunder method "__sub__", stiamo definendo l'operazione di sottrazione
        tra due matrici. In questo modo possiamo chiamare l'oprando "-" tra due oggetti
        Matrix A e B come A-B.
        In questo caso, quando sommo due matrici A e B, voglio ottenere una matrice 
        C = A - B per cui ogni elemento C[i,j] sia uguale a A[i,j] - B[i,j].

        `A` -> Matrix, The matrix to be subtracted up
        '''
        self_mat = self.copy()
        for y in range(self.n_righe):
            for x in range(self.n_righe):
                self_mat[y][x] -= A[y][x]
        return self_mat

    def copy(self):
        A = [[value for value in row] for row in self._A]
        return Matrix(A)

    def submatrix(self, from_row, n_rows, from_col, n_cols):
        A = []
        for row in self._A[from_row : from_row + n_rows]:
            A.append(row[from_col : from_col + n_cols])
        
        return Matrix(A)

    def assign_submatrix(self, from_row, from_col, A):
        new_A = self._A
        for y, row in enumerate(A):  # (0, [...])
            self_row = self._A[y + from_row] 
            for x, value in enumerate(row):
                self_row[x + from_col] = value
            new_A[y + from_row] = self_row
        
        self._A = new_A


def naive_matrix_mult(A, B):
    '''
    `A`, `B` -> matrici di dimensione `NxN`
    '''
    if A.n_cols != B.n_righe:
        raise ValueError("Le matrici non possono essere moltiplicate!")
    
    # creiamo la matrice C, con valori inizializzati a zero, che conterrà il risultato
    # C = []
    # for row in range(A.n_righe):
    #     C.append(list())
    #     for col in range(B.n_cols):
    #         C[row].append(0)

    # Possiamo scrivere i due for scritti sopra in un'unica linea con una LIST COMPREHENSION
    C = [ [0 for col in range(B.n_cols)] for row in range(A.n_righe) ]

    for row in range(A.n_righe):
        for col in range(B.n_cols):
            value = 0
            for k in range(A.n_cols):
                value = value + A[row][k] * B[k][col]
            
            C[row][col] = value

    return Matrix(C)



def get_matrix_quadrant(A):
    '''
    `A` -> Matrix
    '''
    A11 = A.submatrix(0, A.n_righe//2, 0, A.n_cols//2)
    A12 = A.submatrix(0, A.n_righe//2, A.n_cols//2, A.n_cols//2)
    A21 = A.submatrix(A.n_righe//2, A.n_righe//2, 0, A.n_cols//2)
    A22 = A.submatrix(A.n_righe//2, A.n_righe//2, A.n_cols//2, A.n_cols//2)

    return A11, A12, A21, A22  # i valori vengono ritornati come una TUPLA di 4 elementi


def strassen_matrix_mult(A, B):
    '''
    `A`, `B` -> matrici di dimensione `NxN`
    '''
    if max(A.n_righe, B.n_cols, A.n_cols) < 2:
        return naive_matrix_mult(A, B)

    # posso assegnare i 4 valori tornati dalla funzione "get_matrix_quadrant" direttamente
    # "get_matrix_quadrant" torna 4 valori che vengono salvati da Python in una tupla di 4 elementi
    # in questo modo: A11 conterrà il valore della tupla all'indice 0, A12 all'indice 1 ecc
    A11, A12, A21, A22 = get_matrix_quadrant(A)
    B11, B12, B21, B22 = get_matrix_quadrant(B)

    S1 = B12 - B22  # l'operando "-" chiama il dunder method "__sub__" definito nella classe Matrix
    S2 = A11 + A12  # lo stesso vale per l'operando "+"
    S3 = A21 + A22
    S4 = B21 - B11
    S5 = A11 + A22
    S6 = B11 + B22
    S7 = A12 - A22
    S8 = B21 + B22
    S9 = A11 - A21
    S10 = B11 + B12

    P1 = strassen_matrix_mult(A11, S1)
    P2 = strassen_matrix_mult(S2, B22)
    P3 = strassen_matrix_mult(S3, B11)
    P4 = strassen_matrix_mult(A22, S4)
    P5 = strassen_matrix_mult(S5, S6)
    P6 = strassen_matrix_mult(S7, S8)
    P7 = strassen_matrix_mult(S9, S10)

    C11 = P5 + P4 - P2 + P6
    C12 = P1 + P2
    C21 = P3 + P4
    C22 = P5 + P1 - P3 - P7

    result = Matrix([[0 for col in range(B.n_cols)] for row in range(A.n_righe)])

    result.assign_submatrix(0, 0, C11)
    result.assign_submatrix(0, result.n_cols//2, C12)
    result.assign_submatrix(result.n_righe//2, 0, C21)
    result.assign_submatrix(result.n_righe//2, result.n_cols//2, C22)

    return result




if __name__ == '__main__':
    from random import randint, seed
    from sys import stdout
    seed(0)	# i set the seed to 0

    size = 4
    # Creo due matrici A e B di dimensione size x size e valori random
    A = Matrix([[randint(0,10) for _ in range(size)] for _ in range(size)])
    B = Matrix([[randint(0,10) for _ in range(size)] for _ in range(size)])

    C1 = naive_matrix_mult(A, B)
    C2 = strassen_matrix_mult(A, B)
    print("Matrice A:")
    print(A, "\n")
    print("Matrice B:")
    print(B, "\n")
    print("Matrice C1=AxB calcolata con algoritmo naive:")
    print(C1, "\n")
    print("Matrice C2=AxB calcolata con algoritmo Strassen:")
    print(C2)
