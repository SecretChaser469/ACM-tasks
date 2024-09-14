import React, { useState, useEffect } from 'react';
import './App.css';

function App() {
    // State to store the tasks
    const [tasks, setTasks] = useState([]);
    const [newTask, setNewTask] = useState(""); // To hold new task text
    const [isEditing, setIsEditing] = useState(false); // Check if we are editing
    const [currentTask, setCurrentTask] = useState({}); // Hold the task currently being edited

    // Load tasks from local storage when the app loads
    useEffect(() => {
        const storedTasks = JSON.parse(localStorage.getItem("tasks"));
        if (storedTasks) {
            setTasks(storedTasks);
        }
    }, []);

    // Save tasks to local storage whenever they change
    useEffect(() => {
        localStorage.setItem("tasks", JSON.stringify(tasks));
    }, [tasks]);

    // Handle the input field change
    const handleInputChange = (e) => {
        setNewTask(e.target.value);
    };

    // Add a new task to the list
    const addTask = () => {
        if (newTask.trim()) {
            const newTaskObj = {
                id: Date.now(),
                text: newTask,
                completed: false,
            };
            setTasks([...tasks, newTaskObj]); // Add new task to the list
            setNewTask(""); // Clear input field after adding
        }
    };

    // Delete a task by its id
    const deleteTask = (id) => {
        setTasks(tasks.filter((task) => task.id !== id));
    };

    // Mark task as completed or incomplete
    const toggleComplete = (id) => {
        setTasks(
            tasks.map((task) =>
                task.id === id ? { ...task, completed: !task.completed } : task
            )
        );
    };

    // Handle editing a task
    const handleEdit = (task) => {
        setIsEditing(true);
        setCurrentTask(task);
        setNewTask(task.text); // Set input field with the task's current text
    };

    // Update the task after editing
    const updateTask = () => {
        setTasks(
            tasks.map((task) =>
                task.id === currentTask.id ? { ...task, text: newTask } : task
            )
        );
        setIsEditing(false); // Exit editing mode
        setNewTask(""); // Clear input field
    };

    return (
        <div className="app">
            <h1>To-Do List</h1>

            <div className="input-container">
                <input
                    type="text"
                    placeholder="Add a new task"
                    value={newTask}
                    onChange={handleInputChange}
                />
                {isEditing ? (
                    <button onClick={updateTask}>Update Task</button>
                ) : (
                    <button onClick={addTask}>Add Task</button>
                )}
            </div>

            <ul>
                {tasks.map((task) => (
                    <li key={task.id} className={task.completed ? "completed" : ""}>
                        <span onClick={() => toggleComplete(task.id)}>
                            {task.text}
                        </span>
                        <button onClick={() => handleEdit(task)}>Edit</button>
                        <button onClick={() => deleteTask(task.id)}>Delete</button>
                    </li>
                ))}
            </ul>
        </div>
    );
}

export default App;
