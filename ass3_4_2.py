import heapq

def min_distance(points, n):
    # points를 노드화
    for i in range(n):
        for j in range(n):
            if i!=j:
                x1=points[i][0]
                y1=points[i][1]
                x2=points[j][0]
                y2=points[j][1]
                
                distance = ((x1-x2)**2 + (y1-y2)**2)**0.5
                
                adj[i].append([distance, j])
                adj[j].append([distance, i])
    
    # 최소 스패닝 트리
    distance = 0.0
    cnt = 0
    while pq:
        if cnt == n+1:
            break
        w, s = heapq.heappop(pq)
        if not visited[s]:
            visited[s] = True
            distance += w
            cnt += 1
            for i in adj[s]:
                heapq.heappush(pq, i)
    
    return distance
    

# points = [(12,-3),(1,1),(2,9),(8,3),(1,0),(111,-678),(1,4),(3,3),(2,-1),(9,32),(-11,-45), (-11, -45)] #739.36
points = [(1, 5), (2,4), (3, 3), (9,7), (6,3), (3,3)] # 10.82
points = list(set(points)) # 중복 제거
n = len(points)

visited = [False]*(n+1)
adj = [[] for i in range(n+1)] 
pq = [[0, 1]]


print(min_distance(points, n))