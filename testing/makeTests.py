import random as r

#should probably do: test case that has inserts and deletes dynamically

def main():
	r.seed()

	#table size control
	a = 7
	b = 9
	c = 11
	d = 14
	e = 16
	
	with open("output.txt",'w' ) as f:
		f.write("5\n")
		
		f.write(str(a) + " ")
		f.write(str(b) + " ")
		f.write(str(c) + " ")
		f.write(str(d) + " ")
		f.write(str(e) + " ")
		
		f.write("\n")

		#needed so we know what we've added 
		s = set()

		#change xrange to control # of inserts
		for i in xrange(10*(a+b+c+d+e)):
			a = r.randint(0,600)
			f.write("insert " + str(a) + "\n")			
			s.add(a)

		#ensure these all come out as 1
		for i in s:
			f.write("search " + str(i) + "\n")

		#needed so we know what we've deleted in following loop
		discarded = set()

		for i in s:
			if r.randint(0,1) == 0:
				pass
			else:
				f.write("remove " + str(i) + "\n")
				discarded.add(i)

		s = s - discarded

		#first for should result in finds, the next for should result in rejections
		for i in s:
			f.write("search " +  str(i) + "\n")

		for i in discarded:
			f.write("search " + str(i) + "\n")

		f.write("print\n")

main()
