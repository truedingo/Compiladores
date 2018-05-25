int readint(void) {
	int read = 0, sign = 1;
	char c = getchar();

	if(c == '-')
		sign = -1;

	while(c != '\n') {
		if(c != '-')
			read = read * 10 + c - '0';
		c = getchar();
	}

	return sign * read ;
}

void printint(int n) {
	if(n < 0) {
		putchar('-');
		n = -n;
	}

	if(n / 10) {
		printint(n / 10);
	}

	putchar(n % 10 + '0');
}

int main(void) {
	int i = 1;

	while(i != 0) {
		i = readint();
		printint(i);
		putchar('\n');
	}
}
