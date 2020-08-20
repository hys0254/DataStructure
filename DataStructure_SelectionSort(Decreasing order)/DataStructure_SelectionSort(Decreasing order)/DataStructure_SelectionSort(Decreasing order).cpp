

#include <iostream>

int minSelect(int target[], int targetCnt);
void swapElement(int target[], int maxPos, int last);
void selectionSort(int target[], int numCnt);

using namespace std;

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
    selectionSort(arrNum, numCnt);
    cout << "정렬결과 순서는 ";
    for (int i = 0; i < numCnt; i++) {
        cout << arrNum[i] << "\t";
    }
}

int minSelect(int target[], int targetCnt)
{
    int minPos = 0;
    int currentPos = 1;
    while (currentPos < targetCnt) {
        if (target[minPos] > target[currentPos]) {
            minPos = currentPos;
        }
        currentPos++;
    }
    return minPos;
}

void swapElement(int target[], int maxPos, int last)
{
    int temp = target[maxPos];
    target[maxPos] = target[last];
    target[last] = temp;
}

void selectionSort(int target[], int numCnt)
{
    int lastPos = numCnt - 1;
    int maxPos;
    while (lastPos > 0) {
        maxPos = minSelect(target, lastPos + 1);
        swapElement(target, maxPos, lastPos);
        lastPos--;
    }
}


