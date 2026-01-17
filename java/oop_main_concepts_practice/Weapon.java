public class Weapon  extends Item{
    
    private String type;
    private int damage;
    public Weapon(String name,int quantity, int damage , String type )
    {
        super(name, quantity);
        this.damage = damage;
        this.type = type;
        this.damage = damage;
    }
    public int getDamage() {
        return damage;
    }
    public String getType() {
        return type;
    }
    @Override
    public void displayInfo() {
        System.out.println( "\n Weapon: " + getName() + "Quantity :" + getQuantity()+ " Type :" + type);
    }
}
