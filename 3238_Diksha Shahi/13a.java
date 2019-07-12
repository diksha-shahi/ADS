import mypackage.areaCalculation;
import java.util.Scanner;


class main{
    public static void main( String args[]){
        boolean e = true;
        do{
            
            System.out.println("Area Calculation");
            System.out.println("1.Circle");
            System.out.println("2.Rectangle");
            System.out.println("3.Triangle ");
            System.out.println("0.Exit");
            Scanner in = new Scanner(System.in);
            int inp = in.nextInt();
            areaCalculation a = new areaCalculation();
            switch(inp){
                case 1 :
                    System.out.println("Radius: ");
                    double radius = in.nextDouble();
                    System.out.println("AREA : " + a.calcCircleArea(radius));
                    break;

                case 2 :
                    System.out.println("Width and Height: ");
                    double width = in.nextDouble();
                    double height = in.nextDouble();
                    System.out.println("AREA : " + a.calcRectangleArea(width,height));
                    break;

                case 3 :
                    System.out.println("triangle side: ");
                    double s1 = in.nextDouble();
                    double s2 = in.nextDouble();
                    double s3 = in.nextDouble();
                    if(s1+s2<s3 || s2+s3<s1 || s1+s3<s2)
                        System.out.println("triangle cannot be formed");
                    else{ 
                        System.out.println("AREA : " + a.calcTriangleArea(s1,s2,s3));
                        break;   
                    }

                case 0:
                    e = false;
                    break;

                default:
                    System.out.println("WRONG INPUT");
            }
        }
        while(e);
    }
}
