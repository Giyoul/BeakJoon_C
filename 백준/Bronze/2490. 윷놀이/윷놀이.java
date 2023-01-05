import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Main stepG = new Main();
        stepG.g02();
    }

    void g02() {
        Scanner s = new Scanner(System.in);
        
        for(int i = 0; i < 3; i++){
            int[] num = new int[2];
            for(int j = 0; j < 4; j++){
                int yout = s.nextInt();
                num[yout]++;
            }
            if(num[0] == 0){
                System.out.println("E");
            }
            else if(num[0] == 1){
                System.out.println("A");
            }
            else if(num[0] == 2){
                System.out.println("B");
            }
            else if(num[0] == 3){
                System.out.println("C");
            }
            else{
                System.out.println("D");
            }
        }
        System.out.print("");
	}
}