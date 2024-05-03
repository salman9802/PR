package com.example.q15;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

public class AddEmployeeActivity extends AppCompatActivity {

    EditText empNo, empName, address, phone, salary;
    Button addBtn;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_add_employee);

        empNo = (EditText) findViewById(R.id.emp_no);
        empName = (EditText) findViewById(R.id.emp_name);
        address = (EditText) findViewById(R.id.address);
        phone = (EditText) findViewById(R.id.phone);
        salary = (EditText) findViewById(R.id.salary);
        addBtn = (Button) findViewById(R.id.add_emp);

        addBtn.setOnClickListener(v -> {
            try{
                String emp_no,emp_name,address,phone,salary;

                emp_no = empNo.getText().toString();
                emp_name = empName.getText().toString();
                address = this.address.getText().toString();
                phone = this.phone.getText().toString();
                salary = this.salary.getText().toString();

                if(emp_no.isEmpty() || emp_name.isEmpty() || address.isEmpty() || phone.isEmpty() || salary.isEmpty())
                    Toast.makeText(this, "Please fill all fields!", Toast.LENGTH_SHORT).show();

                EmployeeDB db = new EmployeeDB(this);
                db.open();
                db.insertEmployee(new Employee(emp_no, emp_name, address, phone, salary));
                db.close();
                Toast.makeText(this, "Employee Added Successfully!", Toast.LENGTH_SHORT).show();
            }catch (Exception e) {
                Toast.makeText(this, e.getMessage(), Toast.LENGTH_SHORT).show();
            }
        });
    }
}