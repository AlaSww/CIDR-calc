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
int get_networks(){
    int result=0;
    while(result<=0){
        printf("Enter the number of newtworks:");
        scanf("%d",&result);
    }
    return(result);
}

void sortIndexes(int arr[], int indices[], int n) {
    for (int i = 0; i < n; i++) {
        indices[i] = i;
    }


    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[indices[j]] < arr[indices[j + 1]]) { 
                int temp = indices[j];
                indices[j] = indices[j + 1];
                indices[j + 1] = temp;
            }
        }
    }
}
int main() {
    int networks=get_networks();
    int hostslist[networks];
    int indices[networks];
    for(int i=1;i<=networks;i++){
        int hosts=0;
        printf("Number of hosts of network %d: \n",i);
        scanf("%d",&hosts);
        hostslist[i-1]=hosts;
    }
    sortIndexes(hostslist,indices,networks);
    for(int i=0;i<networks;i++){
        printf("Network %d:\n",indices[i]+1);
        int cidr = get_cidr_notation(hostslist[indices[i]]);
        int usedhosts= pow(2,32-cidr);
        printf("CIDR Notation: /%d\n", cidr);
        char *subnetmask = get_subnetmask(cidr);
        printf("Subnet Mask: %s\n", subnetmask);
        free(subnetmask);
        printf("add this value to the previous address:%d \n\n\n",usedhosts+1);
    }
    return 0;
}
