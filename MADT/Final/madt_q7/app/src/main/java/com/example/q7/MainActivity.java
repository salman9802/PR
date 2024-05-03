package com.example.q7;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.widget.DatePicker;
import android.widget.ImageView;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {
    /* Construct an app to display the image on date wise.  */

    ImageView imageView;
    DatePicker datePicker;
    TextView dateTextView;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        imageView = (ImageView) findViewById(R.id.image_view);
        datePicker = (DatePicker) findViewById(R.id.date_picker);
        dateTextView = (TextView) findViewById(R.id.date_text_view);

        datePicker.init(datePicker.getYear(), datePicker.getMonth(), datePicker.getDayOfMonth(), (v, y, m, d) -> {
            updateImage(y, m, d);
        });
    }

    public void updateImage(int year, int month, int day) {
        String selectedDate = String.format("%02d_%02d_%d", day, month+1, year);
        dateTextView.setText("Selected Date: " + selectedDate);
        int resourceId = getResources().getIdentifier("date_" + selectedDate + "_foreground", "drawable", getPackageName());
        if(resourceId!=0) imageView.setImageResource(resourceId);
        else {
            dateTextView.setText("No Image with this date");
            imageView.setImageResource(R.drawable.ic_launcher_background);
        }
    }
}