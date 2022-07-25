#include <iostream>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    // trace : 코드를 아주 디테일하게 하나하나 확인
    //         코드를 '한 줄 한 줄' 직접 실행

    // breakpoint : F9
    //                코드를 어디에서 멈출지(한줄 한줄 실행하기 시작할 부분)
    // 디버깅모드(trace)시작 : F5

    // step over : F10
    //               한 줄씩 코드 실행
    // step into : F11
    //               한 줄씩 코드 실행

    // resume : F5(지금 코드부터 이어서 쭉 실행, breakpoint를 만나면 스탑)
    // 디버깅모드(trace)종료 : shift + F5


    // 조사식 : 각각의 변수들이 어떻게 변해가는지 확인하기 용이한 창(확인하고 싶은 내용을 이름에 입력하면 알아서 찾아서 나옴)
    //           디버그 -> 창 -> 조사식 -> 조사식1~4까지 아무거나
    int a = 1; // <- breakpoint찍고 한줄한줄 실행해가며 i와 a가 어떻게 변해가는지 확인

    for (int i = 0; i < 100; i++)
    {
        // 언제 이상한 값이 나오는지 확인

        if (a < 0) // a가 음수가 되면 잘못된다.
        {
            // 아~~무 의미없는 코드를 입력(breakpoint는 항상 코드부분에만 등록)
            int de = 1;
        }
        a = a * 2;
        cout << a << "\n";
    }

    // a : 1->5->4
    // b : 2
    int t = 1;

    // 모든 주석과 코드들은 각 반의 교수님을 통해서 공유

    return 0;
}