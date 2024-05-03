package com.example.q13;

import android.content.ContentValues;
import android.content.Context;
import android.database.Cursor;
import android.database.SQLException;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteOpenHelper;

import java.util.ArrayList;

public class CustomerDB {
    public final String columns[] = {
            "_id", "customer_name", "customer_address", "customer_phone"
    };

    private final String DATABASE_NAME = "CustomerDB", DATABASE_TABLE = "customers_table";
    private final int DATABASE_VERSION = 1;

    private DBHelper helper;
    private Context context;
    private SQLiteDatabase database;

    CustomerDB(Context context) {
        this.context = context;
    }

    public void open() throws SQLException {
        helper = new DBHelper(this.context);
        database = helper.getWritableDatabase();
    }

    public void close() {
        helper.close();
    }

    public long insertCustomer(Customer customer) {
        ContentValues cv = new ContentValues();
        cv.put(columns[1], customer.getName());
        cv.put(columns[2], customer.getAddress());
        cv.put(columns[3], customer.getPhoneNumber());

        return database.insert(this.DATABASE_TABLE, null, cv);
    }

    public ArrayList<Customer> fetchAll() {
        ArrayList<Customer> result = new ArrayList<>();
        Cursor cursor = database.query(this.DATABASE_TABLE, this.columns, null, null, null, null, null);
        int columnIndexes[] = {cursor.getColumnIndex(this.columns[0]),
                cursor.getColumnIndex(this.columns[1]),
                cursor.getColumnIndex(this.columns[2]),
                cursor.getColumnIndex(this.columns[3])
        };

        for(cursor.moveToFirst(); !cursor.isAfterLast(); cursor.moveToNext()) {
            result.add(new Customer(cursor.getString(columnIndexes[0]),
                cursor.getString(columnIndexes[1]),
                cursor.getString(columnIndexes[2]),
                cursor.getString(columnIndexes[3])
            ));
        }

        return result;
    }

    private class DBHelper extends SQLiteOpenHelper {

        DBHelper(Context context) {
            super(context, DATABASE_NAME, null, DATABASE_VERSION);
        }

        @Override
        public void onCreate(SQLiteDatabase sqLiteDatabase) {
            String CREATE_TABLE_SQL = "CREATE TABLE " + DATABASE_TABLE + " (" +
                    columns[0] + " INTEGER PRIMARY KEY AUTOINCREMENT, " +
                    columns[1] + " TEXT NOT NULL, " +
                    columns[2] + " TEXT NOT NULL, " +
                    columns[3] + " TEXT NOT NULL);";

            sqLiteDatabase.execSQL(CREATE_TABLE_SQL);
        }

        @Override
        public void onUpgrade(SQLiteDatabase sqLiteDatabase, int i, int i1) {

        }
    }
}
