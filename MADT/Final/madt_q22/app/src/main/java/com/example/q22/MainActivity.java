package com.example.q22;

import androidx.annotation.Nullable;
import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.net.Uri;
import android.os.Bundle;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {

    private static class REQUEST_CODES {
        static int FILE_CHOOSER = 1;
    }

    TextView attachmentTextView;
    EditText toEditText, subjectEditText, msgEditText;
    Button addAttachmentBtn, sendBtn;
    boolean isAttachmentPresent = false;
    Uri uri;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        this.toEditText = (EditText) findViewById(R.id.to_edit_text);
        this.subjectEditText = (EditText) findViewById(R.id.subject_edit_text);
        this.msgEditText = (EditText) findViewById(R.id.msg_edit_text);
        this.addAttachmentBtn = (Button) findViewById(R.id.add_attachment_btn);
        this.attachmentTextView = (TextView) findViewById(R.id.attachment_text_view);
        this.sendBtn = (Button) findViewById(R.id.sendt_btn);

        this.addAttachmentBtn.setOnClickListener(v -> {
            showFileChooser();
        });

        this.sendBtn.setOnClickListener(v -> {
            sendEmail();
        });
    }

    public void showFileChooser() {
//        Intent intent = new Intent(Intent.ACTION_OPEN_DOCUMENT);
        Intent intent = new Intent(Intent.ACTION_GET_CONTENT);
        intent.setType("*/*");
        startActivityForResult(intent, REQUEST_CODES.FILE_CHOOSER);
    }

    @Override
    protected void onActivityResult(int requestCode, int resultCode, @Nullable Intent data) {
        if(requestCode == REQUEST_CODES.FILE_CHOOSER && resultCode == RESULT_OK && data != null && data.getData() != null) {
            this.uri = data.getData();
            this.attachmentTextView.setText("Attachment found!");
            this.isAttachmentPresent = true;
        }
        super.onActivityResult(requestCode, resultCode, data);
    }

    public void sendEmail() {
        String to = this.toEditText.getText().toString();
        String subject = this.subjectEditText.getText().toString();
        String msg = this.msgEditText.getText().toString();

        if(to.isEmpty()) Toast.makeText(this, "'To' field cannot be blank", Toast.LENGTH_SHORT).show();
        if(subject.isEmpty()) Toast.makeText(this, "'Subject' field cannot be blank", Toast.LENGTH_SHORT).show();
        if(msg.isEmpty()) Toast.makeText(this, "'Message' field cannot be blank", Toast.LENGTH_SHORT).show();

        Intent intent = new Intent(Intent.ACTION_SEND);
        intent.putExtra(Intent.EXTRA_EMAIL, new String[] {to});
        intent.putExtra(Intent.EXTRA_SUBJECT, subject);
        intent.putExtra(Intent.EXTRA_TEXT, msg);
        intent.putExtra(Intent.EXTRA_STREAM, this.uri);

        intent.setType("*/*");

        startActivity(Intent.createChooser(intent, "Send Email"));
    }

}