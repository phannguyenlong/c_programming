package synchornization.hospital;

import java.util.Queue;

public class DoctorThread implements Runnable {
    private Queue<String> waiting_room; // shared data

    public DoctorThread(Queue<String> waiting_room) {
        this.waiting_room = waiting_room;
    }

    @Override
    public void run() {
        while (true) {
            try {
                synchronized (waiting_room) { // waiting room is shared data
                    while (waiting_room.isEmpty()) {
                        System.out.println("Doctor is waiting for patient");
                        waiting_room.wait();
                    }
                    String patient = waiting_room.poll(); // get patient
                    System.out.println("[Doctor] Treating " + patient);
                }
                Thread.sleep(1200); // thread wait for 1200ms
            } catch (InterruptedException e) {
                System.out.println("[Doctor] Closing...");
                break;
            }
        }
    }
}