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
void printMatrix(const int *pointer,int N){
    for (int i = 0; i <= N - 1; i++){
        for (int j = 0; j <= N - 1; j++){
            printf(" %2d ",*(pointer + i*N + j));
        }
        cout << "\n";
    }
    cout << "\n";
}

//Используя арифметику указателей, заполняет квадратичную целочисленную матрицу порядка N (6,8,10) случайными числами от 1 до  N*N согласно схемам, приведенным на рисунках.
// Пользователь должен видеть процесс заполнения квадратичной матрицы.
void function1(int *pointer, int N){
    char exercise;
    cout << "Choose the type of matrix (a or b):";
    cin >> exercise;
    cin.sync();
    if (exercise == 'a'){
        int value = 1;
        for (int i = 0; i <= N / 2 - 1; i++){
            bool flag = false;
            for (int x = i; x <= N - 1 - i; x++){
                *(pointer + i*N + x) = value++;
                flag = true;
            }
            if(flag){ printMatrix(pointer, N); }
            flag = false;
            for (int y = i + 1; y <= N - 1 - i; y++){
                *(pointer + y*N + N - 1 - i) = value++;
                flag = true;
            }
            if(flag){ printMatrix(pointer, N); }
            flag = false;
            for (int z = N - 2 - i; z >= i; z--){
                *(pointer + (N - 1- i)*N + z) = value++;
                flag = true;
            }
            if(flag){ printMatrix(pointer, N); }
            flag = false;
            for (int w = N - 2 - i; w >= i + 1; w--){
                *(pointer + w*N + i) = value++;
                flag = true;
            }
            if(flag){ printMatrix(pointer, N); }
        }
    } else if(exercise == 'b'){
        int value = 1;
        for (int i = 0; i <= N - 1; i++){
            bool flag = false;
            for (int j = 0; j <= N - 1; j++){
                *(pointer + j*N + i) = value++;
                flag = true;
            }
            i++;
            if(flag){ printMatrix(pointer, N); }
            flag = false;
            for (int z = N - 1; z >= 0; z--){
                *(pointer + z*N + i) = value++;
                flag = true;
            }
            if(flag){ printMatrix(pointer, N); }
        }
    }else{
        function1(pointer, N);
    }

}

int main() {
    cout << "Set the matrix size(6,8,10):";
    int N = checkInput();
    int arr[N][N];
    int *pointer = (int *) arr;
    //заполняем матрицу нулевыми значениями
    for (int i = 0; i <= N - 1; i++){
        for (int j = 0; j <= N - 1; j++){
            *(pointer + i*N + j) = 0;
        }
    }
    printMatrix(pointer,N);
    int circle = 1;
    while (circle == 1){
        //1.Используя арифметику указателей, заполняет квадратичную целочисленную матрицу порядка N (6,8,10) случайными числами от 1 до  N*N согласно схемам, приведенным на рисунках.
        // Пользователь должен видеть процесс заполнения квадратичной матрицы.
        function1(pointer, N);
        //2.Получает новую матрицу, из матрицы п. 1, переставляя ее блоки в соответствии со схемами:
        cout << "if you want to repeat then input 1: ";
        circle = checkInput();
    }

    return 0;
}
