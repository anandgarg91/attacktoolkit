<img src="attacker1.png" width="80" height="80">

# Attacktoolkit

* Different attack scripts for PBA
* Program will change the ttl value and stored the packet in file

# Prerequisite

sudo apt-get install libpcap-dev

# How to compile and run for ttl attack

* The program is inside ttl folder 
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

* Tcp sequence number starts form 39th byte (4 byte length)
* Ack number starts from 43rd byte (4 bytes)
* These numbers are relative 
* To get the absolute packet length (Ack of receiver - sequence of sender to decode the next seq)

# Tcp segement length to predict the next sequence

* The program is inside tcpseg folder
* output of new_fourbyte program will give the requires seg and ack number to get the tcp segment length

# Program to get the TCP seg length

* Program name hex2dec.c 
* compilation: gcc hex2dec -lm
* The output is the absolute value of segment length

# Run both the attacks in one

* chmod +x toolkit.sh
* run ./toolkit.sh
