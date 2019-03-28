def display (v):
    print(v)

def printAllSubset(arr ,n ,sum):
    if (n==0 or sum <0):
        return
    dp = [[False] * (sum + 1) for i in range(n)]
    for i in range(0, n):
        dp[i][0] = True
    if (arr[0] <= sum):
        dp[0][arr[0]] = True
    print(dp)
    for i in range(1, n):
        for j in range(0, sum+1):
            print(i, j)
            dp[i][j] = (dp[i-1][j] or dp[i-1][j-arr[i]]) if (arr[i] <= j) else dp[i-1][j]
    if (dp[n-1][sum] == False):
        print("there is no subset with ", sum)
        return
    p=[]
    print(dp)
    print(len(dp))
    printSubsetRec(arr, n-1, sum, p, dp)


def printSubsetRec(arr, i, sum, p, dp):
    if (i==0 and sum != 0 and dp[0][sum]):
        p.append(arr[i])
        display(p)
        p=[]
        return
    elif (i==0 and sum ==0):
        display(p)
        p=[]
        return
    elif (dp[i-1][sum]):
        b= []
        b= p.copy()
        printSubsetRec(arr, i-1, sum, b, dp)
    elif (sum > arr[i] and dp[i-1][sum - arr[i]]):
        p.append(arr[i])
        printSubsetRec(arr, i-1, sum-arr[i], p, dp)



arr = [17,18,19,20,21,3, 8, 3, 6, 4]
n = len(arr)
sum = 14
printAllSubset(arr, n, sum)

