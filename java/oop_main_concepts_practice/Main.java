public class Main {

    public static void main(String[] args)
    {
        Inventory myInventory = new Inventory();

        Fruit newFruit = new Fruit("Fuji", "apple", 20);
        Weapon weapon = new Weapon("Gun", 100, 99, "Ranged");

        myInventory.addItem(newFruit);
        myInventory.addItem(weapon);

        myInventory.displayInventory();

    }
    
}
