package com.example.q9;

import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.widget.Button;
import android.widget.TextView;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {
    /* Construct a bank app to display different menu like windrow, deposite etc. */

    TextView balanceTextView;
    int balance = 0;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        balanceTextView = (TextView) findViewById(R.id.balance_text_view);

        balanceTextView.setText("Current Balance: ₹" + balance);
    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        getMenuInflater().inflate(R.menu.main_menu, menu);
        return true;
    }

    @Override
    public boolean onOptionsItemSelected(@NonNull MenuItem item) {
        switch (item.getTitle().toString()) {
            case "Deposit":
                balance += 1000;
                balanceTextView.setText("Current Balance: ₹" + balance);
                return true;
            case "Withdraw":
                balance -= 500;
                balanceTextView.setText("Current Balance: ₹" + balance);
                return true;
            default:
                return super.onOptionsItemSelected(item);
        }
    }
}