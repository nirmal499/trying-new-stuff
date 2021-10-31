package mod11;

class ThreadImplement {
    public static void main(String[] args) {
        MyOwnThread1 threadA1 = new MyOwnThread1("A");
        MyOwnThread1 threadB1 = new MyOwnThread1("B");

        threadA1.start();
        threadB1.start();

        Thread threadA2 = new Thread(new MyOwnThread2("A"));
        Thread threadB2 = new Thread(new MyOwnThread2("B"));
        threadA2.start();
        threadB2.start();

    }

    public static class MyOwnThread1 extends Thread {
        String name = "";

        MyOwnThread1(String _name) {
            name = _name;
        }

        public void run() {
            System.out.println("Thread " + name + " running");
        }
    }

    public static class MyOwnThread2 implements Runnable {
        String name = "";

        MyOwnThread2(String _name) {
            name = _name;
        }

        public void run() {
            System.out.println("Thread " + name + " running");
        }
    }

}