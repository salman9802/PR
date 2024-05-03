package com.example.q20;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.text.Editable;
import android.text.TextWatcher;
import android.util.Log;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.EditText;
import android.widget.ListView;
import android.widget.Toast;

import java.util.ArrayList;

public class MainActivity extends AppCompatActivity {
    /* Java Android Program to Demonstrate List View Activity with all operations (Insert,
delete, Search). */

    EditText editText;
    Button addBtn;
    ListView listView;
    ArrayAdapter<String> adapter;
    ArrayList<String> list;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        this.editText = (EditText) findViewById(R.id.edit_text);
        this.addBtn = (Button) findViewById(R.id.add_btn);
        this.listView = (ListView) findViewById(R.id.list_view);

        this.list = new ArrayList<>();
//        this.list.add("Dummy Text #1");
//        this.list.add("Dummy Text #2");
        this.adapter = new ArrayAdapter<>(this, android.R.layout.simple_list_item_1, this.list);

        this.listView.setAdapter(this.adapter);

        // Insert functionality
        this.addBtn.setOnClickListener(v -> {
            String item = this.editText.getText().toString();
            if(item.isEmpty()) Toast.makeText(this, "Text cannot be empty!", Toast.LENGTH_SHORT).show();
            else {
//                Toast.makeText(this, item, Toast.LENGTH_SHORT).show();
                this.adapter.insert(item, 0);
//                this.adapter.notifyDataSetChanged();
//                runOnUiThread(() -> {
                    this.adapter.notifyDataSetChanged();
//                });
                this.editText.setText("");
                Toast.makeText(this, "Text added!", Toast.LENGTH_SHORT).show();
//                Toast.makeText(this, String.valueOf(this.adapter.getCount()), Toast.LENGTH_SHORT).show();
            }
        });

        // Search functionality on edit text
        this.editText.addTextChangedListener(new TextWatcher() {
            @Override
            public void beforeTextChanged(CharSequence charSequence, int i, int i1, int i2) {}
            @Override
            public void onTextChanged(CharSequence s, int i, int i1, int i2) {
                adapter.getFilter().filter(s);
            }
            @Override
            public void afterTextChanged(Editable editable) {}
        });

        // Delete functionality
        this.listView.setOnItemLongClickListener((parent, view, i, l) -> {
//            Toast.makeText(this, i, Toast.LENGTH_SHORT).show();
            if(i >= 0 && i < list.size()) {
                this.adapter.remove(this.list.get(i));
//                runOnUiThread(() -> {
                    this.adapter.notifyDataSetChanged();
//                });
                this.listView.setAdapter(this.adapter);
                Toast.makeText(this, "Item deleted!", Toast.LENGTH_SHORT).show();
//            Toast.makeText(this, String.valueOf(this.adapter.getCount()), Toast.LENGTH_SHORT).show();
            }
            return true;
        });
    }
}