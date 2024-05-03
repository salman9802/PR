package com.example.q18;

import androidx.appcompat.app.AlertDialog;
import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {
    /* Q18. Java Android Program to Demonstrate Alert Dialog Box */

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    }

    public void onBtnClicked(View v) {
        AlertDialog.Builder builder = new AlertDialog.Builder(this);
        builder.setTitle("Example Alert Dialog Box");
        builder.setMessage("This is an example of an alert dialog box.");

        // Set Cancelable false for when the user clicks on the outside the Dialog Box then it will remain show
        builder.setCancelable(false);

        builder.setPositiveButton("Yes", (dialogInterface, i) -> {
            Toast.makeText(this, "Yes Clicked!", Toast.LENGTH_SHORT).show();
            finish();
        });

        builder.setNegativeButton("No", (dialogInterface, i) -> {
            Toast.makeText(this, "No Clicked!", Toast.LENGTH_SHORT).show();
            dialogInterface.cancel();
        });

        // Create alert dialog box
        AlertDialog alertDialog = builder.create();
        alertDialog.show();
    }
}