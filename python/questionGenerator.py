#change lines at ******** marks
#create 2 D array in python for dp variable


dp=[]***********
p=[]
i=0
arr=[]
sum,n=0,0
def display (v):
	print(v)

def printSubsetRec(arr,i,sum,p):
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
		b.append(p)
		printSubsetRec(arr,i-1,sum,b)
	elif (sum > arr[i] and dp[i-1][sum - arr[i]]):
		p.append(arr[i])
		printSubsetRec(arr,i-1,sum-arr[i],p)
		

def printAllSubset(arr ,n ,sum):
	if (n==0 or sum <0):
		return
	dp =[[0]* n] * sum+1
	for i in range(0,n):
		for j in range(0,sum+1):
			dp[i][j] = (arr[i] <= j) if (dp[i-1][j] or dp[i-1][j-arr[i]]) else dp[i - 1][j]
	if (dp[n-1][sum] == False):
		print("there is no subset with ",sum)
		return
	p=[]
	printSubsetRec(arr,n-1,sum,p)
