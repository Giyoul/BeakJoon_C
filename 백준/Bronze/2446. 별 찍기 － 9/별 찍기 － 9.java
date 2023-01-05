import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Main stepG = new Main();
        stepG.g02();
    }

    void g02() {
        Scanner s = new Scanner(System.in);
        int n = s.nextInt();
        
        for(int i = n; i > 0; i--){
            for(int j = 0; j < n-i; j++){    // 공백 출력
                System.out.print(" ");
            }
            for(int j = 0; j < 2 * i - 1; j++){
                System.out.print("*");
            }
            System.out.println("");
        }
        for(int i = 1; i < n; i++){
            for(int j = 0; j < n-i - 1; j++){    // 공백 출력
                System.out.print(" ");
            }
            for(int j = 0; j < 2 * i + 1; j++){
                System.out.print("*");
            }
            System.out.println("");
        }
	}
}