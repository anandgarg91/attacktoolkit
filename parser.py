# parsering script
import sys
import os
import re
x = []
def main():
      
      file = open(sys.argv[1],"r")
      lines = file.readlines()
      file.close()
      count = 0;
      canPrintLines = False
      for line in lines:
	count = count+1;
	line = line.rstrip()
        if re.search("class=\"f3\"",line):#and(re.search("data-ga-click",next(line))):
		count=0;
	if count==2:
		print(line)
		f=open("repo.txt","a+")
		f.write(line)
		f.close()
	
def parser():
	f= open("repo.txt","r")
	string = f.read()
	print(string.split())
	myref = string.split()	
	print(myref[-1])
	

main()
parser()
