import java.util.Scanner;

public class palindrome {
  public static boolean checkPalindrome(String string) {
    string = string.toLowerCase();

    for (int i = 0, middle = string.length() / 2; i < middle; i++) {

      if (string.charAt(i) != string.charAt((string.length() - 1) - i)) {

        return false;
      }

    }
    return true;
  }

  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    System.out.println(checkPalindrome("bob"));
    scanner.close();

  }
}
