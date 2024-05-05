const EventEmitter = require("node:events");
const { setTimeout } = require("node:timers");
const emitter = new EventEmitter();
emitter.on("hello", name => {
    console.log("Hello, " + name);
});

setTimeout(_ => emitter.emit("hello", "John"), 2500);
emitter.emit("hello", "Mary");