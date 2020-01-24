<!DOCTYPE html>
<html>
  <head>
    <title>Challenge 24 Tester</title>
    <link href="/website/style.css" rel="stylesheet" type="text/css" />
  </head>


  <body>

    <h2>Challenge 24 Tester</h2>
    <p>Test to see if your set of integers can be used to play Challenge 24! If you want to see the solutions, enter Y as the option (not case sensitive). Remember to fill out all fields!</p>

    <?php
       // define variables and set to empty values
       $arg1 = $arg2 = $output = $retc = "";
       $arg3 = "";
       $arg4 = $arg5 = "";

       if ($_SERVER["REQUEST_METHOD"] == "POST") {
         $arg1 = test_input($_POST["arg1"]);
         $arg2 = test_input($_POST["arg2"]);
         $arg3 = test_input($_POST["arg3"]);
         $arg4 = test_input($_POST["arg4"]);
         $arg5 = test_input($_POST["arg5"]);
         exec("/usr/lib/cgi-bin/sp3a/chal24 " . $arg1 . " " . $arg2 . " " . $arg3 . " " . $arg4 . " " . $arg5, $output, $retc); 
       }

       function test_input($data) {
         $data = trim($data);
         $data = stripslashes($data);
         $data = htmlspecialchars($data);
         return $data;
       }
    ?>

    <form method="post" action="<?php echo htmlspecialchars($_SERVER["PHP_SELF"]);?>">
      Num1: <input type="text" name="arg1"><br>
      Num2: <input type="text" name="arg2"><br>
      Num3: <input type="text" name="arg2"><br>
      Num4: <input type="text" name="arg2"><br>
      Option: <input type="text" name="arg2"><br>
      <br>
      <input type="submit" value="Go!">
    </form>

    <?php
       // only display if return code is numeric - i.e. exec has been called
       if (is_numeric($retc)) {
         echo "<h3>Your Input:</h3>";
         echo $arg1;
         echo "<br>";
         echo $arg2;
         echo "<br>";
         echo $arg3;
         echo "<br>";
         echo $arg4;
         echo "<br>";
         echo $arg5;
         echo "<br>";
       
         echo "<h3>Program Output (an array):</h3>";
         foreach ($output as $line) {
           echo $line;
           echo "<br>";
         }
       
         echo "<h3>Program Return Code:</h3>";
         echo $retc;
       }
    ?>
    
  </body>
</html>
