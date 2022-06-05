from cmath import inf


class node():
    def __init__(self, idx, dist=0, pred=None, color="white"):
        self.idx = idx
        self.dist = dist
        self.pred = pred
        self.color = color


class graph():
    def __init__(self, E=list(), V=list(), directed=False, weighted=False):
        self.directed = directed  # Boolean che indica se il grafo è orientato o no
        self.weighted = weighted
        self.n = len(V)  # numero di nodi

        self._set_nodes(V)  # lista con i vertici del grafo
        self.adj = dict()
        self._set_edges(E)  # dictionary con nodo:edges del grafo


    def _set_nodes(self, V):
        self.V = [0 for _ in range(max(V)+1)]
        for v in V:
            self.V[v] = node(v)


    def _set_edges(self, E):
        if len(E) == 0:
            return {k:list() for k in self.V.idx}
        
        self.E = dict()
        for edge in E:
            self.add_edge(edge)


    def _create_edge(self, src, dest, weight=0):
        node = (dest, weight)
        self.E[src] = self.E.get(src, list())  # otteniamo i nodi adiacenti a src o una list vuota
        self.E[src].append(node)
        
        if not self.directed:
            node = (src, weight)
            self.E[dest] = self.E.get(dest, list())  # otteniamo i nodi adiacenti a src o una list vuota
            self.E[dest].append(node)


    def _update_adj(self, src, dest):
        self.adj[src] = self.adj.get(src, set())  # ad ogni chiave, il valore è un SET di vertici adiacenti
        self.adj[src].add(dest)

        self.adj[dest] = self.adj.get(dest, set())
        self.adj[dest].add(src)


    def add_edge(self, edge):
        '''
        Aggiunge un edge tra il nodo `src` e il nodo `dest`, con peso `weight`.
        Se `weight` non è dato come input, assumiamo che il grafo abbia archi non pesati.
        '''
        src, dest = edge[:2]
        if self.weighted:
            weight = edge[2]
        else:
            weight = 0

        # aggiungo l'edge tra src e dest
        self._create_edge(src, dest, weight)
        # sistemiamo le adiacencies
        self._update_adj(src, dest)
        # settiamo i nodi nel modo corretto
        self._update_nodes()


    def _update_nodes(self):
        # per ogni nodo nel dizionario di nodi adiacenti, 
        for v in sorted(self.adj.keys()):
            if v >= len(self.V):
                self.V.append(node(v))


    def update_edge(self, src, dest, weight=0):
        for i in self.E[src]:
            if i[0]==dest and i[1]>weight:
                i[1] = weight
                return
        self.add_edge((src, dest, weight))


    def print_dp(self):
        out = '\t'.join(['V','Dist', 'Pred']) + '\n'
        for v in self.V:
            out += f'{v.idx}\t{v.dist}\t{v.pred}\n'
        print(out)

    
    def _initialize_nodes(self):
        for v in self.V:
            v.color = "white"
            v.dist = 0
            v.pred = None


    def BFS(self, src):
        self._initialize_nodes()
        # consideriamo i nodi come interi da 0 a n
        # list di Booleani, per ogni nodo indica se è stato visitato o meno
        queue = []  # creiamo la coda

        # aggiungiamo src alla coda e lo settiamo come visitato
        queue.append(src)
        self.V[src].color = "grey"

        while len(queue) > 0:
            # per ogni iterazione, togliamo il primo nodo dalla coda
            src = queue.pop(0)
            
            # prendiamo la lista di nodi adiacenti a src,
            # visitiamo quelli non ancora visitati e
            # li aggiungiamo alla coda
            for node_idx in self.adj[src]:
                if self.V[node_idx].color == "white":
                    self.V[node_idx].color = "grey"
                    self.V[node_idx].dist = self.V[src].dist + 1
                    self.V[node_idx].pred = src
                    queue.append(node_idx)
            
            self.V[src].color = "black"
