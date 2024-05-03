package com.example.q15;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

public class AddDepartmentActivity extends AppCompatActivity {

    EditText deptNo, deptName, location, empNo;
    Button addBtn;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_add_department);

        deptNo = (EditText) findViewById(R.id.dept_no);
        deptName = (EditText) findViewById(R.id.dept_name);
        location = (EditText) findViewById(R.id.location);
        empNo = (EditText) findViewById(R.id.emp_no);
        addBtn = (Button) findViewById(R.id.add_dept);

        addBtn.setOnClickListener(v -> {
            try {
                String dept_no, dept_name, location, emp_no;

                dept_no = deptNo.getText().toString();
                dept_name = deptName.getText().toString();
                location = this.location.getText().toString();
                emp_no = empNo.getText().toString();

                if (dept_no.isEmpty() || dept_name.isEmpty() || location.isEmpty() || emp_no.isEmpty())
                    Toast.makeText(this, "Please fill all fields!", Toast.LENGTH_SHORT).show();

                DepartmentDB db = new DepartmentDB(this);
                db.open();
                db.insertDepartment(new Department(dept_no, dept_name, location, emp_no));
                db.close();
                Toast.makeText(this, "Department Added Successfully!", Toast.LENGTH_SHORT).show();
            } catch (Exception e) {
                Toast.makeText(this, e.getMessage(), Toast.LENGTH_SHORT).show();
            }
        });
    }
}