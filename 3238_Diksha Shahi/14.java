
class PersonalDataException extends RuntimeException
{
 String message;

 PersonalDataException(String s)
 {
  message = s;
 } 


 void display()
 {
  System.out.println("PersonalDataException :" + message);
 }

 
 public String toString()
 {
  return "PersonalDataException : "+ message; 
 } 

 public String getMessage()
 {
  return message;
 }

}


class Person
{
 String name;
 int age;

 Person(String n, int a)throws PersonalDataException
 {
  setName(n);
  setAge(a);
 }

 void setName(String n)throws PersonalDataException
 {
  int i;
  String temp = n.toUpperCase();
  int l = temp.length();
  char q;

  for(i = 0; i < l; i++)
  {
   
   q = temp.charAt(i);   

   if(q < 65 || q >90)
   {
    PersonalDataException pe = new PersonalDataException("Invalid Name : " + n);   
    throw(pe);
   }

  }

  name = n; 
 }

 void setAge(int a) throws PersonalDataException
 {
  if(a < 0 || a > 100)
  {
   PersonalDataException pe = new PersonalDataException("Invalid Age : " + a);   
   throw(pe);
  }

  age = a; 

 }

 void display()
 {
  System.out.println(name + " " + age);
 }
}

class CustomException
{
 public static void main(String args[])
 {
  try
  {
   String s = args[0];
   int a = Integer.parseInt(args[1]);
   Person p = new Person(s, a);
   p.display();

  }
  catch(ArrayIndexOutOfBoundsException ex)
  {
   System.out.println("Usage : java CustomException <name> <age>");
  }
  catch(PersonalDataException pde)
  {
    pde.display();
  }
  catch(Exception ex)
  {
   System.out.println(ex);
  }
 }
}
