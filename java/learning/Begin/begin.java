class Begin {
    public static void main(String args[]) {
        System.out.println("Hello Java");
        int a = run(20);
        System.out.println(a);

        // handle strings
        String line1 = "Nah nah nah nah nah nah nah nah nah yeah";
        String line2 = "Nah nah nah nah nah nah, nah nah nah, hey Jude";
        System.out.print("Is line1 equal line2: " + line1.equals(line2)); // Using "equal" to compare strings and strings
    }

    public static int run(int num) {
        int sum = 0;
        for (int i = 0; i < num; i++) {
            sum += i;
        }
        return sum;
    }
}