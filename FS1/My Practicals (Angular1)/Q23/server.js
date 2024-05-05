// Using node js create a User Login System
const http = require("http");
const qs = require("querystring");

const users = [
    {username: "John", password: "123456"},
    {username: "Mary", password: "abcdef"}
];

function parseReqBody(req, cb) {
    let body = "";
    req.on("data", data => body += data);
    req.on("end", d => cb(qs.parse(body)));
}

const server = http.createServer((req, res) => {
    switch (req.url) {
        case "/":
            res.statusCode = 200;
            res.setHeader("Content-Type", "text/html");
            res.write(`<!DOCTYPE html>
            <html lang="en">
            <head>
                <meta charset="UTF-8" />
                <meta name="viewport" content="width=device-width, initial-scale=1.0" />
                <title>Homepage</title>
            </head>
            <body>
                <h1>User Login System</h1>
                <a href="/login">Login</a>
            </body>
            </html>`);
            res.end();
            break;
    
        case "/login":
            if(req.method === "GET") {
                res.statusCode = 200;
                res.setHeader("Content-Type", "text/html");
                res.write(`
                <form action="/login" method="post">
                Enter username: <input type="text" name="username"/> <br />
                Enter password: <input type="text" name="password"/> <br />
                <input type="submit" value="Login" />
                </form>
                `);
                res.end();
            } else {
                parseReqBody(req, data => {
                    const {username, password} = data;
                    const userIndex = users.findIndex(user => user.username === username && user.password === password);
                    if(userIndex === -1) {
                        res.statusCode = 404;
                        res.end("User not found");
                    } else {
                        res.statusCode = 200;
                        res.setHeader("Content-Type", "text/html");
                        res.end("<h1>Login Successful!</h1>");
                    }
                });
            }
            break;
        default:
            break;
    }
});

server.listen(80, "localhost", _ => {
    console.log("Server started!");
});