package com.example.q13;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;

import java.util.ArrayList;

public class MainActivity extends AppCompatActivity {
    /*
        Create table Customer (id, name, address, phno). Create Application for Performing
        the following operation on the table. (using sqlite database) i) Insert New Customer
        Details. ii) Show All the Customer Details
    */

    EditText customerNameEditText, customerAddressEditText, customerPhoneEditText;
    Button insertCustomerBtn;
    TextView customerDetailsTextView;
    CustomerDB db;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        this.initViews();
        db = new CustomerDB(this);

        this.insertCustomerBtn.setOnClickListener(v -> {
            String name = this.customerNameEditText.getText().toString(),
                    address = this.customerAddressEditText.getText().toString(),
                    phone = this.customerPhoneEditText.getText().toString();

            if(name.isEmpty() || address.isEmpty() || phone.isEmpty())
                Toast.makeText(this, "Please Fill all fields!", Toast.LENGTH_SHORT).show();
            else {
                try {

                    db.open();
                    db.insertCustomer(new Customer(null, name, address, phone));
                    db.close();
                    this.showCustomers();
                    this.customerNameEditText.setText("");
                    this.customerAddressEditText.setText("");
                    this.customerPhoneEditText.setText("");

                    Toast.makeText(this, "Customer Inserted Successfully!", Toast.LENGTH_SHORT).show();
                }catch(Exception e) {
                    Toast.makeText(this, e.getMessage(), Toast.LENGTH_SHORT).show();
                }
            }
        });
    }

    public void initViews() {
        this.customerNameEditText = (EditText) findViewById(R.id.customer_name);
        this.customerAddressEditText = (EditText) findViewById(R.id.customer_address);
        this.customerPhoneEditText = (EditText) findViewById(R.id.customer_phone);
        this.insertCustomerBtn = (Button) findViewById(R.id.insert_customer);
        this.customerDetailsTextView = (TextView) findViewById(R.id.customer_details);
    }

    public void showCustomers() {
        try {
            this.db.open();
            ArrayList<Customer> customers = this.db.fetchAll();
            this.db.close();
            if(customers.size() > 0) {
                String result = "";
                for (Customer c :customers) {
                    result += "Id: " + c.get_id() + ", Name: " + c.getName() + ", Address: " + c.getAddress() + ", Phone: " + c.getPhoneNumber() + "\n";
                }

                this.customerDetailsTextView.setText(result);
            }
        } catch (Exception e) {
            Toast.makeText(this, e.getMessage(), Toast.LENGTH_SHORT).show();
        }
    }


}