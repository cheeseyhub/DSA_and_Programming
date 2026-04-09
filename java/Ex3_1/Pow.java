public class Pow {
    public static double pow(int x , int n)
    {
        if (n < 0)
        {
            return 1.0 / pow(x,-n);
        }
        double result = 1;

        for(int i = 1; i <=n;i++)
        {
            result *= x;
        }
        return result;
    }
    public static void main(String[] args) {
        
        System.out.println(pow(2,-8));
    }
    
}
