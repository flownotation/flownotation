
#param @Bob:secrecy 
void func(int x) {
	return 0;
}

int main() {
	#requires @Alice:secrecy 
	int bal;

	func(bal);
	return 0;
}
