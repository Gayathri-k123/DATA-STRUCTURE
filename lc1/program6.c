#include <stdio.h>
void main() {
    	int n1, n2;
    	int co=0,cc=0,k=0;
    	printf("\nThe size of first set:");
    	scanf("%d", &n1);
    	printf("\nThe size of second set:");
    	scanf("%d", &n2);
    	int a[n1],b[n2],c[n1+n2];
    	int unionSet[n1+n2];
    	int diffA[n1],diffB[n2];
    	printf("\nEnter elements of first set:");
    	for (int i = 0; i < n1; i++) {
        	scanf("%d", &a[i]);
    	}
    	printf("\nEnter elements of second set:");
    	for (int i = 0; i < n2; i++) {
        	scanf("%d", &b[i]);
    	}
    	for (int i = 0; i < n1; i++) {
        	for (int j = 0; j < n2; j++) {
            	if (a[i] == b[j]) {
                	int found = 0;
                	for (int m = 0; m < k; m++) {
                    		if (c[m] == a[i]) {
                        		found = 1;
                        		break;
                    		}
                	}
                		if (!found) {
                    			c[k] = a[i];
                    			k++;
                    			cc++;
                		}
                break;
            }
        }
    }
    	if (k != 0) {
        	printf("Intersection:");
        	for (int l = 0; l < k; l++) {
            	printf("%d\t", c[l]);
        	}
    	}else {
        	printf("Intersection:No common elements\n");
    	}
    	int uIndex = 0;
    	for (int i = 0; i < n1; i++) {
        	unionSet[uIndex++] = a[i];
    	}
    	for (int i = 0; i < n2; i++) {
        	int found = 0;
        	for (int j = 0; j < uIndex; j++) {
            	if (b[i] == unionSet[j]) {
                	found = 1;
                	break;
            	}
        }
        	if (!found) {
            	unionSet[uIndex++] = b[i];
        	}
    	}
    	printf("\nUnion:");
    	for (int i = 0; i < uIndex; i++) {
        	printf("%d\t", unionSet[i]);
    	}
    	int diffAIndex = 0;
    	for (int i = 0; i < n1; i++) {
        	int found = 0;
        	for (int j = 0; j < n2; j++) {
            	if(a[i] == b[j]) {
                	found = 1;
                	break;
            	}
        }
        	if (!found) {
            	diffA[diffAIndex++] = a[i];
        	}
   	 }
    		printf("\nDifference A - B is:");
    		if (diffAIndex > 0) {
        	for (int i = 0; i < diffAIndex; i++) {
            	printf("%d\t", diffA[i]);
        	}
    		}else {
        	printf("No elements in A - B\n");
    		}
    	int diffBIndex = 0;
    	for (int i = 0; i < n2; i++) {
        	int found = 0;
        	for (int j = 0; j < n1; j++) {
            	if (b[i] == a[j]) {
                	found = 1;
                	break;
            		}
        	}
        	if(!found){
            	diffB[diffBIndex++] = b[i];
        	}
    	}
    	printf("\nDifference B - A is:");
    	if (diffBIndex > 0) {
        	for (int i = 0; i < diffBIndex; i++) {
            	printf("%d\t", diffB[i]);
        	}
	printf("\n");
    	}else {
        	printf("No elements in B - A\n");
    	}
}
