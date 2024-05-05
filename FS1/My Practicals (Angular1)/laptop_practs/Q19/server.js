// Create a node.js file that Select all records from the "customers" table, and display the result object on console

const mysql = require("mysql")

const conn = mysql.createConnection({
    host: "localhost",
    user: "root",
    password: "",
});

conn.query(`
    CREATE TABLE IF NOT EXISTS TEST_DB_NODEJS.customers (
        id INT PRIMARY KEY AUTO_INCREMENT,
        first_name VARCHAR(50),
        last_name VARCHAR(50),
        age SMALLINT
    )
`.replace(/(\r\n|\n|\r)/gm, "").replace(/\s+/g," ").trim());

/* 
conn.query(`
        INSERT INTO TEST_DB_NODEJS.customers(first_name, last_name, age) VALUES
        ("John", "Doe", 25),
        ("Josh", "Smith", 22),
        ("Mary", "Jane", 15)
`.replace(/(\r\n|\n|\r)/gm, "").replace(/\s+/g," ").trim());
 */

conn.query(`
    SELECT * FROM TEST_DB_NODEJS.customers
`.replace(/(\r\n|\n|\r)/gm, "").replace(/\s+/g," ").trim(), (err, results, fields) => {
    if(err) {
        console.error(err);
        console.error(err.stack);
    } else {
        console.log(results);
        /* for(const [ _, {id, first_name, last_name, age} ] of Object.entries(results)) {
            console.log(`Customer[id=${id}, first_name=${first_name}, last_name=${last_name}, age=${age}]`);
        } */
    }
});