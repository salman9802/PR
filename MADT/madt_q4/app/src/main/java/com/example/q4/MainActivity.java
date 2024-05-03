package com.example.q4;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {

    EditText phoneNumber;
    Button submit;
    
    private String[] possibleAreaCodes = {
        "040", "041", "050", "0400", "044"
    };

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        phoneNumber = (EditText) findViewById(R.id.phone_number);
        submit = (Button) findViewById(R.id.submit);

        submit.setOnClickListener(v -> {
            String value = phoneNumber.getText().toString();
            // If value is empty
            if(value.isEmpty()) Toast.makeText(this, "Phone is empty!", Toast.LENGTH_SHORT).show();
            else {
                int index = verifyAreaCode(value);
                // If area code is not valid
                if(index == -1) Toast.makeText(this, "Invalid Area Code!", Toast.LENGTH_SHORT).show();
                else {
                    String telephone = value.substring(index);
                    // if telephone is not valid
                    if((telephone.length() < 6) || (telephone.length() > 8)) {
                        Toast.makeText(this, "Telephone should be 6-8 numbers", Toast.LENGTH_SHORT).show();
                    } else {
                        Toast.makeText(this, "Valid Phone Number!", Toast.LENGTH_LONG).show();
                    }
                }
            }
        });

    }
    
    public int verifyAreaCode (String value) {
        for(String areaCode : possibleAreaCodes) {
           if(value.startsWith(areaCode)) {
               return areaCode.length(); // start index for telephone
           }
        }
        return -1; // if not valid area code
    }
}