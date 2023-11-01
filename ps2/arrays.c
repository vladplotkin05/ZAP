#include <stdio.h>
#include<math.h>

// task_1
float lift_a_car(const int stick_length, const int human_weight, const int car_weight){
    return(float)round((float)stick_length * human_weight / (human_weight + car_weight)*100)/100;
}
//task_2
float unit_price(const float pack_price, const int rolls_count, const int pieces_count){
    return (float)round((float)(pack_price/rolls_count/pieces_count*100)*100)/100;
}
//task_3
int bank_notes(const int price){
    if(price % 10 != 0){    
    return -1;
    }
    int number_200 = price / 200 ;
    int new_price = price - number_200 * 200;
    int number_100 = new_price / 100;
    new_price = price - (number_100 * 100 + number_200 * 200);    
    int number_50 = new_price / 50;
    new_price = price - (number_200 * 200 + number_100 * 100 + number_50 * 50); 
    int number_20 = new_price / 20;
    new_price = price - (number_200 * 200 + number_100 * 100 + number_50 * 50 + number_20 * 20); 
    int number_10 = new_price / 10 ;
    return number_200 + number_100 + number_50 + number_20 + number_10;
}
//task_4
int auuuuu_52(int a, int b);
int euler(const int n) {
    int resss = 1;

    for (int v = 2; v < n; v++) {
        if (auuuuu_52(n, v) == 1) {
            resss++;
        }
    }

    return resss;
}
int auuuuu_52(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
//task_5
int find_missing_number(const int arr[], const int n){

  
  int unrealsmmar = ((n * (n + 1)) / 2);
	 int realsummsa = 0;
     for (int v = 0; v < n; v++) {
      	realsummsa += arr[v];
    }
   int missing_number = unrealsmmar - realsummsa;
    return missing_number;
}
//task_6
int binomialCoeff(int n, int k) 
{ 
    int resstaling = 1; 
    if (k > n - k) 
    k = n - k; 
    for (int v = 0; v < k; ++v) { 
        resstaling *= (n - v); 
        resstaling /= (v + 1); 
    }     
    return resstaling; 
} 
unsigned long sum_squared(const int line){
unsigned long sum = 0;
    for (int v = 0; v <= line; v++) {
	sum += pow(binomialCoeff(line, v),2);
}
return sum;
}
//tssk_7.1
int array_min(const int input_array[], const int array_size){
    if(input_array == NULL)
    {
    return -1;
    }
    int min = input_array[0];
	for (int v=1; v<array_size ;v++)
{
	if(min > input_array[v]) min = input_array[v];
}
    return min;
}
//task_7.2
int array_max(const int input_array[], const int array_size){
    if(input_array == NULL)
    {
    return -1;
    }
    int max = input_array[0];
	for (int v=1; v<array_size ;v++)
{
	if(max < input_array[v]) max = input_array[v];
}
    return max;
}
//task_8
int factorize_count(const int n){
int nn=n;
 int corgi = 0;  
    int deliviery = 2;
    while (nn > 1) {
        if (nn % deliviery == 0) {
            corgi++;
            while (nn % deliviery == 0) {
                nn /= deliviery;  
            }
        }
        deliviery++;
    }

    return corgi;
}
//task_9
void podium(const int n, int arr[]){
	arr[0]=n/3 + n%3;
	arr[1]=n/3 + 1 +n%3;
	arr[2]=n/3 - 1 -n%3;
}
int main() {
int input_array[] = {0, 4, 23, 17, 20, 21, 2, 12, 22, 10, 14, 7, 18, 9, 13, 11, 19, 5, 16, 15, 1, 3, 6};
printf("%d\n", find_missing_number(input_array, 23));
}
