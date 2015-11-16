<?php

	function Connection(){
		$server="10.3.1.105";
		$user="jonasxt155";
		$pass="bpd0mpxj";
		$db="jonasxt155_brabo";
	   	

		$connection = mysql_connect($server, $user, $pass);

		if (!$connection) {
	    	die('MySQL ERROR: ' . mysql_error());
		}
		
		mysql_select_db($db) or die( 'MySQL ERROR: '. mysql_error() );

		return $connection;
	}
?>
