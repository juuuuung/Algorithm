import java.io.*;
import java.util.StringTokenizer;

public class Main{

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer token = new StringTokenizer(br.readLine(), " ");

		int set = Integer.parseInt(token.nextToken());
		int variance = Integer.parseInt(token.nextToken());
		int sales = Integer.parseInt(token.nextToken());

		if (sales <= variance)
			System.out.println("-1");
		else
			System.out.println((set / (sales - variance) + 1));
	}
}