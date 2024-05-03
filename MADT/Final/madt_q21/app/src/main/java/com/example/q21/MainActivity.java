package com.example.q21;

import androidx.appcompat.app.AppCompatActivity;
import androidx.core.app.ActivityCompat;

import android.Manifest;
import android.content.pm.PackageManager;
import android.database.Cursor;
import android.net.Uri;
import android.os.Bundle;
import android.widget.ListView;

import java.util.ArrayList;

public class MainActivity extends AppCompatActivity {
    /* Java Android Program to Display SMS from the Phone Numbers, which are in Your Contacts */

    ListView smsListView;

    public void requestPermissions() {
        if(ActivityCompat.checkSelfPermission(this, Manifest.permission.READ_SMS) == PackageManager.PERMISSION_DENIED)
            ActivityCompat.requestPermissions(this, new String[] {Manifest.permission.READ_SMS}, PackageManager.PERMISSION_GRANTED);
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        this.smsListView = (ListView) findViewById(R.id.sms_list_view);

        this.requestPermissions(); // Request READ_SMS permission

        if (android.os.Build.VERSION.SDK_INT >= android.os.Build.VERSION_CODES.O) { // ContentResolver.query() supported only API 26
            /* private Set<String> getContactNumbers() {
                    Set<String> numbers = new HashSet<>();
                    Cursor cursor = getContentResolver().query(ContactsContract.CommonDataKinds.Phone.CONTENT_URI,
                            null, null, null, null);
                    if (cursor != null) {
                        while (cursor.moveToNext()) {
                            String number = cursor.getString(cursor.getColumnIndex(ContactsContract.CommonDataKinds.Phone.NUMBER));
                            numbers.add(number);
                        }
                        cursor.close();
                    }
                    return numbers;
                } */
            Cursor cursor = getContentResolver().query(Uri.parse("content://sms/inbox"), null, null, null);

            ArrayList<SMS> smses = new ArrayList<>();
            if (cursor.moveToFirst()) {
                for (cursor.moveToFirst(); !cursor.isAfterLast(); cursor.moveToNext()) {

                    int addressIndex = cursor.getColumnIndex("address"); // No. & Name
                    int bodyIndex = cursor.getColumnIndex("body"); // Body

                    SMS sms = new SMS();
                    if (addressIndex != -1) sms.setNo(cursor.getString(addressIndex));
                    if (addressIndex != -1) sms.setName(cursor.getString(addressIndex));
                    if (bodyIndex != -1) sms.setBody(cursor.getString(bodyIndex));

                    smses.add(sms);
                }
                cursor.close();
            }

            SMSAdapter adapter = new SMSAdapter(this, smses);

            this.smsListView.setAdapter(adapter);
        }
    }
}