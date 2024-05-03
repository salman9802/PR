package com.example.q15;

import android.content.ContentValues;
import android.content.Context;
import android.database.Cursor;
import android.database.SQLException;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteOpenHelper;

import java.util.ArrayList;

public class DepartmentDB {

    final static public String DATABASE_NAME = "prac_q18_dept";
    final private String DATABASE_TABLE = "departments";
    final private int DATABASE_VERSION = 1;
    final private String columns[] = {"dept_no","dept_name","location", "emp_no"};

    private Context context;
    private SQLiteDatabase database;
    private DBHelper helper;

    public DepartmentDB(Context context) {
        this.context = context;
    }

    public void open() {
        this.helper = new DBHelper(this.context);
        this.database = this.helper.getWritableDatabase();
    }

    public void close() {
        this.helper.close();
    }

    public long insertDepartment(Department department) throws SQLException {
        ContentValues cv = new ContentValues();
        cv.put(columns[1], department.getDept_name());
        cv.put(columns[2], department.getLocation());
        cv.put(columns[3], department.getEmp_no());

        return this.database.insert(DATABASE_TABLE, null, cv);
    }

    public ArrayList<Department> fetchAll() {
        ArrayList<Department> result = new ArrayList<>();
        Cursor cursor = database.query(this.DATABASE_TABLE, this.columns, null, null, null, null, null);
        int columnIndexes[] = {cursor.getColumnIndex(this.columns[0]),
                cursor.getColumnIndex(this.columns[1]),
                cursor.getColumnIndex(this.columns[2]),
                cursor.getColumnIndex(this.columns[3])
        };

        for(cursor.moveToFirst(); !cursor.isAfterLast(); cursor.moveToNext()) {
            result.add(new Department(cursor.getString(columnIndexes[0]),
                    cursor.getString(columnIndexes[1]),
                    cursor.getString(columnIndexes[2]),
                    cursor.getString(columnIndexes[3])
            ));
        }

        return result;
    }

    public String fetchEmpNo(String depName) {
        String whereClause = "dept_name=?";
        String whereArgs[] = { depName };
        Cursor cursor = this.database.query(DATABASE_TABLE, columns, whereClause, whereArgs, null, null, null);

        if(cursor.getCount() == 0 ) return null;
        else {
            cursor.moveToNext();
            int colIndex = cursor.getColumnIndex(columns[3]);
            String empNo = cursor.getString(colIndex);
            cursor.close();
            return empNo;
        }
    }

    private class DBHelper extends SQLiteOpenHelper {
        DBHelper(Context context) {
            super(context, DATABASE_NAME, null, DATABASE_VERSION);
        }

        @Override
        public void onCreate(SQLiteDatabase sqLiteDatabase) {
            /* CREATE TABLE departments (
                    dept_no INT PRIMARY KEY AUTOINCREMENT,
                    dept_name TEXT NOT NULL,
                    location TEXT NOT NULL,
                    emp_no INT,
                    FOREIGN KEY(emp_no) REFERENCES employees(emp_no)
                ); */
            String CREATE_TABLE_SQL = "CREATE TABLE IF NOT EXISTS " + DATABASE_TABLE + " (\n" +
                    "                    " + columns[0] + " INTEGER PRIMARY KEY AUTOINCREMENT,\n" +
                    "                    " + columns[1] + " TEXT NOT NULL,\n" +
                    "                    " + columns[2] + " TEXT NOT NULL,\n" +
                    "                    " + columns[3] + " INT,\n" +
                    "                    FOREIGN KEY(" + columns[3] + ") REFERENCES employees(emp_no)\n" +
                    "                );";

            sqLiteDatabase.execSQL(CREATE_TABLE_SQL);
        }

        @Override
        public void onUpgrade(SQLiteDatabase sqLiteDatabase, int i, int i1) {

        }
    }
}
