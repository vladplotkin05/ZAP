#include <stdio.h>
#include <math.h>

// task_1
float lift_a_car(int stick_length, int human_weight, int car_weight)
{
    return roundf((float)stick_length * human_weight / (human_weight + car_weight) * 100) / 100;
}

// task_2
float unit_price(float pack_price, int rolls_count, int pieces_count)
{
    return roundf((pack_price / rolls_count / pieces_count) * 100) / 100;
}

// task_3
int bank_notes(int price)
{
    if (price % 10 != 0)
        return -1;

    int count = 0;
    count += price / 200;
    price %= 200;
    count += price / 100;
    price %= 100;
    count += price / 50;
    price %= 50;
    count += price / 20;
    price %= 20;
    count += price / 10;

    return count;
}

// task_4
int gcd(int a, int b)
{
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int euler(int n)
{
    int result = 1; 
    for (int i = 2; i < n; i++)
    {
        if (gcd(n, i) == 1)
            result++;
    }
    return result;
}

// task_5
int find_missing_number(int n, const int arr[])
{
    int expected_sum = (n * (n + 1)) / 2;
    int actual_sum = 0;
    for (int i = 0; i < n; i++)
    {
        actual_sum += arr[i];
    }
    return expected_sum - actual_sum;
}

// task_6
int binomialCoeff(int n, int k)
{
    if (k > n - k)
        k = n - k;

    int res = 1;
    for (int i = 0; i < k; i++)
    {
        res *= (n - i);
        res /= (i + 1);
    }
    return res;
}

unsigned long sum_squared(int line)
{
    unsigned long sum = 0;
    for (int i = 0; i <= line; i++)
    {
        unsigned long c = binomialCoeff(line, i);
        sum += c * c;
    }
    return sum;
}

// task_7.1
int array_min(const int input_array[], int array_size)
{
    if (input_array == NULL || array_size <= 0)
        return -1;

    int min = input_array[0];
    for (int i = 1; i < array_size; i++)
    {
        if (input_array[i] < min)
            min = input_array[i];
    }
    return min;
}

// task_7.2
int array_max(const int input_array[], int array_size)
{
    if (input_array == NULL || array_size <= 0)
        return -1;

    int max = input_array[0];
    for (int i = 1; i < array_size; i++)
    {
        if (input_array[i] > max)
            max = input_array[i];
    }
    return max;
}

// task_8
int factorize_count(int n)
{
    int count = 0;
    for (int d = 2; d * d <= n; d++)
    {
        if (n % d == 0)
        {
            count++;
            while (n % d == 0)
                n /= d;
        }
    }
    if (n > 1) 
        count++;
    return count;
}

// task_9
void podium(int n, int arr[])
{
    if (n % 3 == 0)
    {
        arr[0] = n / 3 + 1;
        arr[1] = n / 3 + 2;
        arr[2] = n / 3 - 1;
    }
    else if (n % 3 == 1)
    {
        arr[0] = n / 3;
        arr[1] = n / 3 + 1;
        arr[2] = n / 3 - 1;
    }
    else
    {
        arr[0] = n / 3 + 1;
        arr[1] = n / 3 + 2;
        arr[2] = n / 3 - 1;
    }
}

int main()
{
    int input_array[] = {0, 4, 23, 17, 20, 21, 2, 12, 22, 10, 14, 7, 8, 9, 13, 11, 19, 5, 16, 15, 1, 3, 6};
    printf("%d\n", find_missing_number(23, input_array));
    return 0;
}
