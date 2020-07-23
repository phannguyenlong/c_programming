package chap3;

import java.util.Arrays;

public class CeacarCipher implements CharSequence {
    private char[] string_arr;
    public CeacarCipher(String line, int shift) {
        string_arr = line.toCharArray();
        for (int i = 0; i < string_arr.length; i++) {
            int tmp = (int) string_arr[i];
            if (tmp >= 48 && tmp <= 57) {
                string_arr[i] = (char) ((tmp + shift) > 57 ? (48 + (shift - (57 - tmp))) : tmp + shift); //cast int to char
            }
            else if (tmp >= 65 && tmp <= 90) {
                string_arr[i] = (char) ((tmp + shift) > 90 ? (65 + (shift - (90 - tmp))) : tmp + shift);
            }
            else if (tmp >= 97 && tmp <= 122) {
                string_arr[i] = (char) ((tmp + shift) > 122 ? (97 + (shift - (122 - tmp))) : tmp + shift);
            }
        }
        System.out.println(string_arr);
    }
    
    @Override
    public int length() {
        return string_arr.length;
    }

    @Override
    public char charAt(int index) {
        return string_arr[index];
    }

    @Override
    public CharSequence subSequence(int start, int end) {
        char[] subarr = Arrays.copyOfRange(string_arr, start, end + 1); // create subarray
        return String.valueOf(subarr);
    }
    public static void main(String[] args) {
        CharSequence cs = new CeacarCipher("Test 26", 1);
        System.out.println(cs.length());
        System.out.println(cs.charAt(1));
        System.out.println(String.valueOf(cs.subSequence(0, 6)));
    }   
}