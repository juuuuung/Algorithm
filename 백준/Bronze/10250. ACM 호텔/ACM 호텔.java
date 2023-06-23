import java.io.*;
import java.util.StringTokenizer;

public class Main{
	public static void main(String[] args) throws IOException {
		// H,W,N = 층, 가로 넓이, 몇번재 손님인지
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int t = Integer.parseInt(br.readLine());
		int[] arr = new int[t];
		for (int i = 0; i < t; i++) {
			StringTokenizer token = new StringTokenizer(br.readLine());
			int h = Integer.parseInt(token.nextToken());
			int w = Integer.parseInt(token.nextToken());
			int user = Integer.parseInt(token.nextToken());

			if (user % h == 0)
				arr[i] = h * 100 + (user / h);
			else
				arr[i] = (user % h) * 100 + (user / h) + 1;
		}
		for (int i : arr)
			System.out.println(i);
	}
}