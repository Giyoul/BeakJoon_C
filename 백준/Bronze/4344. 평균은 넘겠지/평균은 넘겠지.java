import java.util.Scanner;
import java.util.ArrayList;

class Main {
    public static void main(String[] args) {
        Main stepG = new Main();
        stepG.g02();
    }

    void g02() {
        Scanner s = new Scanner(System.in);
        
        int n = s.nextInt();
        
        for(int i = 0; i < n; i++){
            int people = s.nextInt();
            int total_score = 0;
            int student_count = 0;
            ArrayList<Integer> li = new ArrayList<>();
            
            for(int j = 0; j < people; j++){
                int grade = s.nextInt();
                li.add(grade);
                total_score+=grade;
            }
            double average = (double)total_score / (double)people;
            
            for(int j = 0; j < people; j++){
                if(li.get(j) > average) student_count++;
            }
            System.out.printf("%.3f%%\n", (double)student_count / (double)people * 100);
        }
	}
}