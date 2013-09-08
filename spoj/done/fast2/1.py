a = raw_input()
for i in range(0,int(a)):
	n = raw_input()
	ans = pow(2,int(int(n)+1))
	ans = int(ans) - 1
	ans = int(ans) % 1298074214633706835075030044377087
	print int(ans)
