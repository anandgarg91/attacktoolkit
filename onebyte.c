#include "stdio.h"
#include<time.h>
#include<pcap.h>
#include<stdlib.h>

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
	
	printf("packet cap length: %d\n", packet_header.caplen);
	printf("packet total len %d\n", packet_header.len);
	unsigned char store[100];
	for(int i=0;i<packet_header.len;i++)
		{
			if(i==22)	
				{
					const u_char *temp = (packet+22);
					store[i]=0x33;
					printf("%x", 0x33);
				}
			else	
				{
					const u_char *temp = packet+i;
					store[i]=*temp;
					printf("%x", *temp);
				}
				
			
		}
printf("\n");
FILE *fptr;
fptr=fopen("testing.pcap","w");
for(int j=0;j<packet_header.len;j++)
{
fprintf(fptr,"%x",store[j]);
}
fclose(fptr);
}


