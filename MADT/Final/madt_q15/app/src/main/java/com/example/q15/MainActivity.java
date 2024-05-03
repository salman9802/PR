package com.example.q15;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.ListView;
import android.widget.Toast;

import java.util.ArrayList;

public class MainActivity extends AppCompatActivity {
    /*
        Create Following Table: Emp (emp_no,emp_name,address,phone,salary) Dept
        (dept_no,dept_name,location) Emp-Dept is related with one-many relationship.
        Create application for performing the following Operation on the table 1) Add
        Records into Emp and Dept table. 2) Accept Department name from User and delete
        employee information which belongs to that department.
    */

//    final static public String DATABASE_NAME = "prac_q18";
    Button addEmpBtn, addDeptBtn, deleteEmpBtn, showEmpsBtn, showDeptsBtn;

    ListView listView;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        addEmpBtn = (Button) findViewById(R.id.add_emp);
        addDeptBtn = (Button) findViewById(R.id.add_dept);
        deleteEmpBtn = (Button) findViewById(R.id.delete_emp);
        showEmpsBtn = (Button) findViewById(R.id.show_emps);
        showDeptsBtn = (Button) findViewById(R.id.show_depts);

        addEmpBtn.setOnClickListener(v -> {
            startActivity(new Intent(this, AddEmployeeActivity.class));
        });

        addDeptBtn.setOnClickListener(v -> {
            startActivity(new Intent(this, AddDepartmentActivity.class));
        });

        listView = (ListView) findViewById(R.id.list_view);

        showEmpsBtn.setOnClickListener(v -> {
            try {
                ArrayList<Employee> data;
                EmployeeDB db = new EmployeeDB(this);
                db.open();
                data = db.fetchAll();
                db.close();

                ArrayAdapter<Employee> adapter = new ArrayAdapter<Employee>(this,android.R.layout.simple_list_item_1, data);
                listView.setAdapter(adapter);
            }catch(Exception e) {
                Toast.makeText(this, e.getMessage(), Toast.LENGTH_SHORT).show();
            }
        });

        showDeptsBtn.setOnClickListener(v -> {
            try {
                ArrayList<Department> data;
                DepartmentDB db = new DepartmentDB(this);
                db.open();
                data = db.fetchAll();
                db.close();

                ArrayAdapter<Department> adapter = new ArrayAdapter<Department>(this,android.R.layout.simple_list_item_1, data);
                listView.setAdapter(adapter);
            }catch(Exception e) {
                Toast.makeText(this, e.getMessage(), Toast.LENGTH_SHORT).show();
            }
        });

        deleteEmpBtn.setOnClickListener(v -> {
            startActivity(new Intent(this, DeleteEmployeeOfDepartment.class));
        });

    }
}