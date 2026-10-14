/* ============================================================
 * Student Grade Management System
 * Data Structures Project - Arrays Application (Web Version)
 *
 * Uses ARRAYS (JavaScript arrays) to store student records.
 * Parallel arrays: names[i] and grades[i] belong to same student.
 * ============================================================ */

// ---------- Parallel arrays (same concept as C++ version) ----------
let studentNames = [];
let studentGrades = [];

// ---------- AI Feature 1: Grade Classification ----------
function aiGrade(score) {
    if (score >= 80) return "A - Excellent";
    if (score >= 70) return "B - Very Good";
    if (score >= 60) return "C - Good";
    if (score >= 50) return "D - Pass";
    return "F - Fail";
}

// ---------- AI Feature 2: Performance Prediction ----------
function aiPredict(score) {
    if (score >= 75) return "Likely to excel in final exams";
    if (score >= 55) return "Average performance, needs improvement";
    return "At risk - recommend remedial classes";
}

// ---------- Show message to user ----------
function showMessage(text, type) {
    const msg = document.getElementById("message");
    msg.textContent = text;
    msg.className = "message " + type;
    setTimeout(() => { msg.textContent = ""; msg.className = "message"; }, 3000);
}

// ---------- Add a student ----------
function addStudent() {
    const nameInput  = document.getElementById("nameInput");
    const gradeInput = document.getElementById("gradeInput");

    const name  = nameInput.value.trim();
    const grade = parseInt(gradeInput.value);

    // Validation
    if (!name) {
        showMessage("Please enter a student name.", "error");
        return;
    }
    if (isNaN(grade) || grade < 0 || grade > 100) {
        showMessage("Grade must be a number between 0 and 100.", "error");
        return;
    }

    // Store in parallel arrays (same index)
    studentNames.push(name);
    studentGrades.push(grade);

    // Clear inputs
    nameInput.value = "";
    gradeInput.value = "";
    nameInput.focus();

    showMessage(`${name} added successfully.`, "success");
    render();
}

// ---------- Remove a student by index ----------
function removeStudent(index) {
    studentNames.splice(index, 1);
    studentGrades.splice(index, 1);
    render();
}

// ---------- Clear all ----------
function clearAll() {
    if (studentNames.length === 0) return;
    if (confirm("Remove all student records?")) {
        studentNames = [];
        studentGrades = [];
        render();
    }
}

// ---------- Render the table ----------
function render() {
    const tbody = document.getElementById("studentBody");
    tbody.innerHTML = "";

    if (studentNames.length === 0) {
        tbody.innerHTML = '<tr><td colspan="6" class="empty">No students added yet.</td></tr>';
        updateStats();
        return;
    }

    // Traverse the arrays (classic array operation)
    for (let i = 0; i < studentNames.length; i++) {
        const row = document.createElement("tr");
        row.innerHTML = `
            <td>${i + 1}</td>
            <td>${studentNames[i]}</td>
            <td>${studentGrades[i]}</td>
            <td>${aiGrade(studentGrades[i])}</td>
            <td>${aiPredict(studentGrades[i])}</td>
            <td><button class="remove" onclick="removeStudent(${i})">Remove</button></td>
        `;
        tbody.appendChild(row);
    }

    updateStats();
}

// ---------- Aggregate statistics (array traversal) ----------
function updateStats() {
    const total = studentNames.length;

    document.getElementById("statTotal").textContent = total;

    if (total === 0) {
        document.getElementById("statAvg").textContent  = "0";
        document.getElementById("statHigh").textContent = "0";
        document.getElementById("statLow").textContent  = "0";
        return;
    }

    let sum = 0;
    let high = studentGrades[0];
    let low  = studentGrades[0];

    for (let i = 0; i < studentGrades.length; i++) {
        sum += studentGrades[i];
        if (studentGrades[i] > high) high = studentGrades[i];
        if (studentGrades[i] < low)  low  = studentGrades[i];
    }

    document.getElementById("statAvg").textContent  = (sum / total).toFixed(2);
    document.getElementById("statHigh").textContent = high;
    document.getElementById("statLow").textContent  = low;
}

// ---------- Allow Enter key to add student ----------
document.addEventListener("DOMContentLoaded", () => {
    document.getElementById("gradeInput")
        .addEventListener("keypress", e => { if (e.key === "Enter") addStudent(); });
    render();
});