// Write node js application that transfer a file as an attachment on web and enables browser to prompt the user to download file using express js.

const fs = require("fs");
const path = require("path");

const express = require("express");
const multer = require("multer");

const app = express();
// const upload = multer({dest: "uploads/"});
const storage = multer.diskStorage({ // Storage Engine to store on disk
    destination: "./uploads",
    filename: (req, file, cb) => { // specify the filename in callback
        cb(null, file.originalname); 
        // cb(null, "uploaded-file" + path.extname(file.originalname)); 
    }
});
const upload = multer({storage}).single("file");



app.get("/", (req, res) => {
    const homePage = `
    <!DOCTYPE html>
    <html lang="en">
    <head>
        <meta charset="UTF-8" />
        <meta name="viewport" content="width=device-width, initial-scale=1.0" />
        <title>HomePage</title>
    </head>
    <body>
        <form action="/send-attachment" enctype="multipart/form-data" method="POST">
            Upload Attachment: <input type="file" name="file"/> <br />
            <input type="submit" value="Upload" />
        </form>
    </body>
    </html>
    `;
    res.send(homePage);
});

// app.post("/send-attachment",  upload.single("file"), (req, res) => {
app.post("/send-attachment", (req, res) => {
    upload(req, res, err => {
        if(err) res.status(500).send(err);
        else {
            res.send(`<h1>Uploaded</h1><a href="/get-attachment/${req.file.originalname}"> Download</a>`);
        }
    });
});

app.get("/get-attachment/:filename", (req, res) => {
    res.download(`./uploads/${req.params.filename}`);
});


app.listen(80, _ => {
    console.log("Server started.");
});