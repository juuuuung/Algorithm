import java.io.*;

public class Main{

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int X = Integer.parseInt(br.readLine());

		int before_cnt = 0, know_cnt = 1;

		while (true) {
			if (X <= before_cnt + know_cnt) {
				int a = (before_cnt + know_cnt) - X;
				if (know_cnt % 2 == 1) {
					System.out.println((1 + a) + "/" + (know_cnt - a));
				} else {
					System.out.println((know_cnt - a) + "/" + (1 + a));
				}
				break;
			} else {
				before_cnt += know_cnt;
				know_cnt++;
			}
		}
	}
}