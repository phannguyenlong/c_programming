package chap4.string;

import java.util.Arrays;
import java.util.Comparator;

/**
 * This is exercise 4.4
 * This will check whether this a anagram or not (anagram is permuation of letter in first word to be a new word)
 * This program will care about lower and upper case
 */
public class AnagramCheck {
    public AnagramCheck() {
    } 
    
    boolean check(String str1, String str2) {
        if (str1.length() != str2.length())
            return false;
        // covert to array and sort
        // char[] arr1 = sortString(str1);
        // char[] arr2 = sortString(str2);

        char[] arr1 = sortStringByComparator(str1);
        char[] arr2 = sortStringByComparator(str2);

        for (int i = 0; i < arr1.length; i++) {
            if (arr1[i] != arr2[i])
                return false;
        }

        return true;
    }

    char[] sortString(String str) {
        char[] arr = str.toCharArray();
        for (int i = 0; i < arr.length; i++) {
            for (int x = 0; x < arr.length; x++)
                if ((int) arr[i] < (int) arr[x]) {
                    char tmp = arr[i];
                    arr[i] = arr[x];
                    arr[x] = tmp;
                }
        }
        return arr;
    }

    char[] sortStringByComparator(String str) {
        // cannot use char cause char is not an object ==> must convert to Character object
        Character[] arr = new Character[str.length()];
        for (int i = 0; i < arr.length; i++) {
            arr[i] = str.charAt(i);
        }
        
        
        Arrays.sort(arr,new Comparator<Character> () {
            @Override
            public int compare(Character o1, Character o2) {
                return Character.compare(o1, o2);
            }
        });
          // using StringBuilder to convert Character array to String 
        StringBuilder sb = new StringBuilder(arr.length); 
        for (Character c : arr) 
            sb.append(c.charValue()); 

        return sb.toString().toCharArray(); // so dump return
    }
    
    public static void main(String[] args) {
        if (args.length != 2) {
            System.out.println("Systax error: java anagram <string1> <string2>");
            System.exit(0);
        } else {
            AnagramCheck checker = new AnagramCheck();
            System.out.println(checker.check(args[0], args[1]));
        }
    }
}