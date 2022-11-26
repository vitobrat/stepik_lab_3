#include <iostream>
#include <windows.h>
#include <chrono>
#include <thread>

using namespace std;

void gotoXY(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    this_thread::sleep_for(chrono::milliseconds(400));
}


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
    cout << "\n";
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

void quickSort(int *pointer, int N, int *end){
    int *start = pointer, *finish = end;
    int *pivot = pointer;
    while (start <= finish){
        while (*start < *pivot)
            start++;
        while (*finish > *pivot)
            finish--;
        if (start <= finish)
        {
            swap(*start, *finish);
            start++;
            finish--;
        }
    }
    if (finish > pointer)
        quickSort(pointer, N, finish);
    if (start < end)
        quickSort(start, N, end);
}
//Создайте матрицу 3*3, заполните ее случайными числами (-30 до 30). Найдите определитель матрицы.
void dopFunction(){
    int N = 3;
    int arr[N][N];
    int *pointer = (int *) arr;
    int *end = arr[0] + N * N - 1;
    srand(time(NULL));
    for (int *i = pointer; i <= end; i++){
        *i = (rand() % 61) - 30;
    }
    printMatrix(pointer, N, end);
    int resultP = (*pointer * *(pointer + 4) * *end) + (*(pointer + 1) * *(pointer + 5) * *(pointer + 6)) + (*(pointer + 3) * *(pointer + 7) * *(pointer + 2));
    int resultM = -(*(pointer + 2) * *(pointer + 4) * *(pointer + 6)) - (*(pointer + 3) * *(pointer + 1) * *end) - (*(pointer + 7) * *(pointer + 5) * *pointer);
    cout << "Determinant = " << (*pointer * *(pointer + 4) * *end) << " + " << (*(pointer + 1) * *(pointer + 5) * *(pointer + 6)) << " + "
    << (*(pointer + 3) * *(pointer + 7) * *(pointer + 2)) << " + (" << -(*(pointer + 2) * *(pointer + 4) * *(pointer + 6)) << ") + ("
    << -(*(pointer + 3)* *(pointer + 1) * *end) << ") + (" << - (*(pointer + 7) * *(pointer + 5) * *pointer) << ") = " << resultP + resultM << "\n";

}

//Используя арифметику указателей, заполняет квадратичную целочисленную матрицу порядка N (6,8,10) случайными числами от 1 до  N*N согласно схемам, приведенным на рисунках.
// Пользователь должен видеть процесс заполнения квадратичной матрицы.
void function1(int *pointer,int N, int *end){
    char exercise;
    cout << "Choose the type of matrix (a or b):";
    cin >> exercise;
    cin.sync();
    system("cls");
    if (exercise == 'a'){
        int value = 1;
        for (int i = 0; i <= N / 2 - 1; i++){
            bool flag = false;
            for (int *x = pointer + i * N + i, j = i; x <= pointer + (i + 1) * N - i - 1; x++, j++){
                *x = value++;
                gotoXY(j*4, i);
                cout << *x;
                flag = true;
            }
            if(!flag){ break; }
            flag = false;
            for (int *y = pointer + (i + 2) * N - i - 1, j = i + 1; y <= end - i * N - i; y += N, j++){
                *y = value++;
                gotoXY( (N - i - 1)*4, j);
                cout << *y;
                flag = true;
            }
            if(!flag){ break; }

            flag = false;
            for (int *z = end - i * N - i - 1, j = N - i - 2; z >= end - (i + 1) * N + i + 1; z--, j--){
                *z = value++;
                gotoXY(j*4 , N - i - 1);
                cout << *z;
                flag = true;
            }
            if(!flag){ break; }

            flag = false;
            for (int *w = end - (i + 2) * N + i + 1, j = N - 2 - i; w >= pointer + (i + 1) * N + i; w -= N, j--){
                *w = value++;
                gotoXY(i*4 , j);
                cout << *w;
                flag = true;
            }
            if(!flag){ break; }

        }
    } else if(exercise == 'b'){
        int value = 1;
        for (int i = 0; i <= N - 1; i++){
            bool flag = false;
            for (int *j = pointer + i, x = 0; j <= end - N + i + 1; j += N, x++){
                *j = value++;
                gotoXY(i*4, x);
                cout << *j;
                flag = true;
            }
            i++;
            if(!flag){ break; }
            flag = false;
            for (int *z = end - N + i + 1, x = N - 1; z >= pointer + i; z -= N, x--){
                *z = value++;
                gotoXY(i*4, x);
                cout << *z;
                flag = true;
            }
            if(!flag){ break; }

        }
    }else {
        function1(pointer, N, end);
    }
    getchar();
    system("cls");
    printMatrix(pointer, N, end);
}
//2.Получает новую матрицу, из матрицы п. 1, переставляя ее блоки в соответствии со схемами:
void function2(int *pointer,int N, int *end){
    int arr1[N/2][N/2], arr2[N/2][N/2], arr3[N/2][N/2], arr4[N/2][N/2];
    int *pointer1 = (int *) arr1, *pointer2 = (int *) arr2, *pointer3 = (int *) arr3, *pointer4 = (int *) arr4;
    int *end1 = arr1[0] + N * N / 4 - 1, *end2 = arr2[0] + N * N / 4 - 1, *end3 = arr3[0] + N * N / 4 - 1, *end4= arr4[0] + N * N / 4 - 1;
    for (int *x = pointer1, i = 0; x <= end1; x++){
        *x = *(pointer + i);
        i++;
        if (i % (N/2) == 0){
            i+=N/2;
        }
    }
    for (int *y = pointer2, i = N / 2; y <=end2 ; y++){
        *y = *(pointer + i);
        i++;
        if (i % (N/2) == 0){
            i+=N/2;
        }
    }
    for (int *z = pointer3, i = N * N / 2; z <=end3 ; z++){
        *z = *(pointer + i);
        i++;
        if (i % (N/2) == 0){
            i+=N/2;
        }
    }
    for (int *w = pointer4, i = N * N / 2 + N / 2; w <=end4 ; w++){
        *w = *(pointer + i);
        i++;
        if (i % (N/2) == 0){
            i+=N/2;
        }
    }
    char exercise;
    cout << "Choose the type of matrix (a or b or c or d):";
    cin >> exercise;
    cin.sync();
    if (exercise == 'a'){
        for (int *x = pointer1, *y = pointer2; x <= end1; x++, y++){
            swap(*x, *y);
        }

        for (int *z = pointer1, *w = pointer4; z <= end1; z++, w++){
            swap(*z, *w);
        }
        for (int *q = pointer1, *r = pointer3; q <= end1; q++, r++){
            swap(*q, *r);
        }
    } else if(exercise == 'b'){
        for (int *x = pointer1, *y = pointer4; x <= end1; x++, y++){
            swap(*x, *y);
        }
        for (int *z = pointer2, *w = pointer3; z <= end2; z++, w++){
            swap(*z, *w);
        }
    }else if(exercise == 'c'){
        for (int *x = pointer1, *y = pointer3; x <= end1; x++, y++){
            swap(*x, *y);
        }
        for (int *z = pointer2, *w = pointer4; z <= end2; z++, w++){
            swap(*z, *w);
        }
    }else if(exercise == 'd'){
        for (int *x = pointer1, *y = pointer2; x <= end1; x++, y++){
            swap(*x, *y);
        }
        for (int *z = pointer3, *w = pointer4; z <= end3; z++, w++){
            swap(*z, *w);
        }
    }else{
        function2(pointer, N, end);
    }
    for (int *x = pointer1, i = 0; x <= end1; x++){
        *(pointer + i) = *x;
        i++;
        if (i % (N/2) == 0){
            i+=N/2;
        }
    }
    for (int *y = pointer2, i = N / 2; y <=end2 ; y++){
        *(pointer + i) = *y;
        i++;
        if (i % (N/2) == 0){
            i+=N/2;
        }
    }
    for (int *z = pointer3, i = N * N / 2; z <=end3 ; z++){
        *(pointer + i) = *z;
        i++;
        if (i % (N/2) == 0){
            i+=N/2;
        }
    }
    for (int *w = pointer4, i = N * N / 2 + N / 2; w <=end4 ; w++){
        *(pointer + i) = *w;
        i++;
        if (i % (N/2) == 0){
            i+=N/2;
        }
    }
    printMatrix(pointer, N, end);
}
//3.Используя арифметику указателей, сортирует элементы сортировкой quick sort
void function3(int *pointer, int N, int *end){
    quickSort(pointer, N, end);
    cout << "Sorted array:\n";
    printMatrix(pointer, N, end);
}
//4. Уменьшает, увеличивает, умножает или делит все элементы матрицы на введенное пользователем число.
void function4(int *pointer, int N, int *end){
    cout << R"(Which operation do you want to do(1 : "-", 2 : "+", 3 : "*", 4 : "/",):)";
    int operand = checkInput();
    cout << "Input the value you want to change to the matrix by:";
    int value = checkInput();
    switch (operand) {
        case 1:
            for(int *i = pointer; i <= end; i++){
                *i -= value;
            }
            break;
        case 2:
            for(int *i = pointer; i <= end; i++){
                *i += value;
            }
            break;
        case 3:
            for(int *i = pointer; i <= end; i++){
                *i *= value;
            }
            break;
        case 4:
            for(int *i = pointer; i <= end; i++){
                *i /= value;
            }
            break;
        default:
            function4(pointer, N, end);
    }
    cout << "Result:\n";
    printMatrix(pointer, N, end);
}

int main() {
    dopFunction();
    int circle = 1;
    while (circle == 1){
        cout << "Set the matrix size(6,8,10):";
        int N = checkInput();
        int arr[N][N];
        int *pointer = (int *) arr;
        int *end = arr[0] + N * N - 1;
        //заполняем матрицу нулевыми значениями
        for (int *i = arr[0]; i <= end; i++){
            *i = 0;
        }
        //1.Используя арифметику указателей, заполняет квадратичную целочисленную матрицу порядка N (6,8,10) случайными числами от 1 до  N*N согласно схемам, приведенным на рисунках.
        // Пользователь должен видеть процесс заполнения квадратичной матрицы.
        function1(pointer, N, end);
        cout << "\n";
        //2.Получает новую матрицу, из матрицы п. 1, переставляя ее блоки в соответствии со схемами:
        function2(pointer, N, end);
        //3.Используя арифметику указателей, сортирует элементы сортировкой quick sort
        function3(pointer, N, end);
        //4.Уменьшает, увеличивает, умножает или делит все элементы матрицы на введенное пользователем число.
        function4(pointer, N, end);
        cout << "If you want to repeat then input 1: ";
        circle = checkInput();
    }

    return 0;
}
