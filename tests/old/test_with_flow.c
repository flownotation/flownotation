
// #provides @trusted
int getInput() {
    return 1;
}

int network_send(int x) { 
    return 0;
}

int main() {

    // #requires @trusted
	int x;

    x = getInput();

    network_send(x);

    return 0;
}
