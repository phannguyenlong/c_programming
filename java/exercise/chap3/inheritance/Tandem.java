package chap3.inheritance;

/**
 * This is class inherit form class Bicycle
 * This is belong to ex3.6
 */
public class Tandem extends Bicycle {
    private String seats;
    
    public Tandem(String candence, String speed, String gear, String seats) {
        super(candence, speed, gear);
        this.seats = seats;
    }

    public String getSeats() {
        return seats;
    }
    public void setSeats(String seats) {
        this.seats = seats;
    }
}