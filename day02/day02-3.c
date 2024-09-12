#include <stdio.h>

int main() {
	int num;
	for (int i = 0; i < 100;i++) {
		if (i % 12 == 0)
			printf("%d ", i);
		else if (i % 7 == 0)
			printf("%d ", i);
	}



	return 0;
}