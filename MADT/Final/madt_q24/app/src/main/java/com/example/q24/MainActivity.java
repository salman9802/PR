package com.example.q24;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.net.Uri;
import android.os.Bundle;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {
    /* Q24. Write a program to search a specific location on Google Map. */

    EditText locationEditText;
    Button searchBtn;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        this.locationEditText = (EditText) findViewById(R.id.location_edit_text);
        this.searchBtn = (Button) findViewById(R.id.search_btn);

        this.searchBtn.setOnClickListener(v -> {
            String searchLocation = this.locationEditText.getText().toString();
            if(searchLocation.isEmpty())
                Toast.makeText(this, "Please enter a location to search", Toast.LENGTH_SHORT).show();
            else
                startActivity(new Intent(Intent.ACTION_VIEW, Uri.parse("geo:0,0?q=" + searchLocation)));
        });
    }
}