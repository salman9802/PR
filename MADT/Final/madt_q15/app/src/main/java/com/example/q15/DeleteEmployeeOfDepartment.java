package com.example.q15;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

public class DeleteEmployeeOfDepartment extends AppCompatActivity {

    EditText deptNameEditText;
    Button delEmpBtn;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_delete_employee_of_department);

        this.deptNameEditText = (EditText) findViewById(R.id.dept_name);
        this.delEmpBtn = (Button) findViewById(R.id.del_emp);

        this.delEmpBtn.setOnClickListener(v -> {
            String deptName = this.deptNameEditText.getText().toString();

            if(deptName.isEmpty()) Toast.makeText(this, "Please enter department name!", Toast.LENGTH_SHORT).show();
            else {
                try {
                    DepartmentDB db = new DepartmentDB(this);
                    db.open();
                    String empNo = db.fetchEmpNo(deptName);
                    db.close();
                    
                    EmployeeDB db2 = new EmployeeDB(this);
                    db2.open();
                    db2.deleteEmployee(empNo);
                    db2.close();

                    Toast.makeText(this, "Employee information deleted Successfully!", Toast.LENGTH_SHORT).show();
                }catch(Exception e) {
                    Toast.makeText(this, e.getMessage(), Toast.LENGTH_SHORT).show();
                }
            }
        });
    }
}