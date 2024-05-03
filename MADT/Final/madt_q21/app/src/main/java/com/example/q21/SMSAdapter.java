package com.example.q21;

import android.content.Context;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ArrayAdapter;
import android.widget.TextView;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;

import java.util.ArrayList;

public class SMSAdapter extends ArrayAdapter<SMS> {

    private final Context context;
    private final ArrayList<SMS> smses;

    public SMSAdapter(@NonNull Context context, ArrayList<SMS> smses) {
        super(context, R.layout.sms_list_row_layout, smses);
        this.context = context;
        this.smses = smses;
    }

    @NonNull
    @Override
    public View getView(int position, @Nullable View convertView, @NonNull ViewGroup parent) {
        LayoutInflater inflater = (LayoutInflater) this.context.getSystemService(Context.LAYOUT_INFLATER_SERVICE);
        View row = inflater.inflate(R.layout.sms_list_row_layout, parent, false);

        TextView nameTv, noTv, bodyTv;
        nameTv = row.findViewById(R.id.name);
        noTv = row.findViewById(R.id.no);
        bodyTv = row.findViewById(R.id.body);

        SMS currentSMS = this.smses.get(position);

        nameTv.setText(currentSMS.getName());
        noTv.setText(currentSMS.getNo());
        bodyTv.setText(currentSMS.getBody());

        return row;
    }
}
