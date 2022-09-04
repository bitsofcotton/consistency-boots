#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/udp.h>
#include <arpa/inet.h>
#include <netdb.h>

unsigned short cksum(unsigned short *m, int s) {
  unsigned long res = 0;
  for( ; 1 < s; ++ m, s -= 2) res += *m;
  if(! (-- s)) res += *(unsigned char*)m;
  // REDUCE;
  res = (res & 0xffff) + (res >> 16);
  res = (res & 0xffff) + (res >> 16);
  return ~ res;
}

int main(int argc, char* argv[]) {
  int n, soc, on = 1;
  if(argc < 4)
    errx(1, "udpserial <data size> <usleep> <ip_bind> <ip_to>");
  struct sockaddr_in addr;
  struct sockaddr_in addrto;
  addr.sin_family = AF_INET;
  addr.sin_addr.s_addr = inet_addr(argv[3]);
  addrto.sin_family = AF_INET;
  addrto.sin_addr.s_addr = inet_addr(argv[4]);
  bzero(addr.sin_zero, 8 * sizeof(int8_t));
  soc = socket(AF_INET, SOCK_RAW | SOCK_NONBLOCK, IPPROTO_RAW);
  if(soc < 0) errx(1, "could not make socket.");
/*
  if((setsockopt(soc, IPPROTO_IP, IP_HDRINCL, &on, sizeof(on))) < 0)
    errx(1, "could not set hdrincl.");
*/
  struct ip *iph;
  struct udphdr *udph;
  // XXX:
  char packet[32 + atoi(argv[1])];
  unsigned char scan[17 + atoi(argv[1])];
  bzero(&scan, sizeof(scan));
  while(! (scan[0] & 0xc0)) {
    for(int i = sizeof(scan) / sizeof(char) - 1; 0 <= i; i --)
      if((++ scan[i]) & 0xff) break;
    iph = (struct ip *) packet;
    iph->ip_v = 4; iph->ip_hl = 5;
    iph->ip_tos = scan[0] & 0x3f;
    iph->ip_len = 0;
    iph->ip_id  = (((unsigned short)scan[1]) << 8) | (unsigned short)scan[2];
    iph->ip_off = (((unsigned short)scan[3]) << 8) | (unsigned short)scan[4];
    iph->ip_ttl = 16;
    iph->ip_p   = IPPROTO_UDP;
    iph->ip_sum = 0;
    iph->ip_src.s_addr = (((uint32_t)scan[5] & 0xff) << 24) |
                         (((uint32_t)scan[6] & 0xff) << 16) |
                         (((uint32_t)scan[7] & 0xff) << 8) |
                          ((uint32_t)scan[8] & 0xff);
    iph->ip_dst.s_addr = (((uint32_t)scan[9]  & 0xff) << 24) |
                         (((uint32_t)scan[10] & 0xff) << 16) |
                         (((uint32_t)scan[11] & 0xff) << 8) |
                          ((uint32_t)scan[12] & 0xff);
    // iph->ip_dst.s_addr = inet_addr(argv[4]);
    iph->ip_sum = cksum((unsigned short *)&iph, sizeof(struct ip));
    udph = (struct udphdr *)(packet + sizeof(struct ip));
/*
    udph->uh_sport = (((unsigned short)scan[9]) << 8) | (unsigned short)scan[10];
    udph->uh_dport = (((unsigned short)scan[11]) << 8) | (unsigned short)scan[12];
*/
    udph->uh_sport = (((unsigned short)scan[13]) << 8) | (unsigned short)scan[14];
    udph->uh_dport = (((unsigned short)scan[15]) << 8) | (unsigned short)scan[16];
    udph->uh_ulen = htons(1 + sizeof(struct udphdr));
    udph->uh_sum = 0;
    int c = atoi(argv[1]);
    for(char* start = packet + sizeof(struct ip) + sizeof(struct udphdr);
              0 < c; ++ start, -- c) *start = scan[17 + c];
    n = sendto(soc, packet, sizeof(struct ip) + sizeof(struct udphdr) + 1, 0, (struct sockaddr *)(&addrto), sizeof(struct sockaddr));
    usleep(atoi(argv[2]));
  }
  return 0;
}

