package synchornization.hospital;

import java.util.LinkedList;
import java.util.Queue;

/**
 * This is the demo apply synchorinzed for porcess patient
 */
public class Office {
    public static void main(String[] args) throws InterruptedException {
        Queue<String> waiting_room = new LinkedList<String>();

        System.out.println("===========Hospital Program=========");
        Thread assistant = new Thread(new AssitantThread(waiting_room));
        Thread doctor = new Thread(new DoctorThread(waiting_room));

        assistant.start();
        doctor.start();
        
        // waiting time for to kill both thread
        Thread.sleep(10000);
        assistant.interrupt();
        Thread.sleep(8000);
        doctor.interrupt();
    }    
}