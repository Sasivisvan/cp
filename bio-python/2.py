from collections import deque

def build_graph(kmers):
    graph = {}
    n = len(kmers)
    for kmer in kmers:
        graph[kmer] = []
    for i in range(n):
        for j in range(n):
            if i!=j and kmers[i][1:] == kmers[j][:-1]:
                graph[kmers[i]].append(kmers[j])
                
    return graph
ans =""

def find_hamiltonian_path(graph, kmers, seq, total_size):
    k = len(kmers[0])
    if(len(seq) == total_size):
        print(seq)
        global ans 
        ans = seq
        return True
    
    #dead end
    if len(seq)>=len(kmers[0]):
        if len(graph[seq[-k:]]) == 0:
            return False
        else:
            for kmer in list(graph[seq[-k:]]):
                graph[seq[-k:]].remove(kmer)
                if find_hamiltonian_path(graph, kmers, seq+kmer[-1:], total_size):
                    return True
                graph[seq[-k:]].append(kmer)
    else:
        for kmer in kmers:
            find_hamiltonian_path(graph, kmers, kmer, total_size)
            
    return None
            
patterns = ["GAT", "ATT", "TTA", "TAC", "ACA"]

graph = build_graph(patterns)

find_hamiltonian_path(graph, patterns, "", 7)

print(ans)
    
        
    
    
    
    
                
            
    
                
        
        