package com.example.q11;

import android.content.Context;
import android.widget.Toast;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;

public class Student {
    String rollNo, name;
    static private Context context;

    private static String FILENAME = "students.txt";

    public Student(String rollNo, String name) {
        this.rollNo = rollNo;
        this.name = name;
    }

    public String getRollNo() {
        return rollNo;
    }

    public String getName() {
        return name;
    }

    public static void setContext(Context context) { Student.context = context; }

    public static ArrayList<String> getStudents() {
        try{
            String line;
            ArrayList<String> result = new ArrayList<>();
            BufferedReader reader = new BufferedReader(new InputStreamReader(Student.context.openFileInput(Student.FILENAME)));
            while((line = reader.readLine()) != null) {
                result.add(line);
            }
            return result;
        } catch (FileNotFoundException e) {
            Toast.makeText(Student.context, e.getMessage(), Toast.LENGTH_SHORT).show();
        } catch (IOException e) {
            Toast.makeText(Student.context, e.getMessage(), Toast.LENGTH_SHORT).show();
        }
        return null;
    }

    public boolean save() {
        try {
            ArrayList<String> previousStudents = Student.getStudents();
            OutputStreamWriter o = new OutputStreamWriter(Student.context.openFileOutput(Student.FILENAME, Context.MODE_APPEND));
//            for(String line : previousStudents)
//                o.append(line);
            o.append(this.getRollNo() + "," + this.getName() + "\n");
            o.flush();
            o.close();
            return true;
        } catch (FileNotFoundException e) {
//            Toast.makeText(context, e.getMessage(), Toast.LENGTH_SHORT).show();
            return false;
        } catch (IOException e) {
//            Toast.makeText(context, e.getMessage(), Toast.LENGTH_SHORT).show();
            return false;
        }
    }
}
