import java.io.*;
import java.math.BigDecimal;

public class Stream {
    // This is byte stream | read 8 bit each time
    public void testByteStream() throws IOException {
        FileInputStream in = null;
        FileOutputStream out = null;
        try {
            in = new FileInputStream("java/stream/data/text.txt");
            out = new FileOutputStream("java/stream/data/copy.txt");
            char c; // cause stream read 1 character at one time ==> use int or char
            while ((c = (char) in.read()) != (char) -1) {
                System.out.print(c + "\t"); // will wrint the number of word
                out.write(c);
            }
        } catch (FileNotFoundException e) {
            System.out.println("Can not locate file " + e.getMessage());
        } finally {
            if (in != null)
                in.close();
            if (out != null)
                out.close();
            System.out.println();
        }
    }

    // Character stream | read 1 character at a time (~16 bit)
    public void testCharacterStream() throws IOException {
        FileReader in = null;
        FileWriter out = null;
        try {
            in = new FileReader("java/stream/data/text.txt");
            out = new FileWriter("java/stream/data/copy.txt");
            char c;
            while ((c = (char) in.read()) != (char) -1) {
                System.out.print(c + "\t");
                out.write(c);
            }
        } finally {
            if (in != null)
                in.close();
            if (out != null)
                out.close();
            System.out.println();
        }
    }

    // Read 1 line at a time. Use Character Stream to read
    public void testLineIO() throws IOException {
        BufferedReader in = null;
        PrintWriter out = null;
        try {
            in = new BufferedReader(new FileReader("java/stream/data/text.txt"));
            out = new PrintWriter(new FileWriter("java/stream/data/copy.txt"));
            String line;
            while ((line = in.readLine()) != null) {
                System.out.println(line);
                out.println(line);
            }
        } finally {
            if (in != null)
                in.close();
            if (out != null)
                out.close();
            System.out.println();
        }
    }

    // use Character or Byte Stream to read and then store in buffer. Return buffer
    // when requested
    // Higher efficient
    public void testBufferStream() throws IOException {
        BufferedWriter out = null;
        try {
            out = new BufferedWriter(new FileWriter("java/stream/data/out.txt"));
            for (int i = 0; i < 100; i++) {
                out.write(" T3Xt " + i);
                // out.flush();
            }
        } finally {
            if (out != null)
                out.close();
        }
        BufferedReader in = null;
        try {
            in = new BufferedReader(new FileReader("java/stream/data/out.txt"));
            String line;
            while ((line = in.readLine()) != null) {
                System.out.println(line);
            }
        } finally {
            if (in != null)
                in.close();
            System.out.println();
        }
    }

    // Data Stream use for kind of data (String, int, double, ...)
    public void testDataStream() throws IOException {
        // writing the data using DataOutputStream
        try (DataOutputStream dout = new DataOutputStream(new FileOutputStream("java/stream/data/data_stream.dat"))) {
            dout.writeDouble(1.1);
            dout.writeInt(55);
            dout.writeBoolean(true);
            dout.writeChar('4');
        } catch (FileNotFoundException ex) {
            System.out.println("Cannot Open the Output File");
            return;
        }

        // reading the data back using DataInputStream
        try (DataInputStream din = new DataInputStream(new FileInputStream("java/stream/data/data_stream.dat"))) {
            double a = din.readDouble();
            int b = din.readInt();
            boolean c = din.readBoolean();
            char d = din.readChar();
            System.out.println("Values: " + a + " " + b + " " + c + " " + d);
        } catch (FileNotFoundException e) {
            System.out.println("Cannot Open the Input File");
            return;
        }
    }

    // Object Stream use to write Object (with implement Serializable) to file
    public void ObjectStream() throws IOException, ClassNotFoundException {
        GoodClass good1 = new GoodClass("Apple", "USA apple", new BigDecimal(0.29));
        GoodClass good2 = new GoodClass("Coconut", "Vn cocunut", new BigDecimal(3.5));
        ObjectInputStream in = null;
        ObjectOutputStream out = null;
        try {
            //Output
            out = new ObjectOutputStream(new BufferedOutputStream(new FileOutputStream("java/stream/data/object.dat")));
            out.writeObject(good1);
            out.writeObject(good2);
            out.close();
            //Input
            in = new ObjectInputStream(new BufferedInputStream(new FileInputStream("java/stream/data/object.dat")));
            while (true) {
                GoodClass object = (GoodClass) in.readObject(); // has to cast
                System.out.println(object.toString());
                object.display();
            }
        } catch (EOFException e) {
            // Has to catch this
        } finally {
            if (out != null)
                out.close();
            if (in != null)
                in.close();
        }
    }

    public static void main(String[] args) throws IOException, ClassNotFoundException {
        Stream file = new Stream();
        System.out.println("Byte Stream");
        file.testByteStream();
        System.out.println("Character Stream");
        file.testCharacterStream();
        System.out.println("LineIO Stream");
        file.testLineIO();
        System.out.println("Buffer Stream");
        file.testBufferStream();
        System.out.println("Data Stream");
        file.testDataStream();
        System.out.println();
        System.out.println("Object Stream");
        file.ObjectStream();
    }
}