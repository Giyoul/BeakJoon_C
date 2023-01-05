import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Main stepG = new Main();
        stepG.g02();
    }

    void g02() {
        Scanner s = new Scanner(System.in);
        char[][] strarr = new char[5][15];
        int count = 0;
        
        // 문자열 저장
        for(int i = 0; i < 5; i++){
            String word = s.nextLine();
            for(int j = 0; j < word.length(); j++){
				strarr[i][j] = word.charAt(j);
			}
        }
        
        for(int i = 0; i < 15; i++){
            for(int j = 0; j < 5; j++){
                if(strarr[j][i] == '\0'){
                    continue;
                }
                System.out.print(strarr[j][i]);
            }
        }
	}
}