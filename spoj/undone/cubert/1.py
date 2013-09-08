import re
a = raw_input()

while(int(a) > int(0)):
	n = raw_input()
	if(re.search(r"(\d+)",n)):
		m = pow(int(n),1.0/3)
		print m
		print pow(int(n),1.0/3)
		a = int(a) - 1

#for i in range(0,int(a)):
#	n = raw_input()
#	while( n == "" or re.match(r'( *)',n) ):
#		print n
#		n = raw_input()
#	print int(n)
