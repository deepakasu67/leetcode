
# def numberOfConnection(gridOfNodes):
#     prev = 0
#     connections = 0
#
#     for i  in range(len(gridOfNodes)):
#         sum = 0
#         for j in range(len(gridOfNodes[i])):
#             sum += gridOfNodes[i][j]
#         if(sum > 0):
#             connections += prev * sum
#             prev = sum
#     return connections
#
# # gridNodes = [[1,1,1],[0,1,0],[0,0,0],[1,1,0]]
# gridNodes = [[1,0,1,1],[0,1,1,0],[0,0,0,0],[1,0,0,0]]
# print(numberOfConnection(gridNodes))

# def largestRepackaged(arrivingPackets):
#     twoPowers = {}


def fn( stockPrice, k):
    n =len(stockPrice)
    if k == 0 or k > n :
        return 0
    ans = 0
    preCompute = [-1 for i in range(n)]
    i = 0
    curr = 0
    for i in range(n - 1):
        if stockPrice[i+1] > stockPrice[i]:
            curr+=1
        else:
            preCompute[i-curr] = curr + 1
            curr = 0

    preCompute[i-curr] = curr + 1
    for i in range(n):
        if preCompute[i] != -1 and preCompute[i] >= k:
            ans += preCompute[i] - k + 1

    return ans

print(fn([1,2,3,4], 4))



