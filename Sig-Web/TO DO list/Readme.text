Step 1: Setting Up Your React Project
First, we need to create a basic React app where we will build our To-Do List.

Install Node.js (if you don’t have it yet):

React apps are usually created using Node.js, so you’ll need to install it first. You can download Node.js from https://nodejs.org/en
Create a New React Project:

Open a terminal (or command prompt) on your computer.
Run the following command:
npx create-react-app todo-list
npx create-react-app is a tool that helps you create a React project with everything pre-configured.
todo-list is the name of your project folder.
After the project is created, navigate to the folder:

cd todo-list
Start the development server to view the app in your browser:

npm start
Your app will open in a browser window (usually at http://localhost:3000). Initially, you'll just see a basic React page.
Step 2: Understanding React Components
React works by dividing the webpage into components. Components are reusable pieces of UI (User Interface). Think of them like building blocks. Our app will consist of several components, such as:

App Component: This is the main component where the overall logic resides.
To-Do Item Component: Each task will be a separate "to-do item" component.
To-Do List Component: This will handle displaying all the tasks.
Step 3: Building the App in React
Now that your app is set up, we’ll start building the To-Do List.

1. App.js File:
In your project folder, open the App.js file. This file is where we will write most of the code for managing tasks.

Understanding State in React:

React apps use state to track data (like the list of tasks). When the state changes, the app automatically updates to show the new data. In this case, our state will store a list of tasks, and we’ll use the React function useState to manage it.
Add the Basic Structure
Here’s a simple breakdown of how the App.js file will be structured:

jsx

import React, { useState, useEffect } from 'react';
import './App.css';

function App() {
    const [tasks, setTasks] = useState([]); // An array to hold our tasks
    const [newTask, setNewTask] = useState(""); // A string to hold the new task's input text

    return (
        <div className="app">
            <h1>To-Do List</h1>
            <input 
                type="text"
                placeholder="Add a new task"
                value={newTask}
                onChange={(e) => setNewTask(e.target.value)} 
            />
            <button>Add Task</button>
            <ul>
                {tasks.map(task => (
                    <li key={task.id}>{task.text}</li>
                ))}
            </ul>
        </div>
    );
}

export default App;
Explanation:
State Variables:
tasks: This holds the list of to-do items. We’ll use it to manage all the tasks.
newTask: This holds the text entered in the input field for a new task.
Rendering the UI:
We have an <input> element to allow users to type in a task. It uses the newTask state to store whatever the user types.
When the user adds a task, we’ll push it into the tasks array, and each task will be displayed inside a <li> (list item).
2. Adding a New Task:
Now let’s modify the "Add Task" button to actually add a task to the list. We’ll write a function that runs when the user clicks the button.

jsx

function addTask() {
    if (newTask.trim()) {
        const newTaskObj = {
            id: Date.now(), // A unique ID for each task
            text: newTask,  // The actual task text
            completed: false // We'll use this later for marking tasks as completed
        };
        setTasks([...tasks, newTaskObj]); // Add the new task to the list
        setNewTask(""); // Clear the input field
    }
}
trim(): This removes any extra spaces from the beginning or end of the input.
setTasks([...tasks, newTaskObj]): This takes the current list of tasks and adds the new task at the end.
setNewTask(""): This resets the input field to be empty again after adding the task.
Now modify the button in the return statement to call addTask:

jsx

<button onClick={addTask}>Add Task</button>
3. Displaying the Tasks:
When we add tasks, they should appear in the list below the input field. We use the map() function to go through each task in the tasks array and display it in the browser.

jsx

<ul>
    {tasks.map(task => (
        <li key={task.id}>
            {task.text}
        </li>
    ))}
</ul>
Step 4: Marking a Task as Completed
Now let’s add a feature where we can click on a task to mark it as completed. We’ll modify the tasks array so each task has a completed status (true or false).

Modify the task item to toggle its completion status:
jsx
Copy code
function toggleComplete(id) {
    setTasks(
        tasks.map(task => 
            task.id === id ? { ...task, completed: !task.completed } : task
        )
    );
}
Update the li element to toggle completion when clicked:
jsx

<li key={task.id} className={task.completed ? "completed" : ""} onClick={() => toggleComplete(task.id)}>
    {task.text}
</li>
If task.completed is true, the class completed will be applied, which we can style in CSS.
Step 5: Deleting a Task
Add a button to delete tasks:

Function to Delete a Task:
jsx

function deleteTask(id) {
    setTasks(tasks.filter(task => task.id !== id));
}
Delete Button in Each List Item:
jsx
Copy code
<li key={task.id} className={task.completed ? "completed" : ""}>
    <span onClick={() => toggleComplete(task.id)}>{task.text}</span>
    <button onClick={() => deleteTask(task.id)}>Delete</button>
</li>
Step 6: Local Storage
To make the app remember tasks between sessions, we’ll use localStorage, which saves data in the browser.

Load Tasks from Local Storage:

When the app starts, we want to load any saved tasks:
jsx

useEffect(() => {
    const storedTasks = JSON.parse(localStorage.getItem("tasks"));
    if (storedTasks) {
        setTasks(storedTasks);
    }
}, []);
Save Tasks to Local Storage:

Whenever tasks change, save them to localStorage:
jsx

useEffect(() => {
    localStorage.setItem("tasks", JSON.stringify(tasks));
}, [tasks]);
Step 7: CSS Styling
To make the app look nice, here’s some basic CSS for the app. Add this in the App.css file
