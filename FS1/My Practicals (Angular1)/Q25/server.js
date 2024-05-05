// Using node js create a Recipe Book
const fs = require("fs");
const http = require("http");

class Router {
    constructor(req, res) {
        this.req = req;
        this.res = res;
    }

    get(url, cb) {
        if(this.req.url === url && this.req.method === "GET") {
            cb(this.req, this.res);
        }
    }

    post(url, cb) {
        if(this.req.url === url && this.req.method === "POST") {
            cb(this.req, this.res);
        }
    }
}

const server = http.createServer((req, res) => {
    const router = new Router(req, res);

    router.get("/", (req, res) => {
        res.statusCode = 200;
        const readStream = fs.createReadStream("./index.html");
        readStream.pipe(res);
    });

    router.get("/biryani", (req, res) => {
        fs.readFile("./resources/biryani.pdf", (err, data) => {
            if(err) throw err;
            else {
                res.writeHead(200, {"Content-Type": "application/pdf"});
                res.end(data);
            }
        });
    });

    router.get("/butter-chicken", (req, res) => {
        fs.readFile("./resources/butter-chicken.pdf", (err, data) => {
            if(err) throw err;
            else {
                res.writeHead(200, {"Content-Type": "application/pdf"});
                res.end(data);
            }
        });
    });
    
    router.get("/chicken-fried-rice", (req, res) => {
        fs.readFile("./resources/chicken-fried-rice.pdf", (err, data) => {
            if(err) throw err;
            else {
                res.writeHead(200, {"Content-Type": "application/pdf"});
                res.write(data);
                res.end();
            }
        });
    });
});


server.listen(80, "localhost", _ => {
    console.log("Server started!");
});