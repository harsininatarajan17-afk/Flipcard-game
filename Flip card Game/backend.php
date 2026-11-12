<?php
$servername = "localhost";
$username = "root";
$password = "";
$dbname = "memory_game";

// Create connection
$conn = new mysqli($servername, $username, $password, $dbname);
if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}

// Store score
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $player1 = $_POST['player1'];
    $score1 = $_POST['score1'];
    $player2 = $_POST['player2'];
    $score2 = $_POST['score2'];

    $sql = "INSERT INTO scores (player, score) VALUES ('$player1', '$score1'), ('$player2', '$score2')";
    if ($conn->query($sql) === TRUE) {
        echo "Scores saved successfully!";
    } else {
        echo "Error: " . $conn->error;
    }
}

// Retrieve scores
$sql = "SELECT * FROM scores ORDER BY score DESC LIMIT 10";
$result = $conn->query($sql);
$scores = [];
while ($row = $result->fetch_assoc()) {
    $scores[] = $row;
}
echo json_encode($scores);

$conn->close();
?>