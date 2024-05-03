package com.example.q11;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;

import java.util.ArrayList;

public class MainActivity extends AppCompatActivity {
    /* Create an Android application, the user can enter 10 students information and stored
    it in file and display student information in second view and also search the particular
    student information. */

    EditText rollNoEditText, nameEditText, searchStudentEditText;
    TextView searchStudentTextView;
    Button addStudentBtn, allStudentsBtn, searchStudentBtn;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        this.rollNoEditText = (EditText) findViewById(R.id.student_roll_no);
        this.nameEditText = (EditText) findViewById(R.id.student_name);
        this.addStudentBtn = (Button) findViewById(R.id.add_student);
        this.allStudentsBtn = (Button) findViewById(R.id.all_students);

        this.searchStudentEditText = (EditText) findViewById(R.id.search_student_edit_text);
        this.searchStudentBtn = (Button) findViewById(R.id.search_student_btn);
        this.searchStudentTextView = (TextView) findViewById(R.id.search_student_text_view);

        Student.setContext(this);

        this.addStudentBtn.setOnClickListener(v -> {
            String rollNo = this.rollNoEditText.getText().toString();
            String name = this.nameEditText.getText().toString();
            if(rollNo.isEmpty() || name.isEmpty())
                Toast.makeText(this, "Please fill all fields!", Toast.LENGTH_SHORT).show();
            else {
                Student newStudent = new Student(rollNo, name);
                if(newStudent.save()) Toast.makeText(this, "Student Added!", Toast.LENGTH_SHORT).show();
                else Toast.makeText(this, "Failed to save student", Toast.LENGTH_SHORT).show();
                this.rollNoEditText.getText().clear();
                this.nameEditText.getText().clear();
            }
        });

        this.allStudentsBtn.setOnClickListener(v -> {
            startActivity(new Intent(this, AllStudentsActivity.class));
        });
        
        this.searchStudentBtn.setOnClickListener(v -> {
            String rollNo = this.searchStudentEditText.getText().toString();
            if(rollNo.isEmpty()) Toast.makeText(this, "Please enter RollNo. of Student to search", Toast.LENGTH_SHORT).show();
            else {
                ArrayList<String> students = Student.getStudents();
                for (String student : students) {
                    if(student.startsWith(rollNo)) {
                        searchStudentTextView.setText("Student Found. ( " + student.replace(",", " : ") + " )");
                        return;
                    }
                }
                searchStudentTextView.setText("Student with given Roll No. not found.");
            }
        });
    }
}