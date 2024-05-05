// Create a Node.js file that opens the requested file and returns the content to the client If anything goes wrong, throw a 404 error 

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
                Enter filename: <input type="text" name="file" /><br />
                <input type="submit" value="Submit" />
            </form>
        </body>
        </html>`);
    });

    handler.post("/append", (req, res) => {
        parseBody(req, ({file}) => {
            if(!fs.existsSync(file)) {
                res.writeHead(404, {"Content-Type": "text/plain"});
                res.end("File not found!");
            } else {
                const content = fs.readFileSync(file);
                if(!content || content.length == 0) {
                    res.writeHead(404, {"Content-Type": "text/plain"});
                    res.end("No data found!");
                } else {
                    res.writeHead(200, {"Content-Type": "text/html"});
                    res.end(content);
                }
            }
        });
    });
});

server.listen(80, "localhost", _ => console.log("Server started!"));