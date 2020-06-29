public class nestedClass {
     public static void main(String[] args) {
        nestedClass obj = new nestedClass();
        nestedClass.innerClass innerObject = obj.new innerClass();
        System.out.println(innerObject.prime());
    }
    public class innerClass {
        public int prime() {
            return 7;
        }
    }
}