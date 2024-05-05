// Using nodejs create a web page to read two file names from user and append contents of first file into second file 

class Handler {
    constructor(req, res) {
        this.req = req;
        this.res = res;
    }

    get(url, cb) {
        if(this.req.url === url && this.req.method == "GET") cb(this.req, this.res);
    }

    post(url, cb) {
        if(this.req.url === url && this.req.method == "POST") cb(this.req, this.res);
    }
}

const qs = require("querystring");

function parseBody(req, cb) {
    let body = "";
    req.on("data", chunk => body += chunk);
    req.on("end", _ => cb(qs.parse(body)));
}

const http = require("http");
const fs = require("fs");

const server = http.createServer((req, res) => {
    const handler = new Handler(req, res);

    handler.get("/", (req, res) => {
        res.writeHead(200, {"Content-Type": "text/html"});
        res.end(`<!DOCTYPE html>
        <html lang="en">
        <head>
            <meta charset="UTF-8" />
            <meta name="viewport" content="width=device-width, initial-scale=1.0" />
            <title>Form</title>
        </head>
        <body>
            <form action="/append" method="POST">
                Enter first filename: <input type="text" name="file1" /><br />
                Enter second filename: <input type="text" name="file2" /><br />
                <input type="submit" value="Submit" />
            </form>
        </body>
        </html>`);
    });

    handler.post("/append", (req, res) => {
        parseBody(req, ({file1, file2}) => {
            if(!fs.existsSync(file1) || !fs.existsSync(file2)) {
                res.writeHead(200, {"Content-Type": "text/html"});
                res.end("Please enter valid filename(s)");
            } else {
                const content = fs.readFileSync(file1);
                fs.appendFileSync(file2, content);
                res.writeHead(200, {"Content-Type": "text/html"});
                res.end("Content of file1 appended in file2!");
            }
        });
    });
});

server.listen(80, "localhost", _ => console.log("Server started!"));