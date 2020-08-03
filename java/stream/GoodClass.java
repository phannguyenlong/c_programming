import java.io.Serializable;
import java.math.BigDecimal;

public class GoodClass implements Serializable{
    private static final long serialVersionUID = 1L;
    
    private String good, desc;
    private BigDecimal price;

    public GoodClass(String good, String desc, BigDecimal price) {
        this.good = good;
        this.desc = desc;
        this.price = price;
    }
    
    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append(good).append(" ");
        sb.append(desc).append(" ");
        sb.append(price);
        return sb.toString();
    }

    public String getGood() {
        return good;
    }

    public void setGood(String good) {
        this.good = good;
    }

    public String getDesc() {
        return desc;
    }

    public void setDesc(String desc) {
        this.desc = desc;
    }

    public BigDecimal getPrice() {
        return price;
    }

    public void setPrice(BigDecimal price) {
        this.price = price;
    }

    public void display() {
        System.out.println(String.format("Price: %s, Good: %s, Desc: %s", price, good, desc));
    }
}