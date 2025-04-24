
int fib(int n)
{
    if (n <= 1)
        return n;
    return fib(n - 1) + fib(n - 2);
}

int nwd(int a, int b)
{
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int nww(int a, int b)
{
    return (a * b) / nwd(a, b);
}

bool isPrime(int n)
{
    if (n <= 1)
        return false;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

bool *sito(int n)
{
    bool *prime = malloc(((n + 1)) * sizeof(bool));
    for (int i = 0; i <= n; i++)
    {
        prime[i] = true;
    }
    prime[0] = prime[1] = false;
    for (int j = 2; j * j <= n; j++)
    {
        if (prime[j])
        {
            for (int k = j * j; k <= n; k += j)
            {
                prime[k] = false;
            }
        }
    }
    return prime;
}
void bubble(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    { 
        for (int j = 0; j < n - i - 1; j++)
        { 
            if (arr[j] > arr[j + 1])
            { 
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
