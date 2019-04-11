# attacktoolkit
different attack scripts for PBA
Program will change the ttl value and stored the packet in file

# Prerequisite

sudo apt-get install libpcap-dev

# How to compile and run

* gcc onebyte.c -lpcap
* ./a.out input_file outputfile

Note: input file here is the captured pcap file 

# Pcap format to run the wireshark on pcap

outputfile of above program will act as a input for text2pcap

* outputfile.pcap is generated from text2pcap tool it requires the 
input file in certain order which is in inputfile.pcap

* text2pcap -d inputfile outputfile

# To get specific range of packet

editcap -r oldfile newfile 1-10

# Tcp Sequence details

* Tcp sequence number starts form 35th byte (2 byte length)
* Ack number starts from 37th byte (2 bytes)
* These numbers are relative 
* To get the absolute packet length (Ack of receiver - sequence of receiver to decode the next seq)



