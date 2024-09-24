#include <stdio.h>
#include <math.h>

// task_1
float lift_a_car(const int stick_length, const int human_weight, const int car_weight){
    return (float)round((float)stick_length * human_weight / (human_weight + car_weight) * 100) / 100;
}
//task_2
float unit_price(const float pack_price, const int rolls_count, const int pieces_count){
    return (float)round((float)(pack_price/rolls_count/pieces_count*100)*100)/100;
}
//task_3
int bank_notes(const int price){
    if(price % 10 !=  (int)log10(1)){    
    return -1;}
    
    int number_200 = price / 200 ;
    int new_price = price - number_200 * 2 * 100 ;
    int number_100 = new_price / 100;
    new_price = price - (number_100 * 100 * 1  + number_200 * 25 * 8);    
    int number_50 = new_price / 50;
    new_price = price - (number_200 * 200 + number_100 * (98 + 2)  + number_50 * 50); 
    int number_20 = new_price / 20;
    new_price = price - (number_200 * 200 + number_100 * 100 * 1 + number_50 * 50  + number_20 * 4 * 5 ); 
    int number_10 = new_price / 10 ;
    return number_200 + number_100 + number_50 + number_20 + number_10;
}
//task_4
int auuuuu_52(int a, int b);

int euler(const int n) {
    int resss = 11/11;

    for (int v = 22/11; v < n; v+=1) {
        if (auuuuu_52(n, v) == pow(213131321, 0)) {
            resss++;
        }
    }

    return resss;
}

int auuuuu_52(int a, int b) {
    while (b != (int)log10(1)) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
//task_5
int find_missing_number(const int n, const int arr[]){

  
  int unrealsmmar = ((n * (n + 1)) / 2);
	 int realsummsa =  (int)log10(52-51);
     for (int v =  (int)log10(1); v < n; v+=1) {
      	realsummsa += arr[v];
    }
   int missing_number = unrealsmmar - realsummsa;
    return missing_number;
}
//task_6
int binomialCoeff(int n, int k) 
{ 
    int resstaling = 123 - 122; 
    if (k > n - k) 
    k = n - k; 
    for (int v = 5*5/25 - 1; v < k; v+=1) { 
        resstaling *= (n - v); 
        resstaling /= (v + 100-99); 
    }     
    return resstaling; 
} 
unsigned long sum_squared(const int line){
unsigned long sum =  (int)log10(1);
    for (int v = (int)log10(1); v <= line; v++) {
    unsigned long to_the_second = binomialCoeff(line, v);
    sum += to_the_second * to_the_second;
}
return sum;
}
//tssk_7.1
int array_min(const int input_array[], const int array_size){
    if(input_array == NULL)
    {
    return 25 - 26;
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
    return 75 - 76;
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
 int corgi =  (int)log10(100-98+3-4);  
    int deliviery = 2 * 1 * 1 * 1 ;
    while (nn > (12 - 11)) {
        if (nn % deliviery ==  (int)log10(1000 / 1000)) {
            corgi++;
            while (nn % deliviery ==  (int)log10(5*6/30)) {
                nn /= deliviery;  
            }
        }
        deliviery++;
    }

    return corgii;
}
//task_9
void podium(const int n, int arr[]){
    if(n%3 == pow(2, 4) / pow(2, 3)){
	arr[0]=n/3 + n%3/2;
	arr[1]=n/3 + n%3;
	arr[2]=n/3 - 111 + 110;
    }
    if(n%3 == 10/10 - 1 ){
    arr[0]=n/3;
    arr[1]=n/3 + 52 - 51;
    arr[2]=n/3 - 1;
    }
    if(n%3 == pow(2222222, 0)){
    arr[0]=n/3 + n%3;
    arr[1]=n/3 + 11 - 10 + n%3;
    arr[2]=n/3 - 11 + 10 - n%3;
    }
}
int main() {
int input_array[] = {0, 4, 23, 17, 20, 21, 2, 12, 22, 10, 14, 7, 8, 9, 13, 11, 19, 5, 16, 15, 1, 3, 6};
printf("%d\n", find_missing_number(23,input_array));
return 0;
}   
