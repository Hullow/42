
void f(int param1, int param2)
{
	char local_var_1;
	char local_var_2;

	/* local_var_2 = g(local_var_1);*/
	if (param1 + param2 > 42)
		f(param1 + 1, param2 + 2);
}

char g(char c)
{
	int other_local_var;
	return (other_local_var + 1);
}

int main()
{
	int a;
	int b;

	f(a,b);
}