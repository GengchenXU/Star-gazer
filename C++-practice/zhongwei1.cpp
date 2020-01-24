    #include<stdio.h>
    #include<algorithm>
    using namespace std;
    int data[10000];
    int main() {
    	int n;
    	while (scanf("%d", &n) != EOF) {
    		if (n == 0)
    			break;
    		for (int i = 0; i < n; i++)
    			scanf("%d", &data[i]);
    		sort(data, data + n);
    		int mid;
    		if (n % 2 == 0)
    			mid = (data[n / 2 - 1] + data[n / 2]) / 2;
    		else
    			mid = data[n / 2];
    		printf("%d\n", mid);
    	}
    	return 0;
    }

