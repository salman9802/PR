package com.example.q15;

import android.content.ContentValues;
import android.content.Context;
import android.database.Cursor;
import android.database.SQLException;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteOpenHelper;

import java.util.ArrayList;

public class EmployeeDB {

    final static public String DATABASE_NAME = "prac_q18_emps";
    final private String DATABASE_TABLE = "employees";
    final private int DATABASE_VERSION = 1;
    final private String columns[] = {
            "emp_no","emp_name","address","phone","salary"
    };

    private Context context;
    private SQLiteDatabase database;
    private DBHelper helper;

    EmployeeDB(Context context) {
        this.context = context;
    }

    public void open() {
        this.helper = new DBHelper(this.context);
        this.database = this.helper.getWritableDatabase();
    }

    public void close() {
        this.helper.close();
    }

    public long insertEmployee(Employee employee) throws SQLException {
        ContentValues cv = new ContentValues();
        cv.put(columns[0], employee.getEmp_no());
        cv.put(columns[1], employee.getEmp_name());
        cv.put(columns[2], employee.getAddress());
        cv.put(columns[3], employee.getPhone());
        cv.put(columns[4], employee.getSalary());

        return this.database.insert(DATABASE_TABLE, null, cv);
    }

    public ArrayList<Employee> fetchAll() {
        ArrayList<Employee> result = new ArrayList<>();
        Cursor cursor = database.query(this.DATABASE_TABLE, this.columns, null, null, null, null, null);
        int columnIndexes[] = {cursor.getColumnIndex(this.columns[0]),
                cursor.getColumnIndex(this.columns[1]),
                cursor.getColumnIndex(this.columns[2]),
                cursor.getColumnIndex(this.columns[3]),
                cursor.getColumnIndex(this.columns[4])
        };

        for(cursor.moveToFirst(); !cursor.isAfterLast(); cursor.moveToNext()) {
            result.add(new Employee(cursor.getString(columnIndexes[0]),
                    cursor.getString(columnIndexes[1]),
                    cursor.getString(columnIndexes[2]),
                    cursor.getString(columnIndexes[3]),
                    cursor.getString(columnIndexes[4])
            ));
        }

        return result;
    }

    public long deleteEmployee(String empNo) {
        return this.database.delete(DATABASE_TABLE, "emp_no=?", new String[] {empNo});
    }

    private class DBHelper extends SQLiteOpenHelper {
        DBHelper(Context context) {
            super(context, DATABASE_NAME, null, DATABASE_VERSION);
        }

        @Override
        public void onCreate(SQLiteDatabase sqLiteDatabase) {
            /*
            CREATE TABLE employees (
                emp_no INT PRIMARY KEY AUTOINCREMENT,
                emp_name TEXT NOT NULL,
                address TEXT NOT NULL,
                salary TEXT NOT NULL
            );
             */
            String CREATE_TABLE_SQL = "CREATE TABLE IF NOT EXISTS " + DATABASE_TABLE + " (\n" +
                    "                " + columns[0] + " INTEGER PRIMARY KEY AUTOINCREMENT,\n" +
                    "                " + columns[1] + " TEXT NOT NULL,\n" +
                    "                " + columns[2] + " TEXT NOT NULL,\n" +
                    "                " + columns[3] + " TEXT NOT NULL,\n" +
                    "                " + columns[4] + " TEXT NOT NULL\n" +
                    "            );";

            sqLiteDatabase.execSQL(CREATE_TABLE_SQL);
        }

        @Override
        public void onUpgrade(SQLiteDatabase sqLiteDatabase, int i, int i1) {

        }
    }
}
