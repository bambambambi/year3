<?php
	@mysql_connect("localhost", "guest", "1234xy")
		or die("Access to db server denied");
	@mysql_select_db("scheduling")
		or die("Access to scheduling denied");
?>
