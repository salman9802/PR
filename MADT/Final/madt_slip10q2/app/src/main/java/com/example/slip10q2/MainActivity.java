package com.example.slip10q2;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Context;
import android.content.Intent;
import android.os.Bundle;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Spinner;

import java.util.ArrayList;

public class MainActivity extends AppCompatActivity {

    EditText itemEditText;
    Button addToSpinnerBtn, removeFromSpinnerBtn;
    Spinner spinner;
    ArrayList<String> spinnerList;
    ArrayAdapter<String> spinnerAdapter;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        this.itemEditText = (EditText) findViewById(R.id.item_edit_text);
        this.addToSpinnerBtn = (Button) findViewById(R.id.add_to_spinner_btn);
        this.removeFromSpinnerBtn = (Button) findViewById(R.id.remove_from_spinner_btn);
        this.spinner = (Spinner) findViewById(R.id.spinner);

        this.spinnerList = new ArrayList<>();
//        ArrayAdapter<String> spinnerAdapter = new ArrayAdapter<>(this, android.R.layout.simple_list_item_1, spinnerList);
        this.spinnerAdapter = new ArrayAdapter<>(this, android.R.layout.simple_list_item_1, this.spinnerList);
        this.spinner.setAdapter(this.spinnerAdapter);

        this.addToSpinnerBtn.setOnClickListener(v -> {
            String item = this.itemEditText.getText().toString();
            if(!item.isEmpty()) addToSpinner(item);
            this.itemEditText.setText("");
        });

        this.removeFromSpinnerBtn.setOnClickListener(v -> {
            String item = this.itemEditText.getText().toString();
            if(!item.isEmpty()) removeFromSpinner(item);
            this.itemEditText.setText("");
        });
    }

    public void addToSpinner(String item) {
        this.spinnerAdapter.add(item);
//        this.spinner.
    }

    public void removeFromSpinner(String item) {
        this.spinnerAdapter.remove(item);
    }
}