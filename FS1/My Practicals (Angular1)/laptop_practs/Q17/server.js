// Create a Node.js file that writes an HTML form, with an upload field 
const fs = require("fs");
const http = require("http");
const path = require("path");

const formidable = require("formidable"); // npm install formidable

http.createServer((req, res) => {
    if(req.method === "POST") { // upload endpoint
        const form = new formidable.IncomingForm();
        form.parse(req, (err, fields, files) => {
            // console.log(err, fields, files);
            
            const oldPath = files.file[0].filepath;
            const newPath = path.join(__dirname, files.file[0].originalFilename);
            console.log(oldPath, newPath);

            fs.copyFile(oldPath, newPath, err => {
                if(err) throw err;
                else {
                    res.write("File Copied");
                }
            })

            
            fs.unlink(oldPath, err => {
                if(err) throw err;
                else {
                    res.write("File Removed");
                }
            });
            res.write("Upload Success");
            res.end();

            // Not working because of different drives
            /* fs.rename(oldPath, newPath, err => {
                if(err) throw err;
                else {
                    res.write("File uploaded and moved");
                }
            }); */
        });
    } else { // form endpoint
        res.setHeader("Content-Type", "text/html");
        res.write(`
            <!DOCTYPE html>
            <html lang="en">
            <head>
                <meta charset="UTF-8" />
                <meta name="viewport" content="width=device-width, initial-scale=1.0" />
                <title>File Upload</title>
            </head>
            <body>
                <form action="/" method="post" enctype="multipart/form-data">
                <input type="file" name="file" id="file" text="Upload File" />

                <input type="submit" value="Submit" />
                </form>
            </body>
            </html>
        `);
        res.end();
    }
}).listen(80);
