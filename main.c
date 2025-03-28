#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

int get_cidr_notation(int hosts) {
    int host_bits = ceil(log2(hosts + 2));  
    int subnet_mask = 32 - host_bits;
    return subnet_mask;
}

char* get_subnetmask(int cidr) {
    unsigned int subnet_mask = 0;

    for (int i = 0; i < cidr; i++) {
        subnet_mask |= (1 << (31 - i));  
    }

    char *result = (char*)malloc(16 * sizeof(char)); 

    sprintf(result, "%d.%d.%d.%d", 
            (subnet_mask >> 24) & 0xFF, 
            (subnet_mask >> 16) & 0xFF, 
            (subnet_mask >> 8) & 0xFF,  
            subnet_mask & 0xFF);        

    return result;  
}

int main() {
    int hosts = 100;
    int cidr = get_cidr_notation(hosts);  
    printf("CIDR Notation: /%d\n", cidr);
    

    char *subnetmask = get_subnetmask(cidr);
    printf("Subnet Mask: %s\n", subnetmask);

    free(subnetmask);

    return 0;
}
