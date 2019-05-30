<?php
	Header('Content-type: text/xml');
	include_once("conn.php");

	$pid = $_GET['q'];

	$query = "SELECT courses.cid, courses.cname
		  FROM programs, courses
		  WHERE pid='$pid'
		  AND programs.cid=courses.cid";

	$result = @mysql_query($query) or die("Query failed");
	$num_rows = mysql_num_rows($result);

	echo '<courses>';
	while($row = mysql_fetch_array($result)) {
		echo '<course>';
		echo "<cid>".$row['cid']."</cid>";
		echo "<cname>". $row['cname']."</cname>";
		echo '</course>';
	}
	echo '</courses>';
	mysql_close();
?>
