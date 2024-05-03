package com.example.q15;

public class Employee {
    String emp_no,emp_name,address,phone,salary;

    public Employee(String emp_no, String emp_name, String address, String phone, String salary) {
        this.emp_no = emp_no;
        this.emp_name = emp_name;
        this.address = address;
        this.phone = phone;
        this.salary = salary;
    }

    public String getEmp_no() {
        return emp_no;
    }

    public String getEmp_name() {
        return emp_name;
    }

    public String getAddress() {
        return address;
    }

    public String getPhone() {
        return phone;
    }

    public String getSalary() {
        return salary;
    }

    @Override
    public String toString() {
        return "Employee{" +
                "emp_no='" + emp_no + '\'' +
                ", emp_name='" + emp_name + '\'' +
                ", address='" + address + '\'' +
                ", phone='" + phone + '\'' +
                ", salary='" + salary + '\'' +
                '}';
    }
}
