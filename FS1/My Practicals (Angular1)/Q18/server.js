// Create a Node.js file that demonstrate create database and table in MySQL

const mysql = require("mysql");

const conn = mysql.createConnection({
    host: "localhost",
    user: "root",
    password: ""
});

conn.connect(err => {
    if(err) {
        console.error(err);
        console.error(err.stack);
        return;
    }

    console.log("Connected");
});

conn.query("CREATE DATABASE IF NOT EXISTS TEST_DB_NODEJS", (err, results, fields) => {
    if(err) throw err;
    else {
        console.log(results);
        console.log(fields);
    }
});

conn.query(`CREATE TABLE IF NOT EXISTS 
    TEST_DB_NODEJS.users (
        id INT PRIMARY KEY AUTO_INCREMENT,
        name TEXT
    )
`.replace(/(\r\n|\n|\r)/gm, "").replace(/\s+/g," ").trim());
