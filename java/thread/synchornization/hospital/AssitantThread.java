package synchornization.hospital;

import java.util.Queue;

public class AssitantThread implements Runnable {
    private Queue<String> waiting_room;
    private int patient_number = 1;

    public AssitantThread(Queue<String> waiting_room) {
        this.waiting_room = waiting_room;
    }

    @Override
    public void run() {
        while (true) {
            try {
                Thread.sleep(500); // Thread sleep for 500ms
                String patient = new String("Patient " + patient_number++);
                System.out.println("[Assistant] New: " + patient);
                synchronized (waiting_room) { // shared data waitting room
                    waiting_room.add(patient);
                    waiting_room.notifyAll(); // wake thread Doctor up to run
                }
            } catch (InterruptedException e) {
                System.out.println("[Assistant] Closing ...");
                break;
            }
        }
    }


}