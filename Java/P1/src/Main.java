
public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		char[] test1 = {'a','a','b','b','c','c','c'};
		System.out.println(compress(test1));
		System.out.println(test1);

	}
	
	static public int compress(char[] chars) {
        String s = "";
        int count = 1;
        s += ""+chars[0];
        for(int i = 0; i < chars.length-1; i++){
            if(chars[i] != chars[i+1]){
               s += "" + chars[i+1];
               count = 1;
            } 
        }
        System.out.println(s);
        chars = s.toCharArray();
        return s.length();
    }

}
