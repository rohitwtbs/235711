import java.util.*;

public class input {
    public static void main (String[] args) {
        System.out.println("Program executed");
        Scanner sc = new Scanner(System.in);
        String inputSentence = sc.nextLine();
        System.out.println(inputSentence);
        Book b = new Book(101,"Let us C","Yashwant Kanetkar","BPB",8);
        System.out.println(b.quantity);
        HashSet<Book> hs = new HashSet<Book>();
        hs.add(b);
        for(Book abook:hs) {
            System.out.println(abook);
        }
        
    }
    public int add (int a , int b) {
        return a+b;
    }
}

class Book {  
    int id;  
    String name,author,publisher;  
    int quantity;  
    public Book(int id, String name, String author, String publisher, int quantity) {  
        this.id = id;  
        this.name = name;  
        this.author = author;  
        this.publisher = publisher;  
        this.quantity = quantity;  
    }  
    }  