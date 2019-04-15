#!/bin/bash

cd ttl
gcc onebyte.c -lpcap
./a.out capture04.pcap test.pcap
cd ../tcpseg
gcc fourbyte.c -lpcap
./a.out sixpacket.pcap
