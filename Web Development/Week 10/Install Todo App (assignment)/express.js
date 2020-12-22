const express = require('express');
const app = express();
const tasksRouter = require('./routes/tasks');

app.listen(3000, (err) => {
	if (err) { console.error (err); }
	console.log('Listening on 3000');
});

app.use(express.json());

app.use('/tasks', tasksRouter);