const EventEmitter = require('events');
const fs = require("fs");
const moment = require('moment');
const readline = require("readline");
const {Readable} = require("stream");

const file_name = moment().format("YYYY_MM_DD_h_mm_ss");
const content = "Hello World!!!!!!!!!!!!!!!! Lorem ipsum dolor sit amet, consectetur adipiscing elit. Quisque nisl eros, pulvinar facilisis justo mollis, auctor consequat urna. Morbi a bibendum metus. Donec scelerisque sollicitudin enim eu venenatis. Duis tincidunt laoreet ex, in pretium orci vestibulum eget. Class aptent taciti sociosqu ad litora torquentper conubia nostra, per inceptos himenaeos. Duis pharetra luctus lacus ut vestibulum. Maecenas ipsum lacus, lacinia quis posuere ut, pulvinar vitae dolor.Integer eu nibh at nisi ullamcorper sagittis id vel leo. Integer feugiat faucibus libero, at maximus nisl suscipit posuere. Morbi nec enim nunc. Phasellus bibendum turpis ut ipsum egestas, sed sollicitudin elit convallis. Cras pharetra mi tristique sapien vestibulum lobortis. Nam eget bibendum metus,non dictum mauris. Nulla at tellus sagittis, viverra est a, bibendum metus. \n Lorem ipsum dolor sit amet, consectetur adipiscing elit. Quisque nisl eros, pulvinar facilisis justo mollis, auctor consequat urna. Morbi a bibendum metus. Donec scelerisque sollicitudin enim eu venenatis. Duis tincidunt laoreet ex, in pretium orci vestibulum eget. Class aptent taciti sociosqu ad litora torquentper conubia nostra, per inceptos himenaeos. Duis pharetra luctus lacus ut vestibulum. Maecenas ipsum lacus, lacinia quis posuere ut, pulvinar vitae dolor.Integer eu nibh at nisi ullamcorper sagittis id vel leo. Integer feugiat faucibus libero, at maximus nisl suscipit posuere. Morbi nec enim nunc. Phasellus bibendum turpis ut ipsum egestas, sed sollicitudin elit convallis. Cras pharetra mi tristique sapien vestibulum lobortis. Nam eget bibendum metus,non dictum mauris. Nulla at tellus sagittis, viverra est a, bibendum metus. \n Lorem ipsum dolor sit amet, consectetur adipiscing elit. Quisque nisl eros, pulvinar facilisis justo mollis, auctor consequat urna. Morbi a bibendum metus. Donec scelerisque sollicitudin enim eu venenatis. Duis tincidunt laoreet ex, in pretium orci vestibulum eget. Class aptent taciti sociosqu ad litora torquentper conubia nostra, per inceptos himenaeos. Duis pharetra luctus lacus ut vestibulum. Maecenas ipsum lacus, lacinia quis posuere ut, pulvinar vitae dolor.Integer eu nibh at nisi ullamcorper sagittis id vel leo. Integer feugiat faucibus libero, at maximus nisl suscipit posuere. Morbi nec enim nunc. Phasellus bibendum turpis ut ipsum egestas, sed sollicitudin elit convallis. Cras pharetra mi tristique sapien vestibulum lobortis. Nam eget bibendum metus,non dictum mauris. Nulla at tellus sagittis, viverra est a, bibendum metus.Lorem ipsum dolor sit amet, consectetur adipiscing elit. Quisque nisl eros, pulvinar facilisis justo mollis, auctor consequat urna. Morbi a bibendum metus. Donec scelerisque sollicitudin enim eu venenatis. Duis tincidunt laoreet ex, in pretium orci vestibulum eget. Class aptent taciti sociosqu ad litora torquentper conubia nostra, per inceptos himenaeos. Duis pharetra luctus lacus ut vestibulum. Maecenas ipsum lacus, lacinia quis posuere ut, pulvinar vitae dolor.Integer eu nibh at nisi ullamcorper sagittis id vel leo. Integer feugiat faucibus libero, at maximus nisl suscipit posuere. Morbi nec enim nunc. Phasellus bibendum turpis ut ipsum egestas, sed sollicitudin elit convallis. Cras pharetra mi tristique sapien vestibulum lobortis. Nam eget bibendum metus,non dictum mauris. Nulla at tellus sagittis, viverra est a, bibendum metus. \n Lorem ipsum dolor sit amet, consectetur adipiscing elit. Quisque nisl eros, pulvinar facilisis justo mollis, auctor consequat urna. Morbi a bibendum metus. Donec scelerisque sollicitudin enim eu venenatis. Duis tincidunt laoreet ex, in pretium orci vestibulum eget. Class aptent taciti sociosqu ad litora torquentper conubia nostra, per inceptos himenaeos. Duis pharetra luctus lacus ut vestibulum. Maecenas ipsum lacus, lacinia quis posuere ut, pulvinar vitae dolor.Integer eu nibh at nisi ullamcorper sagittis id vel leo. Integer feugiat faucibus libero, at maximus nisl suscipit posuere. Morbi nec enim nunc. Phasellus bibendum turpis ut ipsum egestas, sed sollicitudin elit convallis. Cras pharetra mi tristique sapien vestibulum lobortis. Nam eget bibendum metus,non dictum mauris. Nulla at tellus sagittis, viverra est a, bibendum metus. \n Lorem ipsum dolor sit amet, consectetur adipiscing elit. Quisque nisl eros, pulvinar facilisis justo mollis, auctor consequat urna. Morbi a bibendum metus. Donec scelerisque sollicitudin enim eu venenatis. Duis tincidunt laoreet ex, in pretium orci vestibulum eget. Class aptent taciti sociosqu ad litora torquentper conubia nostra, per inceptos himenaeos. Duis pharetra luctus lacus ut vestibulum. Maecenas ipsum lacus, lacinia quis posuere ut, pulvinar vitae dolor.Integer eu nibh at nisi ullamcorper sagittis id vel leo. Integer feugiat faucibus libero, at maximus nisl suscipit posuere. Morbi nec enim nunc. Phasellus bibendum turpis ut ipsum egestas, sed sollicitudin elit convallis. Cras pharetra mi tristique sapien vestibulum lobortis. Nam eget bibendum metus,non dictum mauris. Nulla at tellus sagittis, viverra est a, bibendum metus.Lorem ipsum dolor sit amet, consectetur adipiscing elit. Quisque nisl eros, pulvinar facilisis justo mollis, auctor consequat urna. Morbi a bibendum metus. Donec scelerisque sollicitudin enim eu venenatis. Duis tincidunt laoreet ex, in pretium orci vestibulum eget. Class aptent taciti sociosqu ad litora torquentper conubia nostra, per inceptos himenaeos. Duis pharetra luctus lacus ut vestibulum. Maecenas ipsum lacus, lacinia quis posuere ut, pulvinar vitae dolor.Integer eu nibh at nisi ullamcorper sagittis id vel leo. Integer feugiat faucibus libero, at maximus nisl suscipit posuere. Morbi nec enim nunc. Phasellus bibendum turpis ut ipsum egestas, sed sollicitudin elit convallis. Cras pharetra mi tristique sapien vestibulum lobortis. Nam eget bibendum metus,non dictum mauris. Nulla at tellus sagittis, viverra est a, bibendum metus. \n Lorem ipsum dolor sit amet, consectetur adipiscing elit. Quisque nisl eros, pulvinar facilisis justo mollis, auctor consequat urna. Morbi a bibendum metus. Donec scelerisque sollicitudin enim eu venenatis. Duis tincidunt laoreet ex, in pretium orci vestibulum eget. Class aptent taciti sociosqu ad litora torquentper conubia nostra, per inceptos himenaeos. Duis pharetra luctus lacus ut vestibulum. Maecenas ipsum lacus, lacinia quis posuere ut, pulvinar vitae dolor.Integer eu nibh at nisi ullamcorper sagittis id vel leo. Integer feugiat faucibus libero, at maximus nisl suscipit posuere. Morbi nec enim nunc. Phasellus bibendum turpis ut ipsum egestas, sed sollicitudin elit convallis. Cras pharetra mi tristique sapien vestibulum lobortis. Nam eget bibendum metus,non dictum mauris. Nulla at tellus sagittis, viverra est a, bibendum metus. \n Lorem ipsum dolor sit amet, consectetur adipiscing elit. Quisque nisl eros, pulvinar facilisis justo mollis, auctor consequat urna. Morbi a bibendum metus. Donec scelerisque sollicitudin enim eu venenatis. Duis tincidunt laoreet ex, in pretium orci vestibulum eget. Class aptent taciti sociosqu ad litora torquentper conubia nostra, per inceptos himenaeos. Duis pharetra luctus lacus ut vestibulum. Maecenas ipsum lacus, lacinia quis posuere ut, pulvinar vitae dolor.Integer eu nibh at nisi ullamcorper sagittis id vel leo. Integer feugiat faucibus libero, at maximus nisl suscipit posuere. Morbi nec enim nunc. Phasellus bibendum turpis ut ipsum egestas, sed sollicitudin elit convallis. Cras pharetra mi tristique sapien vestibulum lobortis. Nam eget bibendum metus,non dictum mauris. Nulla at tellus sagittis, viverra est a, bibendum metus.Lorem ipsum dolor sit amet, consectetur adipiscing elit. Quisque nisl eros, pulvinar facilisis justo mollis, auctor consequat urna. Morbi a bibendum metus. Donec scelerisque sollicitudin enim eu venenatis. Duis tincidunt laoreet ex, in pretium orci vestibulum eget. Class aptent taciti sociosqu ad litora torquentper conubia nostra, per inceptos himenaeos. Duis pharetra luctus lacus ut vestibulum. Maecenas ipsum lacus, lacinia quis posuere ut, pulvinar vitae dolor.Integer eu nibh at nisi ullamcorper sagittis id vel leo. Integer feugiat faucibus libero, at maximus nisl suscipit posuere. Morbi nec enim nunc. Phasellus bibendum turpis ut ipsum egestas, sed sollicitudin elit convallis. Cras pharetra mi tristique sapien vestibulum lobortis. Nam eget bibendum metus,non dictum mauris. Nulla at tellus sagittis, viverra est a, bibendum metus. \n Lorem ipsum dolor sit amet, consectetur adipiscing elit. Quisque nisl eros, pulvinar facilisis justo mollis, auctor consequat urna. Morbi a bibendum metus. Donec scelerisque sollicitudin enim eu venenatis. Duis tincidunt laoreet ex, in pretium orci vestibulum eget. Class aptent taciti sociosqu ad litora torquentper conubia nostra, per inceptos himenaeos. Duis pharetra luctus lacus ut vestibulum. Maecenas ipsum lacus, lacinia quis posuere ut, pulvinar vitae dolor.Integer eu nibh at nisi ullamcorper sagittis id vel leo. Integer feugiat faucibus libero, at maximus nisl suscipit posuere. Morbi nec enim nunc. Phasellus bibendum turpis ut ipsum egestas, sed sollicitudin elit convallis. Cras pharetra mi tristique sapien vestibulum lobortis. Nam eget bibendum metus,non dictum mauris. Nulla at tellus sagittis, viverra est a, bibendum metus. \n";

class MyEmitter extends EventEmitter{}
let myEmitterObj = new MyEmitter();


myEmitterObj.once("newListener", () => {
    if(process.env.NODE_ENV === undefined)
    {
        console.log("NODE_ENV not defined. Define it first to (development or production) and then restart cmd to run the app!!");
        process.exit();
    }
})


myEmitterObj.on("createFolders", () => {
    let env_dir = __dirname + `\\${process.env.NODE_ENV}`;

    if(!fs.existsSync(env_dir))
        fs.mkdirSync(env_dir, error_callback);
    
    let src_dir = env_dir + "\\src";
    if(!fs.existsSync(src_dir))
        fs.mkdirSync(src_dir, error_callback);

    let dest_dir = env_dir + "\\dest";
    if(!fs.existsSync(dest_dir))
        fs.mkdirSync(dest_dir, error_callback);

    function error_callback(err){ 
        if (err)  
            console.error(err); 
    }

    console.log("Source Folder Task Executed");
});


myEmitterObj.on("createSourceFile", () => {
    let file_loc = __dirname + `\\${process.env.NODE_ENV}\\src\\${file_name}.txt`;//this can be problematic if write stream takes only file name and not path
    fs.writeFileSync(file_loc, content);
    console.log("Data write to File in src folder Sucessfull!!");
});


myEmitterObj.on("createDestFile", () => {
    if(process.argv[2] == "--stream"){
        if(Boolean(process.argv[3])){
            const file_loc = `.\\${process.env.NODE_ENV}\\dest\\${file_name}(stream).txt`;
            const readable = Readable.from(content, {
                highWaterMark: 1,
            });
            const my_write_stream = fs.createWriteStream(file_loc);
            
            let cont = "";
            readable.on("data", (chunk) => {
                cont += chunk;
                console.log("A chunck Transferred");
            });
            readable.on("end", () => {
                my_write_stream.write(cont);
                my_write_stream.end();
                console.log("Data write to File in dest folder Sucessfull!!\nFinsihed Executing the Script. Press ctrl+c to end the script");
            });
            readable.on("error", () => {
                console.log("Some error occured while writing to the file! Try Again later\nFinsihed Executing the Script. Press ctrl+c to end the script");
            });
        }
        else{
            const file_loc = `.\\${process.env.NODE_ENV}\\dest\\${file_name}(async fs).txt`;
            fs.writeFile(file_loc, content, (err) => {
                try{
                    console.log("Data write to File in dest folder Sucessfull!!\nFinsihed Executing the Script. Press ctrl+c to end the script");
                }catch{
                    console.log("An Error Occured While writing to dest Folder :(\nFinsihed Executing the Script. Press ctrl+c to end the script");
                }
            });
        }
    }
    else
    {
        console.log("pass valid --stream argument to create destination file");
        process.exit();
    }
});


myEmitterObj.on("error", (err) => {
    console.log(err);
});


myEmitterObj.emit("createFolders");
myEmitterObj.emit("createSourceFile");
myEmitterObj.emit("createDestFile");


const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout,
});

rl.on("SIGINT", () => {
    console.log("Received Interrupt Signal");
    rl.close();
});
