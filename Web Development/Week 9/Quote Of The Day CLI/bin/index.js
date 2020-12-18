#!/usr/bin/env node

// The first line that begins with #! is usually called a “shebang.” This is normally only used on Linux or UNIX operating systems 
// to inform the system what type of script is included in the rest of the text file. However, this first line is also required for 
// Node.js scripts to be installed and run properly on macOS and Windows.

//ref for http.request() - https://nodejs.dev/learn/making-http-requests-with-nodejs
const https = require('https');

let options = {
    host: "quotes.rest",
    path: "/qod",
    method: "GET",
    headers: {  'Accept': 'application/json', }
}

/*  Your Understanding  -
    To understand what the http.request() function does you need to understand the http.ClientRequest class as given in doc -
                1. This object is created internally and returned when http.request() is called. It represents an in-progress request whose header has already been queued (but not sent).
                2. Becasue The header are not actually sent, they are still mutable using the setHeader(name, value), getHeader(name), removeHeader(name) API. 
                3. The actual header will be sent along with the first data chunk (i.e. when calling request.write()) or when calling request.end().
                4. To get the response, add a listener for 'response' to the request object (apart from manually adding it using.on(), this can also be done by 
                   passing the listener/callback as an arg when calling http.request()). 'response' will be emitted from the request object
                   when the response headers have been received. The 'response' event listener/allback is executed with one argument which is an instance of http.IncomingMessage.

                   Extra - If no 'response' handler is added, then the response will be entirely discarded. However, if a 'response' event handler is added, then the data from the response object must be consumed, either by calling response.read() whenever there is a 'readable' event, or by adding a 'data' handler, or by calling the .resume() method. Until the data is consumed, the 'end' event will not fire. Also, until the data is read it will consume memory that can eventually lead to a 'process out of memory' error.
    
    Now let's understand http.request. The request() function takes 2 param -
        a. The request url info (in terms of options object. It can also be a url object)
        b. The callback, which will be added as a one-time listener for the 'response' event (as described above).
            i. This callack takes an IncomingMessage object (which is nothing but a readable stream object as it is extended from Stream.Readable) as argument
               for allowing us to read the response status, headers and data.
               Now, in your code, you have read the chunk in one go using res.on("data"). Because the quote is a small data, 99% of the time it will transferrd in a single chunk/stream
               but it can happen that the data gets send in multiple chunks, in which case only a part of quote will be displyed.
               So to be sure, you should call the method in this way -  https://nodejs.org/api/http.html#http_http_request_options_callback (look at the code in the section. It writes data only when res.on("end") listner is called. This makes sure we write only when the whole data is transferred)

            Note - also notice that we have used process.stdout.write() to print the chunk not console.log() becuase console.log() prints some odd output (maybe the buffer value).
            Search the reason for it here. One doc you can look at - https://stackoverflow.com/questions/4976466/difference-between-process-stdout-write-and-console-log-in-node-js
            This link (https://nodejs.org/api/process.html#process_process_stdout) can also help a little. According to this -
                                    
                                        The process.stdout property returns a stream connected to stdout

            so using write() on it writes to the stream. And as the data itself is a stream obj using stream method to write the data to the console is more compatible.

    NOTE - to make a POST request we mention the method as POST in the options obj. And the data is sent in the following way -
                                        code in this section - https://nodejs.org/api/http.html#http_http_request_options_callback
            http.request() returns an instance of the http.ClientRequest class. The ClientRequest instance is a writable stream. That is why we can 
            use write() to add data to the request and it will be sent as soon as we call the write function().
*/ 

//creates ClientRequest obeject and stores it in the 'req' var. Remeber the request is not sent at the moment. It's headers are queued
let req = https.request(options, (res) => {//this is the callback which will define th esteps to be taken when we receive a response from the server
    res.on("data", (chunk) => {//res is a stream object so we have to read data in stream fashion i.e. using res.on("data")
        // process.stdout.write(chunk);
        let res_obj = JSON.parse(chunk);
        if(res_obj.contents != undefined)
            console.log(res_obj.contents.quotes[0].quote); 
        else if(res_obj.error != undefined)
            console.log(res_obj.error.message); 
    })
});

req.on("error", () => {
    console.log("The request could not be processed. Check your internet Connection");
});

req.end();/*This is necessary. The call to request() does not actually send the request as ponited out by the docs (given in 3rd point of above explantion about http.ClientRequest)
*/