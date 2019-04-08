#!/usr/bin/python 

import sys
import os

input_file = sys.argv[1]
output_file = sys.argv[2]

print input_file
print output_file

str = "tcprewrite --ttl -i "+sys.argv[1]+" -o "+sys.argv[2]

print str
#os.system(str)
