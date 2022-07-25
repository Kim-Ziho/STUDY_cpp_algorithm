#include <iostream>
using namespace std;


int main() {

    // cin의 속도를 높이기 위한 코드(항상 main의 맨 앞에 위치)
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    // 문제 1
    //// 0 1 0 0 1 1 0 1 0 1
    //// 10개의 0과 1로 이루어진 공백으로 구분된 data가 주어짐
    //// 다음 줄에 입력으로 숫자 1개 입력(0 ~ 9 중의 한 숫자)
    //// 입력된 temp라는 번째 인접한 주변에 1이 몇개나 존재하는가?

    //// ex. 입력
    ////        0 1 0 0 1 1 0 1 0 1        <- 10개의 data
    ////        4                        <- 번째에 해당하는 temp
    //// 4번 주변인 3번, 4번, 5번 중 4번과 5번에 1이 있다.
    ////       출력
    ////     2개

    //int arr[10];
    //for (int i = 0; i < 10; i++)
    //{
    //    cin >> arr[i];
    //}
    //int temp;
    //cin >> temp;
    //int ans = 0;
    ////temp == 0이라면 temp-1 == -1
    //// 실제로 배열 index가 -1이 되는 코드를 채점 서버에 제출
    //// Runtime Error <- 코드가 실행하다보니 문제가 생겼다.

    ////if (arr[temp - 1] != 0 && temp - 1 >= 0) // 0이 아니면 1
    ////    ans++;
    ////if (arr[temp] != 0)
    ////    ans++;
    ////// 실제 배열엔 9번까지 밖에 없는데, temp+1이 10이라서 10번위치를 확인
    ////// Runtime Error <- 코드가 실행하다보니 문제가 생겼다.
    ////if (arr[temp + 1] != 0 && temp + 1 <= 9)
    ////    ans++;

    ////arr[temp + -1]
    ////arr[temp + 0]
    ////arr[temp + 1]

    ////arr[temp(+d)]
    ////ex) d : -1이면 앞
    ////      d : 0이면 temp위치
    ////      d : 1이면 뒤

    //int d[] = {-1, 0, 1}; // 다음 좌표를 계산할때 사용할 값들을 저장한 배열 : 방향 배열
    //for(int i = 0; i < 3; i++)
    //{
    //    // d를 기반으로 다음 좌표 계산
    //    int nextTemp = temp + d[i]; // i == 0 : temp -1,  i == 1 : temp,  i == 2 : temp + 1

    //    // 문제가 생길 수 있는 부분 예외처리
    //    if (nextTemp < 0 || nextTemp > 9)
    //        continue;// nextTemp라는 'temp의 주변 좌표'가 0~9라는 범위를 벗어나면 '무시'

    //    // 하고 싶은 기능 추가
    //    if (arr[nextTemp] != 0)
    //        ans++;
    //}





    int MAP[10][10] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 2, 0, 0, 0, 0, 0, 0, 5, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 100, 0, 0},
        {0, 0, 0, 0, 0, 10, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {1, 0, 0, 20, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };
    // MAP[row][col] = 해당 (row, col)위치에 몇 개의 지뢰가 있는가?
    //     row : 줄(행)에 해당하는 index
    //     col : 칸(열)에 해당하는 index
    //   value : 해당 (row, col)위치에 몇 개의 지뢰가 있는가?

    // row, col이 입력
    // 해당 위치 주변까지 확인했을때 지뢰가 있으면 지뢰 개수만큼 BOOM! 출력

    int row, col;
    cin >> row >> col;
    // 지뢰가 있는지 확인할 좌표 입력

    //MAP[row + 0][col + 0]; // 0번째 : 자기자신
    //MAP[row + 0][col +-1]; // 1번째 : 왼쪽
    //MAP[row + 0][col + 1]; // 2번째 : 오른쪽
    //MAP[row +-1][col + 0]; // 3번째 : 위
    //MAP[row + 1][col + 0]; // 4번째 : 아래

    int dr[] = {0, 0, 0,-1, 1}; // row쪽 방향 배열
    int dc[] = {0,-1, 1, 0, 0}; // col쪽 방향 배열
    for (int i = 0; i < 5; i++)
    {
        // d를 기반으로 다음 좌표 계산
        int nr = row + dr[i]; // row쪽 좌표 계산
        int nc = col + dc[i]; // col쪽 좌표 계산
        // nr,nc : row, col 주변 좌표

        // 문제가 생길 수 있는 부분 예외처리

        // MAP을 벗어나면 무시 
        if (nr < 0 || nc < 0) // 위로 너무 올라갔거나 왼쪽으로 너무 많이 갔으면 잘못됨.
            continue; // 무시
        if (nr > 9 || nc < 9) // 아래로 너무 내려갔거나 오른쪽으로 너무 많이 갔으면 잘못됨.
            continue; // 무시


        // 하고 싶은 기능 추가
        if (MAP[nr][nc] != 0) // MAP[nr][nc]에 봤더니 0개가 아니더라(지뢰가 있더라)
        {
            // MAP[nr][nc] : row, col에 매설된 지뢰 개수
            for (int i = 0; i < MAP[nr][nc]; i++)
                cout << "BOOM!";
        }
    }



    return 0;
}