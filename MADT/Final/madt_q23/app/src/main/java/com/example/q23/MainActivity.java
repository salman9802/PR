package com.example.q23;

import androidx.appcompat.app.AppCompatActivity;

import android.graphics.Color;
import android.graphics.Paint;
import android.graphics.Typeface;
import android.os.Bundle;
import android.widget.Button;
import android.widget.CheckBox;
import android.widget.EditText;
import android.widget.RadioButton;
import android.widget.RadioGroup;
import android.widget.TextView;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {
    /* Create an Android application which will ask the user to input his name and a
    message, display the two items concatenated in a label, and change the format of the
    label using radio buttons and check boxes for selection, the user can make the label
    text bold, underlined or italic and change its color .include buttons to display the
    message in the label, clear the text boxes and label and then exit. */
    EditText nameEditText, messageEditText;
    TextView resultTextView;
    RadioGroup radioGroup; // for colors
    RadioButton redRadioButton, greenRadioButton, blueRadioButton;
    CheckBox underlineCheckBox, boldCheckBox, italicCheckBox;
    Button displayMessageBtn, clearBtn;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        this.initViews();

        this.displayMessageBtn.setOnClickListener(v -> {
            String name = this.nameEditText.getText().toString(),
                    message = this.messageEditText.getText().toString();
            if(name.isEmpty() || message.isEmpty())
                Toast.makeText(this, "Please enter name and message!", Toast.LENGTH_SHORT).show();
            else {
                this.resultTextView.setText(name + " " + message);

                if(underlineCheckBox.isChecked())
                    this.resultTextView.setPaintFlags(this.resultTextView.getPaintFlags() | Paint.UNDERLINE_TEXT_FLAG);
                else
                    this.resultTextView.setPaintFlags(this.resultTextView.getPaintFlags() & (~Paint.UNDERLINE_TEXT_FLAG));

                if(boldCheckBox.isChecked() && italicCheckBox.isChecked())
                    this.resultTextView.setTypeface(null, Typeface.BOLD_ITALIC);
                else if(boldCheckBox.isChecked())
                    this.resultTextView.setTypeface(null, Typeface.BOLD);
                else if(italicCheckBox.isChecked())
                    this.resultTextView.setTypeface(null, Typeface.ITALIC);
                else
                    this.resultTextView.setTypeface(null, Typeface.NORMAL);

                int checkRadioButtonId = this.radioGroup.getCheckedRadioButtonId();
                if (checkRadioButtonId == this.redRadioButton.getId())
                    this.resultTextView.setTextColor(Color.RED);
                else if(checkRadioButtonId == this.greenRadioButton.getId())
                    this.resultTextView.setTextColor(Color.GREEN);
                else if(checkRadioButtonId == this.blueRadioButton.getId())
                    this.resultTextView.setTextColor(Color.BLUE);
            }
        });

        this.clearBtn.setOnClickListener(v -> {
            this.nameEditText.setText("");
            this.messageEditText.setText("");
            this.resultTextView.setText("");
            this.resultTextView.setPaintFlags(this.resultTextView.getPaintFlags() & (~Paint.UNDERLINE_TEXT_FLAG));
        });
    }

    public void initViews() {
        this.nameEditText = (EditText) findViewById(R.id.name_edit_text);
        this.messageEditText = (EditText) findViewById(R.id.message_edit_text);
        this.resultTextView = (TextView) findViewById(R.id.result_text_view);
        this.radioGroup = (RadioGroup) findViewById(R.id.radio_group);
        this.boldCheckBox = (CheckBox) findViewById(R.id.bold_check_box);
        this.italicCheckBox = (CheckBox) findViewById(R.id.italic_check_box);
        this.underlineCheckBox = (CheckBox) findViewById(R.id.underline_check_box);
        this.redRadioButton = (RadioButton) findViewById(R.id.red_radio_btn);
        this.greenRadioButton = (RadioButton) findViewById(R.id.green_radio_btn);
        this.blueRadioButton = (RadioButton) findViewById(R.id.blue_radio_btn);
        this.displayMessageBtn = (Button) findViewById(R.id.display_msg_btn);
        this.clearBtn = (Button) findViewById(R.id.clear_btn);
    }
}