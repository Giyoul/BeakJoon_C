import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Main stepG = new Main();
        stepG.g02();
    }

    void g02() {
        Scanner s = new Scanner(System.in);
        int testcase = s.nextInt();
        
        for(int i = 0; i < testcase; i++){
            int first = 0, second = 0, third = 0;
            for(int j = 0; j < 10; j++){
                int num = s.nextInt();
                if(num > first){
                    third = second;
                    second = first;
                    first = num;                 
                }
                else if(num > second){
                    third = second;
                    second = num;            
                }
                else if(num > third){
                    third = num;
                }
                
            }
            System.out.println(third);
        }
	}
}