/*
    하노이 테이블 알고리즘은 간략하게 3가지 경우의 수로 나눌 수 있다.
    1. 가장 큰 원판을 옮기기 위해 가장큰 원판 위의 n-1개의 원판을 A에서 B로 옮기는 과정
    2. 가장 큰 원판이 A에서 C로 이동하는 과정
    3. B에 있는 n-1개의 원판을 C로 옮기는 과정
    
    이를 그대로 구현하면 된다.
    참고로 하노이 테이블의 경우는 2의 n승이다.
*/
import java.io.*;

class Main {
    public static StringBuilder sb = new StringBuilder();    // stringbuilder 선언
    public static void main(String[] args) throws IOException {    // 예외 처리
        
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));    // 버퍼리더 선언
        
        int n = Integer.parseInt(br.readLine());    // int형 입력
        sb.append((int)(Math.pow(2, n)-1)).append('\n');    // 자동으로 개행이 되지 않기 떄문에 \n을 꼭 붙여준다.
        
        hanoi(n, 1, 2, 3);    // n개의 테이블을 1에서 2를 거쳐 3으로 이동한다.
        System.out.print(sb);        
    }
    
    static void hanoi(int n, int from, int mid, int to){
        if(n == 1){
            sb.append(from+" "+to+"\n");    // 원반이 1개이면
            return;
        }
        
        hanoi(n-1, from, to, mid);    // A에 있는 n-1개를 A에서 C를 거쳐 B로 이동
        sb.append(from+" "+to+"\n");    // A에 있는 1개를 C로 이동
        hanoi(n-1, mid, from, to);    // B에 있는 n-1개를 B에서 A를 거쳐 C로 이동
    }
}

/*
    자바는 C++처럼 풀면 안된다는걸 뼈저리게 느끼게 해준 문제
    속도를 생각해서라도 다음부터는 StringBuilder와 BufferedReader을 사용하도록 하자
*/