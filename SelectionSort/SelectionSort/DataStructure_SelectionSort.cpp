// SelectionSort.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int maxSelect(int target[], int targetCnt);
void swapElement(int target[], int maxPos, int last);
void selectionSort(int target[],int numCnt);

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

int maxSelect(int target[], int targetCnt)
{
    int maxPos = 0;
    int currentPos = 1;
    while (currentPos < targetCnt) {
        if (target[maxPos] < target[currentPos]) {
            maxPos = currentPos;
        }
        currentPos++;
    }
    return maxPos;
}

void swapElement(int target[], int maxPos, int last)
{
    int temp = target[maxPos];
    target[maxPos] = target[last];
    target[last] = temp;
}

void selectionSort(int target[], int numCnt)
{
    int lastPos = numCnt-1;
    int maxPos;
    while (lastPos > 0) {
        maxPos = maxSelect(target,lastPos+1);
        swapElement(target , maxPos, lastPos);
        lastPos--;
    }
}


// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.