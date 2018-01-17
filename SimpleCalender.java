import java.io.*;
import java.util.*;
import java.text.*;


class SimpleCalender{
	public static void main(String args[]) {
		Scanner inputReg = new Scanner(System.in);
          DateFormat df = new SimpleDateFormat("d/M/yyyy");
          df.getCalendar().setLenient(false);
          System.out.print("Enter Date of Birth (DD/MM/YYYY): ");

          Date theDate = null;
          try {
              String date=inputReg.nextLine();
              // System.out.println("date="+date+"@");
            theDate = df.parse(date);
        } catch (ParseException e) {
            e.printStackTrace();
        }

		SimpleDateFormat sdf = new SimpleDateFormat("EEEE");
       System.out.println(sdf.format(theDate));
       Calendar dob=df.getCalendar(); // Set this inside Customer
       inputReg.close();
	}


}