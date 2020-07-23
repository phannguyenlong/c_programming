package chap3.inheritance;


public class Bicycle {
    protected String candence;
    protected String speed;
    protected String gear;
    
    public Bicycle(String candence, String speed, String gear) {
        this.candence = candence;
        this.gear = gear;
        this.speed = speed;
    }

    public String getCandence() {
        return this.candence;
    }

    public void setCandence(String candence) {
        this.candence = candence;
    }

    public String getSpeed() {
        return this.speed;
    }

    public void setSpeed(String speed) {
        this.speed = speed;
    }

    public String getGear() {
        return this.gear;
    }

    public void setGear(String gear) {
        this.gear = gear;
    }
    
}