package com.example.q15;

public class Department {
    String dept_no,dept_name,location, emp_no;

    public Department(String dept_no, String dept_name, String location, String emp_no) {
        this.dept_no = dept_no;
        this.dept_name = dept_name;
        this.location = location;
        this.emp_no = emp_no;
    }

    public String getDept_no() {
        return dept_no;
    }

    public String getDept_name() {
        return dept_name;
    }

    public String getLocation() {
        return location;
    }

    public String getEmp_no() {
        return emp_no;
    }

    @Override
    public String toString() {
        return "Department{" +
                "dept_no='" + dept_no + '\'' +
                ", dept_name='" + dept_name + '\'' +
                ", location='" + location + '\'' +
                ", emp_no='" + emp_no + '\'' +
                '}';
    }
}
