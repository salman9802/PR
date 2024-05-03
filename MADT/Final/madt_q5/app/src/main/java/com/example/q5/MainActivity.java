package com.example.q5;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.ImageView;
import android.widget.Spinner;

import java.util.ArrayList;
import java.util.List;

public class MainActivity extends AppCompatActivity {
/* By using Spinner, Buttons. Write a program to draw GUI. */

    Spinner spinner;
    Button show;
    ArrayList<String> shapes = new ArrayList<>();
    ImageView recImg, cirImg;
    String currentSelection = null;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        spinner = (Spinner) findViewById(R.id.spinner);
        show = (Button) findViewById(R.id.show_btn);
        recImg = (ImageView) findViewById(R.id.rectangle_img);
        cirImg = (ImageView) findViewById(R.id.circle_img);

        shapes.add("Circle");
        shapes.add("Rectangle");
        ArrayAdapter<String> adapter = new ArrayAdapter<>(this, android.R.layout.simple_spinner_item, shapes);

        spinner.setAdapter(adapter);

        spinner.setOnItemSelectedListener(new AdapterView.OnItemSelectedListener() {
            @Override
            public void onItemSelected(AdapterView<?> adapterView, View view, int i, long l) {
                if(shapes.get(i).equals("Circle")) {
                    currentSelection = "Circle";
                } else {
                    currentSelection = "Rectangle";
                }
            }
            @Override
            public void onNothingSelected(AdapterView<?> adapterView) { }
        });

        show.setOnClickListener(v -> {
            if(currentSelection.equals("Circle")) {
                recImg.setVisibility(View.INVISIBLE);
                cirImg.setVisibility(View.VISIBLE);
            } else {
                recImg.setVisibility(View.VISIBLE);
                cirImg.setVisibility(View.INVISIBLE);
            }
        });
    }
}