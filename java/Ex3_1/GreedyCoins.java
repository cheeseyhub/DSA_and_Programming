public class GreedyCoins {
    public static void greedyAlgo(int dollars)
    {
        int Quaters = dollars  / 25;
        dollars %= 25;

        int Dimes = dollars / 10;
        dollars %= 10;

        int nickels = dollars / 5;
        dollars %= 5;

        int pennies = dollars / 1 ;
        dollars %= 1;


        System.out.println(" Quaters used were : " + Quaters );
        System.out.println(" Dimes used were : " + Dimes );
        System.out.println(" nickels used were : " + nickels);
        System.out.println(" pennies used were : " + pennies );


    }
    public static void main(String[] args) {
        
        greedyAlgo(87);
    }
    
}
