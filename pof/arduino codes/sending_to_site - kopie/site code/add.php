<?php
   	include("connect.php");
   	
   	$link=Connection();

	$data=$_POST["data"];

	$query = "UPDATE`kotOpen` SET `open`=".$data." WHERE `ID`=0"; 
	//echo $query;
   mysql_query($query,$link);
	mysql_close($link);

   	header("Location: index.php");
?>
