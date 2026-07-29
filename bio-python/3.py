def build_graph(kmers):
    graph = {}
    
    for kmer in kmers:
        
        if kmer[:-1] not in graph:
            graph[kmer[:-1]] = []
        
        graph[kmer[:-1]].append(kmer[1:])
        
    return graph

kmers = [ "GAT", "ATT", "TTA", "TAC", "ACA", "CAT", "ATC", "GAA"]

graph= build_graph(kmers)

for i in graph:
    print(i,": ",end="")
    for j in graph[i]:
        print(j,end=" ")
    print()
    