
char* format(char* str)
{
	size_t lenght = strlen(str);
	char* temp = (char*)malloc(lenght);
	int count = 0;
	for (int i = 0; i < lenght; i++)
	{	
		if (str[i] >= 48 && str[i] <= 57 || str[i] >= 65 && str[i] <= 90 || str[i] >= 97 && str[i] <= 122)
		{
			temp[count] = str[i];
			count++;
		}				
	}
	temp[count] = '\0';

	count = 0;
	lenght = strlen(temp);
	char* result = (char*)malloc(lenght);
	int step;
	for (int i = 0; i < lenght; )
	{
		if ((lenght - i) > 4)
			step = 3;
		else
			step = 2;
		for (int t = 0; t < step; t++)
		{
			result[count] = temp[i];
			count++;
			i++;
		}
		result[count] =' ';
		count++;
	}
	result[count] = '\0';	
	return result;
}

int main()
{
	char str[] = "Afr4g 63 -&6h+tAfr4g 63 -&6h+t";
	char* s = format(str);
	cout << s << "\t- s " << endl;

	return 0;
}
