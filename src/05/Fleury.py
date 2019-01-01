# Fleury's Algorithm implementation


import copy

class FleuryException(Exception):
    def __init__(self, message):
        super(FleuryException, self).__init__(message)
        self.message = message

class Fleury:

    COLOR_WHITE = 'white'
    COLOR_GRAY  = 'gray'
    COLOR_BLACK = 'black'

    def __init__(self, graph):

        self.graph = graph

    def run(self):

        print "** Running Fleury algorithm for graph : ** \n"
        for v in self.graph:
            print v, ' => ', self.graph[v]
        print '\n'
        output = None
        try:
            output = self.fleury(self.graph)
        except FleuryException as (message):
            print message

        if output:
            print '** Found Eulerian Cycle : **\n'
            for v in output:
                print v
        print '\n** DONE **'

    def is_connected(self, G):

        start_node = list(G)[0]
        color = {}
        iterator = 0;
        for v in G:
            color[v] = Fleury.COLOR_WHITE
        color[start_node] = Fleury.COLOR_GRAY
        S = [start_node]
        while len(S) != 0:
            u = S.pop()
            for v in G[u]:
                if color[v] == Fleury.COLOR_WHITE:
                    color[v] = Fleury.COLOR_GRAY
                    S.append(v)
                color[u] = Fleury.COLOR_BLACK
        return list(color.values()).count(Fleury.COLOR_BLACK) == len(G)

    def even_degree_nodes(self, G):

        even_degree_nodes = []
        for u in G:
            if len(G[u]) % 2 == 0:
                even_degree_nodes.append(u)
        return even_degree_nodes


    def is_eulerian(self, even_degree_odes, graph_len):

        return graph_len - len(even_degree_odes) == 0


    def convert_graph(self, G):

        links = []
        for u in G:
            for v in G[u]:
                links.append((u, v))
        return links


    def fleury(self, G):

        edn = self.even_degree_nodes(G)
        
        if not self.is_eulerian(edn, len(G)):
            raise FleuryException('This is not an Eulerian graph!')
        g = copy.copy(G)
        cycle = []
        
        u = edn[0]
        while len(self.convert_graph(g)) > 0:
            current_vertex = u
            for u in list(g[current_vertex]):
                g[current_vertex].remove(u)
                g[u].remove(current_vertex)

                bridge = not self.is_connected(g)
                if bridge:
                    
                    g[current_vertex].append(u)
                    g[u].append(current_vertex)
                else:
                    break
            if bridge:
                
                g[current_vertex].remove(u)
                g[u].remove(current_vertex)
                g.pop(current_vertex)
            cycle.append((current_vertex, u))
        return cycle
