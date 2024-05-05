// Create a node.js file that Insert Multiple Records in "student" table, and display the result object on console

const mysql = require("mysql");

const conn = mysql.createConnection({
    host: "localhost",
    user: "root",
    password: "",
    database: "test"
});

conn.query("CREATE TABLE IF NOT EXISTS student( \
id INT PRIMARY KEY AUTO_INCREMENT,\
name VARCHAR(255)\
)", (err, results, _) => {
    if(err) throw err;
    else {
        console.log(results);
    }
});

conn.query("INSERT INTO student (name) VALUES \
(\"John\"),\
(\"Jack\"),\
(\"Jill\")");

conn.query("SELECT * FROM student", (err, results, fields) => {
    if(err) throw err;
    else console.log(results);
})