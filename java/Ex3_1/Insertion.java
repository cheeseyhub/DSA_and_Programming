import java.util.ArrayList;

public class Insertion {
    public static ArrayList<Integer> insert(ArrayList<Integer> list , int x)
    {

        int pos = 0;
        while (pos < list.size() && list.get(pos)< x)
        {
            pos++;
        }
        list.add(null);
        for(int i = list.size() - 1 ; i > pos; i--)
        {
            list.set(i ,list.get(i -1 ));
        }
        list.set(pos,x);

        return list;





    }
    public static void main(String[] args) {
        
        ArrayList<Integer> myList = new ArrayList<>();
        myList.add(1);
        myList.add(2);
        myList.add(3);
        myList.add(5);
        myList.add(6);
        myList.add(7);
        myList.add(8);
        System.out.println(insert(myList,4));
    }
    
}
