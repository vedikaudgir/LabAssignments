class Word98 {
    int year;


    Word98(int year) {
        this.year = year;
    }


    void display1() {
        System.out.println("Word98 Year: " + this.year);
    }
}


class Word2000 extends Word98 {
    int year;


    Word2000(int y98, int y2000) {
        super(y98);
        this.year = y2000;
    }


    void display2() {
        super.display1();
        System.out.println("Word2000 Year: " + this.year);
    }
}


class Word2003 extends Word2000 {
    int year;


    Word2003(int y98, int y2000, int y2003) {
        super(y98, y2000);
        this.year = y2003;
    }
    
    void display3() {
        super.display2();
        System.out.println("Word2003 Year: " + this.year);
    }
}

class Word2007 extends Word2003 {
    int year;

    Word2007(int y98, int y2000, int y2003, int y2007) {
        super(y98, y2000, y2003);
        this.year = y2007;
    }

    void display4() {
        super.display3();
        System.out.println("Word2007 Year: " + this.year);
    }
}

public class Main {
    public static void main(String[] args) {
        Word2007 obj = new Word2007(1998, 2000, 2003, 2007);
        obj.display4();
    }
}

