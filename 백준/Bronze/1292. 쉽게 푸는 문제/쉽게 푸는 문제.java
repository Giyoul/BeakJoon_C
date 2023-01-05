import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Main stepG = new Main();
        stepG.g02();
    }

    void g02() {
        Scanner s = new Scanner(System.in);
        int start = s.nextInt();
        int end = s.nextInt();
        int[] sum_arr = new int[1001];
        int count = 1;
        int flag = 1;
        
        for(int i = 1; i <= 1001; i++){
            for(int j = 0; j < i; j++){
                sum_arr[count] = sum_arr[count-1] + i;
                count++;
                if(count > end){
                    flag = 0;
                    break;
                }
            }
            if(flag == 0) break;
        }
        System.out.print(sum_arr[end] - sum_arr[start - 1]);
	}
}