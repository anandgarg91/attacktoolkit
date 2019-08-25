# parsering script
import sys
import os
import re
import StringIO
myref1 = []
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
		f.flush()
		f.close()
	
def parser():
	f= open("repo.txt","r")
	string = f.read()
	print(string.split())
	myref = string.split()	
	print(myref[0])
	counter = 0
	for i in myref:
		counter = counter+1
		s= i.split("=")[1]
		st = s.split("\"")
		print st[1][1:]
		s1 = "curl https://api.github.com/search/code?q=extension:project+repo:"+st[1][1:]+" > new_parse_"+st[1].split("/")[1]+"_"+st[1].split("/")[2]+".json"
		print s1		
		os.system(s1)
	print counter

def api():
	response = StringIO.StringIO()
	c=pycurl.Curl()
	c.setopt(c.URL, 'curl "https://api.github.com/search/code?q=extension:project+repo:stefandreyer/CODESYS-MQTT')
	c.setopt(c.WRITEFUNCTION, response.write)
	c.setopt(c.HTTPHEADER, ['Content-TYPE: application/json', 'Accept-Charset: UTF-8'])
	c.setopt(c.POSTFIELDS, '@request.json')
	c.perform()
	c.close()
	print response.getvalue()
	response.close()	
	
def api1():
	os.system("curl https://api.github.com/search/code?q=extension:project+repo:stefandreyer/CODESYS-MQTT > new_parse.json")

main()

parser()

#api1()

