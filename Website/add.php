<?php
$lat=$_GET['l'];
$lng=$_GET['n'];
 
  $servername = "localhost";
  $username = "mhhabibinfo_track";
  $password = "bustrackcse14just";
  $dbname = "mhhabibinfo_track";
	$conn = mysqli_connect($servername,$username,$password,$dbname);
 
if (!$conn) {
    		die("Connection failed with database: " . mysqli_connect_error());
	}
	
if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
  }
 
  
$sql = "INSERT INTO tracking_info values('$lat','$lng')";
 
if ($conn->query($sql) === TRUE) {
    echo "New record created successfully";
} else {
    echo "Error: " . $sql . "<br>" . $conn->error;
}
 
$conn->close();
?>