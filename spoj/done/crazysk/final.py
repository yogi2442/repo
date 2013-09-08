test = raw_input()
for i in range(0,int(test)):
	line = raw_input()
	words = line.split()
	n = words[0]
	k = words[1]
	items = int(n)
	cards = int(n)
	j = 1
	while(int(cards) >= int(k)):
		j = int(cards)/int(k)
		items = int(items) + int(j)
		cards = (int(cards))%int(k) + int(j)
	print int(items)
