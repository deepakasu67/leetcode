from collections import defaultdict

def close_to_target(forwardRouteList, returnRouteList, maxTravelDist):
    max_miles_till_now = float('-inf')
    res = defaultdict(list)

    for f in forwardRouteList:
        id1 = f[0]
        miles1 = f[1]
        if miles1 >= maxTravelDist:
            continue
        for r in returnRouteList:
            id2, miles2 = r[0], r[1]
            if miles2 >= maxTravelDist:
                continue
            if miles1 + miles2 <= maxTravelDist and miles1+miles2 >= max_miles_till_now:
                res[miles1 + miles2].append([id1,id2])
                max_miles_till_now = miles1 + miles2

    return res[max_miles_till_now ]


# target=30
# a=[[3,9],[1,9],[2,9],[4,9]]
# b=[[3,11],[2,11],[4,11],[1,11]]
'''
Output: [[2, 4], [3, 2]]
'''
# target = 7000
# a = [[1, 2000], [2, 4000], [3, 6000]]
# b = [[1, 2000]]

target = 10000
a = [[1,3000],[2,5000],[3,7000],[4,10000]]
b= [[1,2000],[2,3000],[3,4000],[4,5000]]
print(close_to_target(a, b, target))
