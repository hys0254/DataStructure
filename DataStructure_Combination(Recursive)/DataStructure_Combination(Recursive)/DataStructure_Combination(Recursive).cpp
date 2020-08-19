// DataStructure_Combination(Recursive).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
int choose(int n, int c);
using namespace std;
int cnt=0;

int main()
{
    int n=0 , c=0;
    cout << "조합(combination) Recursive TEST" << "\n";
    cout << "n = ";
    cin >> n;
    cout << "c = ";
    cin >> c;

    cout << n<<" combination "<<c<<"is" << choose(n,c) << "\n";
    cout << "function called " << cnt << "times \n";
}
int choose(int n, int k)
{

    cnt++;
    if (k == 1)
        return n;
    else if (n == k)
        return 1;
    else // recursive case: n>k and k>1
        return choose(n - 1, k - 1) + choose(n - 1, k);
}
