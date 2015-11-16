<?php

	include("connect.php"); 	
	
	$link=Connection();
	$result=mysql_query("SELECT * FROM `kotOpen`");
	while ($row = mysql_fetch_assoc($result)) {
    $data = $row['open'];
}
		if ($data == 0)
		     {
		     	$kot= 'dicht';
		     }
		     else
		     {
		     	$kot= 'open';
		     }
?>

<html>
   <head>
      <title>kot open</title>
      <script>
		  window.fbAsyncInit = function() {
		    FB.init({
		      appId      : '1653079894947834',
		      xfbml      : true,
		      version    : 'v2.5'
		    });
		  };

		  (function(d, s, id){
		     var js, fjs = d.getElementsByTagName(s)[0];
		     if (d.getElementById(id)) {return;}
		     js = d.createElement(s); js.id = id;
		     js.src = "//connect.facebook.net/en_US/sdk.js";
		     fjs.parentNode.insertBefore(js, fjs);
		   }(document, 'script', 'facebook-jssdk'));
	</script>
   </head>
<body>
	<h1>brabokot is <?=$kot;?></h1>

	<form action="add.php" method="post">
  open of toe <input type="text" id="name" name="data"><br>
  <input type="submit" value="Submit">
</form>

	<div
	  class="fb-like"
	  data-share="true"
	  data-width="450"
	  data-show-faces="true">
	</div>
</body>
</html>
