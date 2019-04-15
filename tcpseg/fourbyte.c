#include<stdio.h>
#include<time.h>
#include<pcap.h>
#include<stdlib.h>
#include<string.h>
int count;

void my_packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet);

void print_packet_info(const u_char *packet, struct pcap_pkthdr packet_header);

int main(int argc, char **argv)
{
printf("%s",argv[0]);
const u_char *packet;
struct pcap_pkthdr packet_header;
pcap_t *pcap_open_offline(const char *fname, char *errbuf);

char error_buffer[PCAP_ERRBUF_SIZE];
pcap_t *handle = pcap_open_offline(argv[1], error_buffer);

//packet = pcap_next(handle, &packet_header);

pcap_loop(handle, 2, my_packet_handler, NULL);

return 0;

}

void my_packet_handler(u_char *args, const struct pcap_pkthdr *packet_header, const u_char *packet_body)
{

print_packet_info(packet_body, *packet_header);
return;
}


void print_packet_info(const u_char *packet, struct pcap_pkthdr packet_header){
	int count;
	char *s,*s1,*s2;
	//printf("packet cap length: %d\n", packet_header.caplen);
	printf("packet total len %d\n", packet_header.len);
	unsigned char store[1000];
	unsigned char store1[1000];
if(count==0)
	{
		for(int i=0;i<packet_header.len;i++)
			{
				if(i==38)	
					{
						const u_char *temp = (packet+38);
						store[i]=*temp;
						printf("%x", 0x99);
					}

				else if(i==39)	
					{
						const u_char *temp = (packet+39);
						store[i]=*temp;
						printf("%x", 0x99);
							
					}
				else if(i==40)	
					{
						const u_char *temp = (packet+40);
						store[i]=*temp;
						printf("%x", 0x99);
					}
						
				else if(i==41)	
					{
						const u_char *temp = (packet+41);
						store[i]=*temp;
						printf("%x", 0x99);
					}
						
				else	
					{
						const u_char *temp = packet+i;
						store[i]=*temp;
						printf("%x", *temp);
					}
				
			
					}

		}
	else if(count==1)
		{
			for(int i=0;i<packet_header.len;i++)
					{
						if(i==42)	
							{
								const u_char *temp = (packet+42);
								store1[i]=*temp;
								printf("%x", 0x99);
							}

						else if(i==43)	
							{
								const u_char *temp = (packet+43);
								store1[i]=*temp;
								printf("%x", 0x99);
							}
						else if(i==44)	
							{
								const u_char *temp = (packet+44);
								store1[i]=*temp;
								printf("%x", 0x99);
							}
						else if(i==45)	
							{
								const u_char *temp = (packet+45);
								store1[i]=*temp;
								printf("%x", 0x99);
							}
						else	
							{
								const u_char *temp = packet+i;
								store1[i]=*temp;
								printf("%x", *temp);
							}
				
			
					}
		}

printf("\n");
FILE *fptr;
if(count==0)
{
fptr=fopen("output1.pcap","w");
fprintf(fptr,"Seq # of Sender:");
for(int j=38;j<42;j++)
	{
		fprintf(fptr,"%x",store[j]);
	}
fclose(fptr);
}
else
{
fptr=fopen("output2.pcap","w");
fprintf(fptr,"Ack # of Receiver:");
for(int j=42;j<46;j++)
	{
		fprintf(fptr,"%x",store1[j]);
	}
fclose(fptr);
}
count++;
}


