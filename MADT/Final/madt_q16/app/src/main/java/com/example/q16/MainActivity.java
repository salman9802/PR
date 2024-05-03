package com.example.q16;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {
    /* Java Android Program to Perform all arithmetic Operations using Calculators */
    int n1, n2, result;
    String op = null;

    TextView input, output;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        this.input = (TextView) findViewById(R.id.input);
        this.output = (TextView) findViewById(R.id.output);
    }

    public void onClearButtonClicked(View v) {
        this.input.setText("");
        this.output.setText("");
        this.input.setHint("Input");
        this.output.setHint("Output");
        this.n1 = 0;
        this.n2 = 0;
        this.result = 0;
        this.op = null;
    }

    public void onDeleteButtonClicked(View v) {
        if(this.input.getText().toString().length() > 0) {
            this.input.setText(this.input.getText().toString().substring(0, this.input.getText().toString().length() - 1));
        }
    }

    public void onOperatorButtonClicked(View v) {
        Button btn = (Button) v;
        this.n1 = Integer.parseInt(this.input.getText().toString());
        this.input.setHint(input.getText().toString());
        this.input.setText("");
        this.op = btn.getText().toString();

    }

    public void onNumericButtonClick(View v) {
        Button btn = (Button) v;
        this.input.append(btn.getText());
    }

    public void onEqualButtonClick(View v) {
        Button btn = (Button) v;
        if(!this.output.getText().toString().isEmpty()) {
            this.input.setText(this.output.getText());
            this.output.setText("");
        } else {
            this.n2 = Integer.parseInt(this.input.getText().toString());
            switch (this.op) {
                case "+":
                    result = n1 + n2;
                    break;
                case "-":
                    result = n1 - n2;
                    break;
                case "*":
                    result = n1 * n2;
                    break;
                case "/":
                    result = n1 / n2;
                    break;
                case "%":
                    result = n1 % n2;
                    break;
            }
            this.output.setText(String.valueOf(this.result));
        }
    }
}