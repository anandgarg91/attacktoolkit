#include "stdio.h"
#include<time.h>
#include<pcap.h>

void print_packet_info(const u_char *packet, struct pcap_pkthdr packet_header);

int main(void)
{
const u_char *packet;
struct pcap_pkthdr packet_header;
pcap_t *pcap_open_offline(const char *fname, char *errbuf);

char error_buffer[PCAP_ERRBUF_SIZE];
pcap_t *handle = pcap_open_offline("capture04.pcap", error_buffer);

packet = pcap_next(handle, &packet_header);
if(packet == NULL){
	printf("No packet found");
	return 2;
}

print_packet_info(packet, packet_header);
return 0;

}

void print_packet_info(const u_char *packet, struct pcap_pkthdr packet_header){
	printf("pcaket cap length: %d\n", packet_header.caplen);
	printf("pcaket total len %d\n", packet_header.len);
	const u_char *temp_pointer = packet+22;
	printf("%x", *temp_pointer);
		
}



