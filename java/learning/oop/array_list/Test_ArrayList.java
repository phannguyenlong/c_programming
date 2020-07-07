package array_list;

import java.util.ArrayList;

class Test_ArrayList {
 public static void main(String[] args) {
  //Tạo một ArrayList
  ArrayList <String> arlTest = new ArrayList <String>();
  //Kiểm tra size của arrayList
  System.out.println("Size of ArrayList at creation: " + arlTest.size());
  //Lets add some elements to it
  arlTest.add("D");
  arlTest.add("U");
  arlTest.add("K");
  arlTest.add("E");

  //Kiểm tra lại size sau khi đã thêm mới
  System.out.println("Size of ArrayList after adding elements: " + arlTest.size());

  //Hiển thị toàn bộ ArrayList
  System.out.println("List of all elements: " + arlTest);

  //Loại bỏ phần tử D ra khỏi ArrayList
  arlTest.remove("D");
  System.out.println("See contents after removing one element: " + arlTest);

  //Loại bỏ phần tử ra khỏi ArrayList bằng chỉ số
  arlTest.remove(2);
  System.out.println("See contents after removing element by index: " + arlTest);

  //Kiểm tra lại size sau khi loại bỏ phần tử
  System.out.println("Size of arrayList after removing elements: " + arlTest.size());
  System.out.println("List of all elements after removing elements: " + arlTest);

  //Kiểm tra xem ArrayList có chứa "K" không
  System.out.println(arlTest.contains("K"));

 }
}