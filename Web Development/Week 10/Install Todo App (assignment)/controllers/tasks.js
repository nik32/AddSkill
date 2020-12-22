//refer to - https://www.sqlitetutorial.net/sqlite-nodejs/insert/
//			 https://www.sqlitetutorial.net/sqlite-nodejs/

var db = require('../db/db.js');

var listTasks = (req, res) => {
	db.all('SELECT * FROM todos', (err, data) => {
		if (err) {
			console.error('Error listing tasks');
			res.json(	{"success": false,}	);
		} else {
			res.json({
				"success": true,
				"tasks": data,
			});
		}
	})
}

var createTask = (req, res) => {
	
	const { name } = req.body;
	db.run('INSERT INTO todos (name, status) VALUES (?, ?)', [name, 'yet to done'], (err) => {
		if (err) {
			console.error('Error inserting task');
			res.json(	{"success": false}	);
		} 
		else 
			res.json(	{"success": true}	);
	})
}

let deleteTask = (req, res) => {

	const {name} = req.headers;//as delete http request can't have body, you passed the name as part of headers
	// console.log(req);
	// console.log(name); // used these comments to see, how the values sent from headers are stored in the req object 
	db.run('DELETE FROM todos WHERE name = ?', [name], (err) => {
		if (err) {
			console.error('Error deleting the task');
			res.json(	{"success": false}	);
		} 
		else
			res.json(	{"success": true}	); 
	});
}

let updateTask = (req, res) => {

	const { name, status } = req.body;

	db.run('UPDATE todos	SET status = ?	WHERE name = ?', [status, name], (err) => {
		if (err) {
			console.error('Error updating the task');
			res.json(	{"success": false}	);
		} 
		else
			res.json(	{"success": true}	);
	});
}

module.exports.listTasks = listTasks;
module.exports.createTask = createTask;
module.exports.deleteTask = deleteTask;
module.exports.updateTask = updateTask;