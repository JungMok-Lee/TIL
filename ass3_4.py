import sys
import heapq


n = int(input())

visited = [False]*(n+1)
Elist = [[] for i in range(n+1)] 
heap = [[0, 1]]

points=[[0]*2 for i in range(1001)]
# points를 input으로 줄 경우
for i in range(n):
    x, y = map(int, input().split())
    points[i][0]=x;
    points[i][1]=y;

# points를 리스트로 바로 선언해서 이용할 경우.
#points = [[12,-3],[1,1],[2,9],[8,3],[1,0],[111,-678],[1,4],[3,3],[2,-1],[9,32],[-11,-45]]

for i in range(n):
    for j in range(n):
        if i!=j:
            x1=points[i][0]
            y1=points[i][1]
            x2=points[j][0]
            y2=points[j][1]
            
            distance = ((x1-x2)**2 + (y1-y2)**2)**0.5
            
            Elist[i].append([distance, j])
            Elist[j].append([distance, i])
            
answer = 0
cnt = 0
while heap:
    if cnt == n+1:
        break
    w, s = heapq.heappop(heap)
    if not visited[s]:
        visited[s] = True
        answer += w
        cnt += 1
        for i in Elist[s]:
            heapq.heappush(heap, i)
 
print(answer)