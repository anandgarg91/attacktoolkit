# attacktoolkit
different attack scripts for PBA
Program will change the ttl value and stored the packet in file

# Prerequisite

sudo apt-get install libpcap-dev

# How to compile and run

* gcc onebyte.c -lpcap
* ./a.out input_file outputfile

# Pcap format to run the wireshark on pcap

outputfile of above program will act as a input for text2pcap

* outputfile.pcap is generated from text2pcap tool it requires the 
input file in certain order which is in inputfile.pcap

text2pcap -d inputfile outputfile
