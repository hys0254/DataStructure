// Day_2020_08_15_InsertionSort.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;
void insertionSort(int arrNum[], int arrSize);
void insertNextItem(int arrNum[], int targetPos);
int main()
{
    int numCnt;
    cout << "입력할 정수의 개수를 입력하시오 : ";
    cin >> numCnt;
    int* arrNum = new int[numCnt];
    cout << "정수를 " << numCnt << " 개 입력하시오 : ";
    for (int i = 0; i < numCnt; i++) {
        cin >> arrNum[i];
    }
    cout << "입력하신 정수는 ";
    for (int i = 0; i < numCnt; i++) {
        cout << arrNum[i] << "\t";
    }
    cout << endl;
    insertionSort(arrNum, numCnt);
    cout << "정렬결과 순서는 ";
    for (int i = 0; i < numCnt; i++) {
        cout << arrNum[i] << "\t";
    }
}



void insertionSort(int arrNum[], int arrSize)
{
    for (int i = 1; i < arrSize; i++) {
        insertNextItem(arrNum, i);
    }
}

void insertNextItem(int arrNum[], int targetPos)
{
    int targetPosNum = arrNum[targetPos];
    int i = targetPos;
    for (; targetPosNum < arrNum[i - 1]; i--) {

        arrNum[i] = arrNum[i - 1];

    }
    arrNum[i] = targetPosNum;
}
