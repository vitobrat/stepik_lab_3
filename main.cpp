#include <iostream>
using namespace std;

int checkInput(){
    int input;
    try {
        cin >> input;
        if (cin.fail()) {
            throw 1;
        }
    } catch (int exeption) {
        cout << "ERROR!!!";
        exit(0);
    }
    cin.sync();
    return input;
}

//выводит матрицу на экран
void printMatrix(int *pointer,int N ,int *end){
    for (int *i = pointer, count = 1; i <= end; count++, i++){
        printf("%2d ", *i);
        if (count % N == 0){ cout << "\n" ;}
    }
    cout << "\n";
}

//Используя арифметику указателей, заполняет квадратичную целочисленную матрицу порядка N (6,8,10) случайными числами от 1 до  N*N согласно схемам, приведенным на рисунках.
// Пользователь должен видеть процесс заполнения квадратичной матрицы.
void function1(int *pointer,int N, int *end){
    char exercise;
    cout << "Choose the type of matrix (a or b):";
    cin >> exercise;
    cin.sync();
    if (exercise == 'a'){
        int value = 1;
        for (int i = 0; i <= N / 2 - 1; i++){
            bool flag = false;
            for (int *x = pointer + i * N + i; x <= pointer + (i + 1) * N - i - 1; x++){
                *x = value++;
                flag = true;
            }
            if(!flag){ break; }
            printMatrix(pointer, N, end);
            flag = false;
            for (int *y = pointer + (i + 2) * N - i - 1; y <= end - i * N - i; y += N){
                *y = value++;
                flag = true;
            }
            if(!flag){ break; }
            printMatrix(pointer, N, end);
            flag = false;
            for (int *z = end - i * N - i - 1; z >= end - (i + 1) * N + i + 1; z--){
                *z = value++;
                flag = true;
            }
            if(!flag){ break; }
            printMatrix(pointer, N, end);
            flag = false;
            for (int *w = end - (i + 2) * N + i + 1; w >= pointer + (i + 1) * N + i; w -= N){
                *w = value++;
                flag = true;
            }
            if(!flag){ break; }
            printMatrix(pointer, N, end);
        }
    } else if(exercise == 'b'){
        int value = 1;
        for (int i = 0; i <= N - 1; i++){
            bool flag = false;
            for (int *j = pointer + i; j <= end - N + i + 1; j += N){
                *j = value++;
                flag = true;
            }
            i++;
            if(!flag){ break; }
            printMatrix(pointer, N, end);
            flag = false;
            for (int *z = end - N + i + 1; z >= pointer + i; z -= N){
                *z = value++;
                flag = true;
            }
            if(!flag){ break; }
            printMatrix(pointer, N, end);
        }
    }else{
        function1(pointer, N, end);
    }
}
//2.Получает новую матрицу, из матрицы п. 1, переставляя ее блоки в соответствии со схемами:
void function2(){

}

int main() {
    cout << "Set the matrix size(6,8,10):";
    int N = checkInput();
    int arr[N][N];
    int *pointer = (int *) arr;
    int *end = arr[0] + N * N - 1;
    //заполняем матрицу нулевыми значениями
    for (int *i = arr[0]; i <= end; i++){
        *i = 0;
    }
    printMatrix(pointer, N, end);
    int circle = 1;
    while (circle == 1){
        //1.Используя арифметику указателей, заполняет квадратичную целочисленную матрицу порядка N (6,8,10) случайными числами от 1 до  N*N согласно схемам, приведенным на рисунках.
        // Пользователь должен видеть процесс заполнения квадратичной матрицы.
        function1(pointer, N, end);
        //2.Получает новую матрицу, из матрицы п. 1, переставляя ее блоки в соответствии со схемами:
        function2();
        cout << "if you want to repeat then input 1: ";
        circle = checkInput();
    }

    return 0;
}
