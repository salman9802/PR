// Using node js create a eLearning System
const fs = require("fs");
const http = require("http");

const server = http.createServer((req, res) => {
    if(req.url === "/") {
        const r = fs.createReadStream("./index.html");
        res.writeHead(200, {"Content-Type": "text/html"});
        r.pipe(res);
    } else if(req.url === "/html") {
        fs.readFile("./materials/html.pdf", (err, data) => {
            if(err) throw err;
            else {
                res.writeHead(200, {"Content-Type": "application/pdf", "Content-Disposition": "inline"});
                res.write(data);
                res.end();
            }
        });
    } else if(req.url === "/python") {
        fs.readFile("./materials/python.pdf", (err, data) => {
            if(err) throw err;
            else {
                res.writeHead(200, {"Content-Type": "application/pdf", "Content-Disposition": "inline"});
                res.write(data);
                res.end();
            }
        });
    } else if(req.url === "/nodejs") {
        fs.readFile("./materials/nodejs.pdf", (err, data) => {
            if(err) throw err;
            else {
                res.writeHead(200, {"Content-Type": "application/pdf", "Content-Disposition": "inline"});
                res.write(data);
                res.end();
            }
        });
    }
});


server.listen(80, "localhost", _ => {
    console.log("Server started!");
});