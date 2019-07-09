
int trusted_read(int x) {
return x;
}

int trusted_write(int x) {
return x;
}

int random_func(int x) {
return x;
}

int main() {
int x;

int y;

int z;

x = trusted_write(1);
z = trusted_read(x);
z = trusted_read(y);
y = trusted_write(1);
x = trusted_write(trusted_read(y));
y = trusted_write(trusted_read(x));

random_func(trusted_read(x));


}
