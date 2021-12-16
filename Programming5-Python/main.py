import heapq

def shortestPath(n,m,s,t, arr):
    adjList = [[] for _ in range(n)] #init adjacency matrix
    for node in arr:
        # Create Adjacency Matrix
        adjList[node[0]].append((node[1], node[2]))

    priorityq = []          #init priorityq
    q = (0, s, m)        #push temp to heap and pq
    heapq.heappush(priorityq, q)    

    while priorityq:        #while priorityq not empty
        temp = heapq.heappop(priorityq)    #pop item in priorityq
        if s == t:
            return 0
        path, currentCity, stop = temp
        if (currentCity == t):
            return path
        if (stop >= 0):
            for node in adjList[currentCity]:
                temp = ((path + node[1]), node[0], stop - 1)
                heapq.heappush(priorityq, temp)
    return -1

#MAIN DRIVER
if __name__ == "__main__":
    n, m = input().split(" ")
    n = int(n)  #number of cities
    m = int(m)  #number of roads
    s, t = input().split(" ")
    s = int(s)  #init city
    t = int(t)  #goal city
    arr = []
    for j in range(m) :
        a = list(map(int,input().strip().split()))[:n]
        arr.append(a)


    #print solution
    sol = shortestPath(n, n, s, t, arr)
    print(sol)
    #choose which algorithm