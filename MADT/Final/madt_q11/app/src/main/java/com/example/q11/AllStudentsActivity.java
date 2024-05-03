package com.example.q11;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.widget.ArrayAdapter;
import android.widget.ListView;
import android.widget.Toast;

import java.util.ArrayList;

public class AllStudentsActivity extends AppCompatActivity {

    ListView listView;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_all_students);

        this.listView = (ListView) findViewById(R.id.students_list_view);

        ArrayList<String> students = Student.getStudents();
        for(int i = 0; i < students.size(); i++) students.get(i).replace(",", " : ");

        if(students == null) {
            Toast.makeText(this, "No Students found!", Toast.LENGTH_SHORT).show();
        } else {
            ArrayAdapter<String> adapter = new ArrayAdapter<String>(this, android.R.layout.simple_list_item_1, students);
            this.listView.setAdapter(adapter);
        }
    }
}