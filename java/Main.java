public class Main {
  public static void main(String[] args) {
    my_stack<Integer> stack = new my_stack<>();

    stack.append(88);
    stack.append(99);
    stack.append(77);
    stack.append(12);
    stack.append(102983);

    System.out.println(stack.peek());

  }
}
