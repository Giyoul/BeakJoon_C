import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Main step = new Main();
        step.g01();
    }

    void g01() {
        Scanner s = new Scanner(System.in);
        int x = s.nextInt();
        int y = s.nextInt();
        s.close();
        
        if(x > 0 && y > 0) System.out.print("1");
        else if(x > 0 && y < 0) System.out.print("4");
        else if(x < 0 && y > 0) System.out.print("2");
        else System.out.print("3");
	}
}