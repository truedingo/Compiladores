int a = 10, b = 20, c, d = 40;

int main(void) {
	return 0;
}

int stuff(int, short, double, char);
int stuff(int a, short b, double c, char d) {
	stuff(1 + stuff(1, 'a', 0.0, 1), 'a', 0.0, 1);
	main();
}

int stuff2(int a, short b, double c, char d) {
	stuff(1 + stuff(1, 'a', 0.0, 1), 'a', 0.0, 1);
	main();
}
int stuff2(int, short, double, char);
