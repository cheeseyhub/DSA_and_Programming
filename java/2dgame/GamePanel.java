import javax.swing.JPanel;
import java.awt.Dimension;
import java.awt.Color;

public class GamePanel extends JPanel{
   

    int originalTileSize = 16;
    int scale =3;
    int tileSize = originalTileSize * scale;

    int maxScreenCol = 16;
    int maxScreenRow = 12;

    int screenWidth = tileSize * maxScreenRow;
    int screenHeight = tileSize * maxScreenCol;


    public GamePanel() {

        this.setPreferredSize(new Dimension(screenWidth,screenHeight));
        this.setBackground(Color.black);
        this.setDoubleBuffered(true);
    }
}
