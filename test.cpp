
char* format(const char* s) {
    int len = strlen(s);
    len += len / 3 + 1;
    char* result = (char*)malloc(len);
    char* it = result;
    do {
        if (*s >= '0' && *s <= '9'
            || *s >= 'a' && *s <= 'z'
            || *s >= 'A' && *s <= 'Z') {
            *it++ = *s++;
            if ((it - result) % 4 == 3)
                *it++ = ' ';
        }
        else s++;
    } while (*s);
    *it = 0;
    if ((it - result) % 4 == 1) {
        *(it - 2) = *(it - 3);
        *(it - 3) = ' ';
    }
    return result;
}

int main()
{
	char str[] = "Afr4g 63 -&6h+tAfr4g 63 -&6h+t";
	char* s = format(str);
	cout << s << "\t- s " << endl;

	return 0;
}
