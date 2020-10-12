

<script src="https://www.gstatic.com/firebasejs/7.6.0/firebase-app.js"></script>

<!-- TODO: Add SDKs for Firebase products that you want to use
     https://firebase.google.com/docs/web/setup#available-libraries -->
<script src="https://www.gstatic.com/firebasejs/7.6.0/firebase-analytics.js"></script>
<script src="https://www.gstatic.com/firebasejs/7.6.0/firebase-auth.js"></script>
<script src="https://www.gstatic.com/firebasejs/7.6.0/firebase-database.js"></script>
<?php
$data0="";
$data1="";
$data2="";
$data3="";
$data4="";
$phone_number = "8801731821089";

 require __DIR__ . "/vendor/autoload.php";
  use telesign\sdk\messaging\MessagingClient;
$customer_id = "C6DDFCE9-103D-4C8D-8F3B-A74885F62D8D";
  $api_key = "LGX2jBGmRtGMWJi4r/eP6pfLv1HTrFFK4Gk0Ys5C554RSrtOuxZ/tLpCxBjt8JVa769NYDeSeBBbPVAg9g6UiQ==";
if(isset($_GET['data0']))
{


	$data0=$_GET['data0'];
	$data1=$_GET['data1'];
	$data2=$_GET['data2'];
	$data3=$_GET['data3'];
	$data4=$_GET['data4'];
	$output = shell_exec("python ai.py ".$data0." ".$data1." ".$data2." ".$data3." ".$data4."");


	if($output[5]=='2')
	{
		 
 
  
 
  $message = "Alert!High Gas Leakage Detected,Stay away from lighting up fire....";
  $message_type = "ARN";
  $messaging = new MessagingClient($customer_id, $api_key);
  $response = $messaging->message($phone_number, $message, $message_type);
  

		
	}
		if($output[5]=='1')
	{
		 
 
  
  
  $message = "Alert! Mild Gas Leakage Detected";
  $message_type = "ARN";
  $messaging = new MessagingClient($customer_id, $api_key);
  $response = $messaging->message($phone_number, $message, $message_type);
  

		
	}
echo $output;





	

}



?>
<!-- The core Firebase JS SDK is always required and must be listed first -->


<script>
	var firebaseConfig = {
    apiKey: "AIzaSyC1VC0ylZjNW5-oWRXWFIg9WSgcBSJJPuQ",
    authDomain: "ai-based-gas-leak-detection.firebaseapp.com",
    databaseURL: "https://ai-based-gas-leak-detection.firebaseio.com",
    projectId: "ai-based-gas-leak-detection",
    storageBucket: "ai-based-gas-leak-detection.appspot.com",
    messagingSenderId: "368658615290",
    appId: "1:368658615290:web:11c7bbead947deaf78b243",
    measurementId: "G-K65KLCX4TQ"
  };
    firebase.initializeApp(firebaseConfig);
  firebase.analytics();
  // Your web app's Firebase configuration
  var flag=<?php echo "$output[5]"?>;
  var output=[<?php echo "$output[0]"?>,<?php echo "$output[1]"?>,<?php echo "$output[2]"?>,<?php echo "$output[3]"?>,<?php echo "$output[4]"?>];
  var data=[<?php echo "$data0"?>,<?php echo "$data1"?>,<?php echo "$data2"?>,<?php echo "$data3"?>,<?php echo "$data4"?>];
  var i=0;
  if(flag==2 || flag==1)
  {
  	
  	for(i=0; i<5;i++)
  	{
  		console.log("for e dhuksi");
  		var temp=output[i];
  		console.log(temp);
  		if( temp==2 ||temp ==1)
  		{
  			console.log(data[i]);
  			console.log(output[i]);


   firebase.database().ref(new Date().getTime()).set({
   	ppm: data[i],
   	severity: output[i]
   });
  

  		}
  		else 
  		{
  			continue;
  		}
  	}
  
}
</script>
