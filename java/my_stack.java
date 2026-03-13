import java.util.ArrayList;

public class my_stack<T> {

  private ArrayList<T> stack = new ArrayList<T>();

  public void append(T item) {
    stack.add(item);
  }

  public T peek() {

    return stack.getLast();

  }

  public T pop() {
    return stack.removeLast();
  }

}
